#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//helloworld
bool isString(int x){
    if((x>=32)&&(x<=126))
        return true;
    else
        return false;
}
bool isSymbol(int x)
{
    if(((x>=32)&&(x<=33)) ||((x>=35)&&(x<=36)) ||((x>=38)&&(x<=41)) || (x==44)||(x==46) || ((x>=58)&&(x<=59)) || ((x>=91)&&(x<=96)) || ((x>=123)&&(x<=126)) ||(x==63))
        return true;
    else
        return false;
}
bool isIdentifier(int x)
{
    if(((x>=64)&&(x<=90)) || ((x>=97)&&(x<=122)))
           return true;
        else
            return false;
}
bool isOperator(int x){
        if((x==37)||(x == 42)||(x == 43)||(x==45)||(x==47)||((x>=61)&&(x<=62))) //for unary operators
        return true;
    else
        return false;
}
bool isDigit(string word){
    int count=0;
    for(int i=0 ; i < word.length() ; i++){
           int x=int(word[i]);
        if((x>=48)&&(x<=57)){count++;}
        else {
                count =0;
             }
        }
            if(count == word.length())
                {
                     return true;
                }
        else
            return false;
}
bool isKeyword(string word)
{
ifstream keyword("keywords.txt");
string kw;
      while(keyword>>kw)
      {
        if(kw == word)
            return true;
      }
    return false;
}
 void writeSymbol(char tokenChar)
 {
  ofstream output("token.txt", output.app);
    if(output.is_open())
    {
        output <<"<symbol, "<<tokenChar<<" >\n";
        output.close();
    }
    else{
        cout<<"ERROR IN OPENING FILE";
         output.close();

    }
}
void writeidentifier(string tokenId){
    ofstream output("token.txt",output.app);
     if(output.is_open())
    {
        output <<"<id , "<<tokenId<<">\n";
        output.close();
    }
    else{
            cout<<"ERROR IN OPENING FILE";
            output.close();
        }
}
void writeKeyword(string kw){
        ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"<kw ,"<<kw<<" >\n";
            output.close();
        }
        else{
            cout<<"ERROR IN OPENING FILE";
            output.close();
            }
}
void writeOperator(string op){
        ofstream output("token.txt",output.app);
         if(output.is_open())
        {
            output <<"<op ,"<<op<<" >\n";
            output.close();
        }
        else{
            cout<<"ERROR IN OPENING FILE";
            output.close();
            }
}
void writeDigit(string number){
    ofstream output("token.txt",output.app);
     if(output.is_open())
    {
        output <<"digits:"<<number<<"\n";
        output.close();
    }
    else{
            cout<<"ERROR IN OPENING FILE";
             output.close();
        }
}
void writeString(string word){
    ofstream output("token.txt",output.app);
     if(output.is_open())
    {
        output<<"<string:"<<word<<">\n";
        output.close();
    }
    else{
            cout<<"ERROR IN OPENING FILE";
             output.close();
        }
}
//...........................................//
int main () {
    string tokenId;
    string word;
    string key;
    char tokenChar;
    int num=0;
    int count=0;
    string op;
    string s;
    count=0;

    ifstream input("code.txt");
    if(input.is_open())
    {
    while(input >> word)  //input word by word
        {

            int i=0;
            int n=word.length();
            cout<<word[0];
                cout<<word[n-1];
            if(isKeyword(word)){
                writeKeyword(word);
            }
            else if(isDigit(word)){
            writeDigit(word);
            }
            else
            while(i != word.length())
            {
                char x=word[i];

                    if((char(word[0]) == '"')&&(char(word[n-1]) =='"')) //string token
                    {
                        //cout<<word[i];
                        if(isString(int(x))){
                        s+= word[i]; //adds character into identifier string

                        count++;}
                    }
                     else if(isSymbol((int)x))  //special character
                    {
                        tokenChar = char(x);
                        writeSymbol(tokenChar);
                    }

                    else if(isOperator((int) x))//operator token
                    {
                        op += word[i];

                        if(char(word[i+1])==61) /*This condition checks if we have '=' after <,>,=*/
                        {
                        op += word[i+1];
                         i++; //so that it doesnt count = separate .
                        }
                        writeOperator(op);
                        tokenId.clear(); // for a==b; case
                    }
                    else {
                        if(0==(isOperator((int)word[i])))//identifier token
                        {
                            tokenId+= word[i]; //adds character into identifier string
                            if( 1 ==(isOperator((int)word[i+1]))) //if next character is an operator it will print the identifier string
                                writeidentifier(tokenId); //writes character into file
                        }
                        }
                i++;
                }
                if(count == n){
                 writeString(s); //writes character into file
                 }
            }

    }
    else{
    cout<<"error opening file";
    input.close();
    }
    return 0;
}
