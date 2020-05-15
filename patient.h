#include <stdio.h>
#include <stdlib.h>

typedef struct date {
	unsigned int day, month, year;
} Date;

typedef struct patient{int id;char sex[6]; // {“male”,“female”}
	int birthYear;char country[40];//birth country
	char region[40];
	char infectionReason[100];
	int infectedBy; // id of the infected patient 
	Date confirmedDate;
	Date releasedDate;
	Date deceasedDate;
	char status[10];//{“isolated,“released”,“deceased”}
}Patient;

typedef struct region{
	char name[40];
	char capital[40];
	int population;
	float area;
}Region;
