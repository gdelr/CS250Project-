#include "Diagnoses.h"
#include <cstdlib>


int randomNumberGenerator(int min,int max){
    if(rand()%10==0){
        srand(rand()*rand());
    }
    else{
        srand(rand()*rand()*rand());
    }
    int range = max-min ;
    int randomNumber=rand() % range + min ;
    return randomNumber;
}

char randomCharGenerator(int min,int max){
    int randomInt=randomNumberGenerator(min,max);
    return (char)randomInt;
}

std::string randomStringGenerator(int min,int max,int stringLength,bool withSpace){
    std::string output;
    for(int i=0;i<stringLength;i++)
    {
        if(withSpace&&randomNumberGenerator(0,99)==1)
        {
            output+=32;
            continue;
        }
        if(i==4||i==8||i==12||i==16||i==20)
        {
            output+=randomCharGenerator(65,67);
        }
        output+=randomCharGenerator(min,max);
    }
    return output;
}


Diagnoses::Diagnoses(){
    id="";
    disease_name="";
}
Diagnoses::Diagnoses(string i,string n){
    id=i;
    disease_name=n;
}
//getters
string Diagnoses::getId(){return id;}
string Diagnoses::getDisease_name(){return disease_name;}
//setters
void Diagnoses::setId(string i){id=i;}
void Diagnoses::setDisease_name(string n){disease_name=n;}

void Diagnoses::print(std::ostream& out)const{
    out<<"\nID           : "<<id
       <<"\nDisease name : "<<disease_name;
}
void Diagnoses::read(std::istream& in){
    string temp;
    id=randomStringGenerator(48,57,4,0);
    getline(in,temp);
    getline(in,disease_name);

}
