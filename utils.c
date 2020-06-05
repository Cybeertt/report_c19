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

		char **tokenspt = split(nextline, 11, ";");

		Patient pt = PatientCreate(atol(tokenspt[0]), tokenspt[1], atoi(tokenspt[2]), tokenspt[3], tokenspt[4], tokenspt[5], atol(tokenspt[6]), DateRead(tokenspt[7]), DateRead(tokenspt[8]), DateRead(tokenspt[9]), tokenspt[10]);

		
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


void ShowPatient(PtList listPT, long int idn){	
	int size;
    listSize(listPT, &size);

	Patient pt1;
    for(int i = 0; i < size; i++){
        listGet(listPT, i, &pt1);
		if(pt1.id == idn){
			PatientPrint(pt1);
			break;
		} 
    }
}



/*-------------------------------------------*/

void Top5ArrDescSort(PtList listPT){	
	int size;
    listSize(listPT, &size);

	Patient pt1;
    for(int i = 0; i < 5; i++){
        listGet(listPT, i, &pt1);
			PatientPrint(pt1);
			break;
    }
    
}

/*-------------------------------------------*/

void arrDescSortAge(PtList listPT){
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

void arrSortGen(PtList listPT){
	int size;
    listSize(listPT, &size);

	Patient pt1, pt2;

	for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            listGet(listPT, j, &pt1);
            listGet(listPT, j+1, &pt2);
            if (strcmp(pt1.sex, pt2.sex) > 0){

                listSet(listPT, j+1, pt1, &pt2);
                listSet(listPT, j, pt2, &pt1);
            }
			//PatientPrint(pt2); //imprime lista de mulheres
        }
		//PatientPrint(pt1); //imprime lista de homens
		//PatientPrint(pt2); //imprime lista de mulheres
    }
}

void OldestArrSort(PtList listPT){	
	//printf("Female: \n\n");

	arrDescSortAge(listPT);
	//printf("MALE: \n");
	arrSortGen(listPT);
	/*printf("FEMALE: \n");
	arrSortGen(listPT);*/

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


