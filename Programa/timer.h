#ifndef TIMER_H
#define TIMER_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

#define CICLOS 32767 

/*------------------------------------------------------------------------------
Função: timerConfig
Descrição: Configura o timer A
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void timerConfig(void); 

#endif //TIMER_H