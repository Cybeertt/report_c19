#pragma once

#include "date.h"

typedef struct patient {
	long int id;
	char sex[6]; // {“male”,“female”}
	int birthYear;
	char country[40]; // birth country
	char province[40];
	char infectionReason[100];
	long int infectedBy; // id of the infected patient 
	Date confirmedDate;
	Date releasedDate;
	Date deceasedDate;
	char state[10]; // {“isolated,“released”,“deceased”}
} Patient;


/** Cria um objeto paciente com os dados inseridos.
 *
 *  @param[in] <id> Representa o id do paciente.
 *  @param[in] <sex> Representa o genero do paciente.
 *  @param[in] <birthYear> Representa o ano de nascimento do paciente.
 *  @param[in] <country> Representa o pais do paciente.
 *  @param[in] <region> Representa a regiao do paciente.
 *  @param[in] <infectionReason> Representa a razao da infecao do paciente.
 *  @param[in] <infectedBy> Representa o id do paciente que infetou este.
 *  @param[in] <confirmedDate> Representa a data confirmada do paciente.
 *  @param[in] <releasedDate> Representa a data em que o paciente foi libertado.
 *  @param[in] <deceasedDate> Representa a data do falecimento do paciente.
 *  @param[in] <status> Representa o estado do paciente.
 *
 *  @return Paciente criado.
 */
Patient patientCreate(long int id, char sex[6], int birthYear, char country[40],
		      char region[40], char infectionReason[100],
		      long int infectedBy, Date confirmedDate,
		      Date releasedDate, Date deceasedDate, char state[10]);

/*-------------------------------------------*/


/** Calcula a idade do paciente
 *  
 *  @param[in] pt Paciente.
 *
 *  @return Idade se paciente tiver data de nascimento registada, ou
 *  @retval -1 caso nao tenha.
 */
int patientAge(Patient pt);

/** Verifica se exite valor na coluna Infetado e retorna o valor;
 *
 *
 *  @param[in] pt Paciente.
 * 
 *  @return Patient_id se existir, ou
 *  @retval -1 se nao existir.
 *
 */
long int infectedBy(Patient pt);

/** Calcula o numero de dias em que o paciente esteve/esta infetado.
 *  Calcula o numero de dias de isolamento,
 *  caso nao exista data de morte ou de libertacao, calcula com base
 *  na data da ultima infeccao
 *  @param[in] pt Paciente.
 *  @param[in] lastInfectionDt Data da ultima infecao.
 *
 *  @return Numero de dias de isolamento, ou
 *  @retval -1 se nao estiver definida data de isolamento.
 */
int patientDaysWithIllness(Patient pt, Date lastInfectionDt);

/** Calcula o numero de dias que o paciente demorou a recuperar.
 *
 *  @param[in] pt Paciente.
 *
 *  @return Numero de dias ate a recuperacao, ou
 *  @retval -1 se nao estiver definida data de isolamento ou o paciente
 *	nao tiver recuperado.
 */
int patientRecDays(Patient pt);

/** Imprime os dados de um paciente incluindo o numero de dias de internamento.
 *  Imprime os dados no seguinte formato:
 *  {ID:<ID> SEX:<sex> AGE: <age> COUNTRY/REGION: <country> / <Region> INFECTION REASON: <reason> STATE: <state> NUMBER OF DAYS WITH ILLNESS: <value>}
 *
 * @param[in] pt com dados do paciente.
 *
 */
void patientLongPrint(Patient pt, Date lastInfectionDt);

/** Imprime os dados de um paciente.
 *  Imprime os dados do paciente no formato.
 *  {ID:<ID>SEX:<sex>AGE: <age>COUNTRY/REGION: <country> / <Region>INFECTION REASON: <reason>STATE: <state>}
 *
 *  @param[in] pt Paciente.
 *
 */
void patientShortPrint(Patient pt);
