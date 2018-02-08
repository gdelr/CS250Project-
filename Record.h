#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include <iostream>
using namespace std;
class Record{
    string id;
    string patient_id;
    string notes;
public:
    //constructors
    Record();
    Record(string,string,string);
    //getters
    string getId();
    string getPatient_id();
    string getNotes();
    //setters
    void setId(string);
    void setPatient_id(string);
    void setNotes(string);

    void print(ostream&)const;
    void read(istream&);
};
inline
ostream& operator<< (ostream& out, const Record& r){
    r.print(out);
    return out;
}
inline
istream& operator>> (istream& in,Record& r){
    r.read(in);
    return in;
}


#endif // RECORD_H_INCLUDED
