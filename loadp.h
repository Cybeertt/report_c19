#pragma once

/** Efetua o carregamento de um ficheiro csv com todos os dados dos pacientes.
 *
 *  @param[in]  filename nome do ficheiro csv.
 *  @param[out] listPT endereco do apontador para a lista de pacientes.
 *  @param[out] lastInfectionDt data da ultima infecao.
 * 
 *
 */
void loadPatients(char *filename, PtList *listPT, Date *lastInfectionDt);
