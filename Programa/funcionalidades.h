#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

// Bibliotecas utilizadas
#include "msp430f1121.h"

/*------------------------------------------------------------------------------
Fun��o: display
Descri��o: Motra os caracteres do modo escolhido
Entrada: char modo - Modo do sistema
Sa�da: ----
------------------------------------------------------------------------------*/
void display(char modo);

/*------------------------------------------------------------------------------
Fun��o: modoConfig
Descri��o: Configura o modo no display
Entrada: char caractere - Caractere que indica o modo do sistema
Sa�da: ----
------------------------------------------------------------------------------*/
void modoConfig (char caractere);

/*------------------------------------------------------------------------------
Fun��o: iniciaContagem
Descri��o: Zera a contagem de todos os modos ao iniciar o sistema
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void iniciaContagem (void);

/*------------------------------------------------------------------------------
Fun��o: incrementaSec
Descri��o: Passa 1 segundo
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void incrementaSec(void);

/*------------------------------------------------------------------------------
Fun��o: incrementaMin
Descri��o: Passa 1 minuto
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void incrementaMin(void);

/*------------------------------------------------------------------------------
Fun��o: incrementaHora
Descri��o: Passa 1 hora
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/

void incrementaHora (void);
/*------------------------------------------------------------------------------
Fun��o: incrementaSecTC
Descri��o: Passa 1 segundo
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void incrementaSecTC(void);

/*------------------------------------------------------------------------------
Fun��o: incrementaMinTC
Descri��o: Passa 1 minuto
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void incrementaMinTC(void);

/*------------------------------------------------------------------------------
Fun��o: incrementaHoraTC
Descri��o: Passa 1 hora
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void incrementaHoraTC (void);

/*------------------------------------------------------------------------------
Fun��o: decrementaSec
Descri��o: Decrementa 1 segundo 
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void decrementaSec();

/*------------------------------------------------------------------------------
Fun��o: decrementaMin
Descri��o: Decrementa 1 minuto 
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void decrementaMin();

/*------------------------------------------------------------------------------
Fun��o: decrementaHora
Descri��o: Decrementa 1 hora 
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void decrementaHora();

/*------------------------------------------------------------------------------
Fun��o: decrementaMinTC
Descri��o: Decrementa 1 minuto 
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void decrementaMinTC();

/*------------------------------------------------------------------------------
Fun��o: decrementaHoraTC
Descri��o: Decrementa 1 hora 
Entrada: ----
Sa�da: ----
------------------------------------------------------------------------------*/
void decrementaHoraTC();

/*------------------------------------------------------------------------------
Fun��o: incrementaHoraTC
Descri��o: Seta um valor para contagem
Entrada: Respectivos algarismos das horas, minutos e segundos
         char hd, char hu, char md, char mu, char sd, char su
Sa�da: ----
------------------------------------------------------------------------------*/
void setaContagem(char hd, char hu, char md, char mu, char sd, char su);

#endif //FUNCIONALIDADES_H