#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "map.h"
#include "loadp.h"
#include "loadr.h"
#include "commands.h"
#include "patient.h"
#include "stringCode.h"
#include "utils.h"

void
LoadP(PtList *listPT, Date *lastInfectionDt)
{
	char filename[100];

	printf("Patients file: ");

	fgets(filename, 100, stdin);
	filename[strlen(filename) - 1] = '\0';

	/*Import data from file*/
	loadPatients(filename, listPT, lastInfectionDt);
	return;

}

void
LoadR(PtMap *mapPT)
{
	char filename[100] = "regions.csv";

	loadCases(filename, mapPT);

}


void
clearData(PtList listPT, PtMap mapPT)
{
	int size, size2, total;
	total = 0;

	if (listIsEmpty(listPT)) {
		printf("Empty List.");
	} else {
		listSize(listPT, &size);
		total += size;
		listClear(listPT);
	}

	if (mapIsEmpty(mapPT)) {
		printf("Empty Map.");
	} else {
		mapSize(mapPT, &size2);
		total += size2;
		mapClear(mapPT);
	}
	
	printf("\n\n %d records deleted from <Patients | Regions>\n\n", total);
	return;
}

/*-------------------------------------------*/

void
Show(PtList listPT, Date lastInfectionDt, long int idn)
{
	Patient pt;
	int result = getPatient(listPT, idn, &pt);

	if (result == NOT_FOUND) {
		printf("Patient with id %ld was not found\n", idn);
	} else {
		patientLongPrint(pt, lastInfectionDt);
	}

	return;
}

void
Average(PtList listPT)
{
	int avgDec = averageAge(listPT, "deceased");
	int avgRel = averageAge(listPT, "released");
	int avgIso = averageAge(listPT, "isolated");

	printf("Average Age for deceased patients: %d\n", avgDec);
	printf("Average Age for released patients: %d\n", avgRel);
	printf("Average Age for isolated patients: %d\n", avgIso);

	return;
}

void
Oldest(PtList listPT)
{

	PtList maleListPt = getOldest(listPT, "male");
	PtList femListPt = getOldest(listPT, "female");
	int femListSize, maleListSize;
	listSize(femListPt, &femListSize);
	listSize(maleListPt, &maleListSize);
	putchar('\n');
	printf("FEMALE:\n");
	for (int i = 0; i < femListSize; i++) {
		Patient pt;
	       	listGet(femListPt, i, &pt);
		printf("%d- ", i + 1);
		patientShortPrint(pt);
	}
	
	printf("MALE:\n");
	for (int i = 0; i < maleListSize; i++) {
		Patient pt;
	       	listGet(maleListPt, i, &pt);
		printf("%d- ", i + 1);
		patientShortPrint(pt);
	}
	listDestroy(&maleListPt);
	listDestroy(&femListPt);
	return;

}

void
genderStats(PtList listPT)
{
	int mPatient = numGender(listPT, "male");
	int fPatient = numGender(listPT, "female");

	int size;
	listSize(listPT, &size);

	int f = (fPatient * 100) / size;
 	int m = (mPatient * 100) / size;
	int u = 100 - (f + m);

	printf("Gender:\n");
	printf("\nPercentage of Females: %d%%", f);
	printf("\nPercentage of Males: %d%%", m);
	printf("\nPercentage of unknown: %d%%", u);
	printf("\nTotal of patients: %d\n", size);
	return;
}


void
growth(PtList listPT, Date date)
{
	if (isDateNull(date)) {
		printf("The date is invalid\n");
		return;
	}

	Date datebefore = yesterdayDate(date);
	int nextIso = numStatePatient(listPT, "isolated", date);
	int nextDec = numStatePatient(listPT, "deceased", date);
	int beforeIso = numStatePatient(listPT, "isolated", datebefore);
	int beforeDec = numStatePatient(listPT, "deceased", datebefore);

	int newInfRate;
	int newDeathRate;

	/* Para nao dividir por 0*/
	if (beforeIso == 0) {
		newInfRate = 0;
	} else {
		newInfRate = (nextIso - beforeIso) * 100 / beforeIso;
	}
		   

	if (beforeDec == 0) {
		newDeathRate = 0;
	} else {
	    newDeathRate = (nextDec - beforeDec) * 100 / beforeDec;
	}

	printf("Date: ");
	printDate(datebefore);
	putchar('\n');
	printf("Number of dead: %d\n", beforeDec);
	printf("Number of isolated: %d\n\n", beforeIso);

	printf("Date: ");
	printDate(date);
	putchar('\n');
	printf("Number of dead: %d\n", nextDec);
	printf("Number of isolated: %d\n\n", nextIso);

	printf("Rate of new infected: %d%%\n", newInfRate);
	printf("Rate of new dead: %d%%\n", newDeathRate);

	return;

}

void
follow(PtList listPT, long int idn)
{
	Patient pt;
	long int infBy;
	int found = getPatient(listPT, idn, &pt);
	if (found == NOT_FOUND) {
		printf("Patient with id %ld was not found.\n", idn);
		return;
	}
	printf("Following Patient: ");
	patientShortPrint(pt);
	infBy = pt.infectedBy;
	while (infBy != -1) {
		found = getPatient(listPT, infBy, &pt);
		if (found == NOT_FOUND) {
			break;
		}
		printf("contaminated by Patient: ");
		patientShortPrint(pt);
		infBy = pt.infectedBy;
	}
	printf("contaminated by: unknown\n");
	return;
}

void
patientMatrix(PtList listPT)
{
	int size;
	listSize(listPT, &size);
	if (listIsEmpty(listPT) == 1) {
		return;
	}

	
	printf("\t\tIsolated\tReleased\tDeceased\n");

	printf("[0-15]  \t");
	printf("%8d\t", numStateAge(listPT, size, "isolated", 0, 15));
	printf("%8d\t", numStateAge(listPT, size, "released", 0, 15));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 0, 15));
	
	printf("[16-30] \t");
	printf("%8d\t", numStateAge(listPT, size, "isolated", 16, 30));
	printf("%8d\t", numStateAge(listPT, size, "released", 16, 30));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 16, 30));

	printf("[31-45] \t");
        printf("%8d\t", numStateAge(listPT, size, "isolated", 31, 45));
	printf("%8d\t", numStateAge(listPT, size, "released", 31, 45));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 31, 45));

	printf("[46-60] \t");
	printf("%8d\t", numStateAge(listPT, size, "isolated", 46, 60));
	printf("%8d\t", numStateAge(listPT, size, "released", 46, 60));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 46, 60));

	printf("[61-75] \t");
	printf("%8d\t", numStateAge(listPT, size, "isolated", 61, 75));
	printf("%8d\t", numStateAge(listPT, size, "released", 61, 75));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 61, 75));

	printf("[76..[  \t");
	printf("%8d\t", numStateAge(listPT, size, "isolated", 76, 200));
	printf("%8d\t", numStateAge(listPT, size, "released", 76, 200));
	printf("%8d\n", numStateAge(listPT, size, "deceased", 76, 200));

	printf("\n");

	return;
}

void
Top5(PtList listPT, Date lastInfectionDt)
{
	int size;
	listSize(listPT, &size);
	partSortRecovDesc(listPT, 5);
	for (int i = 0; i < 5; i++) {
		Patient pt;
		listGet(listPT, i, &pt);
		patientLongPrint(pt, lastInfectionDt);
	}
	return;
}

void 
Regions(PtList listPT, PtMap mapPT)
{
	int size;
	Region r1;
	mapSize(mapPT, &size);
	StringCode *str;
	str = mapKeys(mapPT);

	sortStringCodes(str, size);

	for (int i = 0; i < size; i++) {
		mapGet(mapPT, str[i], &r1);
		if (nregionStatePt(listPT, r1, "isolated") > 0) {
			printf("%d\t", (nregionStatePt(listPT, r1, "isolated")));
			printf("%s\n", str[i].code);
		}
	}
	free(str);
}

void
Report(PtList listPT, PtMap mapPT)
{

	int size;
	mapSize(mapPT, &size);
	int size2;
	listSize(listPT, &size2);
	StringCode *str;
	str = mapKeys(mapPT);
	Region reg;

	FILE *f = NULL;

	f = fopen("Report.txt", "w");

	if (f == NULL) {
		printf("Report not created.\n");
		return;
	}
	float r1, r2, r3;

	for (int x = 0; x < size; x++) {
		mapGet(mapPT, str[x], &reg);

		
		int i = nregionStatePt(listPT, reg, "isolated");
		int d = nregionStatePt(listPT, reg, "deceased");
		float c = (float) nRegionPt(listPT, reg);
			
		if (c != 0) {
			r1 = (d / reg.population) * 10000;
			r2 = (i / reg.population) * 100;
			r3 = (d / c) * 100;

			fprintf(f, "\n%s -> Mortality: %f | ", 
				reg.name, r1);
			fprintf(f, "Incident Rate: %f%% | ", r2);
			fprintf(f, "lethality: %f%% ", r3);
		} 
	}
		
	printf("Report created");
	fclose(f);
	
	free(str);

}
