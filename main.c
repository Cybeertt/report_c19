﻿/* PROJETO  ATAD 2019-20
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
#include "info.h"
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
		
			/*Import data from file*/
			LoadP(&listPT);		

			//listPrint(listPT);

		}
		else if (equalsStringIgnoreCase(command, "LOADR")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			printf("Comando LOADR nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
		
			clearData(listPT);

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

			Show(listPT);

		}
		else if (equalsStringIgnoreCase(command, "TOP5")) {

			Top5(listPT);
				
			printf("Comando TOP5 nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "OLDEST")) {

			OldestArrSort(listPT);

		}
		else if (equalsStringIgnoreCase(command, "GROWTH")) {
			printf("Comando GROWTH nao implementado.\n");
		}	
		else if (equalsStringIgnoreCase(command, "MATRIX")) {

			patientMatrix(listPT);
			
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
	listDestroy(&listPT);

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
