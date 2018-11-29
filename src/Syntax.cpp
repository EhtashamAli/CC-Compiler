#include "Syntax.h"

void Syntax::printData(){
    for(int i=0; i <totalTokens; i++){
        cout<<"TokenName:"<<tokenName[i]<<endl;
        cout<<"TokenVal:"<<tokenVal[i]<<endl;
    }
}

bool Syntax::isHeader(){
int i=0;
    while(tokenVal[i] != "newLine" ){
        if(tokenVal[i] =="#")
            if(tokenVal[i+1] == "header")
                if(tokenVal[i+2] =="{") //add more headers if req
                     if(tokenVal[i+3] == ("iostream")) //add more headers if req
                         if(tokenVal[i+4] == "}") //add more headers if req*/
                            if(tokenVal[i+5]=="newline")
                         {
                             return 1;
                         }

       i++;
}

            cout<<"error in line:"<<i<<endl;
            return 0;

}
bool Syntax::isNamespace(){
int i=0;

    while(tokenVal[i+1] != "using" ){i++;}

    while(tokenVal[i]!=";"){
        if(tokenVal[i] =="using")
            if(tokenVal[i+1] == "namespace")
                if(tokenVal[i+2] =="std")
                    if(tokenVal[i+3] ==";")//add more headers if req
                         {
                             return 1;
                         }

       i++;
}

            cout<<"error in line:"<<i<<endl;
            return 0;

}

bool Syntax::isMain(){
    int i=0;
    while((tokenVal[i] != "digit")  ) { i++;}
    while(tokenVal[i]!="{"){
        if(tokenVal[i] =="digit" )
            if(tokenVal[i+1] == "container")
                if(tokenVal[i+2] =="(")
                    if(tokenVal[i+3] ==")")
                        if(tokenVal[i+4]=="{")
                            {
                                if(tokenVal[i+5]=="}"){
                                     if(tokenVal[i+6]!="\0"){
                                        cout<<"out of main scope";
                                     }
                                     else{
                                        //compiled
                                     }
                                }
                                else {
                                    //checking of remaining
                                }

                            if(tokenVal[totalTokens-1] == "}")//add more headers if req
                             {
                                 return 1;
                             }
    }
    i++;
    return 0;
        }
}
bool Syntax::isInput(){
   // std::vector<int> lines;
    bool Error = false;
    for(int i=0; i<totalTokens ; i++){
        if(tokenVal[i] == "input"){
            if(tokenVal[i+1] == ":"){
                 if(tokenName[i+2] == "id")
                    if(tokenVal[i+3] == ";"){
                        continue;
                    } else {
                    cout<<"Error on line"<<i<<"\t";
                    Error = true;
                    }
            } else {
                    cout<<"Error on line"<<i<<"\t";
                    Error = true;
            }
        } else {
           continue;
        }
    }
    if(Error){
        return 0;
    } else {
        return 1;
    }
}
bool Syntax::isDeclaration(){
    int flag =0;
    int i=0,idCount=0;
    while((tokenVal[i]!= "digit")&&(tokenVal[i+1]!="container")) {i++;}
    i++; //to skip container
    while(tokenVal[i]!="digit"){i++;}
    i++;//for declaration
    int counter=i;//to go to the digit again

    while(tokenVal[counter]!="newline"){
        if(tokenName[counter]=="id")
            {
            idCount++;
            }

            counter++;

    }
    while(idCount!=0)
        {
        if(tokenName[i] == "id")
            {
            if(tokenVal[i+1]==","){idCount--;} //case 1: ,
            else if(tokenVal[i+1]==";") {flag++;idCount--;} //case2: ;
            else if(tokenVal[i+1]=="=")
                { //case3: =
                if(tokenName[i+2]=="id"||tokenName[i+2]=="digit"){
                if(tokenVal[i+3]==","){idCount--;}
                else if(tokenVal[i+3]==";")
                    flag++;}
                else return 0;
                }
            }
            i++;
            if(tokenVal[i]==" ")i++;
        }
        if(flag>0)return 1;
return 0;
}
/*
bool Syntax::isLoop(){
    int flag =0;
    int i=0,idCount=0;
    while(tokenVal[i]!="loop"){i++;}
    i++;//for declaration
    int counter=i;//to go to the digit again

    while(tokenVal[i]!="endloop")
        {
        if(tokenVal[i] == "(" )
        if(tokenVal[i+1] == "digit" ||tokenVal[i+]"  )
        else if(tokenName[i]=="id")
        {
            if(tokenVal[i]=="=")
            if(tokenName[i+1]=="id")
            if(tokenVal[i+1]=="=")
                if(tokenName[i+1]=="id")
                if(tokenName[i+1]=="id")
            }
            i++;
            if(tokenVal[i]==" ")i++;
        }
        if(flag>0)return 1;
return 0;
}*/
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
        i+=2;
        while(token[i]!='>')
        {
            val+=token[i];
            i++;
        }
    }
    tokenName[j] = name;
    tokenVal[j] = val;
    totalTokens = j;
    tokenName[j+1]="\0";
    tokenVal[j+1]="\0";
}
