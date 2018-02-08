#include "Appointment.h"

    //constructors
Appointment::Appointment(){
    doctor_id="";
    patient_id="";
    slot_id="";
    reason="";
    diagnosis_id="";
    prescribed_medication="";
}
Appointment::Appointment(string d,string p,string s,string r,string i,string m){
    doctor_id=d;
    patient_id=p;
    slot_id=s;
    reason=r;
    diagnosis_id=i;
    prescribed_medication=m;

}
//getters
int Appointment::getId(){return thisID;}
string Appointment::getDoctor_id(){return doctor_id;}
string Appointment::getPatiend_id(){return patient_id;}
string Appointment::getSlot_id(){return slot_id;}
string Appointment::getReason(){return reason;}
string Appointment::getDiagnosis_id(){return diagnosis_id;}
string Appointment::getPerscribed_medication(){return prescribed_medication;}
//setters
void Appointment::setDoctor_id(string a){doctor_id=a;}
void Appointment::setPatient_id(string a){patient_id=a;}
void Appointment::setSlot_id(string a){slot_id=a;}
void Appointment::setReason(string a){reason=a;}
void Appointment::setDiagnosis_id(string a){diagnosis_id=a;}
void Appointment::setPerscribed_medication(string a){prescribed_medication=a;}

void Appointment::incrementId(){
    static int id;
    id++;
    thisID=id;
}

void Appointment::print(std::ostream& out)const{
    out<<"\n\tID                   : "<<thisID
       <<"\n\tDoctor's ID          : "<<doctor_id
       <<"\n\tPatient's ID         : "<<patient_id
       <<"\n\tSlot's ID            : "<<slot_id
       <<"\n\tReason               : "<<reason
       <<"\n\tDiagnosis ID         : "<<diagnosis_id
       <<"\n\tPrescribed medication: "<<prescribed_medication;
}
void Appointment::read(std::istream& in){
    in>>doctor_id>>patient_id>>slot_id>>reason>>diagnosis_id>>prescribed_medication;
}
