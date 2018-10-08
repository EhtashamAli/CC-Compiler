#include<iostream>
#include<fstream>
using namespace std;
//did nothing

//fiza was here
int main (){

    string word;

    ifstream input("code.txt");
    fstream output("token.txt");
    if(input.is_open())
    {
        while(input >> word){
        //cout<<word<<"\n";

            if(output.is_open())
            {
                output << word<<"\n";
            }
            else{
                cout<<"ERROR IN OPENING FILE";
                 output.close();
            }
        }
    }
    else
    cout<<"error opening file";
    input.close();


    return 0;
}
