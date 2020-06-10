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
		//PatientPrint(pt2);
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

	arrDescSortAge(listPT);

	arrSortGen(listPT);


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


