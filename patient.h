#pragma once

typedef struct date {
	unsigned int day, month, year;
} Date;

typedef struct patient{
	long int id;
	char sex[6]; // {“male”,“female”}
	int birthYear;
	char country[40];//birth country
	char province[40];
	char infection_case[100];
	long int infected_by; // id of the infected patient 
	Date confirmed_date;
	Date released_date;
	Date deceased_date;
	char state[10];//{“isolated,“released”,“deceased”}
}Patient;

typedef struct region{
	char name[40];
	char capital[40];
	int population;
	float area;
}Region;


Date DateCreate(int day, int month, int year);


Patient PatientCreate(long int id, char sex[6], int birthYear, char country[40], char region[40], char infectionReason[100], long int infectedBy, int day, int month, int year, char state[10]);


Region RegionCreate(char* name, char* capital, int population, float area);

void DatePrint(Date dt);


int countLeapYears(Date d); 


int PassedDays(Patient pt1);

int CurrentAge(Patient pt);


void PatientPrint(Patient pt);


void RegionPrint(Region rn);

