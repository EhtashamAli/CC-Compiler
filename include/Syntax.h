#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;


class Syntax
{
    private:
        int totalTokens;

    public:

    Syntax(){ totalTokens = 0;}

    string tokenName[1000];
    string tokenVal[1000];
    bool isOutput();
    bool isHeader();
    bool isMain();
    bool isDeclaration();
    bool isNamespace();
    bool isInput();
    bool isLoop();
    bool isIF_ELSE();
    void tokenParse(string,int);



};
#endif
