#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class Syntax
{
    private:
        string tokenName[1000];
        string tokenVal[1000];

    public:
    void openTokenFile();
    void isLoop(string);
    void tokenParse(string,int);
    string getTokenName();
    string getTokenVal();

};
#endif
