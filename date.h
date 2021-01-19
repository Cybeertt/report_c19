#pragma once

typedef struct date {
	unsigned int day, month, year;
} Date;

enum month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

/** Cria um objeto data a partir do dia, mes e ano.
 *
 *  @param[in] day
 *  @param[in] month
 *  @param[in] year
 *
 *  @return objeto do tipo data.
 */
Date DateCreate(int day, int month, int year);

/*-------------------------------------------*/

/** Cria um objeto data a partir de uma string no formato dd/mm/yyyy.
 *
 *  @param[in] dateStr
 *
 *  @returns data correspondente.
 */
Date dateRead(char* dateStr);

/** Verifica se a data dt1 e mais recente que a dt2.
 *
 *  @param[in] dt1
 *  @param[in] dt2
 *
 *  @retval 1 se data dt1 e mais recente, ou
 *  @retval 0 caso contrario.
 */
int isDateMoreRecent(Date dt1, Date dt2);

/** Verifica se a data dt e nula.
 *
 *  @param[in] dt
 *
 *  @retval 1 se a data dt for nula, ou
 *  @retval 0 caso contrario.
 */
int isDateNull(Date dt);

/** Calcula o intervalo de dias entre a data dt1 e a data dt2.
 *
 *  @param[in] dt1
 *  @param[in] dt2
 *
 *  @return intervalo entre datas.
 */
int dayInterval(Date dt1, Date dt2);

/** Calcula a data do dia anterior.
 *
 *  @param[in] dt
 *
 *  @return data do dia anterior.
 */
Date yesterdayDate(Date dt);

/** Calcula o dia do ano a que corresponde a data.
 *
 *  @param[in] dt1
 *
 *  @return Dia do ano a que corresponde a data.
 */
int dayOfYear(Date dt1);

/** Verifica se o ano e bissexto.
 *
 *  @param[in] year
 *
 *  @retval 1 se for ano bissexto, ou
 *  @retval 0 se nao for.
 */
int isLeapYear(int year);

/** Calcula o numero de dias de um determinado mes.
 *
 *  @param[in] month
 *  @param[in] leapYearFlg flag que indica se e um ano bissexto.
 *
 *  @return Numero de dias do mes.
 */
int daysOfMonth(int month, int leapYearFlg);

/** Imprime a data.
 *  Imprime a data no formato: dd/mm/yyyy
 *
 *  @param[in] dt1
 *
 */
void printDate(Date dt1);
