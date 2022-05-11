#ifndef LCM_H
#define LCM_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

// Estabelecendo os bits onde os dispositivos estão conectados e referências
// Porta de dado e controle do LCM (Liquid Crystal Module)
#define LCM_DADO_DIR P1DIR
#define LCM_DADO_OUT P1OUT
#define LCM_CTL_DIR P2DIR
#define LCM_CTL_OUT P2OUT

// Definição dos bits e da máscara de envio para o LCD
#define RS BIT3
#define RW BIT4
#define EN BIT5

/*------------------------------------------------------------------------------
Função: configuraLCM
Descrição: Configuração das portas conectadas ao LCM
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void configuraLCM(void);  

/*------------------------------------------------------------------------------
Função: programaLCM
Descrição: Configuração do comportamento do LCM
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void programaLCM(void);   

/*------------------------------------------------------------------------------
Função: enviaComando
Descrição: Envia um comando para o LCM
Entrada: unsigned char comando - Comando a ser enviado
Saída: ----
------------------------------------------------------------------------------*/
void enviaComando(unsigned char comando); 

/*------------------------------------------------------------------------------
Função: enviaDado
Descrição: Envia um dado para o LCM
Entrada: unsigned char dado - Dado a ser enviado
Saída: ----
------------------------------------------------------------------------------*/
void enviaDado(unsigned char dado);

/*------------------------------------------------------------------------------
Função: enviaString 
Descrição: Envia uma string para o LCM
Entrada: const char *apt - Ponteiro que passa por toda a string
Saída: ----
------------------------------------------------------------------------------*/
void enviaString (const char *apt);  

/*------------------------------------------------------------------------------
FUNCÃO: posicionaCursor
DESCRIÇÃO: Define a posição no display
ENTRADAS: número da posição e valor a ser enviado
SAÍDA: ----
------------------------------------------------------------------------------*/
void posicionaCursor (char posicao, char numero);

#endif //LCM_H