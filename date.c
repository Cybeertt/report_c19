#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"


void
printDate(Date dt1)
{
	printf("%02d/%02d/%04d", dt1.day, dt1.month, dt1.year);
}

Date
DateCreate(int day, int month, int year)
{
	Date dt;
	dt.day = day;
	dt.month = month;
	dt.year = year;
	return dt;
}

int
isLeapYear(int year)
{
	if (year % 4) {
		return 0;
	} else if (year % 100) {
		return 1;
	} else if (year % 400) {
		return 0;
	} else {
		return 1;
	}
}

int
dayOfYear(Date dt1)
{
	int nday = 0;
	int leapYearFlg = isLeapYear(dt1.year);
	for (enum month m = Jan; m < dt1.month; m++) {
		nday += daysOfMonth(m, leapYearFlg);
	}
	return nday + dt1.day;
}

int
daysOfMonth(int month, int leapYearFlg)
{
	switch (month) {
	    case Jan:
	    case Mar:
	    case May:
	    case Jul:
	    case Aug:
	    case Oct:
	    case Dec:
		return 31;
	    case Feb:
		if (leapYearFlg) return 29;
		else return 28;
	    default:
		return 30;
	}
}
	

int
dayInterval(Date dt1, Date dt2)
{
	int dtInterval = 0;
	if (isDateMoreRecent(dt1, dt2))
		return -1 * dayInterval(dt2, dt1);
	for (int year = dt1.year; year < dt2.year; year++) {
		if (year % 4 == 0) dtInterval += 366;
		else dtInterval += 365;
	}
	return dtInterval + dayOfYear(dt2) - dayOfYear(dt1);
}

Date
yesterdayDate(Date dt)
{
	Date res = dt;
	if (res.day > 1) {
		res.day = res.day - 1;
	} else if (res.month != Jan) {
		/* Primeiro dia do mes */
		res.month = res.month - 1;
		int leapFlg = isLeapYear(res.year);
		res.day = daysOfMonth(res.month, leapFlg);
	} else {
		/* primeiro dia do ano*/
		res.year = res.year - 1;
		res.month = Dec;
		res.day = 31;
	}
	return res;
}

	
Date
dateRead(char* dateStr)
{
	int day, month, year;
	day = month = year = 0;
	if (strlen(dateStr) == 0) {
		return DateCreate(0, 0, 0);
	} else {
		sscanf(dateStr, "%2d/%2d/%4d", &day, &month, &year);
		return DateCreate(day, month, year);
	}
}

int
isDateMoreRecent(Date dt1, Date dt2)
{
	if (dt1.year > dt2.year) {
		return 1;
	} else if (dt1.year == dt2.year && dt1.month > dt2.month) {
		return 1;
	} else if (dt1.year == dt2.year && dt1.month == dt2.month &&
		   dt1.day > dt2.day) {
		return 1;
	} else {
		return 0;
	}
}

int
isDateNull(Date dt)
{
	if (dt.year == 0 && dt.month == 0 && dt.day == 0) return 1;
	else return 0;
}
