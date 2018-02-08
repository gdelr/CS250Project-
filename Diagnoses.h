#ifndef DIAGNOSES_H_INCLUDED
#define DIAGNOSES_H_INCLUDED
#include <iostream>
using namespace std;

class Diagnoses{
    string id;
    string disease_name;
public:
    //constructors
    Diagnoses();
    Diagnoses(string,string);
    //getters
    string getId();
    string getDisease_name();
    //setters
    void setId(string);
    void setDisease_name(string);

    void print(std::ostream& out)const;
    void read(std::istream& in);
};

inline
ostream& operator<< (ostream& out, const Diagnoses& d){
    d.print(out);
    return out;
}
inline
istream& operator>> (istream& in,Diagnoses& d){
    d.read(in);
    return in;
}



#endif // DIAGNOSES_H_INCLUDED
