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
 * @param [in] <id> Representa o id do paciente
 * @param [in] <sex> Representa o genero do paciente
 * @param [in] <birthYear> Representa o ano de nascimento do paciente
 * @param [in] <country> Representa o pais do paciente
 * @param [in] <region> Representa a regiao do paciente
 * @param [in] <infectionReason> Representa a razao da infecao do paciente
 * @param [in] <infectedBy> Representa o id do paciente
 * @param [in] <confirmedDate> Representa a data confirmada do paciente
 * @param [in] <releasedDate> Representa a data em que o paciente foi libertado
 * @param [in] <deceasedDate> Representa a data do falecimento do paciente
 * @param [in] <status> Representa o estado do paciente
 * 
 * @param [out] pt retorna o paciente criado
 */
Patient PatientCreate(long int id, char sex[6], int birthYear, char country[40], char region[40], char infectionReason[100], long int infectedBy, Date confirmed_date, Date released_date, Date deceased_date, char state[10]);

/*-------------------------------------------*/

/**
 * @PatientPrint imprime um paciente com todos os dados incluindo a idade.
 * 
 * @param [in] pt com dados do paciente do ficheiro csv
 * 
 * @param [out] {ID:<ID>SEX:<sex>AGE: <age>COUNTRY/REGION: <country> / <Region>INFECTION REASON: <reason>STATE: <state>}
 */
void PatientPrint(Patient pt);

/**
 * @PatientTopPrint imprime um paciente com todos os dados incluindo a idade e o numero de dias que o paciente está enternado.
 * 
 * @param [in] pt com dados do paciente do ficheiro csv
 * 
 * @param [out] {ID:<ID> SEX:<sex> AGE: <age> COUNTRY/REGION: <country> / <Region> INFECTION REASON: <reason> STATE: <state> NUMBER OF DAYS WITH ILLNESS: <value>}
 */
void PatientTopPrint(Patient pt);

