// Bibliotecas utilizadas  
#include "funcionalidades.h"
#include "lcm.h"

// Variáveis de modos
char modo = 0; 
/* 
    * 0 - relógio || 1 - cronômetro || 2 - temporizador
*/
char crono = 0; 
/* 
    * 0 - parar || 1 - disparar || 2 - zerar
*/
char tempo = 0; 
/* 
    * 0 - trava || 1 - dispara|| 2 - seta 10min 
*/

// Caracteres do relógio
                  //{dHora, uHora, dMin, uMin, dSec, uSec}
char contaRLG [6] = {0, 0, 0, 0, 0, 0};
// Caracteres do cronômetro/temporizador
                  //{dHoraTC, uHoraTC, dMinTC, uMinTC, dSecTC, uSecTC}
char contaTC [6] = {0, 0, 0, 0, 0, 0};

//---------------------------Implementação de rotinas-------------------------//
void display(char modo){
  if(modo){
    for(int i=0; i<6; i++){
      posicionaCursor(i, contaTC [i]);
    }
  }
  else{
    for(int i=0; i<6; i++){
      posicionaCursor(i, contaRLG [i]);
    }
  }
}

//----------------------------------------------------------------------------//
void zeraDisplay(char modo){
  if(modo){
    for(int i=0; i<6; i++){
      contaTC [i] = 0;
      posicionaCursor(i, contaTC [i]);
    }
  }
  else{
    for(int i=0; i<6; i++){
      contaRLG [i] = 0;
      posicionaCursor(i, contaRLG [i]);
    }
  }
}

//----------------------------------------------------------------------------//
void modoConfig (char caractere){
  enviaComando(0x80);
  enviaDado(caractere); 
  if(modo != 0){
    zeraDisplay(1);
  }
}

//----------------------------------------------------------------------------//
void incrementaSec(void){
  if(contaRLG[5] < 9){ // Caso não tiver atingido o valor máximo
    contaRLG[5]++;
    if(modo==0)
      posicionaCursor(5, contaRLG[5]); // Envia número para o display
  }
  else{
    contaRLG[5]=0; 
    if(modo==0)
      posicionaCursor(5, contaRLG[5]); // Envia número para o display
    
    if(contaRLG[4] < 5){ // Dezena de segundos menor que o máximo
      contaRLG[4]++;
      if(modo==0)
        posicionaCursor(4, contaRLG[4]); // Envia número para o display
    }
    else{
      contaRLG[4]=0; 
      if(modo==0)
        posicionaCursor(4, contaRLG[4]); // Envia número para o display
      incrementaMin(); // Função que passa minuto
    }
  }
}

//----------------------------------------------------------------------------//
void incrementaMin(void){
  if(contaRLG[3] < 9){ // Caso não tiver atingido o valor máximo
    contaRLG[3]++;
    if(modo==0)
      posicionaCursor(3, contaRLG[3]); // Envia número para o display
  }
  else{
    contaRLG[3] = 0; 
    if(modo==0)
      posicionaCursor(3, contaRLG[3]); // Envia número para o display
    
    if(contaRLG[2] < 5){ // Dezena de minutos menor que o máximo
      contaRLG[2]++; 
      if(modo==0)
        posicionaCursor(2, contaRLG[2]); // Envia número para o display
    }
    else{
      contaRLG[2] = 0; 
      if(modo==0)
        posicionaCursor(2, contaRLG[2]); // Envia número para o display
      incrementaHora(); // Função que passa hora
    }
  }
}

//----------------------------------------------------------------------------//
void incrementaHora (void){
  if(contaRLG[1] < 9 && contaRLG[0] < 2) {
    contaRLG[1]++;  
    if(modo==0)
      posicionaCursor(1, contaRLG[1]); // Envia número para o display
  }
  else if(contaRLG[1] == 9 && contaRLG[0] < 2) {
    contaRLG[1] = 0; 
    if(modo==0)
      posicionaCursor(1, contaRLG[1]); // Envia número para o display
    contaRLG[0]++;
    if(modo==0)
      posicionaCursor(0, contaRLG[0]); // Envia número para o display
  }
  else if(contaRLG[0] == 2 && contaRLG[1] < 3){ 
    contaRLG[1]++; 
    if(modo==0)
      posicionaCursor(1, contaRLG[1]); // Envia número para o display
  }
  else{ 
    zeraDisplay(0); // Zera o relógio 
  }
}

//----------------------------------------------------------------------------//
void incrementaSecTC(void){
  if(contaTC[5] < 9){ // Caso não tiver atingido o valor máximo
    contaTC[5]++;
    posicionaCursor(5, contaTC[5]); // Envia número para o display
  }
  else{
    contaTC[5]=0; 
    posicionaCursor(5, contaTC[5]); // Envia número para o display
    
    if(contaTC[4] < 5){ // Dezena de segundos menor que o máximo
      contaTC[4]++; 
      posicionaCursor(4, contaTC[4]); // Envia número para o display
    }
    else{
      contaTC[4]=0; 
      posicionaCursor(4, contaTC[4]); // Envia número para o display
      incrementaMinTC(); // Função que passa minuto
    }
  }
}

//----------------------------------------------------------------------------//
void incrementaMinTC(void){
  if(contaTC[3] < 9){ // Caso não tiver atingido o valor máximo
    contaTC[3]++; 
    posicionaCursor(3, contaTC[3]); // Envia número para o display
  }
  else{
    contaTC[3] = 0; 
    posicionaCursor(3, contaTC[3]); // Envia número para o display
    
    if(contaTC[2] < 5){ // Dezena de minutos menor que o máximo
      contaTC[2]++; 
      posicionaCursor(2, contaTC[2]); // Envia número para o display
    }
    else{
      contaTC[2] = 0; 
      posicionaCursor(2, contaTC[2]); // Envia número para o display
      incrementaHoraTC(); // Função que passa hora
    }
  }
}

//----------------------------------------------------------------------------//
void incrementaHoraTC (void){
  if(contaTC[1] < 9 && contaTC[0] < 2) {
    contaTC[1]++;  
    posicionaCursor(1, contaTC[1]); // Envia número para o display
  }
  else if(contaTC[1] == 9 && contaTC[0] < 2) {
    contaTC[1] = 0; 
    posicionaCursor(1, contaTC[1]); // Envia número para o display
    contaTC[0]++; 
    posicionaCursor(0, contaTC[0]); // Envia número para o display
  }
  else if(contaTC[0] == 2 && contaTC[1] < 3){ 
    contaTC[1]++; 
    posicionaCursor(1, contaTC[1]); // Envia número para o display
  }
  else{ 
    zeraDisplay(1); // Zera o relógio 
  }
}

//----------------------------------------------------------------------------//
void decrementaSec(){
  if(modo==2 && tempo==1){
    if(contaTC [5] > 0) {
      contaTC [5]--; 
      posicionaCursor(5, contaTC [5]); // Envia número para o display
    }
    else {
      if(contaTC [4] > 0) {
        contaTC [5] = 9; 
        posicionaCursor(5, contaTC [5]); // Envia número para o display
        
        contaTC [4]--; 
        posicionaCursor(4, contaTC [4]); // Envia número para o display
      }
      else{ 
        contaTC [4] = 5; 
        posicionaCursor(4, contaTC [4]); // Envia número para o display
        
        contaTC [5] = 9; 
        posicionaCursor(5, contaTC [5]); // Envia número para o display
        
        decrementaMinTC(); 
      }
    }
  }
}

//----------------------------------------------------------------------------//
void decrementaMin(){
    if(contaRLG [3] > 0){ 
      contaRLG [3]--; 
      posicionaCursor(3, contaRLG [3]); // Envia número para o display
    }
    else 
    {
      if(contaRLG [2] > 0) 
      {
        contaRLG [3] = 9; 
        posicionaCursor(3, contaRLG [3]); // Envia número para o display
        
        contaRLG [2]--; 
        posicionaCursor(2, contaRLG [2]); // Envia número para o display
      }
      else{ 
        contaRLG [2] = 5; 
        posicionaCursor(2, contaRLG [2]); // Envia número para o display
        
        contaRLG [3] = 9; 
        posicionaCursor(2, contaRLG [2]); // Envia número para o display
        decrementaHora();
      }
    }
}

//----------------------------------------------------------------------------//
void decrementaHora(){
    if(contaRLG [1] > 0){ 
      contaRLG [1]--; 
      posicionaCursor(1, contaRLG [1]); //  Envia número para o display
    }
    else{ 
      if(contaRLG [0] > 0){ 
        contaRLG [1] = 9; 
        posicionaCursor(1, contaRLG [1]); //  Envia número para o display
        if(contaRLG [0] > 0){ 
          contaRLG [0]--;
          posicionaCursor(0, contaRLG [0]); //  Envia número para o display
        }
      }
      else{ 
        contaRLG [0] = 2; 
        posicionaCursor(0, contaRLG [0]); //  Envia número para o display
        
        contaRLG [1] = 3; 
        posicionaCursor(1, contaRLG [1]); //  Envia número para o display
      }
    }
}

//----------------------------------------------------------------------------//
void decrementaMinTC(){
    if(contaTC [3] > 0){ 
      contaTC [3]--; 
      posicionaCursor(3, contaTC [3]); // Envia número para o display
    }
    else 
    {
      if(contaTC [2] > 0) 
      {
        contaTC [3] = 9; 
        posicionaCursor(3, contaTC [3]); // Envia número para o display
        
        contaTC [2]--; 
        posicionaCursor(2, contaTC [2]); // Envia número para o display
      }
      else{ 
        contaTC [2] = 5; 
        posicionaCursor(2, contaTC [2]); // Envia número para o display
        
        contaTC [3] = 9; 
        posicionaCursor(2, contaTC [2]); // Envia número para o display
        decrementaHora();
      }
    }
}

//----------------------------------------------------------------------------//
void decrementaHoraTC(){
    if(contaTC [1] > 0){ 
      contaTC [1]--; 
      posicionaCursor(1, contaTC [1]); //  Envia número para o display
    }
    else{ 
      if(contaTC [0] > 0){ 
        contaTC [1] = 9; 
        posicionaCursor(1, contaTC [1]); //  Envia número para o display
        if(contaTC [0] > 0){ 
          contaTC [0]--;
          posicionaCursor(0, contaTC [0]); //  Envia número para o display
        }
      }
      else{ 
        contaTC [0] = 2; 
        posicionaCursor(0, contaTC [0]); //  Envia número para o display
        
        contaTC [1] = 3; 
        posicionaCursor(1, contaTC [1]); //  Envia número para o display
      }
    }
}

//----------------------------------------------------------------------------//
void setaContagem(char hd, char hu, char md, char mu, char sd, char su){
  contaTC[0] = hd;
  contaTC[1] = hu;
  contaTC[2] = md;
  contaTC[3] = mu;
  contaTC[4] = sd;
  contaTC[5] = su;
  display(1);
}