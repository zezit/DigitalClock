/******************************************************************************
   CEFET-MG - Eletrônica - 3B
   Alunos: Ana Cecília Araújo
           José Victor Mendes Dias
   Data: 30/01/2021
   Projeto Final - SDIII

                            MODOS DO DISPLAY LCD

                ------------------------------------------------
  RELÓGIO       | R           0  0 : 0  0 : 0  0               |                    
                ------------------------------------------------
                ------------------------------------------------
  CRONÔMETRO    | C           0  0 : 0  0 : 0  0               |                    
                ------------------------------------------------
                ------------------------------------------------
  TEMPORIZADOR  | T           0  0 : 1  0 : 0  0               |                    
                ------------------------------------------------

                                  MSP430F1121
                      3,3V  ----------------------
                       +   |                      |
                       |   |                   XIN|
                       ----|RST                   |
                           |                  XOUT|
                           |                      |
                           |                      |
           (74HC241) 1Y0-->|P2.0              P1.0|-->D0 (LCM)
                           |                      |
           (74HC241) 1Y0-->|P2.1              P1.1|-->D1 (LCM)
                           |                      |
    (74HC241) 1OE/ e 2OE<--|P2.2              P1.2|-->D2 (LCM)    
                           |                      |     
                      RS<--|P2.3              P1.3|-->D3 (LCM)
                           |                      |
                      RW<--|P2.4              P1.4|-->D4 (LCM)
                           |                      |
                       E<--|P2.5              P1.5|-->D5 (LCM)
                           |                      |
                           |P2.6              P1.6|-->D6 (LCM)
                           |                      |
                           |P2.7              P1.7|-->D7 (LCM)
                           |                      |
                            ----------------------
   
Desenvolvido com IAR Embedded Workbench Versão: 7.21.1
*******************************************************************************/
// Bibliotecas utilizadas
#include "msp430f1121.h"
// Módulos criados
#include "lcm.h"
#include "keyboard.h"
#include "timer.h"
#include "funcionalidades.h"

extern char modo;
extern char crono;
extern char tempo;

//---------------------------Implementação de rotinas-------------------------//
// Rotina principal
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  configuraLCM();
  programaLCM();
  confTeclado();
  enviaString("R   00:00:00   ");
  timerConfig();
  
  for(;;){
    reconheceTecla();
  }

  return 0;
}

// Interrupção do Timer A
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void) {
  switch(__even_in_range(TA0IV, 0x0A)){
  case TA0IV_NONE:
    break;
  case TA0IV_TACCR1:
    break;
  case TA0IV_6:
    break;
  case TA0IV_8:
    break;
  case TA0IV_TAIFG:
    incrementaSec();
    if(modo){
      display(1);
      if(modo==1 && crono==1)
        incrementaSecTC();
      else if(modo==2 && tempo==1)
        decrementaSec();
    }
    else{
      display(0);
    }
    break;
  default:
    break;
  }
}