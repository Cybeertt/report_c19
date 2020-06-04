#pragma once

char** split(char *string, int nFields, const char *delim);

/**
* @loadPatients estrutura  que efetua o carregamento de um ficheiro 
* csv com todos os dados dos pacientes d
*
* @param [char] *filename nome do ficheiro csv
* @param [PtList] *listPT array com dados do ficheiro csv
*
* formato da impressao: {n de relatorios de pacientes foram lidos}
*
*/
void loadPatients(char *filename, PtList *listPT);

/*int CurrentAge(PtList listPT, int birthYear, int startAge);


int RangeAge(PtList listPT, int startAge, int *endAge);*/

/**
* @ShowPatient estrutura que imprime o id com os dados do paciente
*
* @param [PtList] listPT array com dados do ficheiro csv
*
* formato da impressao: {ID:<ID>SEX:<sex>AGE: <age>COUNTRY/REGION: <country> / <Region>INFECTION REASON: <reason>STATE: <state>NUMBER OF DAYS WITH ILLNESS: <value>}
*
*/
void ShowPatient(PtList listPT);

void arrDescSort(PtList listPT);

/**
* @Top5ArrDescSort estrutura que imprime o top 5 o maior numero de 
* dias que os pacientes demoram a curar por ordem decrescente 
*
* @param [PtList] listPT array com dados do ficheiro csv
*
* formato da impressao: {ID:<ID>SEX:<sex>AGE: <age>COUNTRY/REGION: <country> / <Region>INFECTION REASON: <reason>STATE: <state>NUMBER OF DAYS WITH ILLNESS: <value>}
*
*/
void Top5ArrDescSort(PtList listPT);

void Female(PtList listPT);

/**
* @OldestArrSort estrutura que imprime idade dos pacientes por ordem
* decrescente por genero
*
* @param [PtList] listPT array com dados do ficheiro csv
*
* formato da impressao: {Female: 1- ID:<ID>, SEX: <sex>, AGE: <age>,COUNTRY/REGION: <country> / <Region>,STATE: <state> ...}
*
*/
void OldestArrSort(PtList listPT);

int StatePatient(PtList listPT, char* state, int startRank, int *endRank);

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