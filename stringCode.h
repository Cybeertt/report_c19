#pragma once

#include "cadeia_caracteres.h"

typedef struct stringCode {
	String code; //a aloca��o TEM DE SER EST�TICA
} StringCode;

StringCode stringCodeCreate(char* str);

void sortStringCodes(StringCode *strC, int size);
