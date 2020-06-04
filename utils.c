#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "list.h"
#include "utils.h"
#include "patient.h"

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

void loadPatients(char *filename, PtList *listPT){

	FILE *f = NULL;

	f = fopen(filename, "r");

	if (f == NULL) {
		printf("An error ocurred... It was not possible to open the file %s ...\n", filename);
		return;
	}

	char nextline[1024];

	int countPT = 0; 
	bool firstLine = true;

	*listPT = listCreate(10);

	while (fgets(nextline, sizeof(nextline), f)) {
		if (strlen(nextline) < 1)
			continue;

		/*As the first line of the file contains the names of the fields it should be ignored*/
		if (firstLine){
			firstLine = false;
			continue;
		} 

		char **tokenspt = split(nextline, 16, ";");

		//Date dt = DateCreate(atoi(tokensdt[0]), atoi(tokensdt[1]), atoi(tokensdt[2]));

		Patient pt = PatientCreate(atoi(tokenspt[0]), tokenspt[1], atoi(tokenspt[2]), tokenspt[3], tokenspt[4], tokenspt[5], atoi(tokenspt[6]), atoi(tokenspt[7]), atoi(tokenspt[8]), atoi(tokenspt[9]), tokenspt[10]);

		// free(tokensdt);  release of the memory alocated in function split
		
		free(tokenspt); // release of the memory alocated in function split

		int error_code = listAdd(*listPT, countPT, pt);

		if (error_code == LIST_FULL ||error_code == LIST_INVALID_RANK || 
		    error_code == LIST_NO_MEMORY || error_code == LIST_NULL){
			printf("An error ocurred... Please try again... \n");
			return;
		}
		countPT++;
	}
	
	printf("\n\n%d patient reports were read!\n\n", countPT);
	fclose(f);
}

/*-------------------------------------------*/

void ShowPatient(PtList listPT){	
	int size;
	long int idn;
    listSize(listPT, &size);
	
	Patient pt;

	//int age = CurrentAge(pt);	

    printf("Escreva o ID do paciente: ");
    scanf("%ld", &idn);
	for (int i = 0; i < 1; i++) {
		if (pt.id = idn) {
		  printf("ID: %ld\n SEX: %s\n AGE: Unknown\n COUNTRY/REGION: %s/%s| INFECTION REASON: %s\n INFECTION BY: %ld\n \n\n", pt.id, pt.sex,  pt.country, pt.province, pt.infection_case, pt.infected_by);
		}
	}
}

void arrDescSort(PtList listPT){
	int size;
    listSize(listPT, &size);

	Patient pt1, pt2;
	int max;
    for(int i = 0; i < size; i++){
		max = i;
        for(int j = i; j < size; j++){
            listGet(listPT, max, &pt1);
            listGet(listPT, j, &pt2);
            if ( pt1.birthYear > pt2.birthYear){
				max = j;
            }
        }
		listGet(listPT, i, &pt1);
		listSet(listPT, max, pt1, &pt2);
        listSet(listPT, i, pt2, &pt1);
    }
}
/*-------------------------------------------*/

void Top5ArrDescSort(PtList listPT){	
	int size;
    listSize(listPT, &size);
	
	Patient pt;

    /*printf("Escreva o ID do paciente: ");
    fgets(idn, sizeof(idn), stdin);*/
	for (int i = 0; i < 5; i++) {
		PatientPrint(pt);
	}
}

/*-------------------------------------------*/

void Female(PtList listPT){
	int size;
    listSize(listPT, &size);
	
	
	int agemax;
	Patient pt1, pt2;
	//Listar as pessoas do sexo feminino
	if(pt1.sex == "female" && pt2.sex == "female"){
		printf("FEMALES:\n");
		for(int i = 0; i < size; i++){
			agemax = i;
		    for(int j = i; j < size; j++){
		        listGet(listPT, agemax, &pt1);
		        listGet(listPT, j, &pt2);
		        if ( pt1.birthYear > pt2.birthYear){
					agemax = j;
		        }
		    }
			listGet(listPT, i, &pt1);
			listSet(listPT, agemax, pt1, &pt2);
		    listSet(listPT, i, pt2, &pt1);
			PatientPrint(pt1);
		}
	}
}

void Male(PtList listPT){
	int size;
    listSize(listPT, &size);
	
	
	int agemax;
	Patient pt1, pt2;

	//Listar as pessoas do sexo masculino 
	if(pt1.sex == "male" && pt2.sex == "male"){
		printf("\n\nMALES:\n");
		for(int i = 0; i < size; i++){
		    agemax = i;
		    for(int j = i; j < size; j++){
		        listGet(listPT, agemax, &pt1);
		        listGet(listPT, j, &pt2);
		        if ( pt1.birthYear > pt2.birthYear){
					agemax = j;
		        }
		    }
			listGet(listPT, i, &pt1);
			listSet(listPT, agemax, pt1, &pt2);
		    listSet(listPT, i, pt2, &pt1);
		}
	}
}

void OldestArrSort(PtList listPT){	
	Female(listPT);
	Male(listPT);
}

/*-------------------------------------------*/

int StatePatient(PtList listPT, char* state, int startRank, int *endRank){
	Patient pt;
	int sum = 0, count = 0;
	listGet(listPT, startRank, &pt);
	while(pt.state == state){
		count++;
		int error = listGet(listPT, ++startRank, &pt);
		if (error != LIST_OK) break;
	}
	*endRank += count;
	return count;
	/*for(int i = 0; i < size; i++){
		int error = listGet(listPT, i, &pt);
		if (error != LIST_OK)
			return -1;
		if(pt.state == state)
			;
	}
	count++;*/
}

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

void Report(){
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


