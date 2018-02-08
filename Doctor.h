#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED


#include <iostream>
#include <vector>

#include "Appointment.h"
#include "Slot.h"
using namespace std;

class Doctor{
    string id;
    string username;
    string password;
    string name;
    string phone;
    string skill;
public:
    //constructor
    Doctor();
    Doctor(string,string,string,string,string,string);
    //getters
    string getId();
    string getUsername();
    string getPassword();
    string getName();
    string getPhone();
    string getSkill();
    //setters
    void setId(string);
    void setUsername(string);
    void setPassword(string);
    void setName(string);
    void setPhone(string);
    void setSkill(string);

    void print(std::ostream& out)const;
    void read(std::istream& in);
};

inline
std::ostream& operator<< (std::ostream& out, const Doctor& a){
    a.print(out);
    return out;
}
inline
std::istream& operator>> (std::istream& in,Doctor& a){
    a.read(in);
    return in;
}




#endif // DOCTOR_H_INCLUDED
