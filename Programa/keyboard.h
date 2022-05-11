#ifndef KEYBOARD_H
#define KEYBOARD_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

// Porta de dado e controle do teclado
#define TEC_DIR P2DIR // Define o direcional do teclado
#define TEC_IN P2IN // Define a porta de entrada do teclado
#define TEC_OUT P1OUT // Define a porta de saída do teclado

// Definição dos bits e das máscaras para controle do teclado
#define S0 BIT0 // Define bit0 como reconhcimento das colunas 3 e 2
#define S1 BIT1 // Define bit1 como reconhcimento das colunas 1 e 0
#define LIN0 BIT0  // Define bit0 como a primeira (0) linha do teclado     
#define LIN1 BIT1  // Define bit0 como a segunda (1) linha do teclado         
#define LIN2 BIT2  // Define bit0 como a terceira (2) linha do teclado    
#define LIN3 BIT3  // Define bit0 como a quarta (3) linha do teclado    
#define OE BIT2    // Define bit2 como seletor do 74HC241  

/*------------------------------------------------------------------------------
Função: confTeclado
Descrição: Configuração dos regitrados de acordo com o hardware
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void confTeclado (void);

/*------------------------------------------------------------------------------
Função: teclado
Descrição: Verifica pressionamento de tecla e retorna qual foi pressionada
Entrada: ----
Saída: NULL -> nenhuma tecla pressionada
ou
tecla -> Código ASCII da tecla pressionada
------------------------------------------------------------------------------*/
char teclado (void);

/*------------------------------------------------------------------------------
Função: identifica_coluna
Descrição: identifica a coluna da tecla pressionada
Entrada: ----
Saída: col -> número da coluna
------------------------------------------------------------------------------*/
char indentifica_coluna (void);

/*------------------------------------------------------------------------------ 
Função: reconheceTecla
Descrição: Seleção de modo e configuração de tempo do sistema.
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void reconheceTecla(void);

#endif //KEYBOARD_H