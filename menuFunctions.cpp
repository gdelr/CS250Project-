#include "menuFunctions.h"

Appointment scheduleAppointment(vector<Slot>& slotList){
    Appointment temp;
    string doctor_id;
    string patien_id;
    string slot_id;
    string reason;

    cout<<"\n\t\tEnter doctor ID :\n\t\t";
    cin>>doctor_id;

    cout<<"\n\t\tEnter patient ID :\n\t\t";
    cin>>patien_id;

    cout<<"\n\t\tEnter slot ID :\n\t\t";
    cin>>slot_id;

    for(int i=0;i<slotList.size();i++){
        if(slot_id==slotList[i].getId()){
            slotList[i].setAbalible(0);
        }
    }
    cout<<"\n\t\tEnter reason :\n\t\t";
    cin>>reason;

    temp.setDoctor_id(doctor_id);
    temp.setPatient_id(patien_id);
    temp.setReason(reason);
    temp.setSlot_id(slot_id);
    temp.incrementId();

    return temp;
}

void showAllAppointments(vector<Appointment>&appList){
    for(int i=0;i<appList.size();i++){
        cout<<appList[i];
    }
}

void changeExistingAppintment(vector<Appointment>&appList){
    int lookUp;
    int place;
    bool yes;
    string modify;
    cout<<"\n\t\tEnter the appointment id that you want to Modify/Reschedule :\n\t\t";
    do{
        cin>>lookUp;
        for(int i=0;i<appList.size();i++){
            if(lookUp==appList[i].getId()){
                place=i;
                yes=1;
                break;
            }
        }
    }while(!yes);
    cout<<"\n\t\tYou selected appointment "<<lookUp<<". Here is what it looks like:"<<appList[place];
    int input;
    cout<<"\n\t\tSelect option to modify:"
        <<"\n\t\t1. Modify appointment's doctor id"
        <<"\n\t\t2. Modify appointment's patient id"
        <<"\n\t\t3. Modify appointment's slot id"
        <<"\n\t\t4. Modify appointment's reason"
        <<"\n\t\t5. Modify appointment's diagnosis id"
        <<"\n\t\t6. Modify appointment's prescribed medication\n";
    cin>>input;
    switch(input){
        case 1 :
            cin>>modify;
            appList[place].setDoctor_id(modify);
            break;
        case 2 :
            cin>>modify;
            appList[place].setPatient_id(modify);
            break;
        case 3 :
            cin>>modify;
            appList[place].setSlot_id(modify);
            break;
        case 4 :
            cin>>modify;
            appList[place].setReason(modify);
            break;
        case 5 :
            cin>>modify;
            appList[place].setDiagnosis_id(modify);
            break;
        case 6 :
            cin>>modify;
            appList[place].setPerscribed_medication(modify);
            break;
    }
}

void removeAppointment(vector<Appointment>&appList,vector<Slot>& slotList){
///The slot associated with the deleted appointment must be changed to available). Confirmation message is required
    int lookUp;
    int place;
    bool yes;
    string modify;
    cout<<"\n\t\tEnter the appointment id that you want to delete :\n\t\t";
    do{
        cin>>lookUp;
        for(int i=0;i<appList.size();i++){
            if(lookUp==appList[i].getId()){
                place=i;

                yes=1;
                break;
            }
        }
    }while(!yes);
    for(int i=0;i<slotList.size();i++){
        if(slotList[i].getId()==appList[place].getSlot_id()){
            slotList[i].setAbalible(0);
        }
    }
    appList.erase(appList.begin()+place);
}

void searchAppointmentsDocName(vector<Appointment>& appList,vector<Doctor>& docList){
    string docName;
    cout<<"\n\t\tEnter Doctors name (no space) :";
    cin>>docName;
    string tempDocId;
    for(int i=0;i<docList.size();i++){
        if(docName==docList[i].getName()){
            tempDocId=docList[i].getId();
        }
    }
    for(int i=0;i<appList.size();i++){
        if(appList[i].getDoctor_id()==tempDocId){
            cout<<"\n\t\t"<<appList[i];
        }
    }
}

void searchAppointmentsPatient(vector<Appointment>& appList,vector<Patient>& patList){
///Show all appointments for a patient by patient's name, email, and dob
    int input;
    string searchBy;
    string tempPatientID;
    cout<<"\n\t\tSelect an option:"
        <<"\n\t\t1. Search by name"
        <<"\n\t\t2. Search by email"
        <<"\n\t\t3. Search by date of birth\n\t\t\t";
    cin>>input;
    switch(input){
        case 1 :cout<<"\n\t\tPlease enter the patient's name : ";
                cin>>searchBy;
                for(int i=0;i<patList.size();i++){
                    if(searchBy==patList[i].getName()){
                        tempPatientID=patList[i].getId();
                    }
                }
                break;
        case 2 :cout<<"\n\t\tPlease enter the patient's email : ";
                cin>>searchBy;
                for(int i=0;i<patList.size();i++){
                    if(searchBy==patList[i].getEmail()){
                        tempPatientID=patList[i].getId();
                    }
                }
                break;
        case 3 :cout<<"404 ERROR DOB NOT FOUND";
                return;
    }
    for(int i=0;i,appList.size();i++){
        if(tempPatientID==appList[i].getPatiend_id()){
            cout<<"\n\t\t"<<appList[i]<<endl;
            break;
        }
    }
}

///Slots

void availableSlots(vector<Slot>& slotList){
    for(int i=0;i<slotList.size();i++){
        if(slotList[i].getAvaliable()){
            cout<<"\n\t\t"<<slotList[i]<<endl;
        }
    }
}

void unavailableSlots(vector<Slot>& slotList){
    for(int i=0;i<slotList.size();i++){
        if(!slotList[i].getAvaliable()){
            cout<<"\n\t\t"<<slotList[i]<<endl;
        }
    }
}

Slot addNewSlot(vector<Slot>& slotList){
    Slot temp;
    string input;
    cout<<"\n\t\tPlease Enter ID : ";
    cin>>input;
    temp.setId(input);
    cout<<"\n\t\tPlease Enter Date ID : ";
    int thing;
    cin>>thing;
    temp.setDate_id(thing);
    cout<<"\n\t\tPlease Enter Doctor ID : ";
    cin>>input;
    temp.setDoctor_id(input);
    cout<<"\n\t\tPlease set Availability (available/unavailable) : ";
    cin>>input;
    if(input=="available"){
        temp.setAbalible(1);
    }
    else{
        temp.setAbalible(0);
    }
}

void removeSlot(vector<Slot>& slotList){
    int input;
    cout<<"\n\t\tEnter the number of the slot that you want to remove : ";
    cin>>input;
    cout<<input;
    slotList.erase(slotList.begin()+input-1);
}

void searchSlotRange(vector<Slot>& slotList,vector<Date_Time>& dtl){
    Time temp1,temp2;
    Date_Time temp3;
    cout<<"\n\t\tEnter first time (hours minutes a/p) : ";
    cin>>temp1;
    cout<<"\n\t\tEnter second time (hours minutes a/p) : ";
    cin>>temp2;

    for(int i=0;i<slotList.size();i++){
        for(int j=0;j<dtl.size();j++){
            if(slotList[i].getDate_id()==dtl[j].getId()){
                temp3=dtl[j];
                if(temp1<temp3.getTime()&&temp3.getTime()<temp2){
                    cout<<"\n\t\t"<<slotList[i];
                }
            }
        }
    }
}

void printAllSlots(vector<Slot>& slotList){
    for(int i=0;i<slotList.size();i++){
        cout<<"\n\t\t"<<slotList[i];
    }
}

void searchSlotsDoctor(vector<Slot>& slotList,vector<Doctor>&docList){
    string doctorId;
    cout<<"\n\t\tEnter doctor ID : ";
    cin>>doctorId;
    int place;
    for(int i=0;i<docList.size();i++){
        if(doctorId==docList[i].getId()){
            place=i;
        }
    }
    for(int i=0;i<slotList.size();i++){
        if(slotList[i].getDoctor_id()==docList[place].getId()){
            cout<<"\n\t\t"<<slotList[i];
        }
    }
}

void modifySlot(vector<Slot>& slotList){
    string lookUp;
    int place;
    bool yes;
    string modify;
    cout<<"\n\t\tEnter the slot id that you want to Modify :\n\t\t";
    do{
        cin>>lookUp;
        for(int i=0;i<slotList.size();i++){
            if(lookUp==slotList[i].getId()){
                place=i;
                yes=1;
                break;
            }
        }
    }while(!yes);
    cout<<"\n\t\tYou selected slot "<<lookUp<<". Here is what it looks like:"<<slotList[place];
    int input;
    cout<<"\n\t\tSelect option to modify:"
        <<"\n\t\t1. Modify date ID : "
        <<"\n\t\t2. Modify Doctor ID : "
        <<"\n\t\t3. Modify if available (1 if available / 0 if unavailable) : ";
    cin>>input;
    switch(input){
        case 1 :
            int temp;
            cin>>temp;
            slotList[place].setDate_id(temp);
            break;
        case 2 :
            cin>>input;
            cin>>modify;
            slotList[place].setDoctor_id(modify);
            break;
        case 3 :
            bool temp2;
            cin>>temp2;
            slotList[place].setAbalible(temp2);
            break;
    }
}

///Doctor
Doctor addDoctor(vector<Doctor>& docList){
        Doctor temp;
        cout<<"\n\t\tPlease Enter the new doctor's information\n\t\t\t(id username password name phone skil) ";
        cin>>temp;
        return temp;
    }

    void updateDoctor(vector<Doctor>& docList){
        string lookUp;
        int place;
        bool yes;
        string modify;
        cout<<"\n\t\tEnter the doctor id that you want to update :\n\t\t";
        do{
            cin>>lookUp;
            for(int i=0;i<docList.size();i++){
                if(lookUp==docList[i].getId()){
                    place=i;
                    yes=1;
                    break;
                }
            }
        }while(!yes);
        cout<<"\n\t\tYou selected Doctor "<<lookUp<<". Here is what it looks like:"<<docList[place];
        int input;
        cout<<"\n\t\tSelect option to modify:"
            <<"\n\t\t1. update Doctors's username"
            <<"\n\t\t2. update Doctors's password"
            <<"\n\t\t3. update Doctors's name"
            <<"\n\t\t4. update Doctors's phone"
            <<"\n\t\t5. update Doctors's skill";
        cin>>input;
        switch(input){
            case 1 :
                cin>>modify;
                docList[place].setUsername(modify);
                break;
            case 2 :
                cin>>modify;
                docList[place].setPassword(modify);
                break;
            case 3 :
                cin>>modify;
                docList[place].setName(modify);
                break;
            case 4 :
                cin>>modify;
                docList[place].setPhone(modify);
                break;
            case 5 :
                cin>>modify;
                docList[place].setSkill(modify);
                break;
    }
}

    int deleteDoctor(vector<Doctor>& docList,vector<Appointment>& appList){
        string docId;
        cout<<"\n\t\tEnter Doctor ID :\n\t\t";
        cin>>docId;
        for(int i=0;i<appList.size();i++){
            if(appList[i].getDoctor_id()==docId){
                cout<<"\n\t\tThe selected doctor cannot be deleted because he/she has appointments.";

            }
        }
        int place;
        for(int i=0;i<docList.size();i++){
            if(docId==docList[i].getId()){
                place=i;
            }
        }
        docList.erase(docList.begin()+place);
        return 1;
    }
    void printDoctors(vector<Doctor>& docList){
        for(int i=0;i<docList.size();i++){
            cout<<"\n\t\t"<<docList[i];
        }
    }
    void searchDoc(vector<Doctor>& docList){
        string name;
        cout<<"\n\t\tEnter the name of the doctor:\n\t\t";
        cin>>name;
        for(int i=0;i<docList.size();i++){
            if(name==docList[i].getName()){
                cout<<"\n\t\t"<<docList[i];
            }
        }
    }

///patients
Patient addPatient(vector<Patient>& patList){
    Patient temp;
    cout<<"\n\t\tEnter new patient's info \n\t\t(id doctor's id, record's id name phone gender email blood type)";
    cin>>temp;
    return temp;
}

void updatePatient(vector<Patient>& patList){
        string lookUp;
        int place;
        bool yes;
        string modify;
        cout<<"\n\t\tEnter the Patient id that you want to update :\n\t\t";
        do{
            cin>>lookUp;
            for(int i=0;i<patList.size();i++){
                if(lookUp==patList[i].getId()){
                    place=i;
                    yes=1;
                    break;
                }
            }
        }while(!yes);
        cout<<"\n\t\tYou selected Doctor "<<lookUp<<". Here is what it looks like:"<<patList[place];
        int input;
        cout<<"\n\t\tSelect option to modify:"
            <<"\n\t\t1. update Patient's doctor id"
            <<"\n\t\t2. update Patient's record id"
            <<"\n\t\t3. update Patient's name"
            <<"\n\t\t4. update Patient's phone"
            <<"\n\t\t5. update Patient's gender"
            <<"\n\t\t6. update Patient's email"
            <<"\n\t\t7. update Patient's blood type";
        cin>>input;
        switch(input){
            case 1 :
                cin>>modify;
                patList[place].setDoctor_id(modify);
                break;
            case 2 :
                cin>>modify;
                patList[place].setRecord_id(modify);
                break;
            case 3 :
                cin>>modify;
                patList[place].setName(modify);
                break;
            case 4 :
                cin>>modify;
                patList[place].setPhone(modify);
                break;
            case 5 :
                cin>>modify;
                patList[place].setGender(modify);
                break;
            case 6 :
                cin>>modify;
                patList[place].setEmail(modify);
                break;
            case 7 :
                cin>>modify;
                patList[place].setBlood_type(modify);
                break;
    }
}
void deletePatient(vector<Patient>& patList){
    string patID;
    cout<<"\n\t\tEnter the id of the patient that you want to delete : ";
    cin>>patID;
    int place;
    for(int i=0;i<patList.size();i++){
        if(patID==patList[i].getId()){
            place=i;
        }
    }
    patList.erase(patList.begin()+place);
}

void printPatients(vector<Patient>& patList){
    for(int i=0;i<patList.size();i++){
        cout<<"\n\t\t"<<patList[i];
    }
}
void searchPatient(vector<Patient>& patList){
    int input;
    cout<<"\n\t\tSelect how you want to search patients : "
        <<"\n\t\t1. Name"
        <<"\n\t\t2. email";
    cin>>input;
    for(int i=0;i<patList.size();i++){
        switch(input){
            if(input==1){
                string name;
                cin>>name;
                if(patList[i].getName()==name){
                    cout<<"\n\t\t"<<patList[i];
                }
            }
            else if(input==2){
                string email;
                cin>>email;
                if(patList[i].getEmail()==email){
                    cout<<"\n\t\t"<<patList[i];
                }
            }
        }
    }
}

void searchPatientByDoc(vector<Patient>& patList,vector<Doctor>&docList){
    string docName;
    cout<<"\n\t\tEnter the name of the doctor :\n\t\t";
    cin>>docName;
    string docId;
    for(int i=0;i<docList.size();i++){
        if(docName==docList[i].getName()){
            docId=docList[i].getId();
        }
    }
    for(int i=0;i<patList.size();i++){
        if(docId==patList[i].getDoctor_id()){
            cout<<"\n\t\t"<<patList[i];
        }
    }
}

void searchPatientByTime(vector<Patient>& patList,vector<Appointment>& appList,vector<Date_Time>&dtl,vector<Slot>& slotList){
    Time temp1,temp2;
    Date_Time temp3;
    cout<<"\n\t\tEnter first time (hours minutes a/p) : ";
    cin>>temp1;
    cout<<"\n\t\tEnter second time (hours minutes a/p) : ";
    cin>>temp2;
}

///Record

Record addRecord(vector<Record>& recList){
    string id;
    string patient_id;
    string notes;
    cout<<"\n\t\tEnter new Record (id patient's id notes)";
    Record temp;
    cin>>temp;
    return temp;
}

void updateDiagnosis(vector<Patient>&patList,vector<Appointment>& appList,vector<Diagnoses>& dList){
    string patId;
    cout<<"\n\t\tEnter the id of the patient :\n\t\t";
    cin>>patId;
    int plcae;
    for(int i=0;i<appList.size();i++){
        if(patId==appList[i].getPatiend_id()){
            plcae=i;
        }
    }
    Diagnoses temp;
    string diagID;
    string diag;
    cout<<"\n\t\tEnter the Id of the diagnosis:\n\t\t";
    cin>>diagID;
    temp.setId(diagID);
    appList[plcae].setDiagnosis_id(diagID);
    cout<<"\n\t\tEnter diagnosis:\n\t\t";
    cin>>diag;
    temp.setDisease_name(diag);
    dList.push_back(temp);
}

void upDateRecord(vector<Patient>& patList,vector<Record>& recList){
    string id;
    cout<<"\n\t\tEnter the id of the patient : \n\t\t";
    cin>>id;
    for(int i=0;i<patList.size();i++){
        if(id==patList[i].getId()){
            id=patList[i].getRecord_id();
        }
    }
    int place;
    for(int i=0;i<recList.size();i++){
        if(id==recList[i].getId()){
            place=i;
        }
    }
    cout<<"\n\t\tSelect an opting to update:";
    cout<<"\n\t\t1. patient's id";
    cout<<"\n\t\t2. notes";
    int input;
    cin>>input;
    if(input==1){
        cout<<"\n\t\t\tEnter updated patient's id:\n\t\t\t";
        string thing;
        cin>>thing;
        recList[place].setPatient_id(thing);
    }
    else if(input==2){
        cout<<"\n\t\t\tEnter updated patient's notes:\n\t\t\t";
        string thing;
        cin>>thing;
        recList[place].setNotes(thing);
    }
}
void printRecord(vector<Record>& recList){
    for(int i=0;i<recList.size();i++){
        cout<<recList[i];
    }
}

void deleteRecord(vector<Record>& recList){
    string recID;
    cout<<"\n\t\tEnter the id of the record that you want to delete : ";
    cin>>recID;
    int place;
    for(int i=0;i<recList.size();i++){
        if(recID==recList[i].getId()){
            place=i;
        }
    }
    recList.erase(recList.begin()+place);
}
///Lab

Lab addLab(vector<Lab>&labList){
    string id;
    string slot;
    Lab temp;
    cout<<"\n\t\tEnter the id of the Lab:\n\t\t";
    cin>>id;
    temp.id=id;
    cout<<"\n\t\tEnter the slot if of the Lab:\n\t\t";
    cin>>slot;
    temp.slot_id=slot;

        cout<<"\nLab ID      : "<<temp.id;
        cout<<"\nLab slot ID : "<<temp.slot_id<<endl;
    return temp;
}
void deleteLab(vector<Lab>& labList){
    string id;
    cout<<"\n\t\tEnter the id of the lab you want to delete:\n\t\t";
    cin>>id;
    int place;
    for(int i=0;i<labList.size();i++){
        if(id==labList[i].id){
            place=i;
        }
    }
    labList.erase(labList.begin()+place);
}

void printLabs(vector<Lab>& labList){
    cerr<<"\t\t\t\t\t\t"<<labList.size();
    for(int i=1;i<labList.size();i++){
        cout<<"\nLab ID      : "<<labList[i].id;
        cout<<"\nLab slot ID : "<<labList[i].slot_id<<endl;
    }
}
///main

void mainMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    cout <<"\nWelcome to HMS. Please choose an action:"
         <<"\n1. Manage Appointments"
         <<"\n2. Manage Slots"
         <<"\n3. Manage Doctors"
         <<"\n4. Manage Patients"
         <<"\n5. Manage Patients' records"
         <<"\n6. Manage Lab"
         <<"\n7. Exit"<<endl;
    int input;
    cin>>input;

    switch(input) {
    case 1 :cout<<"Manage Appointments:";
            ManageAppointmentsMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Manage Slots:";
            ManageSlotsMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout <<"Manage Doctors:";
            ManageDoctorsMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout <<"Manage Patients:";
            ManagePatientsMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 5 :cout <<"Manage Patients' records:";
            ManagePatientsRecordsMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 6 :cout <<"Manage Lab:";
            ManageLabMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 7 :cout <<"Exit:";
            break;
    }

}

void ManageAppointmentsMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. Schedule a new appointment"
    <<"\n\t2. Show all appointments"
    <<"\n\t3. Modify/Reschedule an existing appointment"
    <<"\n\t4. Remove an appointment" //The slot associated with the deleted appointment must be changed to available). Confirmation message is required
    <<"\n\t5. Show all appointments for a doctor by doctor's name"
    <<"\n\t6. Show all appointments for a patient by patient's name, email,and dob"
    <<"\n\t7. Return to main menu"<<endl;

    cin>>input;

    switch(input){
        case 1 :cout<<"Schedule a new appointment:";
                al.push_back(scheduleAppointment(sl));
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 2 :cout<<"Show all appointments:";
                showAllAppointments(al);
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 3 :cout<<"Modify/Reschedule an existing appointment:";
                changeExistingAppintment(al);
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 4 :cout<<"Remove an appointment:";
                removeAppointment(al,sl);//The slot associated with the deleted appointment must be changed to available). Confirmation message is required
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 5 :cout<<"Show all appointments for a doctor by doctor's name";
                searchAppointmentsDocName(al,dl);
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 6 :cout<<"Show all appointments for a patient by patient's name, email, and dob";
                searchAppointmentsPatient(al,pl);
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
        case 7 :cout<<"Returning to the main menu:";
                mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
                break;
    }
}
void ManageSlotsMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. Show available slots"
        <<"\n\t2. Show unavailable slots"
        <<"\n\t3. Add new slot(s)"
        <<"\n\t4. Show slots between two times"
        <<"\n\t5. Show all slots"
        <<"\n\t6. Show all slots for a certain doctor"
        <<"\n\t7. Modify slot information"
        <<"\n\t8. Remove a slot"
        <<"\n\t9. Return to main menu"<<endl;

    cin>>input;
    switch(input){
    case 1 :cout<<"Show available slots:";
            availableSlots(sl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Show unavailable slots:";
            unavailableSlots(sl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout<<"Add new slot:";
            sl.push_back(addNewSlot(sl));
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout<<"Show slots between two times:";
            searchSlotRange(sl,dtl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 5 :cout<<"Show all slots:";
            printAllSlots(sl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 6 :cout<<"Show all slots for a certain doctor:";
            searchSlotsDoctor(sl,dl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 7 :cout<<"Modify slot information:";
            modifySlot(sl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 8 :cout<<"Remove a slot:";
            removeSlot(sl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 9 :cout<<"Returning to the main menu:";
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    }
}
void ManageDoctorsMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. Add doctor"
        <<"\n\t2. Update doctor's info"
        <<"\n\t3. Delete doctor"
        <<"\n\t4. View all doctors"
        <<"\n\t5. search for doctor"
        <<"\n\t6. Return to main menu"<<endl;

    cin>>input;
    switch(input){
    case 1 :cout<<"Add doctor:";
            dl.push_back(addDoctor(dl));
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Update doctor's info:";
            updateDoctor(dl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout<<"Delete doctor:";
            deleteDoctor(dl,al);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout<<"View all doctors:";
            printDoctors(dl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 5 :cout<<"search for doctor:";
            searchDoc(dl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 6 :cout<<"Returning to main menu:";
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    }
}
void ManagePatientsMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. Add Patient"
        <<"\n\t2. Update patient's info"
        <<"\n\t3. Delete patient"
        <<"\n\t4. View all patients"//must show their doctor’s name,diagnosis, …etc
        <<"\n\t5. Search for patient (by name or email)"//must show their doctor’s name, diagnosis, …etc
        <<"\n\t6. Search for patient by doctor's name"
        <<"\n\t7. Show patient's appointment by time range"
        <<"\n\t8. Return to main menu"<<endl;

    cin>>input;
    switch(input){
    case 1 :cout<<"Add Patient:";
            pl.push_back(addPatient(pl));
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Update patient's info:";
            updatePatient(pl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout<<"Delete patient:";
            deletePatient(pl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout<<"View all patients:";
            printPatients(pl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 5 :cout<<"Search for patient (by name or email):";
            searchPatient(pl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 6 :cout<<"Search for patient by doctor's name:";
            searchPatientByDoc(pl,dl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 7 :cout<<"Show patient's appointment by time range:";
            searchPatientByTime(pl,al,dtl,sl);///not done
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 8 :cout<<"Returning to main menu:";
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    }
}
void ManagePatientsRecordsMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. add new record"
        <<"\n\t2. Update a patient's record"
        <<"\n\t3. update a patient's diagnosis"
        <<"\n\t4. show all records"
        <<"\n\t5. Delete record"
        <<"\n\t6. Return to main menu"<<endl;

    cin>>input;
    switch(input){
    case 1 :cout<<"add new record:";
            rl.push_back(addRecord(rl));
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Update a patient's record:";
            upDateRecord(pl,rl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout<<"update a patient's diagnosis:";
            updateDiagnosis(pl,al,il);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout<<"show all records:";
            printRecord(rl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 5 :cout<<"Delete record:";
            deleteRecord(rl);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 6 :cout<<"Returning to main menu:";
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    }
}
void ManageLabMenu(vector<Patient>& pl,vector<Doctor>& dl,vector<Slot>& sl,vector<Date_Time>& dtl,vector<Record>& rl,vector<Diagnoses>& il,vector<Appointment>& al,vector<Lab>& ll){
    int input;
    cout<<"\n\t1. Create an appointment for a lab"
        <<"\n\t2. Delete a lab appointment"
        <<"\n\t3. Show all lab appointments"
        <<"\n\t4. Return to main menu"<<endl;

    cin>>input;
    switch(input){
    case 1 :cout<<"Create an appointment for a lab:";
            if(ll[0].f==0){
                ll.push_back(addLab(ll));
                ll[0].incrementId(0);
            }
            else{
                cout<<"\nOnly 1 lab can be made a day.";
            }
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 2 :cout<<"Delete a lab appointment:";
            deleteLab(ll);
            ll[0].incrementId(1);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 3 :cout<<"Show all lab appointments:";
            printLabs(ll);
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    case 4 :cout<<"Returning to main menu:";
            mainMenu(pl,dl,sl,dtl,rl,il,al,ll);
            break;
    }
}
