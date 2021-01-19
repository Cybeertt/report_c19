#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "list.h"
#include "date.h"
#include "utils.h"

Patient
patientCreate(long int id, char sex[6], int birthYear, char country[40],
	      char province[40], char infectionReason[100], long int infectedBy,
	      Date confirmedDate, Date releasedDate, Date deceasedDate,
	      char state[10])
{
	Patient pt;
	pt.id = id;
	strcpy(pt.sex, sex);
	pt.birthYear = birthYear;
	strcpy(pt.country, country);
	strcpy(pt.province, province);
	strcpy(pt.infectionReason, infectionReason);
	pt.infectedBy = infectedBy;
	pt.confirmedDate = confirmedDate;
	pt.releasedDate = releasedDate;
	pt.deceasedDate = deceasedDate;
	strcpy(pt.state, state);
	return pt;
}

/*-------------------------------------------*/

int
patientAge(Patient pt)
{
	if (pt.birthYear == -1) {
		return -1;
	} else {
		time_t curTime = time(NULL);
		struct tm *ltime = localtime(&curTime);
		int curYear = ltime->tm_year + 1900;
		return curYear - pt.birthYear;
	}
}

long int
infectedBy(Patient pt)
{
	int i = 0; 

	i = pt.infectedBy;

	if (pt.infectedBy == -1) return -1;
	else return i;
}

int
patientRecDays(Patient pt)
{
	if (!isDateNull(pt.releasedDate) && !isDateNull(pt.confirmedDate)) {
		return dayInterval(pt.confirmedDate, pt.releasedDate);
	}
	return -1;
}

int
patientDaysWithIllness(Patient pt, Date lastInfectionDt)
{
	if (isDateNull(pt.confirmedDate)) {
		return -1;
	} else if (!isDateNull(pt.releasedDate)) {
		/* o paciente recuperou */
		return patientRecDays(pt);
	} else if (!isDateNull(pt.deceasedDate)) {
		/* o paciente morreu */
		return dayInterval(pt.confirmedDate, pt.deceasedDate);
	} else {
		return dayInterval(pt.confirmedDate, lastInfectionDt);
	}
}

void
patientLongPrint(Patient pt, Date lastInfectionDt)
{
	int age = patientAge(pt);
	int day = patientDaysWithIllness(pt, lastInfectionDt);
	printf("ID: %ld\nSEX: %s\nAGE: %d\nCOUNTRY/REGION: %s/%s\n"
	       "INFECTION REASON: %s\nSTATE: %s\n"
	       "NUMBER OF DAYS WITH ILLNESS: %d\n\n", pt.id, pt.sex, age,
	pt.country, pt.province, pt.infectionReason, pt.state, day);
}

void
patientShortPrint(Patient pt)
{
	int age = patientAge(pt);
	printf("ID: %ld, SEX: %s, AGE: %d, COUNTRY/REGION: %s / %s, "
	       "STATE: %s\n",
	       pt.id, pt.sex, age, pt.country, pt.province, pt.state);
}
