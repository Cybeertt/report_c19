#pragma once


typedef struct region {
	char name[40];
	char capital[40];
	int area;
	float population;
} Region;


/*-------------------------------------------*/

/** Funcao que cria os dados da regiao.
 * 
 *  @param[in] Representa o nome da regiao
 *  @param[in] Representa a capital da regiao
 *  @param[in] Representa o numero de pessoas de uma regiao
 *  @param[in] Representa o comprimento da area da regiao
 * 
 *  @return rn retorna a regiao criado
 */
Region RegionCreate(char name[40], char capital[40], int population, float area);

/** Funcao de impressao das regioes.
 * 
 *  @param[in] variavel do tipo struct
 * 
 *  Imprime os dados da regiao
 */
void printRegion(Region region);

/** Funcao que remove as virgulas de uma variaval do tipo inteiro.
 * 
 *  @param[in] variavel que recebe o valor sem virgulas
 *  @param[in] variavel que recebe o valor com virgulas
 * 
 *  @return 1;
 */
int RemoveCommasArea(char *dest, char *number);

/** Funcao que remove as virgulas de uma variaval do tipo real.
 * 
 *  @param[in] variavel que recebe o valor sem virgulas
 *  @param[in] variavel que recebe o valor com virgulas
 * 
 *  @return 1;
 */
float RemoveCommasPopulation(char *dest, char *number);
