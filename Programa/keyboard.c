// Bibliotecas utilizadas
#include "keyboard.h"   
#include "funcionalidades.h"

// Tabels de teclas e linhas
const char TAB_TEC[] = {0x00,0xfd,0x39,0x38,0x37,0x78,0x36,0x35,0x34,0x2d,0x33,0x32,0x31,0x2b,0x3d,0x30,0x2e};
const char TAB_LIN[] = {0xfe,0x0d,0x0b,0x07,0x00};

extern char modo;
extern char crono;
extern char tempo;

//---------------------------Implementação de rotinas-------------------------//
void confTeclado (void)
{
  TEC_DIR |= (LIN0+LIN1+LIN2+LIN3);  // Define as linhas como saídas
  P2DIR |= OE;  // Define OE como saída da P2
  P2DIR &= ~(S0 + S1); // Define como entradas as 2 saídas do 74HC241
}

//----------------------------------------------------------------------------//
char teclado (void)
{
  char *aptTec = (char *) TAB_TEC; //(aptTec) <- NULL
  char *aptLin = (char *) TAB_LIN; //(aptLin) <- 0xFE
  char coluna, aux; // Variáveis de armazenamento
  
  TEC_OUT &= ~(LIN0+LIN1+LIN2+LIN3); // Leva todas as linhas a nível baixo
  coluna = indentifica_coluna();

    if(coluna != 0x0F) // verifica se colunas ativam
    {
      __delay_cycles(100000);       // Antibounce
      TEC_OUT = (LIN0+LIN1+LIN2+LIN3);  // Leva todas as linhas a nível alto
      TEC_OUT &= *aptLin; // Ativa apenas a linha 0
      aux = indentifica_coluna(); // chama função que identifica a coluna e armazena seu valor
                                
      // Verifica se nenhuma coluna ativa
      while(*aptLin != 0x00 && aux == 0x0F) 
      {
        aptTec += 4; // Passa para os caracteres da próxima linha 
        aptLin++;    // Passa para a próxima linha   
        TEC_OUT = (LIN0+LIN1+LIN2+LIN3);// Leva todas as linhas a nível alto
        TEC_OUT &= *aptLin; // Ativa apenas a próxima linha
        aux = indentifica_coluna(); // chama função que identifica a coluna e armazena seu valor
      }
      
      if(aptLin == 0x00)  // Verifica se passou por todas as linhas e nenhuma tecla foi pressionada 
      {                      
        aptTec =(char *) TAB_TEC; // Reseta o ponteiro (aptTec) <- NULL
      }
      
      else // Caso tenha encontrado pressionamento em alguma das linhas
      {
        switch(coluna) 
        {
        case 0x0E:      // Tecla na coluna 4
          aptTec +=4;
          break;
        case 0x0D:      // Tecla na coluna 3
          aptTec += 3;
          break;
        case 0x0B:      // Tecla na coluna 2
          aptTec += 2;
          break;
        case 0x07:      // Tecla na coluna 1
          aptTec += 1;
          break;
        default:        // coluna != 1, 2, 3 ou 4
          aptTec =(char *) TAB_TEC; // Reseta o ponteiro (aptTec) <- NULL
          break;
        }
      }
    }
    
    else
    {
      aptTec =(char *) TAB_TEC; // Reseta o ponteiro (aptTec) <- NULL
    }
  return(*aptTec);      // TECLA <- (aptTec)
}

//----------------------------------------------------------------------------//
char indentifica_coluna (void)
{
  char armazena = 0;  // Variável que armazena a coluna da tecla pressionada                                           
  P2OUT |= OE;        // Seletor em nível alto (colunas 3 e 2)                                                
  armazena = (P2IN&0X03)<<2;  // Armazena a coluna nos bits mais significativos                                             
  P2OUT ^= OE;  // Seletor em nível baixo (colunas 1 e 0)                                                            
  armazena |= (P2IN&0X03);  // Armazena a coluna nos bits menos significativos                                                      
  return(armazena);  // retorna a coluna identificada             
}

//----------------------------------------------------------------------------//
void reconheceTecla(void){
  char tecla = teclado();
  switch (tecla){
  case 0x37:
    if(modo==0)
      incrementaHora();
    else if(modo==2 && tempo!=1)
      incrementaHoraTC();
    break;
  case 0x38:
    modo=0;
    modoConfig('R');
    display(0);
    break;
  case 0x39:
    modo=2;    
    tempo=2;
    modoConfig('T');
    setaContagem(0,0,1,0,0,0);
    display(2);
    break;
  case 0xFD:
    modo=1;
    crono=0;
    modoConfig('C');
    display(1);
    break;
  case 0x34:
    if(modo==0)
      decrementaHora();
    if(modo==2 && tempo!=1)
      decrementaHoraTC();
    break;
  case 0x36:
    if(modo==2){
      tempo=0;
      setaContagem(0,0,1,0,0,0);
    }
    else if(modo==1){
      crono=0;
      setaContagem(0,0,0,0,0,0);
    }
    break;
  case 0x31:
    if(modo==0)
      incrementaMin();
    if(modo==2 && tempo!=1)
      incrementaMinTC();
    break;
  case 0x33:
    if(modo==2)
      tempo=1;
    if(modo==1)
      crono=1;
    break;
  case 0x2E:
    if(modo==0)
      decrementaMin();
    if(modo==2 && tempo!=1)
      decrementaMinTC();
    break;
  case 0x3D:
    if(modo==2)
      tempo=0;
    if(modo==1)
      crono=0;
  }
}