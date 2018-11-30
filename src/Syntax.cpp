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
                if(tokenName[i+2]=="id"||"digit"){
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

bool Syntax::isOutput(){
    bool Error = false;
    int i = 0;
    int Count = 0;
    while(i < totalTokens){
        if(tokenVal[i] == "output"){
            if(tokenVal[i+1] == ":"){
                if ((std::regex_match (tokenVal[i+2], std::regex("(.*)") )) || (tokenName[i+2] == "id")){
                    if(tokenVal[i+3] == ";"){
                        i++;
                        continue;
                    } else {
//yhan masla hai koi logic main shayad
                        Count = i+3;
                       while(tokenVal[Count] != ";"){
                            cout<<tokenVal[Count];
                        if(tokenVal[Count] == ":"){
                            if ((std::regex_match (tokenVal[Count+1], std::regex("(.*)") )) || (tokenName[Count+1] == "id")){
                                    if(tokenVal[Count+2] == ";") {break;}
                                    if(tokenVal[Count+2] == ":") {Count++;}
                                    else{
                                        Error = true;
                                        break;
                                    }
                            } else {
                                //error break
                                Error = true;
                                break;
                            }
                        }else{
                                                                                                        cout<<"this";
                                Error = true;
                                break;
                        }
                        }
                        if(Error) {cout<<"1output statement Error on token"<<Count<<"\t";Error = true;i++;continue;}
                        else{i++;continue;}
                    }
                } else {
                    cout<<"output statement Error on token"<<i<<"\t";
                    Error = true;
                    i++;
                    continue;
                }
            }else{
                    cout<<"output statement Error on token"<<i<<"\t";
                    Error = true;
                    i++;
                    continue;
            }
        } else {
            i++;
            continue;
        }
    }
    if(Error)
        return 0;
    else
        return 1;
}

bool Syntax::isInput(){
   // std::vector<int> lines;
    bool Error = false;
    for(int i=0; i<totalTokens ; i++){
        if(tokenVal[i] == "input"){
            if(tokenVal[i+1] == ":"){
                 if(tokenName[i+2] == "id"){
                    if(tokenVal[i+3] == ";"){
                        continue;
                    } else {
                    cout<<"Error on token"<<i<<"\t";
                    Error = true;
                    continue;
                    }
                 } else {
                    cout<<"Error on token"<<i<<"\t";
                    Error = true;
                    continue;
                 }
            } else {
                    cout<<"Error on token"<<i<<"\t";
                    Error = true;
                    continue;
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
bool Syntax::isLoop(){
    int flag =0;
    string name;
    int i=0,idCount=0,count=0;
    while(tokenVal[i]!="loop"){i++;}


//for declaration
    int counter=i+1;//to go to the digit again
    int braceCount=0;

    while(braceCount!=2)
        {
        if(tokenVal[i] =="loop")
        if(tokenVal[i+1] =="(" )
        if(tokenVal[i+2] =="digit"||"float")
        else if(tokenName[i+2] =="id")
            {

                    if(tokenVal[i+3]=="=")
                    if(tokenName[i+4]=="int"||"id")
                    if(tokenVal[i+5]==";")
                    if(tokenName[i+6]=="id")
                    if(tokenName[i+7]=="op" )
                    if(tokenName[i+8]=="id"||"int")
                    if(tokenVal[i+9]==";")
                    if(tokenName[i+10]=="id"||tokenName[i+1]=="int")
                    if(tokenVal[i+11]=="++"||"--")
                    if(tokenVal[i+12]==")")
                    if(tokenVal[i+13]=="newline")
                    if(tokenVal[i+14]=="{")

                        braceCount++;
                        i=i+15;
                        while(tokenVal[i]!="}" ){i++;}
                    if(tokenVal[i]=="}")braceCount++;
            }
        }
        if(tokenName[i+3]=="id")
        if(tokenVal[i+4]=="=")
        if(tokenName[i+5]=="int"||"id")
        if(tokenVal[i+6]==";")
        if(tokenName[i+7]=="id")
        if(tokenName[i+8]=="op" )
        if(tokenName[i+9]=="id"||"int")
        if(tokenVal[i+10]==";")
        if(tokenName[i+11]=="id"||tokenName[i+1]=="int")
        if(tokenVal[i+12]=="++"||"--")
        if(tokenVal[i+13]==")")
        if(tokenVal[i+14]=="newline")
        if(tokenVal[i+15]=="{")

                braceCount++;
                i=i+16;
                while(tokenVal[i]!="}" ){i++;}
            if(tokenVal[i]=="}")braceCount++;
}
        if(braceCount==2)
            return 1;
return 0;
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
