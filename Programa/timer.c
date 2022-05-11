// Bibliotecas utilizadas
#include "timer.h"

//---------------------------Implementa��o de rotinas-------------------------//
void timerConfig(void) 
{
  TACTL = TASSEL_1 + // Fonte do clock: ACLK 32768Hz
    MC_1 +     // Modo de contagem: Crescente
    ID_0 +     // Divis�o 1
    TAIE+      // Ativa interrupt
    TACLR;     // Reseta contador
  TA0CCR0 = CICLOS/2; 
  
  __bis_SR_register(GIE); // Habilita interrup��o geral
}