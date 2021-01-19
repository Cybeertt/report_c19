#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"
#include "patient.h"
#include "list.h"
#include "loadp.h"
#include "utils.h"

void
loadPatients(char *filename, PtList *listPT, Date *lastInfectionDt)
{

	FILE *f = NULL;

	f = fopen(filename, "r");

	if (*listPT != NULL) listDestroy(listPT);
	*listPT = listCreate(10);

	if (f == NULL) {
		printf("File Not found");
		return;
	}

	char nextline[1024];

	int countPT = 0; 
	bool firstLine = true;
	Date currDate = DateCreate(0, 0, 0);


	while (fgets(nextline, sizeof(nextline), f)) {
		if (strlen(nextline) < 1)
			continue;
		/* Os ficheiros do windows tem \r\n */
		if (nextline[strlen(nextline) - 2] == '\r')
			nextline[strlen(nextline) - 2] = '\0';
		else
			nextline[strlen(nextline) - 1] = '\0';

		/*As the first line of the file contains the names of the fields
		  it should be ignored*/
		if (firstLine){
			firstLine = false;
			continue;
		} 
		char **tokenspt = split(nextline, 11, ";");
		long int id;
		if (strcmp(tokenspt[0], "") == 0) id = -1;
		else id = atol(tokenspt[0]);

		int birthYear;
	       	if (strcmp(tokenspt[2], "") == 0) birthYear = -1;
		else birthYear = atoi(tokenspt[2]);

		long int infectedBy;
	       	if (strcmp(tokenspt[6], "") == 0) infectedBy = -1;
		else infectedBy = atol(tokenspt[6]);

		Patient pt = patientCreate(id, tokenspt[1],
					   birthYear, tokenspt[3],
					   tokenspt[4], tokenspt[5],
					   infectedBy, 
					   dateRead(tokenspt[7]),
					   dateRead(tokenspt[8]),
					   dateRead(tokenspt[9]), tokenspt[10]);


		free(tokenspt); // release the memory allocated in split

		if (isDateMoreRecent(pt.confirmedDate, currDate))
			currDate = pt.confirmedDate;

		int error_code = listAdd(*listPT, countPT, pt);

		if (error_code == LIST_FULL ||
		    error_code == LIST_INVALID_RANK ||
		    error_code == LIST_NO_MEMORY ||
		    error_code == LIST_NULL) {
			printf("An error ocurred... Please try again... \n");
			return;
		}
		countPT++;
	}

	*lastInfectionDt=currDate;
	
	printf("\n\n%d patient reports were read!\n\n", countPT);
	fclose(f);
}

/*-------------------------------------------*/
