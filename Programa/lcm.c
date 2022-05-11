// Bibliotecas utilizadas
#include "lcm.h"

const char ENDERECOS [6] = {0x84,0x85,0x87,0x88,0x8A,0x8B};

//---------------------------Implementação de rotinas-------------------------//
void configuraLCM(void)
{
  //Configuração das portas
  LCM_DADO_DIR = 0xFF; // Todos os bits da porta 1 de dados como saída
  LCM_DADO_OUT = 0x00; // Limpa a saída
  LCM_CTL_DIR = 0xFC; // Bits 0 e 1 como entradas (74HC241)
  LCM_CTL_DIR |= RS+RW+EN+BIT2; // Bits da porta de controle como saída
  LCM_CTL_OUT &= ~(RS+RW+EN+BIT2); // Limpa pinos
}

//----------------------------------------------------------------------------//
void programaLCM(void)
{
  enviaComando(0x30); // 8 bits de dados - 1 linha - M 5x7
  enviaComando(0x0C); // Display ativo - cursor inativo
  enviaComando(0x06); // Cursor desloca para a direita
  enviaComando(0x01); // Limpa LCM
  __delay_cycles(100000);  // Delay de 1,6ms (comando limpar)
}

//----------------------------------------------------------------------------//
void enviaComando(unsigned char comando)
{
  LCM_DADO_OUT = comando;  // Carrega comando para o barramento da porta P1
  LCM_CTL_OUT &= ~(EN + RS);  // EN e RS em nível baixo
  __delay_cycles(200);  // Delay de 2ms 
  LCM_CTL_OUT |= EN;    // EN <- 1
  __delay_cycles(200);  // Delay de 2ms
  LCM_CTL_OUT &= ~EN;   // EN <- 0
}

//----------------------------------------------------------------------------//
void enviaDado(unsigned char dado)
{
  LCM_DADO_OUT = dado;  // Carrega comando para o barramento da porta P1
  LCM_CTL_OUT &= ~EN;  // EN em nível baixo
  LCM_CTL_OUT |= RS;  // RS nível alto
  __delay_cycles(200);  // Delay de 40us
  LCM_CTL_OUT |= EN;    // EN <- 1
  __delay_cycles(200);  // Delay de 40us
  LCM_CTL_OUT &= ~EN;   // EN <- 0
}

//----------------------------------------------------------------------------//
void enviaString (const char *apt)
{
  const char *a; // Reset de ponteiro
  a = apt;
  
  while (*a != 0x00) // Ponteiro irá passar até o caracter nulo da string
  {
    enviaDado (*a);  // Envia o carater que o ponteiro está apontando
    a++;  // Passa para o próximo caracter
  }
}
  
//----------------------------------------------------------------------------//
void posicionaCursor (char posicao, char numero)
{
  enviaComando(ENDERECOS[posicao]); // Posiciona cursor no endereço devido
  char display;
  switch(numero) // Verifica o valor recebido
  {
  case 0:
    display = '0';
    break;
  case 1:
    display = '1';
    break;
  case 2:
    display = '2';
    break;
  case 3:
    display = '3';
    break;
  case 4:
    display = '4';
    break;
  case 5:
    display = '5';
    break;
  case 6:
    display = '6';
    break; 
  case 7:
    display = '7';
    break;
  case 8:
    display = '8';
    break;
  case 9:
    display = '9';
    break;
  }
  enviaDado(display); // Envia o valor para o display
}