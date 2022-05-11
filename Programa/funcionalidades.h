#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

/*------------------------------------------------------------------------------
Função: display
Descrição: Motra os caracteres do modo escolhido
Entrada: char modo - Modo do sistema
Saída: ----
------------------------------------------------------------------------------*/
void display(char modo);

/*------------------------------------------------------------------------------
Função: modoConfig
Descrição: Configura o modo no display
Entrada: char caractere - Caractere que indica o modo do sistema
Saída: ----
------------------------------------------------------------------------------*/
void modoConfig (char caractere);

/*------------------------------------------------------------------------------
Função: iniciaContagem
Descrição: Zera a contagem de todos os modos ao iniciar o sistema
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void iniciaContagem (void);

/*------------------------------------------------------------------------------
Função: incrementaSec
Descrição: Passa 1 segundo
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void incrementaSec(void);

/*------------------------------------------------------------------------------
Função: incrementaMin
Descrição: Passa 1 minuto
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void incrementaMin(void);

/*------------------------------------------------------------------------------
Função: incrementaHora
Descrição: Passa 1 hora
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/

void incrementaHora (void);
/*------------------------------------------------------------------------------
Função: incrementaSecTC
Descrição: Passa 1 segundo
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void incrementaSecTC(void);

/*------------------------------------------------------------------------------
Função: incrementaMinTC
Descrição: Passa 1 minuto
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void incrementaMinTC(void);

/*------------------------------------------------------------------------------
Função: incrementaHoraTC
Descrição: Passa 1 hora
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void incrementaHoraTC (void);

/*------------------------------------------------------------------------------
Função: decrementaSec
Descrição: Decrementa 1 segundo 
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void decrementaSec();

/*------------------------------------------------------------------------------
Função: decrementaMin
Descrição: Decrementa 1 minuto 
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void decrementaMin();

/*------------------------------------------------------------------------------
Função: decrementaHora
Descrição: Decrementa 1 hora 
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void decrementaHora();

/*------------------------------------------------------------------------------
Função: decrementaMinTC
Descrição: Decrementa 1 minuto 
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void decrementaMinTC();

/*------------------------------------------------------------------------------
Função: decrementaHoraTC
Descrição: Decrementa 1 hora 
Entrada: ----
Saída: ----
------------------------------------------------------------------------------*/
void decrementaHoraTC();

/*------------------------------------------------------------------------------
Função: incrementaHoraTC
Descrição: Seta um valor para contagem
Entrada: Respectivos algarismos das horas, minutos e segundos
         char hd, char hu, char md, char mu, char sd, char su
Saída: ----
------------------------------------------------------------------------------*/
void setaContagem(char hd, char hu, char md, char mu, char sd, char su);

#endif //FUNCIONALIDADES_H