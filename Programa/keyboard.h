#ifndef KEYBOARD_H
#define KEYBOARD_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

// Porta de dado e controle do teclado
#define TEC_DIR P2DIR // Define o direcional do teclado
#define TEC_IN P2IN // Define a porta de entrada do teclado
#define TEC_OUT P1OUT // Define a porta de sa�da do teclado

// Defini��o dos bits e das m�scaras para controle do teclado
#define S0 BIT0 // Define bit0 como reconhcimento das colunas 3 e 2
#define S1 BIT1 // Define bit1 como reconhcimento das colunas 1 e 0
#define LIN0 BIT0  // Define bit0 como a primeira (0) linha do teclado     
#define LIN1 BIT1  // Define bit0 como a segunda (1) linha do teclado         
#define LIN2 BIT2  // Define bit0 como a terceira (2) linha do teclado    
#define LIN3 BIT3  // Define bit0 como a quarta (3) linha do teclado    
#define OE BIT2    // Define bit2 como seletor do 74HC241  

/*------------------------------------------------------------------------------
Fun��o: confTeclado
Descri��o: Configura��o dos regitrados de acordo com o hardware
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void confTeclado (void);

/*------------------------------------------------------------------------------
Fun��o: teclado
Descri��o: Verifica pressionamento de tecla e retorna qual foi pressionada
Entrada: ----
Sa�da: NULL -> nenhuma tecla pressionada
ou
tecla -> C�digo ASCII da tecla pressionada
------------------------------------------------------------------------------*/
char teclado (void);

/*------------------------------------------------------------------------------
Fun��o: identifica_coluna
Descri��o: identifica a coluna da tecla pressionada
Entrada: ----
Sa�da: col -> n�mero da coluna
------------------------------------------------------------------------------*/
char indentifica_coluna (void);

/*------------------------------------------------------------------------------ 
Fun��o: reconheceTecla
Descri��o: Sele��o de modo e configura��o de tempo do sistema.
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void reconheceTecla(void);

#endif //KEYBOARD_H