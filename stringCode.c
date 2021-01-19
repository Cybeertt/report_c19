#include <string.h>

#include "stringCode.h"

StringCode stringCodeCreate(char *str)
{
	StringCode sc;
	strcpy(sc.code, str);
	return sc;
}

void
sortStringCodes(StringCode *strC, int size)
{	
	for (int i = 0; i < size - 1; i++) {
		StringCode *min_strC = &strC[i];
		StringCode tmp;
		for (int j = i + 1; j < size; j++) {
			if (strcmp(strC[j].code, min_strC->code) < 0) {
				min_strC = &strC[j];
			}
		}
		tmp = strC[i];
		strC[i] = *min_strC;
		*min_strC = tmp;
	}
				
}

