#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "region.h"

Region
RegionCreate(char name[40], char capital[40], int area, float population)
{
	Region rn;
	strcpy(rn.name, name);
	strcpy(rn.capital, capital);
	rn.area = area;
	rn.population = population;
	return rn;
}

void
printRegion(Region region)
{
	printf("%s | %s | %d | %f \n", region.name, region.capital,
		 region.area, region.population);
}

int
RemoveCommasArea(char *dest, char *number)
{
	char *i, *j;
	i = number;
	j = dest;
	while (*i != '\0') {
		if (*i != ',') {
			*j = *i;
			j++;
		}
		i++;
	}
	*j = '\0';
	return 1;
}


float
RemoveCommasPopulation(char *dest, char *number)
{
	
	char *i, *j;
	i = number;
	j = dest;
	while (*i != '\0') {
		if (*i != ',') {
			*j = *i;
			j++;
		}
		i++;
	}
	*j = '\0';
	return 1;
}


