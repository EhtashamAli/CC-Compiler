#include "Syntax.h"
void Syntax::isLoop(string token){
    string name;
    int i=0;
    if(token[0]=='<'){
            i=1;
    while(token[i]!= ',')
        {
        name+=token[i];
        i++;
        }
    }
    cout<<name<<endl;
}


