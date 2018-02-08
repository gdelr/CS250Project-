#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

#include <iostream>
using namespace std;

class Appointment{
    int thisID;
    string doctor_id;
    string patient_id;
    string slot_id;
    string reason;
    string diagnosis_id;
    string prescribed_medication;
public:
    //constructors
    Appointment();
    Appointment(string,string,string,string,string,string);
    //getters
    int getId();
    string getDoctor_id();
    string getPatiend_id();
    string getSlot_id();
    string getReason();
    string getDiagnosis_id();
    string getPerscribed_medication();
    //setters
    void setDoctor_id(string);
    void setPatient_id(string);
    void setSlot_id(string);
    void setReason(string);
    void setDiagnosis_id(string);
    void setPerscribed_medication(string);

    void incrementId();
    void print(std::ostream& out)const;
    void read(std::istream& in);
};

inline
std::ostream& operator<< (std::ostream& out, const Appointment& a){
    a.print(out);
    return out;
}
inline
std::istream& operator>> (std::istream& in,Appointment& a){
    a.read(in);
    return in;
}



#endif // APPOINTMENT_H_INCLUDED
