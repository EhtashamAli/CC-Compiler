#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct TokenData
{
    int line;
    string name;
    string value;
};

class Syntax
{
    private:
        TokenData tokenArray[10000];
        int tokenDataSize;
        int currentLineNumber;

    public:
        Syntax(){tokenDataSize = 0; currentLineNumber=1;}
        void tokenParseAndAdd(string);
        int getTokenCount();
        TokenData getToken(int index);

        void parseGrammar();

        void parseLoop(int &index);
        void parseForLoopCondition(int &index);





};
#endif // SYNTAX_H
