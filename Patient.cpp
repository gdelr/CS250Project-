#include "Patient.h"

//constructor
Patient::Patient(){
    id="";
    doctor_id="";
    record_id="";
    name="";
    phone="";
    gender="";
    email="";
    blood_type="";
}
Patient::Patient(string p,string d,string r,string n,string o,string g,string e,string b){
    id=p;
    doctor_id=d;
    record_id=r;
    name=n;
    phone=o;
    gender=g;
    email=e;
    blood_type=b;
}


//getters
string Patient::getId(){return id;}
string Patient::getDoctor_id(){return doctor_id;}
string Patient::getRecord_id(){return record_id;}
string Patient::getName(){return name;}
string Patient::getPhone(){return phone;}
string Patient::getGender(){return gender;}
string Patient::getEmail(){return email;}
string Patient::getBlood_type(){return blood_type;}
Diagnoses Patient::getDiagnoses(){return diag;}
//setters
void Patient::setId(string a){id=a;}
void Patient::setDoctor_id(string a){doctor_id=a;}
void Patient::setRecord_id(string a){record_id=a;}
void Patient::setName(string a){name=a;}
void Patient::setPhone(string a){phone=a;}
void Patient::setGender(string a){gender=a;}
void Patient::setEmail(string a){email=a;}
void Patient::setBlood_type(string a){blood_type=a;}
void Patient::setDiagnoses(Diagnoses a){diag=a;}


void Patient::print(std::ostream& out)const{
    out<<"\nPatient ID           : "<<id
       <<"\nDoctor's ID          : "<<doctor_id
       <<"\nRecord ID            : "<<record_id
       <<"\nPatient's Name       : "<<name
       <<"\nPhone Number         : "<<phone
       <<"\nPatient gender       : "<<gender
       <<"\nPatient's E-mail     : "<<email
       <<"\nPatient's Blood Type : "<<blood_type;
}

void Patient::read(std::istream& in){
    in>>id>>doctor_id>>record_id>>name>>phone>>gender>>email>>blood_type;
}

