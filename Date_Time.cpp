#include "Date_Time.h"

///Date
//constructors
    Date::Date(){
        day=0;
        month=0;
        year=0;
    }
    Date::Date(int d,int m,int y){
        day=d;
        month=m;
        year=y;
    }
    //getters
    int Date::getDay(){return day;}
    int Date::getMonth(){return month;}
    int Date::getYear(){return year;}
    //setters
    void Date::setDay(int d){day=d;}
    void Date::setMonth(int m){month=m;}
    void Date::setYear(int y){year=y;}

    void Date::print(std::ostream& out)const{
        out<<day<<"/"<<month<<"/"<<year;
    }
    void Date::read(std::istream& in){
        in>>day>>month>>year;
        year%=100;
    }


///Time
    //constructors
    Time::Time(){
        hours=0;
        minutes=0;
        AM_PM=0;
    }
    Time::Time(int h,int m,char a){
        hours=h;
        minutes=m;
        AM_PM=a;
    }
    //getters
    int Time::getHours(){return hours;}
    int Time::getMinutes(){return minutes;}
    char Time::getAM_PM(){return AM_PM;}
    //setters
    void Time::setHours(int h){hours=h;}
    void Time::setMinutes(int m){minutes=m;}
    void Time::setAM_PM(char a){AM_PM=a;}

    void Time::print (ostream& out)const{
        out<<hours<<":"<<minutes;
        string temp;
        if(AM_PM=='a'){temp="AM";}
        else{temp="PM";}
        out<<" "<<temp;
    }
    void Time::read (istream& in){
        in>>hours>>minutes>>AM_PM;
    }

    bool operator< (Time x, Time y){
        if(x.getAM_PM()=='a'&&y.getAM_PM()=='p'){
            return 1;
        }
        else if(x.getAM_PM()=='p'&&y.getAM_PM()=='p'){
            if(x.getHours()<y.getHours()){
                return 1;
            }
            else if(x.getMinutes()<y.getMinutes()){
                return 1;
            }
        }
        else if(x.getAM_PM()=='a'&&y.getAM_PM()=='a'){
            if(x.getHours()<y.getHours()){
                return 1;
            }
            else if(x.getMinutes()<y.getMinutes()){
                return 1;
            }
        }
        else{
            return 0;
        }

    }
    bool operator== (Time x, Time y){
        if((x.getAM_PM()==y.getAM_PM())
           &&(x.getHours()==y.getHours())
           &&(x.getMinutes()==y.getMinutes())
         ){return 1;}
        else{return 0;}
    }

///Date_Time
    //constructors
    Date_Time::Date_Time(){
        id=0;
        date.setDay(0);
        date.setMonth(0);
        date.setYear(0);
    }
    Date_Time::Date_Time(int i,Date d,Time t){
        id=i;
        date=d;
        time=t;
    }
    //getters
    int Date_Time::getId(){return id;}
    Date Date_Time::getDate(){return date;}
    Time Date_Time::getTime(){return time;}
    //setters
    void Date_Time::setId(int i){id=i;}
    void Date_Time::setDate(Date d){date=d;}
    void Date_Time::setTime(Time t){time=t;}

    void Date_Time::print(std::ostream& out)const{
        out<<"\nID     : "<<id
           <<"\nDate   : "<<date
           <<"\nTime   : "<<time;
    }
    void Date_Time::read(std::istream& in){
        in>>id>>date>>time;
    }


    bool operator< (Date_Time x, Date_Time y){
        if(x.getDate().getYear()<y.getDate().getYear()){
            return 1;
        }
        else if(x.getDate().getMonth()<y.getDate().getMonth()){
            return 1;
        }
        else if(x.getDate().getDay()<y.getDate().getDay()){
            return 1;
        }
        else if(x.getTime().getAM_PM()=='a'&&y.getTime().getAM_PM()=='p'){
            return 1;
        }
        else if(x.getTime().getAM_PM()=='p'&&y.getTime().getAM_PM()=='p'){
            if(x.getTime().getHours()<y.getTime().getHours()){
                return 1;
            }
            else if(x.getTime().getMinutes()<y.getTime().getMinutes()){
                return 1;
            }
        }
        else if(x.getTime().getAM_PM()=='a'&&y.getTime().getAM_PM()=='a'){
            if(x.getTime().getHours()<y.getTime().getHours()){
                return 1;
            }
            else if(x.getTime().getMinutes()<y.getTime().getMinutes()){
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    bool operator== (Date_Time x, Date_Time y){
        if( (x.getDate().getYear()==y.getDate().getYear())
           &&(x.getDate().getMonth()==y.getDate().getMonth())
           &&(x.getDate().getDay()==y.getDate().getDay())
           &&(x.getTime().getAM_PM()==y.getTime().getAM_PM())
           &&(x.getTime().getHours()==y.getTime().getHours())
           &&(x.getTime().getMinutes()==y.getTime().getMinutes())
         ){return 1;}
        else{return 0;}

    }

