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
    Syntax S;
    //Syntax s;

   ifstream input("code.txt");
    if(input.is_open())
    {
        int i=0;
  //opening file again for further tokenization
    while (getline(input, line))
     {
         //cout<<i+1<<"\t";
         //cout<<line<<endl;
        // cout<<"____________________________"<<endl;
        int check=t.checkWord(line);
        if(check==0){cout<<"error in line: "<<i+1<<endl;break;}
       // cout<<"____________________________"<<endl;
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
        while (getline(SYNTAX_FILE, line))
         {
             S.tokenParse(line , i);
             i++;
         }
         SYNTAX_FILE.close();
    }
    else{
    cout<<"error opening token.txt file";
    input.close();
    }

    if(S.isHeader() == 1){
        cout<<"header verified"<<endl;
    }

    if(S.isNamespace() == 1){
        cout<<"namespace verified"<<endl;
    }

    if(S.isMain() == 1){
        cout<<"main verified"<<endl;
    }
    if(S.isDeclaration()==1){
        cout<<"declaration verified"<<endl;
    }
    if(S.isInput()==1){
        cout<<"input verified"<<endl;
    }

    //if(S.is)
    return 0;
}
