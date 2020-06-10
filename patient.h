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

typedef struct region{
	char name[40];
	char capital[40];
	int population;
	float area;
}Region;

/**
 * @DateCreate struct Date criacao dos dados da data.
 * 
 * @int <day> Representa o dia da data
 * @int <month> Representa o genero do paciente
 * @int <year> Representa o ano
 * 
 * @return dt retorna a data criada
 */
Date DateCreate(int day, int month, int year);

/**
 * @DateCreate struct Date criacao dos dados da data.
 * 
 * @int <day> Representa o dia da data
 * @int <month> Representa o genero do paciente
 * @int <year> Representa o ano
 * 
 * @return DateCreate(d/m/y) retorna a data criado
 */
Date DateRead(char* dateStr);

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

/**
 * @RegionCreate struct Region criacao dos dados da regiao.
 * 
 * @char <name> Representa o nome da regiao
 * @char <capital> Representa a capital da regiao
 * @int <population> Representa o numero de pessoas de uma regiao
 * @float <area> Representa o comprimento da area da regiao
 * 
 * @return rn retorna a regiao criado
 */
Region RegionCreate(char* name, char* capital, int population, float area);

void DatePrint(Date dt);


int countLeapYears(Date d); 


int PassedDays(Patient pt1);

int CurrentAge(Patient pt);

long int Infect(Patient pt);


void PatientPrint(Patient pt);


void RegionPrint(Region rn);

