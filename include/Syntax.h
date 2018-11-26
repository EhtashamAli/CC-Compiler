#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class Syntax
{
    private:

    public:
        string tokenName[1000];
        string tokenVal[1000];

    bool isHeader();
    void printData();
    void tokenParse(string,int);

};
#endif
