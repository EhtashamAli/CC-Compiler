#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class Token{
public:
    bool isSymbol(int x);
    string isString(string str);
    bool isIdentifier(char ch);
    bool isOperator(char ch);
    bool isDigit(char ch);
    bool isKeyword(string word);

    void writeSymbol(string tokenChar);
    void writeidentifier(string tokenId);
    void writeKeyword(string kw);
    void writeOperator(string op);
    void writeDigit(string number);
    void writeFloat(string number);
    void writeString(string word);
};


#endif // TOKEN_H
