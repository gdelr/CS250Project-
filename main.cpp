///2058 lines of code :)
#include <iostream>
#include <vector>
#include<fstream>

#include "menuFunctions.h"

#include "Patient.h"
#include "Doctor.h"
#include "Slot.h"
#include "Date_Time.h"
#include "Record.h"
#include "Diagnoses.h"
#include "Appointment.h"

#include "Lab.h"

using namespace std;

int main(){

    vector<Lab> labList;
    Lab temp;
    temp.f=0;
    labList.push_back(temp);
///loading patients
    ifstream pf;
    int pLength;
    pf.open("Patients.txt");
    pf>>pLength;
    vector<Patient> patientList(pLength);

    vector<Record> recordList(pLength);

    for(int i=0;i<pLength;i++){
        pf>>patientList[i];
        recordList[i].setId(patientList[i].getRecord_id());
        recordList[i].setPatient_id(patientList[i].getId());
    }
    pf.close();
///loading doctors
    ifstream df;
    int dLength;
    df.open("Doctors.txt");
    df>>dLength;
    vector<Doctor> doctorList(dLength);
    for(int i=0;i<dLength;i++){
        df>>doctorList[i];
    }

    df.close();
///loading Slots
    ifstream sf;
    int sLength;
    sf.open("Slots.txt");
    sf>>sLength;
    vector<Slot> slotList(sLength);
    for(int i=0;i<sLength;i++){
       sf>>slotList[i];
    }
    sf.close();

///loading Date_Time
    ifstream dtf;
    int dtLength;
    dtf.open("Date_Time.txt");
    dtf>>dtLength;
    vector<Date_Time> dateTimeList(dtLength);
    for(int i=0;i<dtLength;i++){
       dtf>>dateTimeList[i];
    }
    dtf.close();

///loading Diagnoses
    ifstream nf;
    int nLength;
    nf.open("Date_Time.txt");
    nf>>nLength;
    vector<Diagnoses> diagnosesList(nLength);
    for(int i=0;i<nLength;i++){
       sf>>diagnosesList[i];
    }
    nf.close();


    vector<Appointment> appointmentList;
    mainMenu(patientList,doctorList,slotList,dateTimeList,recordList,diagnosesList,appointmentList,labList);
    return 0;
}
