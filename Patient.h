#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <iostream>

#include "Diagnoses.h"
using namespace std;
class Patient{
    string id;
    string doctor_id;
    string record_id;
    string name;
    string phone;
    string gender;
    string email;
    string blood_type;
    Diagnoses diag;

public:
    //constructor
    Patient();
    Patient(string,string,string,string,string,string,string,string);
    //getters
    string getId();
    string getDoctor_id();
    string getRecord_id();
    string getName();
    string getPhone();
    string getGender();
    string getEmail();
    string getBlood_type();
    Diagnoses getDiagnoses();
    //setters
    void setId(string);
    void setDoctor_id(string);
    void setRecord_id(string);
    void setName(string);
    void setPhone(string);
    void setGender(string);
    void setEmail(string);
    void setBlood_type(string);
    void setDiagnoses(Diagnoses);


    void print(std::ostream&)const;
    void read(std::istream& in);
};

inline
std::ostream& operator<< (std::ostream& out, const Patient& p){
    p.print(out);
    return out;
}
inline
std::istream& operator>> (std::istream& in,Patient& p){
    p.read(in);
    return in;
}

#endif // PATIENT_H_INCLUDED
