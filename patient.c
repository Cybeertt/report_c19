#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "patient.h"


Date DateCreate(int day, int month, int year){
	Date dt;
	dt.day = day;
	dt.month = month;
	dt.year = year;
	return dt;
}

Date DateRead(char* dateStr){
	int day, month, year;
	if(strlen(dateStr) == 0){
		return DateCreate(0, 0, 0);
	}
	else {
		sscanf(dateStr, "%2d/%2d/%4d", &day, &month, &year);
		return DateCreate(day, month, year);
	}
}

Patient PatientCreate(long int id, char sex[6], int birthYear, char country[40], char province[40], char infection_case[100], long int infected_by, Date confirmed_date, Date released_date, Date deceased_date, char state[10]){
	Patient pt;
	pt.id = id;
	strcpy(pt.sex, sex);
	pt.birthYear = birthYear;
	strcpy(pt.country, country);
	strcpy(pt.province, province);
	strcpy(pt.infection_case, infection_case);
	pt.infected_by = infected_by;
	pt.confirmed_date = confirmed_date;
	pt.released_date = released_date;
	pt.deceased_date = deceased_date;
	strcpy(pt.state, state);
	return pt;
}


Region RegionCreate(char* name, char* capital, int population, float area){
	Region rn;
	strcpy(rn.name, name);
	strcpy(rn.capital, capital);
	rn.population = population;
	rn.area = area;
	return rn;
}

void DatePrint(Date dt){
	printf(" %d/%d/%d\n", dt.day, dt.month, dt.year);
}


/*int countLeapYears(Patient p) 
{ 
	Date d;
    int years = d.year; 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.month <= 2) 
        years--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} */

int PassedDays(Patient pt1){
	
	long int n1 = pt1.confirmed_date.year*365 + pt1.confirmed_date.day; 
  
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 

    for (int i=0; i<pt1.confirmed_date.month - 1; i++) 
        n1 += monthDays[i]; 
  
    	int years_p = pt1.confirmed_date.year;
	
		if (pt1.confirmed_date.month <= 2) 
        	years_p--; 

    	int pt_1 = years_p / 4 - years_p / 100 + years_p / 400; 

		n1 += pt_1;

	//int n =	5;
	
	return n1;

  	if(&pt1.released_date == NULL && &pt1.deceased_date == NULL){
	 
		time_t s;
		struct tm* current_time = malloc(sizeof(struct tm));
		time(&s);

		current_time = localtime(&s);

		int years = current_time->tm_year + 1900; 
	  
		if (current_time->tm_mon + 1 <= 2) 
		    years--; 
	  
		int r = years / 4 - years / 100 + years / 400;

		long int n2 = current_time->tm_year*365 + current_time->tm_mday;
		for (int i=0; i<current_time->tm_mon + 1; i++) 
		    n2 += monthDays[i]; 
		n2 += r; 

	return (n2 - n1);
	} /*else {
		if(&pt1.deceased_date == NULL){
			long int n3 = pt1.released_date.year*365 + pt1.released_date.day; 
			for (int i=0; i<pt1.released_date.month - 1; i++) 
				n3 += monthDays[i]; 
			int years_p2 = pt1.released_date.year;
	
			if (pt1.released_date.month <= 2) 
		    	years_p2--; 

			int pt_2 = years_p2 / 4 - years_p2 / 100 + years_p2 / 400; 
			n3 += pt_2;
			return (n3 - n1);
		}
		else if(&pt1.released_date == NULL){
			long int n4 = pt1.deceased_date.year*365 + pt1.deceased_date.day; 
			for (int i=0; i<pt1.deceased_date.month - 1; i++) 
				n4 += monthDays[i]; 
			int years_p3 = pt1.deceased_date.year;
	
			if (pt1.deceased_date.month <= 2) 
		    	years_p3--; 

			int pt_3 = years_p3 / 4 - years_p3 / 100 + years_p3 / 400; 
			n4 += pt_3;
			
			return (n4 - n1);
		}
	
    }*/
    
}

int CurrentAge(Patient pt){
	int age = 0; 

	time_t s;
	struct tm* current_time;

	s = time(NULL);

	current_time = localtime(&s);

	age = current_time->tm_year + 1900 - pt.birthYear;

	if(!pt.birthYear)	return -1;
	else	return age;
}

long int Infect(Patient pt){
	int i = 0; 

	i = pt.infected_by;

	if(!pt.infected_by)	return -1;
	else	return i;
}

void PatientPrint(Patient pt){
	
	int age = CurrentAge(pt);

	long int infect = Infect(pt);
		
	printf("ID: %ld\n SEX: %s\n AGE: %d\n COUNTRY/REGION: %s/%s| INFECTION REASON: %s\n INFECTION BY: %ld\n STATE: %s \n NUMBER OF DAYS WITH ILLNESS: %d \n\n", pt.id, pt.sex, age, pt.country, pt.province, pt.infection_case, infect, pt.state, 5);
	
}

void RegionPrint(Region rn){
	printf(" %s| %s| %d| %f\n", rn.name, rn.capital, rn.population, rn.area);
}



