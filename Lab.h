#ifndef LAB_H_INCLUDED
#define LAB_H_INCLUDED

#include <iostream>
using namespace std;

struct Lab{
    string id;
    string slot_id;
    int f=0;

    void incrementId(bool a){
        static int done;
        done++;
        f=done;
        if(a){
            done=0;
            f=0;
        }
    }
};

#endif // LAB_H_INCLUDED
