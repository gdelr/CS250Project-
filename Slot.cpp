#include "Slot.h"


Slot::Slot(){
    id="";
    date_id=0;
    doctor_id="";
    avaliable=0;
}

Slot::Slot(string a,int b,string c,bool d){
    id=a;
    date_id=b;
    doctor_id=c;
    avaliable=d;
}
//getters
string Slot::getId(){return id;}
int Slot::getDate_id(){return date_id;}
string Slot::getDoctor_id(){return doctor_id;}
bool Slot::getAvaliable(){return avaliable;}
//setters
void Slot::setId(string a){id=a;}
void Slot::setDate_id(int a){date_id=a;}
void Slot::setDoctor_id(string a){doctor_id=a;}
void Slot::setAbalible(bool a){avaliable=a;}

void Slot::print(std::ostream& out)const{
    out<<"\nID        : "<<id
       <<"\nDate ID   : "<<date_id
       <<"\nDoctor ID : "<<doctor_id
       <<"\nAvailable : ";
    if(avaliable){
        out<<"Available";
    }
    else{
        out<<"Unavailable";
    }
}
void Slot::read(std::istream& in){
    string temp;
    in>>id>>date_id>>doctor_id>>temp;

    if(temp=="available"){
        avaliable=1;
    }
    else{
        avaliable=0;
    }
}
