#include<iostream>
#include<string>
#include<fstream>
#include "Token.h"
#include "Syntax.h"

using namespace std;

//...........................................//
int main () {
    string line;
    Token t;
    Syntax s;

    ifstream input("code.txt");
    if(input.is_open())
    {
        int i=0;
  //opening file again for further tokenization
    while (getline(input, line))
     {
         cout<<i+1<<"\t";
         cout<<line<<endl;
         //cout<<"____________________________"<<endl;
        int check=t.checkWord(line);
        if(check==0){cout<<"error in line: "<<i+1<<endl;break;}
        //cout<<"____________________________"<<endl;
        i++;
     }
    }
    else{
    cout<<"error opening code.txt file";
    input.close();
    }
    //...........................................................
  //...........................................................
fstream SYNTAX_FILE("token.txt");
if(SYNTAX_FILE.is_open())
    {
            int i=0;
        //opening file again for further tokenization
        while (getline(SYNTAX_FILE, line))
         {
             //cout<<line<<endl;
             s.tokenParseAndAdd(line);
         }
         SYNTAX_FILE.close();
         cout<<"total tokens: "<< s.getTokenCount()<<endl;
         s.parseGrammar();
    }
    else{
    cout<<"error opening token.txt file";
    input.close();
    }

    return 0;
}

