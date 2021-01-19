#pragma once

#include "cadeia_caracteres.h"

typedef struct stringCode {
	String code; //a alocação TEM DE SER ESTÁTICA
} StringCode;

StringCode stringCodeCreate(char* str);

void sortStringCodes(StringCode *strC, int size);
