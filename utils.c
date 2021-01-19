#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cadeia_caracteres.h"
#include "date.h"
#include "list.h"
#include "map.h"
#include "utils.h"
#include "patient.h"

char **
split(char *string, int nFields, const char *delim)
{
	char **tokens = (char **) malloc(sizeof(char *) * nFields);
    	int index = 0;
    	int len = strlen(string);
	tokens[index++] = &string[0];

	for (int i=0; i < len; i++) {
		if (string[i] == delim[0]) {
			string[i] = '\0';
			if (i < len - 1) {
				tokens[index++] = &string[i] + 1;
			}
		}

	}
	return tokens;
}

int
getPatient(PtList listPT, long int idn, Patient *pt)
{
	int size;
	listSize(listPT, &size);

	for (int i = 0; i < size; i++) {
		Patient pt2;
		listGet(listPT, i, &pt2);
		if (pt2.id == idn) {
			*pt = pt2;
			return FOUND;
		}
	}
	/* Nao encontrou */
	return NOT_FOUND;
}

int
numStateAge(PtList listPT, int size, char* estadoAtual, int min, int max)
{

	int count = 0;
	Patient pt;	

	for (int i = 0; i < size; i++) {
		listGet(listPT, i, &pt);
		int age = patientAge(pt);

		if (strncmp(estadoAtual, pt.state, strlen(estadoAtual)) == 0 &&
		    min <= age && age <= max)
			count++;
	}
	return count;
}


int
numGender(PtList listPT, char *gender)
{
	int size;
	listSize(listPT, &size);
	int count = 0;
	for (int i = 0; i<size; i++) {
		Patient pt;
		listGet(listPT, i, &pt);
		if (strncmp(gender, pt.sex, strlen(gender)) == 0)
			count++;
	}
	return count;
}

int
averageAge(PtList listPT, char *state)
{
	int cnt, total, size;
	total = cnt = 0;
	Patient pt1;
	listSize(listPT, &size);
	for (int i = 0; i < size; i++) {
		listGet(listPT, i, &pt1);
		int age = patientAge(pt1);
		if (age == -1) {
			continue;
		} else if (strncmp(pt1.state, state, 10) == 0) {
			total += age;
			cnt++;
		}
	}
	if (cnt == 0) {
		return -1;
	} else {
		return total / cnt;
	}
}

/*-------------------------------------------*/

PtList
getOldest(PtList listPT, char *sex)
{
	int size;
	listSize(listPT, &size);
	PtList oldListPT = listCreate(10);
	/* Filter by gender flag*/

	int maxAge = -1;
	int count = 0;

	for (int i = 0; i < size; i++) {
		Patient pt1;
		listGet(listPT, i, &pt1);
		if (sex == NULL || strncmp(sex, pt1.sex, 6) == 0) {
			int newAge = patientAge(pt1);
			if (newAge > maxAge) {
				maxAge = newAge;
				/* Clear list for older patient */
				listClear(oldListPT);
				listAdd(oldListPT, 0, pt1);
				count = 1;
			} else if (newAge == maxAge) {
				listAdd(oldListPT, count, pt1);
				count++;
			}
		}
	}
	return oldListPT;
}

void
partSortRecovDesc(PtList listPT, unsigned int k)
{
	int size;
	listSize(listPT, &size);

	for (unsigned int i = 0; i < k; i++) {
		Patient ptMax;
		listGet(listPT, i, &ptMax);
		Patient pt2;
		int maxRank = i;
		for (unsigned int j = i + 1; j < size; j++) {
			listGet(listPT, j, &pt2);
			int recoveryDays = patientRecDays(pt2);
			if (recoveryDays > patientRecDays(ptMax) ||
			    (recoveryDays == patientRecDays(ptMax) &&
			     patientAge(pt2) > patientAge(ptMax))) {
				ptMax = pt2;
				maxRank = j;
			}
		}
		if (i != maxRank) {
			listSet(listPT, i, ptMax, &pt2);
			listSet(listPT, maxRank, pt2, &ptMax);
		}
	}
}


void
patientStateAtDate(Patient pt, Date date, char *state)
{
	if (!isDateNull(pt.deceasedDate) && 
	    isDateMoreRecent(date, pt.deceasedDate)) {
		strcpy(state, "deceased");
	} else if (!isDateNull(pt.releasedDate) &&
		   isDateMoreRecent(date, pt.releasedDate)) {
		strcpy(state, "released");
	} else if (isDateMoreRecent(date, pt.confirmedDate) &&
		   isDateNull(pt.deceasedDate) && isDateNull(pt.releasedDate)) {
		strcpy(state, "isolated");
	} else {
		strcpy(state, "unknown");
	}
	return;
}
	    
		
int
numStatePatient(PtList listPT, char *estado, Date date)
{
	int count = 0;
	int size;
	listSize(listPT, &size);
	for (int i = 0; i < size; i++) {
		Patient pt;
		char patientState[10];
		listGet(listPT, i, &pt);
		patientStateAtDate(pt, date, patientState);
        	if (strncmp(estado, patientState, 10) == 0)
			count++;
		 
	}

	return count;
}

int
nregionStatePt(PtList listPT, Region rn, char *estado)
{
	int size;
	listSize(listPT, &size);

	Patient pt;
	int count = 0;

	for (int i = 0; i < size; i++) {
		listGet(listPT, i, &pt);
		if (strncmp(rn.name, pt.province, strlen(rn.name)) == 0
		    && strncmp(estado, pt.state, 10) == 0)
			count++;

	}

	return count;
}

int
nRegionPt(PtList listPT, Region rn)
{
	int size;
	listSize(listPT, &size);

	Patient pt;
	int count;

	for (int i = 0; i < size; i++) {
		listGet(listPT, i, &pt);
		if (strncmp(rn.name, pt.province, strlen(rn.name)) == 0)
			count++;

	}

	return count;
}

