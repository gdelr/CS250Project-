#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED

#include <vector>
#include <iostream>

#include "Patient.h"
#include "Doctor.h"
#include "Slot.h"
#include "Date_Time.h"
#include "Record.h"
#include "Diagnoses.h"
#include "Appointment.h"

#include "Lab.h"

using namespace std;

void mainMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);

void ManageAppointmentsMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);
void ManageSlotsMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);
void ManageDoctorsMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);
void ManagePatientsMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);
void ManagePatientsRecordsMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);
void ManageLabMenu(vector<Patient>&,vector<Doctor>&,vector<Slot>&,vector<Date_Time>&,vector<Record>&,vector<Diagnoses>&,vector<Appointment>&,vector<Lab>&);

Appointment scheduleAppointment(vector<Slot>&);
void showAllAppointments(vector<Appointment>&);
void changeExistingAppintment(vector<Appointment>&);
void removeAppointment(vector<Appointment>&,vector<Slot>&);
void searchAppointmentsDocName(vector<Appointment>&,vector<Doctor>&);
void searchAppointmentsPatient(vector<Appointment>&,vector<Patient>&);

void availableSlots(vector<Slot>&);
void unavailableSlots(vector<Slot>&);
Slot addNewSlot(vector<Slot>&);
void removeSlot(vector<Slot>&);
void searchSlotRange(vector<Slot>&,vector<Date_Time>&);
void printAllSlots(vector<Slot>&);
void searchSlotsDoctor(vector<Slot>&,vector<Doctor>&);
void modifySlot(vector<Slot>&);

Doctor addDoctor(vector<Doctor>&);
void updateDoctor(vector<Doctor>&);
int deleteDoctor(vector<Doctor>& docList,vector<Appointment>& appList);
void printDoctors(vector<Doctor>&);
void searchDoc(vector<Doctor>&);

Patient addPatient(vector<Patient>&);
void updatePatient(vector<Patient>& patList);
void deletePatient(vector<Patient>& patList);
void printPatients(vector<Patient>& patList);
void searchPatient(vector<Patient>& patList);
void searchPatientByDoc(vector<Patient>&,vector<Doctor>&);
void searchPatientByTime(vector<Patient>& patList,vector<Appointment>& appList,vector<Date_Time>&dtl,vector<Slot>& slotList);

Record addRecord(vector<Record>& recList);
void updateDiagnosis(vector<Patient>&patList,vector<Appointment>& appList,vector<Diagnoses>& dList);
void upDateRecord(vector<Patient>& patList,vector<Record>& recList);
void printRecord(vector<Record>& recList);
void deleteRecord(vector<Record>& recList);

Lab addLab(vector<Lab>&);
void deleteLab(vector<Lab>&);
void printLabs(vector<Lab>&);

#endif // MENUFUNCTIONS_H_INCLUDED
