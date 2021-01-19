#pragma once

#include "list.h"
#include "map.h"

/** Calcula e imprime a media de idade dos pacientes em cada estado.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *
 */
void Average(PtList listPT);

/** Calcula e imprime os dados dos pacientes mais velhos de cada sexo.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *
 */
void Oldest(PtList listPT);


/** Comando que imprime a proporcao dos pacientes de cada genero.
 * 
 *  @param[in] listPT endereco da lista de pacientes.
 *
 */
void genderStats(PtList listPT);

/** Mostra as estatistica dos infetados e mortos do dia indicado e do anterior.
 *  Mostra os casos de morte e isolados da data inserida
 *  e compara com os valores do dia anterior e mostra as percentagens
 *  da mudança dos dias.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param date Data inserida de procura 
 */
void growth(PtList listPT, Date date);

/** Preenche a lista de pacientes e calcula o dia da ultima infecao.
 *  Pede um nome de um ficheiro e insere os pacientes do ficheiro csv
 *  na lista *listPT,
 *  calcula a data mais recente de infeccao e coloca em lastInfectionDate
 *  e mostra o numero de pacientes.
 *
 *  @param[out] listPT endereco de apontador para lista de pacientes.
 *
 *  @param[out] lastInfectionDt data da ultima infecao
 *
 */
void LoadP(PtList *listPT, Date *lastInfectionDt);

/** Importa as Regioes do ficheiro csv.
 *
 *  @param[in] mapPT lista com os dados dos pacientes
 *  @param[out] {n regions were read!}
 *
 */
void LoadR(PtMap *mapPT);

/** Faz a limpeza dos dados da lista de pacientes e do mapa de regioes.
 * 
 *  @param[out] listPT endereco da lista de pacientes.
 *  @param[out] mapPT endereco do mapa de regioes.
 * 
 */
void clearData(PtList listPT, PtMap mapPT);

/** Mostra os dados de um paciente.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] lastInfectionDt data da ultima infecao.
 *  @param[in] idn id de um paciente.
 *
 */
void Show(PtList listPT, Date lastInfectionDt, long int idn);

/** Mostra de forma decrescente os 5 pacientes
 *  demoraram mais tempo a recuperar.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] lastInfectionDt data da ultima infecao
 *
 */
void Top5(PtList listPT, Date lastInfectionDt);


/** Mostra a sequencia de contaminacao de pacientes partindo de um id.
 *
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] idn id do paciente.
 *
 */
void follow(PtList listPT, long int idn);

/** Mostra o numero de isolados, libertados
 *  e falecidos por faixa etária.
 * 
 *  @param[in] listPT endereco da lista de pacientes.
 * 
 *  formato da impressao: {[0-15] Isolated - 200; Deceased - 0; 
 *  Released - 100 ...}
 *
 */
void patientMatrix(PtList listPT);

/** Devolve uma lista das regioes com pacientes infetados
 * 
 *  @param[in] patients Lista de clientes 
 *  @param[in] regions Lista de regioes
 *
 */
void Regions(PtList listPT,  PtMap mapPT);

/** Mostra as taxas de mortalidade, letalidade e taxa de incidentes.
 * 
 *  @param[in] listPT endereco da lista de pacientes.
 *  @param[in] mapPT endereco do mapa de regioes.
 * 
 *  formato da impressao: {[0-15] Isolated - 200; Deceased - 0; 
 *  Released - 100 ...}
 *
 */
void Report(PtList listPT, PtMap mapPT);
