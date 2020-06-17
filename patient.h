#pragma once

#include "date.h"

typedef struct patient{
	long int id;
	char sex[6]; // {“male”,“female”}
	int birthYear;
	char country[40];//birth country
	char province[40];
	char infection_case[100];
	long int infected_by; // id of the infected patient 
	Date confirmed_date;
	Date released_date;
	Date deceased_date;
	char state[10];//{“isolated,“released”,“deceased”}
}Patient;

/*-------------------------------------------*/

/**
 * @PatientCreate struct Patient criacao dos dados do paciente.
 * 
 * @int <id> Representa o id do paciente
 * @char <sex> Representa o genero do paciente
 * @int <birthYear> Representa o ano de nascimento do paciente
 * @char <country> Representa o pais do paciente
 * @char <region> Representa a regiao do paciente
 * @char <infectionReason> Representa a razao da infecao do paciente
 * @int <infectedBy> Representa o id do paciente
 * @Date <confirmedDate> Representa a data confirmada do paciente
 * @Date <releasedDate> Representa a data em que o paciente foi libertado
 * @Date <deceasedDate> Representa a data do falecimento do paciente
 * @char <status> Representa o estado do paciente
 * 
 * @return pt retorna o paciente criado
 */
Patient PatientCreate(long int id, char sex[6], int birthYear, char country[40], char region[40], char infectionReason[100], long int infectedBy, Date confirmed_date, Date released_date, Date deceased_date, char state[10]);

/*-------------------------------------------*/

/**
 * @PatientPrint imprime um paciente com todos os dados incluindo a idade.
 * 
 * @param [Patient] pt com dados do paciente do ficheiro csv
 * 
 * formato da impressao: {ID:<ID>SEX:<sex>AGE: <age>COUNTRY/REGION: <country> / <Region>INFECTION REASON: <reason>STATE: <state>}
 */
void PatientPrint(Patient pt);

/**
 * @PatientTopPrint imprime um paciente com todos os dados incluindo a idade e o numero de dias que o paciente está enternado.
 * 
 * @param [Patient] pt com dados do paciente do ficheiro csv
 * 
 * formato da impressao: {ID:<ID> SEX:<sex> AGE: <age> COUNTRY/REGION: <country> / <Region> INFECTION REASON: <reason> STATE: <state> NUMBER OF DAYS WITH ILLNESS: <value>}
 */
void PatientTopPrint(Patient pt);

