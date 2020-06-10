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
#include "list.h"
#include "loadp.h"
#include "sort.h"
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

	/* interpretador de comandos */
	String command;
	int quit = 0;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';
        
		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */				
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			//LoadP(listPT); 

			char filename[100] =  "patients.csv";

			/*Import data from file*/
			loadPatients(filename, &listPT);

			//listPrint(listPT);


			//listDestroy(&listPT);			

			printf("Comando LOADP nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADR")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			printf("Comando LOADR nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			printf("Comando CLEAR nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "AVERAGE")) {
			printf("Comando AVERAGE nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "FOLLOW")) {
			printf("Comando FOLLOW nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SEX")) {
			printf("Comando SEX nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {

			long int idn;

			char filename[100] =  "patients.csv";

			/*Import data from file*/
			loadPatients(filename, &listPT);

			printf("Escreva o id do paciente: ");
			scanf("%ld", &idn);

			ShowPatient(listPT, idn);

			listDestroy(&listPT);
			printf("Comando SHOW nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "TOP5")) {

			char filename[150] =  "patients.csv";

			/*Import data from file*/
			loadPatients(filename, &listPT);

			Top5ArrDescSort(listPT);
				

			printf("Comando TOP5 nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "OLDEST")) {

			char filename[150] =  "patients.csv";

			/*Import data from file*/
			loadPatients(filename, &listPT);

			OldestArrSort(listPT);

			listPrint(listPT);

			printf("Comando OLDEST nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "GROWTH")) {
			printf("Comando GROWTH nao implementado.\n");
		}	
		else if (equalsStringIgnoreCase(command, "MATRIX")) {
			
			printf("Comando MATRIX nao implementado.\n");

		}
		else if (equalsStringIgnoreCase(command, "REGIONS")) {
			printf("Comando REGIONS nao implementado.\n");
		}	
		else if (equalsStringIgnoreCase(command, "REPORT")) {
			printf("Comando REPORT nao implementado.\n");
		}
		else {
			printf("%s : Comando nao encontrado.\n", command);
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de modificacao para obter uma comparacao
	* 'case insensitive' */
	return (strcmp(str1, str2) == 0);
}

void printCommandsMenu() {
	printf("\n===================================================================================");
	printf("\n                          PROJECT: COVID-19                    ");
	printf("\n===================================================================================");
	printf("\nA. Base Commands (LOADP, LOADR,CLEAR).");
	printf("\nB. Simple Indicators and searchs (AVERAGE, FOLLOW, MATRIX, OLDEST, RELEASED, SEX, SHOW, TOP5).");
	printf("\nC. Advanced indicator (REGIONS, REPORTS)");
	printf("\nD. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}
