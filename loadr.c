#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadeia_caracteres.h"
#include "stringCode.h"
#include "date.h"
#include "map.h"
#include "loadr.h"
#include "region.h"

void
loadCases(char *filename, PtMap * mapPT)
{

	FILE *f = NULL;

	f = fopen(filename, "r");
	if (f == NULL) {
		printf("An error ocurred... It was not possible"
		       "to open the file %s ...\n", filename);
		return;
	}

	char nextline[1024];

	int countRN = 0;
	bool firstLine = true;

	if (*mapPT != NULL) mapDestroy(mapPT);
	*mapPT = mapCreate(10);
	char output[20];
	char output2[20];

	while (fgets(nextline, sizeof(nextline), f)) {
		if (strlen(nextline) < 1)
			continue;
		
		/*
		 * As the first line of the file contains the names of the fields
		 * it should be ignored 
		 */
		if (firstLine) {
			firstLine = false;
			continue;
		}

		char **tokensrn = splitr(nextline, 4, ";");
		
		/*
		 * long int p = atol(tokensrn[2]);
		 * 
		 * long int a = atol(tokensrn[3]);
		 */

		RemoveCommasArea(output, tokensrn[2]);
		RemoveCommasPopulation(output2, tokensrn[3]);

		MapKey key = stringCodeCreate(tokensrn[0]);

		Region rn = RegionCreate(tokensrn[0], tokensrn[1],
		atoi(output), atof(output2));



		free(tokensrn);	// release of the memory alocated in split

		int error_code = mapPut(*mapPT, key, rn);

		if (error_code == MAP_NULL || error_code == MAP_UNKNOWN_KEY
		    || error_code == MAP_NO_MEMORY
		    || error_code == MAP_NULL) {
			printf
			    ("An error ocurred... Please try again... \n");
			return;
		}
		countRN++;
	}

	printf("\n\n%d regions were read!\n\n", countRN);
	fclose(f);
}

/*-------------------------------------------*/

char **
splitr(char *string, int nFields, const char *delim)
{

	char **tokens = (char **) malloc(sizeof(char *) * nFields);

	int index = 0;

	int len = strlen(string);

	tokens[index++] = &string[0];

	for (int i = 0; i < len; i++) {

		if (string[i] == delim[0]) {

			string[i] = '\0';

			if (i < len - 1) {

				tokens[index++] = &string[i] + 1;

			}

		}

	}

	return tokens;

}

/*
 * void LoadR(PtMap *mapPT){
 * 
 * char filename[100] = "regions.csv";
 * 
 * printf("Error");
 * 
 * loadCases(filename, mapPT);
 * 
 * }
 */
