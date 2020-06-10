#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "cadeia_caracteres.h"
#include "date.h"
#include "list.h"
#include "utils.h"
#include "patient.h"

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 

char** split(char *string, int nFields, const char *delim) {

    char **tokens = (char**) malloc(sizeof(char*) * nFields);

    int index = 0;

    int len = strlen(string);

    tokens[index++] = &string[0];

    for(int i=0; i < len; i++) {

        if( string[i] == delim[0] ) {

            string[i] = '\0';

            if( i < len - 1 ) {

                tokens[index++] = &string[i] + 1;

            }           

        }

    }

    return tokens;

}



/*-------------------------------------------*/

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

/*-------------------------------------------*/

int countLeapYears(Date d) 
{ 
    int years = d.year; 
  
    if (d.month <= 2) 
        years--; 
  
    // Calculo o numero de anos
    return years / 4 - years / 100 + years / 400; 
} 

/*-------------------------------------------*/

int CurrentDays(Patient pt){
	int days;

	time_t s;
	struct tm* current_time;

	s = time(NULL);

	current_time = localtime(&s);

	Date nowDate = DateCreate(current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900);

	int current = nowDate.year*365 + nowDate.day;	

	for (int i=0; i<nowDate.month - 1; i++) 
        	current += monthDays[i];

		current += countLeapYears(nowDate);	

	Date dt, dt1, dt2;

	dt = DateCreate(pt.confirmed_date.day, pt.confirmed_date.month, pt.confirmed_date.year);

	dt1 = DateCreate(pt.released_date.day, pt.released_date.month, pt.released_date.year);

	dt2 = DateCreate(pt.deceased_date.day, pt.deceased_date.month, pt.deceased_date.year);

	int time = dt.year*365 + dt.day;

	for (int i=0; i<dt.month - 1; i++) 
        	time += monthDays[i];

		time += countLeapYears(dt);	

	int time2 = dt1.year*365 + dt1.day;

	int time3 = dt2.year*365 + dt2.day;

	if (!time2 && !time3) {

		return current - time;

		 
	} else if (!time3) {
		for (int i=0; i<dt1.month - 1; i++) 
        	time2 += monthDays[i];

		time2 += countLeapYears(dt1);	

		return time2 - time;
	}
	else if (!time2) {
		for (int i=0; i<dt2.month - 1; i++) 
        	time3 += monthDays[i];

		time3 += countLeapYears(dt2);	


		return time3 - time;
	}

	//return dt.day;
}

/*-------------------------------------------*/

int StatePatient(PtList listPT){

	int size;
    listSize(listPT, &size);

	String estadoAtual = { 0 };

	Patient pt;
	int count = 0;
	
	for(int i = 0; i < size; i++){
		listGet(listPT, i, &pt);
		
		if (strcmp(estadoAtual, pt.state) == 0) {
			continue;
		}
		
		count++;
		strcpy(estadoAtual, pt.state);
	}

	return count;
}

/*
void patientMatrix(PtList listPT){	

	Patient pt;
	
	char *staten = "isolated";
	int numstatus, size, currentRank = 0;
	char *currentState = pt.state;

	listSize(listPT, &size);

	while (currentRank < size){
		listGet(listPT, currentRank, &pt);
		numstatus = StatePatient(listPT, currentState, currentRank, &currentRank);	
	};
	
	printf("The state %s had %d pacient\n", staten, numstatus);
	
	printf("\n");
}

void Report(char *filename, PtList *listPT){

	FILE *f = NULL;

	f = fopen(filename, "r");

	if (f == NULL) {
		printf("An error ocurred... It was not possible to open the file %s ...\n", filename);
		return;
	}

	printf("<country_ name>\n Mortality:<value> ");
	printf("IncidentRate:<value> ");
	printf("Lethality: <value>\n\n");
	printf("<region>\n Mortality:<value> ");
	printf("IncidentRate:<value> ");
	printf("Lethality: <value>\n\n");
	printf("<country_ name>\n Mortality:<value> ");
	printf("IncidentRate:<value> ");
	printf("Lethality: <value>\n\n");
	printf("-------------------------------------------\n\n");
}
*/

