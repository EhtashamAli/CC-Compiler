#include "Syntax.h"

void Syntax::printData(){
    for(int i=0; i <50; i++){
        cout<<"TokenName:"<<tokenName[i]<<endl;
        cout<<"TokenVal:"<<tokenVal[i]<<endl;
    }
}


bool Syntax::isHeader(){
    int i=0;
     while(tokenVal[i] != "newline"){
        if(tokenVal[i] == "#")
            if(tokenVal[i+1] == "header")
                if(tokenVal[i+2] == "{") //add more headers if req
                     if(tokenVal[i+3] == "iostream") //add more headers if req
                         if(tokenVal[i+4] == "}"){ //add more headers if req
                                cout<<"true";
                                return 1;
                         }
        else{
            cout<<"Error at line:"<<i<<endl;
            return 0;
        }
        i += 7;
     }
}
void Syntax::tokenParse(string token , int j){
    string name;
    string val;
    int i=1;
    if(token[0]=='<')
    {
        while(token[i]!= ',')
            {
            name+=token[i];
            i++;
            }
        i++;
        while(token[i]!='>')
            {
            val+=token[i];
            i++;
            }
    }
    tokenName[j] = name;
    tokenVal[j] = val;
}

