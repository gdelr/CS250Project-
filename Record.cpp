#include "Record.h"

Record::Record(){
    id="";
    patient_id="";
    notes="";
}
Record::Record(string i,string p,string n){
    id=i;
    patient_id=i;
    notes=n;
}
//getters
string Record::getId(){return id;}
string Record::getPatient_id(){return patient_id;}
string Record::getNotes(){return notes;}
//setters
void Record::setId(string i){id=i;}
void Record::setPatient_id(string p){patient_id=p;}
void Record::setNotes(string n){notes=n;}

void Record::print(ostream& out)const{
    out<<"\nID          : "<<id
       <<"\nPatient's ID: "<<patient_id
       <<"\nNotes       : "<<notes;
}
void Record::read(istream& in){
    cout<<"\nEnter notes first, than id, than patient id.\n";
    getline (cin,notes);
    in>>id>>patient_id;


}
