#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


class Syntax
{
    private:
        int totalTokens;

    public:

    Syntax(){ totalTokens = 0;}

    string tokenName[1000];
    string tokenVal[1000];

    bool isHeader();
    bool isMain();
    bool isDeclaration();
    bool isNamespace();
    bool isInput();
    void printData();
    bool isLoop();
    void tokenParse(string,int);


};
#endif
