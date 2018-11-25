#include "Syntax.h"

void Syntax::parseGrammar()
{
    for(int i=0; i < tokenDataSize; i++)
    {
        if(tokenArray[i].value == "loop")
        {
            parseLoop(i);
        }
        /*
        if(tokenArray[i].name == "id")
        {
            parseIdentifier(i);
        }
        */
    }
}

void Syntax::parseForLoopCondition(int &index)
{
    int i=index;
    while(tokenArray[i] != ')' || tokenArray[i] !='{')
    {

    }
}

void Syntax::parseLoop(int &index)
{
    cout<<"loop started on line:"<< tokenArray[index].line <<endl;
    int i = index;

    cout<<endl<<"loop condition: ";
    if(tokenArray[i].value != "{")
    {
        parseForLoopCondition(index);
    }


    cout<<endl<<"loop body: ";
    while(tokenArray[i].value != "}")
    {
        cout<<tokenArray[i].value <<" ";
        ++i;
    }
    cout<<endl<<"loop ended on "<<tokenArray[i].line<<endl;
    index = i + 1;
}


void Syntax::tokenParseAndAdd(string token){
    TokenData newToken;
    int i=1;
    if(token[0]=='<')
    {
        while(token[i] != ',')
        {
            newToken.name += token[i];
            i++;
        }
        i+=2;
        while(token[i] != '>')
        {
            newToken.value += token[i];
            i++;
        }
    }
    if(newToken.name == "symbol" && newToken.value=="newline")
        currentLineNumber++;

    newToken.line = currentLineNumber;
    //cout<<"new: "<<newToken.name<<", "<<newToken.value<<", "<<newToken.line<<endl;
    tokenArray[tokenDataSize] = newToken;
    ++tokenDataSize;
}

int Syntax::getTokenCount()
{
    return tokenDataSize;
}

TokenData Syntax::getToken(int index)
{
    if(index < 0 || index >= tokenDataSize)
        cout<<"Error: Index(" << index << ") out of bound!"<<endl;
    return tokenArray[index];
}


