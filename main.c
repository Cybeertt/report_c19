/* PROJETO  ATAD 2019-20
* Identificacao dos Alunos:
*
*      Numero: 190200040 | Nome: Rafael Bernardino Palma
*      Numero: 180221052 | Nome: Antonio Pedro Guerreiro Milheiras
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "cadeia_caracteres.h"
#include "commands.h"
#include "date.h"
#include "list.h"
#include "loadp.h"
#include "utils.h"

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();
//...

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {

	/* declaracao de variaveis */

	PtList listPT = NULL;	

	PtMap mapPT = NULL;	
	Date lastInfectionDt = DateCreate(0, 0, 0);

	/* interpretador de comandos */
	char command[255];
	int quit = 0;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		printCommandsMenu();
		fflush(stdin);
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'*/
		command[strlen(command) - 1] = '\0';
		/* capturar o comando */

		char *instruction = strtok(command, " ");

		if (instruction == NULL) continue;

		if (equalsStringIgnoreCase(instruction, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */

		} else if (equalsStringIgnoreCase(instruction, "LOADP")) {
		
			/*Import data from file*/
			LoadP(&listPT, &lastInfectionDt);		
			//listPrint(listPT);

		} else if (equalsStringIgnoreCase(instruction, "LOADR")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			LoadR(&mapPT);

		} else if (equalsStringIgnoreCase(instruction, "CLEAR")) {
			clearData(listPT, mapPT);

		} else if (equalsStringIgnoreCase(instruction, "AVERAGE")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			Average(listPT);

		} else if (equalsStringIgnoreCase(instruction, "FOLLOW")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			long int idn;
			instruction = strtok(NULL, " ");
			if (instruction == NULL) {
				printf("Usage: FOLLOW patient_id");
				continue;
			}
			sscanf(instruction, "%ld", &idn);
			follow(listPT, idn);

		} else if (equalsStringIgnoreCase(instruction, "SEX")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			genderStats(listPT);

		} else if (equalsStringIgnoreCase(instruction, "SHOW")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			long int idn;
			instruction = strtok(NULL, " ");
			if (instruction == NULL) {
				printf("Usage: SHOW patient_id");
				continue;
			}
			sscanf(instruction, "%ld", &idn);
			Show(listPT, lastInfectionDt, idn);

		} else if (equalsStringIgnoreCase(instruction, "TOP5")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			Top5(listPT, lastInfectionDt);

		} else if (equalsStringIgnoreCase(instruction, "OLDEST")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			Oldest(listPT);

		}
		else if (equalsStringIgnoreCase(instruction, "GROWTH")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			instruction = strtok(NULL, " ");
			if (instruction == NULL) {
				printf("Usage: GROWTH date");
				continue;
			}
			Date date = dateRead(instruction);
			growth(listPT, date);
			
		}	
		else if (equalsStringIgnoreCase(instruction, "MATRIX")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			patientMatrix(listPT);

		} else if (equalsStringIgnoreCase(instruction, "REGIONS")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			if (mapIsEmpty(mapPT)) {
				printf("No region data available...\n");
				continue;
			}
			Regions(listPT, mapPT);

		} else if (equalsStringIgnoreCase(instruction, "REPORT")) {
			if (listIsEmpty(listPT)) {
				printf("No patient data available...\n");
				continue;
			}
			if (mapIsEmpty(mapPT)) {
				printf("No region data available...\n");
				continue;
			}
			Report(listPT, mapPT);

		} else {
			printf("%s : Comando nao encontrado.\n", instruction);
		}
	}

	/* libertar memória e apresentar mensagem de saída. */
	listDestroy(&listPT);

	mapDestroy(&mapPT);

	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	return (strcasecmp(str1, str2) == 0);
}


void printCommandsMenu() {
	printf("\n===================================================================================");
	printf("\n                          PROJECT: COVID-19                    ");
	printf("\n===================================================================================");
	printf("\nA. Base Commands (LOADP, LOADR,CLEAR).");
	printf("\nB. Simple Indicators and searchs (AVERAGE, FOLLOW, GROWTH, MATRIX, OLDEST, SEX, SHOW, TOP5).");
	printf("\nC. Advanced indicator (REGIONS, REPORT)");
	printf("\nD. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}
