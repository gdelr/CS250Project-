#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED
#include <iostream>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
public:
    //constructors
    Date();
    Date(int,int,int);
    //getters
    int getDay();
    int getMonth();
    int getYear();
    //setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    void print(std::ostream&)const;
    void read(std::istream& in);
};

inline
ostream& operator<< (ostream& out, const Date& d){
    d.print(out);
    return out;
}

inline
istream& operator>> (istream& in,Date& d){
    d.read(in);
    return in;
}


struct Time{
    int hours;
    int minutes;
    char AM_PM;
public:
    //constructors
    Time();
    Time(int,int,char);
    //getters
    int getHours();
    int getMinutes();
    char getAM_PM();
    //setters
    void setHours(int);
    void setMinutes(int);
    void setAM_PM(char);

    void print (ostream&)const;
    void read (istream&);
};

bool operator< (Time x, Time y);
bool operator== (Time x, Time y);
inline
bool operator!= (Time& x,Time&y){
    return!(x==y);
}

inline
bool operator> (Time&x,Time&y){
    y<x;
}
inline
bool operator<=(Time&x,Time&y){
    return !(x>y);
}

inline
bool operator>=(Time&x,Time&y){
    return !(x<y);
}
inline
ostream& operator<< (ostream& out, const Time& t){
    t.print(out);
    return out;
}

inline
istream& operator>> (istream& in,Time& t){
    t.read(in);
    return in;
}

class Date_Time{
    int id;
    Date date;
    Time time;
public:
    //constructors
    Date_Time();
    Date_Time(int,Date,Time);
    //getters
    int getId();
    Date getDate();
    Time getTime();
    //setters
    void setId(int);
    void setDate(Date);
    void setTime(Time);

    void print(std::ostream& out)const;
    void read(std::istream& in);
};

inline
ostream& operator<< (ostream& out, const Date_Time& dt){
    dt.print(out);
    return out;
}

inline
istream& operator>> (istream& in,Date_Time& dt){
    dt.read(in);
    return in;
}
bool operator< (Date_Time x, Date_Time y);
bool operator== (Date_Time x, Date_Time y);
inline
bool operator!= (Date_Time& x,Date_Time&y){
    return!(x==y);
}

inline
bool operator> (Date_Time&x,Date_Time&y){
    y<x;
}
inline
bool operator<=(Date_Time&x,Date_Time&y){
    return !(x>y);
}

inline
bool operator>=(Date_Time&x,Date_Time&y){
    return !(x<y);
}

#endif // DATE_TIME_H_INCLUDED
