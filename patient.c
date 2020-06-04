#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "patient.h"

/**
 * @DateCreate struct Date criacao dos dados da data.
 * 
 * @int <day> Representa o dia da data
 * @int <month> Representa o genero do paciente
 * @int <year> Representa o ano
 * 
 * @return dt retorna a data criado
 */
Date DateCreate(int day, int month, int year){
	Date dt;
	dt.day = day;
	dt.month = month;
	dt.year = year;
	return dt;
}

/**
 * @PatientCreate struct Patient criacao dos dados do paciente.
 * 
 * @int <id> Representa o id do paciente
 * @char <sex> Representa o genero do paciente
 * @int <birthYear> Representa o ano de nascimento do paciente
 * @char <country> Representa o pais do paciente
 * @char <region> Representa a regiao do paciente
 * @char <infectionReason> Representa a razao da infecao do paciente
 * @int <infectedBy> Representa o id do paciente
 * @Date <confirmedDate> Representa a data confirmada do paciente
 * @Date <releasedDate> Representa a data em que o paciente foi libertado
 * @Date <deceasedDate> Representa a data do falecimento do paciente
 * @char <status> Representa o estado do paciente
 * 
 * @return pt retorna o paciente criado
 */
Patient PatientCreate(long int id, char sex[6], int birthYear, char country[40], char province[40], char infection_case[100], long int infected_by, int day, int month, int year, char state[10]){
	Patient pt;
	pt.id = id;
	strcpy(pt.sex, sex);
	pt.birthYear = birthYear;
	strcpy(pt.country, country);
	strcpy(pt.province, province);
	strcpy(pt.infection_case, infection_case);
	pt.infected_by = infected_by;
	pt.confirmed_date = DateCreate(day, month, year);
	pt.released_date = DateCreate(day, month, year);
	pt.deceased_date = DateCreate(day, month, year);
	strcpy(pt.state, state);
	return pt;
}

/**
 * @RegionCreate struct Region criacao dos dados da regiao.
 * 
 * @char <name> Representa o nome da regiao
 * @char <capital> Representa a capital da regiao
 * @int <population> Representa o numero de pessoas de uma regiao
 * @float <area> Representa o comprimento da area da regiao
 * 
 * @return rn retorna a regiao criado
 */
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

  	/*if(&pt1.released_date == NULL && &pt1.deceased_date == NULL){
	 
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
	} else {
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
	if(pt.birthYear == '\0'){ return -1;}
		else { return age; }
}

void PatientPrint(Patient pt){
	
	time_t s;
	struct tm* current_time;
	//time(&s);
	s = time(NULL);

	current_time = localtime(&s);

	//int age = current_time->tm_year + 1900 - pt.birthYear;

	int time = current_time->tm_year + 1900 + current_time->tm_mday;

	int age = CurrentAge(pt);

	//int days = PassedDays(pt);

	/*const char *str = "Error";
    char *sch_str = age;
	str = (*sch_str != '\0') ? sch_str : "Unknown";

	if(!pt.birthYear){
		printf("ID: %ld\n SEX: %s\n AGE: Unknown\n COUNTRY/REGION: %s/%s| INFECTION REASON: %s\n INFECTION BY: %ld\n STATE: %s\n NUMBER OF DAYS WITH ILLNESS: %d \n\n", pt.id, pt.sex,  pt.country, pt.province, pt.infection_case, pt.infected_by, pt.state, 5);
	} else {*/
		
		printf("ID: %ld\n SEX: %s\n AGE: %d\n COUNTRY/REGION: %s/%s| INFECTION REASON: %s\n INFECTION BY: %ld\n STATE: %s \n NUMBER OF DAYS WITH ILLNESS: %d \n\n", pt.id, pt.sex, age, pt.country, pt.province, pt.infection_case, pt.infected_by, pt.state, 5);
	//}
}

void RegionPrint(Region rn){
	printf(" %s| %s| %d| %f\n", rn.name, rn.capital, rn.population, rn.area);
}



