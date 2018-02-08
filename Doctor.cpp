#include "Doctor.h"

//constructor
    Doctor::Doctor()
    {
        id="";
        username="";
        password="";
        name="";
        phone="";
        skill="";
    }
    Doctor::Doctor(string i,string u,string p,string n,string o,string s)
    {
        id=i;
        username=u;
        password=p;
        name=n;
        phone=o;
        skill=s;
    }
    //getters
    string Doctor::getId(){return id;}
    string Doctor::getUsername(){return username;}
    string Doctor::getPassword(){return password;}
    string Doctor::getName(){return name;}
    string Doctor::getPhone(){return phone;}
    string Doctor::getSkill(){return skill;}
    //setters
    void Doctor::setId(string a){id=a;}
    void Doctor::setUsername(string a){username=a;}
    void Doctor::setPassword(string a){password=a;}
    void Doctor::setName(string a){name=a;}
    void Doctor::setPhone(string a){phone=a;}
    void Doctor::setSkill(string a){skill=a;}

    void Doctor::print(std::ostream& out)const{
        out<<"\nDoctor ID : "<<id
           <<"\nUsername  : "<<username
           <<"\nPassword  : "<<password
           <<"\nName      : "<<name
           <<"\nPhone     : "<<phone
           <<"\nSkill     : "<<skill;

    }
    void Doctor::read(std::istream& in){
        in>>id>>username>>password>>name>>phone>>skill;
    }
