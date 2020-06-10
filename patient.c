#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "patient.h"
#include "utils.h"


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

/*-------------------------------------------*/


long int Infect(Patient pt){
	int i = 0; 

	i = pt.infected_by;

	if(!pt.infected_by)	return -1;
	else	return i;
}

void PatientPrint(Patient pt){
	
	int age = CurrentAge(pt);

	long int infect = Infect(pt);

		
	printf("ID: %ld\n SEX: %s\n AGE: %d\n COUNTRY/REGION: %s/%s\n STATE: %s \n\n", pt.id, pt.sex, age, pt.country, pt.province, pt.state);
	
}

void PatientTopPrint(Patient pt){
	
	int age = CurrentAge(pt);

	long int infect = Infect(pt);

	int day = CurrentDays(pt);
		
	printf("ID: %ld\n SEX: %s\n AGE: %d\n COUNTRY/REGION: %s/%s| INFECTION REASON: %s\n INFECTION BY: %ld\n STATE: %s \n NUMBER OF DAYS WITH ILLNESS: %d \n\n", pt.id, pt.sex, age, pt.country, pt.province, pt.infection_case, infect, pt.state, day);
	
}




void RegionPrint(Region rn){
	printf(" %s| %s| %d| %f\n", rn.name, rn.capital, rn.population, rn.area);
}



