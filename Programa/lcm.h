#ifndef LCM_H
#define LCM_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

// Estabelecendo os bits onde os dispositivos est�o conectados e refer�ncias
// Porta de dado e controle do LCM (Liquid Crystal Module)
#define LCM_DADO_DIR P1DIR
#define LCM_DADO_OUT P1OUT
#define LCM_CTL_DIR P2DIR
#define LCM_CTL_OUT P2OUT

// Defini��o dos bits e da m�scara de envio para o LCD
#define RS BIT3
#define RW BIT4
#define EN BIT5

/*------------------------------------------------------------------------------
Fun��o: configuraLCM
Descri��o: Configura��o das portas conectadas ao LCM
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void configuraLCM(void);  

/*------------------------------------------------------------------------------
Fun��o: programaLCM
Descri��o: Configura��o do comportamento do LCM
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void programaLCM(void);   

/*------------------------------------------------------------------------------
Fun��o: enviaComando
Descri��o: Envia um comando para o LCM
Entrada: unsigned char comando - Comando a ser enviado
Sa�da: ----
------------------------------------------------------------------------------*/
void enviaComando(unsigned char comando); 

/*------------------------------------------------------------------------------
Fun��o: enviaDado
Descri��o: Envia um dado para o LCM
Entrada: unsigned char dado - Dado a ser enviado
Sa�da: ----
------------------------------------------------------------------------------*/
void enviaDado(unsigned char dado);

/*------------------------------------------------------------------------------
Fun��o: enviaString 
Descri��o: Envia uma string para o LCM
Entrada: const char *apt - Ponteiro que passa por toda a string
Sa�da: ----
------------------------------------------------------------------------------*/
void enviaString (const char *apt);  

/*------------------------------------------------------------------------------
FUNC�O: posicionaCursor
DESCRI��O: Define a posi��o no display
ENTRADAS: n�mero da posi��o e valor a ser enviado
SA�DA: ----
------------------------------------------------------------------------------*/
void posicionaCursor (char posicao, char numero);

#endif //LCM_H