#include "Token.h"

Token::Token()
{
    openTokenFile();
}
Token::~Token()
{
    output.close();
}

void Token::openTokenFile()
{
    output.open("token.txt", ios::out);
    if(!output.is_open())
    {
        cout<<"error opening token file ";
    }
}

void Token::writeToken(string tokenName, string value)
{
    output<<"<"<<tokenName<<", "<<value<<">"<<endl;
}
string Token::isString(string str)
{
	string strings;
	int count = 0;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] == '"') {
			count++;
			while ((str[i + 1] != '"') && (count <= 1)) {
				i++;
				strings += str[i];
			}
		}
	}
	if (strings.length()>0)
		return strings;
	return "";
}
bool Token::isSymbol(int x)
{
        if(
        (x == ' ') ||(x == '!') || (x == '#') || (x == '$') || ((x >= '&') && (x <= ')')) ||
		(x == ',') || (x == ':') || (x == ';') || ((x >= '[') && (x <= '`')) ||
		((x >= '{')&&(x <= '~')) || (x == '?')
        )
		return true;
	else
		return false;
}
bool Token::isIdentifier(char ch)
{
	if (((ch >= '@') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		return true;
	else
		return false;
}
bool Token::isOperator(char ch) {
	if ((ch == '!')||(ch == '%') || (ch == '*') || (ch == '+') || (ch == '-') || (ch == '/') ||
		((ch >= '<') && (ch <= '>'))) //for unary operators
		return true;
	else
		return false;
}
bool Token::isDigit(char ch) {

	if ((ch=='.')||(ch >= '0') && (ch <= '9'))
		return true;
	else
		return false;
}
bool Token::isKeyword(string word)
{
	ifstream keyword("keywords.txt");
	string kw;
	while (keyword >> kw)
	{
		if (kw == word)
			return true;
	}
	return false;
}
void Token::writeNewLine()
 {
     writeToken("symbol", "newline");
}
 void Token::writeSymbol(string tokenChar)
 {
    if(tokenChar==" ")
        writeToken("symbol","sp");
    else
        writeToken("symbol", tokenChar);
}
void Token::writeidentifier(string tokenId)
{
    writeToken("id", tokenId);
}
void Token::writeKeyword(string kw)
{
    writeToken("kw", kw);
}
void Token::writeOperator(string op)
{
    writeToken("op", op);
}
void Token::writeDigit(string number)
{
    writeToken("digit", number);
}
void Token::writeFloat(string number)
{
    writeToken("dec", number);
}
void Token::writeString(string word){
    writeToken("string", word);
}
bool Token::checkWord(string word)
{
    int n;
    int count=0;
    int flag =0;
    int breakCount =0;
    int decimalCount=0;
    string tokenChar;
    string tokenId;
    string symbol;
    string oper;
    string str;
    string digit;
    string strings;

            strings = isString(word);
            if(!strings.empty())
            {
                strings=isString(word);
            }
            int i=0;

            while(i != word.length())
            {
                char x=word[i];
                if(word[i]==' '|| word[i]=='\t'){}
                else {
                     if(isDigit((int)x)&&(!isIdentifier(word[i-1])))
                    {

                                if(word[i-1]=='-')
                                {                       //checks if the number is negative
                                    digit+=word[i-1];
                                    digit+=word[i];
                                }
                                if(word[i+1]=='.') //checks if the number is a float
                                {
                                    decimalCount++;
                                }

                                   else digit+=word[i];


                            if(!isDigit((int)word[i+1])) //writes a float
                                {
                                    if(decimalCount==1)
                                    {
                                    //cout<<"dec          "<<digit<<endl;
                                    writeFloat(digit);
                                    }
                                    else if(decimalCount>1){
                                        breakCount++;
                                        break;
                                        }
                                    else
                                    {
                                        //cout<<"decimal    "<<digit<<endl;
                                        writeDigit(digit); //writes  a decimal

                                    }
                                digit.clear();
                                decimalCount=0;
                                }
                    }
                    else if((isSymbol((int)x)))  //special character
                    {
                        if(word[i]=='"'){
                            flag++;
                        }
                        //
                        else{
                            if((flag==0)||(flag==2))
                                {
                                    tokenChar = word[i];
                                    writeSymbol(tokenChar);
                                    {
                                       //cout<<"symbol        "<<tokenChar<<endl;
                                    }
                                    flag=0;
                                }
                            }
                    }
                    else if(isOperator((int)x))//operator token
                    {
                            if(word[i]=='=' && word[i+1]=='=')
                                {
                                    oper +=word[i];
                                    oper +=word[i+1];
                                    i=i+1;
                                }
                            else if((1==isOperator(word[i-1]))&& word[i]=='=') //This condition checks if we have <= , >= or ==
                                {
                                    oper+=word[i-1]; //i-1 can have < > ,+ ,-
                                    oper+= word[i];
                                     i++; //so that it doesnt count = separate .
                                }
                            else if((word[i]=='+')&&(word[i+1]=='+'))
                                {
                                oper += word[i];
                                oper += word[i+1];
                                 i++;
                                }
                            else if((word[i]=='-')&&(word[i+1]=='-'))
                                {
                                oper+=word[i];
                                oper += word[i+1];
                                i++;
                                }
                            else if((isOperator(word[i])==1) && ((0==isOperator(word[i+1])&&(0==isOperator(word[i-1]) )    )))//pints single operators
                                {
                                    oper=word[i];
                                }
                            else {breakCount++;break;}
                            if(!isOperator((int)word[i+1]))
                            {
                                if(oper.length()>0)
                                    {
                                   // cout<<"operator              "<<oper<<endl;
                                    writeOperator(oper);
                                    }
                                tokenId.clear(); // for a==b; case
                                oper.clear();
                            }
                    }
                       else if(word[i]=='"')
                        {
                                flag++;

                                if(flag==2)
                                {
                                writeString(strings);
                                //cout<<"string  ''"<<strings<<"''"<<endl;
                                strings.clear();
                                }
                        }
                        else{ //keyword and identifier check
                               if(((flag==0)||(flag==2))&& isIdentifier(word[i]))
                                {
                                    //if((word[i]!=',')||(word[i]!= '=')){

                                        if ((word[i+1]>='0')&&(word[i+1]<='9')){//if ientifier ha a number
                                            tokenId+= word[i];
                                            tokenId+= word[i+1]; //adds character into identifier string
                                            i=i+2;
                                            }

                                            tokenId+= word[i]; //adds character into identifier string

                                            if((tokenId.length()>0)&&( (1 == (isDigit((int)word[i+1]) ))||(1 == (isOperator((int)word[i+1]) ))||(1 == (isSymbol((int)word[i+1]) ))||( (i+1)== word.length())) ) //keyword and identifier check
                                            {
                                                if(isKeyword(tokenId))
                                                {

                                                    //cout<<"keyword      "<<tokenId<<endl;
                                                    writeKeyword(tokenId); //writes keyword into file

                                                }
                                                else
                                                {
                                                    if(tokenId[0]>='0' && tokenId[0]<='9')
                                                    {
                                                        breakCount++;
                                                        break;
                                                    }
                                                    else
                                                    writeidentifier(tokenId); //writes identifier into file
                                                    //cout<<"identifier    "<<tokenId<<endl;
                                                }
                                                if(flag==2 || flag==0){
                                                flag=0;
                                                 tokenId.clear();
                                                }
                                            }

                                    }

                                }

                            }
                        i++;
                        }
                tokenId.clear();
                writeNewLine();
                if(breakCount>0){return false;}
                else return true;
          }

