#include "Token.h"

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
	if (((x >= ' ') && (x <= '!')) || ((x >= '#') && (x <= '$')) || ((x >= '&') && (x <= ')')) ||
		(x == ',') || ((x >= ':') && (x <= ';')) || ((x >= '[') && (x <= '`')) ||
		((x >= '{') && (x <= '~')) || (x == '?'))
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
	if ((ch == '%') || (ch == '*') || (ch == '+') || (ch == '-') || (ch == '/') ||
		((ch >= '<') && (ch <= '>'))) //for unary operators
		return true;
	else
		return false;
}
bool Token::isDigit(char ch) {

	if ((ch >= '0') && (ch <= '9'))
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
 void Token::writeSymbol(string tokenChar)
 {
  ofstream output("token.txt", output.app);
        if(output.is_open())
        {
            output <<"<symbol, "<<tokenChar<<" >\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void Token::writeidentifier(string tokenId){
    ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"<id , "<<tokenId<<">\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void Token::writeKeyword(string kw){
        ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"<kw ,"<<kw<<" >\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void Token::writeOperator(string op){
        ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"<op ,"<<op<<" >\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void Token::writeDigit(string number){
    ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"int:"<<number<<"\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
             output.close();
        }
}
void Token::writeFloat(string number){
    ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"float:"<<number<<"\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void Token::writeString(string word){
    ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output<<"<string:"<<word<<">\n";
            output.close();
        }
        else
        {
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
