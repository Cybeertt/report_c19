/**
 * @file mapElem.c
 * @brief Implements operations for types MapKey and MapValue.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "mapElem.h"
#include "region.h"
#include <string.h>
#include <stdio.h>


void mapKeyPrint(MapKey key) {
	printf("%s", key.code);
}

void mapValuePrint(MapValue value) {
	printRegion(value);
}

bool mapKeyEquals(MapKey key1, MapKey key2) {
	return (strcmp(key1.code, key2.code) == 0);
}
