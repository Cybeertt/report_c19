#pragma once

char** split(char *string, int nFields, const char *delim);

PtList copyList(PtList list);

long int Infect(Patient pt);

int CurrentAge(Patient pt);

Date recentdate(PtList listPT);

int countLeapYears(Date d);

int CurrentDays(Patient pt);

int statePatient(PtList listPT, int size, char* estadoAtual, int min, int max);

/**
* @patientMatrix estrutura que imprime o numero de isolados, libertados
* e falecidos por faixa etária 
*
* @param [PtList] listPT array com dados do ficheiro csv
*
* formato da impressao: {[0-15] Isolated - 200; Deceased - 0; 
* Released - 100 ...}
*
*/
void patientMatrix(PtList listPT);
