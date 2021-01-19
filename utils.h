#pragma once

#define FOUND 1
#define NOT_FOUND 0

#include "region.h"

/** Calcula a media da idade dos paciente num estado.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] state estado do paciente.
 *
 *  @return idade media dos pacientes no estado, ou
 *  @retval -1 se nao existem pacientes nesse estado.
 */
int averageAge(PtList listPT, char *state);

char **split(char *string, int nFields, const char *delim);

/** Procura o paciente a partir do id numa lista.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] idn numero identificador do paciente.
 *  @param[out] pt endereco do objeto Patient.
 *
 *  @retval FOUND se paciente foi encontrado na lista.
 *  @retval NOT_FOUND caso nao tenha sido encontrado.
 *
 */
int getPatient(PtList listPT, long int idn, Patient *pt);

/** conta o numero de pacientes num estado por faixa etaria.
 *
 * @param[in] listPT endereco da lista de pacientes.
 * @param[in] size tamanho da lista.
 * @param[in] estadoAtual estado atual que vai ser contado.
 * @param[in] min idade minima.
 * @param[in] max idade maxima.
 *
 * @return numero de pacientes num estado da faixa etaria.
 *
 */
int numStateAge(PtList listPT, int size, char* estadoAtual, int min, int max);

/** Calcula o numero de pacientes num determinada estado.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] estadoAtual estado dos pacientes.
 *  @param[in] date data de referencia.
 *
 *  @return numero de pacientes no estado.
 */
int numStatePatient(PtList listPT, char *estadoAtual, Date date);

/** Encontra os pacientes mais velhos na lista do sexo sex.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] sex genero dos pacientes.
 *
 *  @return lista dos paciente mais velhos do sexo sex, ou
 *  @return lista dos pacientes mais velhos caso sex seja invalido ou NULL.
 */
PtList getOldest(PtList listPT, char *sex);

/** Calcula o numero de pacientes de um genero.
 * 
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] gender genero dos pacientes.
 *
 *  @return numero de pacientes do genero gender.
 */
int numGender(PtList listPT, char* gender);

/** Ordena decrescentemente parcialmente k pacientes por tempo de recuperacao.
 *  Ordena os k pacientes com maior tempo de recuperacao pondo-os no inicio
 *  da lista. A idade dos pacientes e usada para desempatar
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] k numero de pacientes a ordenar.
 */
void partSortRecovDesc(PtList listPT, unsigned int k);

/** Calcula estado do paciente por regiao.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] rn Region.
 *  @param[in] state estado do paciente.
 *
 *  @return total de estados por regiao.
 */
int nregionStatePt(PtList listPT, Region rn, char *estado);

/** Calcula o numero de casos por regiao.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] rn Region.
 *
 *  @return a media total de regioes por estado.
 */
int nRegionPt(PtList listPT, Region rn);

