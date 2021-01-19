#pragma once

#include "map.h"

/** Efetua o carregamento de um ficheiro 
 *  csv com os dados das regioes
 *
 *  @param[in] filename nome do ficheiro csv
 *  @param[in] mapPT endereco de apontador para mapa da regioes
 *
 *  formato da impressao: {n de relatorios de pacientes foram lidos}
 *
 */
void loadCases(char *filename, PtMap *mapPT);

char** splitr(char *string, int nFields, const char *delim);





