#include "Syntax.h"
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
/*string Syntax::*getTokenName(){
    return tokenName;
}
string Syntax::*getTokenVal(){
    return tokenVal;
}
bool Syntax::isLoop(){
    string name = getTokenName();
    string val = getTokenVal();
    int i=0;
    int index;
    while(name[i] == 'kw' && val[i] == 'loop')) {
        index = i;
        i++;
    }
    cout << index<<endl;

}
*/


