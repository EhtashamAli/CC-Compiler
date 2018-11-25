#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class Token{
private:
    ofstream output;
public:
    Token();
    ~Token();

    bool isSymbol(int);
    string isString(string);
    bool isIdentifier(char);
    bool isOperator(char);
    bool isDigit(char);
    bool isKeyword(string);
    bool checkWord(string);

    void openTokenFile (); // opens the token file
    void writeSymbol(string);
    void writeidentifier(string);
    void writeKeyword(string);
    void writeOperator(string);
    void writeDigit(string);
    void writeFloat(string);
    void writeString(string);
    void writeNewLine();
    void writeToken(string,string);//writes to file
};


#endif // TOKEN_H
