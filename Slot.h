#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include <iostream>


using namespace std;
class Slot{
    string id;
    int date_id;
    string doctor_id;
    bool avaliable;
public:
    //constructors
    Slot();
    Slot(string,int,string,bool);
    //getters
    string getId();
    int getDate_id();
    string getDoctor_id();
    bool getAvaliable();
    //setters
    void setId(string);
    void setDate_id(int);
    void setDoctor_id(string);
    void setAbalible(bool);

    void print(std::ostream&)const;
    void read(std::istream& in);
};

inline
ostream& operator<< (ostream& out, const Slot& s){
    s.print(out);
    return out;
}
inline
istream& operator>> (istream& in,Slot& s){
    s.read(in);
    return in;
}

#endif // SLOT_H_INCLUDED
