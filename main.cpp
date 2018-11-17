#include<iostream>
#include<string>
#include<fstream>
#include "Token.h"

using namespace std;

//...........................................//
int main () {
    int count=0;
    int flag =0;
    int decimalCount=0;
    int negCount=0;
    int lineCount=0;
    string tokenId;
    string word;
    string symbol;
    string oper;
    string str;
    string digit;
    string strings;
    string tokenChar;
    string line;

    Token t;

    ifstream input("code.txt");
    if(input.is_open())
    {
    int i=0;
    while(std::getline(input , str))
    {
        strings = t.isString(str);
        if(!strings.empty())
            {
                strings=t.isString(str);
                t.writeString(strings);
                //cout<<"string: ''"<<strings<<"''"<<endl;
                strings.clear();
            }
        i++;
    }
    ifstream input("code.txt"); //opening file again for further tokenization
    while (getline(input, line))
     {
         lineCount++;
         cout<<lineCount<<endl;
    while(input >> word)  //input word by word
        {
            int i=0;
            while(i != word.length())
            {
                char x=word[i];
                    if(t.isDigit((int)x))
                    {
                            if((int)word[i-1]==45){ //checks if the number is negative
                                digit+=word[i-1];
                                digit+=word[i];
                                i++;
                            }
                            if((int)word[i+1]==46) //checks if the number is a float
                             {
                                digit+=word[i];
                                digit+=word[i+1];
                                decimalCount=1;
                                i++;
                            }
                            else digit+=word[i];

                            if((t.isDigit((int)word[i+1]))==0) //writes a float
                                {
                                    if(decimalCount==1)
                                    {
                                    //cout<<"float "<<digit<<endl;
                                    t.writeFloat(digit);
                                    }
                                    else
                                    {
                                        //cout<<"decimal: "<<digit<<endl;
                                        t.writeDigit(digit); //writes  a decimal
                                    }
                                digit.clear();
                                }
                    }

                    else if(t.isSymbol((int)x))  //special character
                    {
                        tokenChar+=word[i];
                        if((t.isSymbol((int)word[i+1]))==0)
                            {
                           //cout<<"symbol: "<<tokenChar<<endl;
                            t.writeSymbol(tokenChar);
                            tokenChar.clear();
                            }
                    }
                    else if(t.isOperator((int) x))//operator token
                    {
                        oper = word[i];

                        if((char(word[i+1])==61)||(((char)word[i+1])==43)||(((char)word[i+1])==45)) //This condition checks if we have '>,<' after =
                        {
                            oper += word[i+1];
                             i++; //so that it doesnt count = separate .
                        }
                        if((char(word[i+1])==60)||(char(word[i+1])==62)||(char(word[i+1])==62)) //This condition checks if we have = after <,>,=
                            {
                                cout<<"error  in line : "<<lineCount<<endl;
                                break;
                            }
                            cout<<"operator"<<oper<<endl;
                            t.writeOperator(oper);
                            tokenId.clear(); // for a==b; case
                            oper.clear();
                    }
                    else {
                        if((int)word[i]==34){
                                flag++;
                            }
                        else{
                           if((flag==0)||(flag==2))
                            {
                                   if(((int)word[i]==64)|| (((int)word[i]>=65) && ((int)word[i]<=90)) || (((int)word[i]>=97) && ((int)word[i] <=122))|| ((int)word[i] != 32) )//identifier token
                                    {
                                        if (((int)word[i]>=48)&&(int)word[i]<=57)//if ientifier ha a number
                                            tokenId+= word[i]; //adds character into identifier string
                                        else
                                        tokenId+= word[i]; //adds character into identifier string

                                    }
                                    if((1 == (t.isOperator((int)word[i+1]) )) || ( 1 == (t.isSymbol((int)word[i+1]) ))||( (i+1) == word.length()))//keyword and identifier check
                                    {
                                            if(t.isKeyword(tokenId))
                                            {
                                                //cout<<"keyword: "<<tokenId<<endl;
                                                t.writeKeyword(tokenId); //writes keyword into file
                                                tokenId.clear();
                                            }
                                            else
                                            {
                                                t.writeidentifier(tokenId); //writes identifier into file
                                                //cout<<"identifier: "<<tokenId<<endl;
                                                tokenId.clear();
                                                   if(flag==2)
                                                    flag=0;
                                            }
                                    }

                                }
                            }
                        }


                i++;
                }
                 decimalCount=0;
                tokenId.clear();
          }
     }




}
    else{
    cout<<"error opening file";
    input.close();
    }
    return 0;
}
