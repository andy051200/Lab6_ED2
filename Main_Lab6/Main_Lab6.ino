/*------------------------------------------------------------------------------  
Archivo: Main_Lab6
Microcontrolador: TM4C123
Autor: Andy Bonilla
Compilador: Energia 1.8.11E23
Programa: laboratorio 6
Hardware: Launchpad Tiva C
    
Creado: 15 de septiembre de 2021    
Descripcion: un mini juego para acostumbrase a la plataforma 
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 ----------------------------LIBRERIAS-----------------------------------------
 -----------------------------------------------------------------------------*/
//ninguna de momento
/*-----------------------------------------------------------------------------
 ----------------------- VARIABLES A IMPLEMTENTAR------------------------------
 -----------------------------------------------------------------------------*/
//-------DIRECTIVAS DEL COMPILADOR
#define LED_J1 RED_LED      //directiva para led rojo, J1
#define LED_J2 GREEN_LED    //directiva para led verde, J2
#define LED_sem BLUE_LED    //directiva praa led azul, comodin

//-------VARIABLES DE PROGRAMA
bool b1 =1;   //variable booleanaa para J1
bool b2 =1;   //variable booleana para J2
unsigned char cuentaJ1=0,cuentaJ2=0;   //variables contadoras para jugadores

/*-----------------------------------------------------------------------------
 ------------------------ PROTOTIPOS DE FUNCIONES ------------------------------
 -----------------------------------------------------------------------------*/
void semaforo(void);      //prototipo de semaforo inicial
void cuenta_j1 (void);    //prototipo de cuenta jugador 1
void cuenta_j2 (void);    //prototipo de cuenta jugador 2
void ganador (void);      //prototipo de jugador ganador
/*-----------------------------------------------------------------------------
 --------------------------- INTERRUPCIONES -----------------------------------
 -----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 ---------------------------------- SET UP -----------------------------------
 -----------------------------------------------------------------------------*/
void setup() 
{
  //-------ENTRADAS DE BOTONES
  pinMode(31, INPUT_PULLUP);    //boton para jugador 1
  pinMode(17, INPUT_PULLUP);    //boton para jugador 2
  //-------SALIDAS DE LEDS
  pinMode(LED_J1, OUTPUT);      //led para J1, rojo
  pinMode(LED_J2, OUTPUT);      //led para J2, verde
  pinMode(LED_sem, OUTPUT);     //led para comodin
}
/*-----------------------------------------------------------------------------
 ----------------------------- MAIN LOOP --------------------------------------
 -----------------------------------------------------------------------------*/
void loop() 
{
  //-------SE LLAMAN FUNCIONES
  cuenta_j1();    //funcion del boton 1, J1
  cuenta_j2();    //funcion del boton 2, J2
  ganador();
}
/*-----------------------------------------------------------------------------
 ----------------------------- MAIN LOOP --------------------------------------
 -----------------------------------------------------------------------------*/
//-------FUNCION DE SEMAFORO INICIAL
void semaforo(void){
  
}

//-------FUNCION PARA CUENTA DEL JUGADOR 1
void cuenta_j1 (void){
  b1 = digitalRead(31);       //se toma la lectura del boton 1
  if (b1==0)
  {
    digitalWrite(LED_J1, 1);
    cuentaJ1++;
  }
  else
  {
    digitalWrite(LED_J1, 0);
  }
  
}

//------FUNCION PARA CUENTA DEL JUGADOR 2
void cuenta_j2 (void){
  b2 = digitalRead(17);       //se toma la lectura del boton 2
  if (b2==0)
  {
    digitalWrite(LED_J2, 1);
    cuentaJ2++;
  }
  else
  {
    digitalWrite(LED_J2, 0);
  }
}

//-------FUNCION PARA GANADOR
void ganador (void){
  //-------EVALUAR SI LLEGO A LA CUENTA
  if (cuentaJ1==7 && cuentaJ2<7){
    for(int i=0; i<=15;i++ ){
      digitalWrite(LED_J1, 1);
      delay(500);
      digitalWrite(LED_J1, 0);
      delay(500);
    }
  }
  else
  {
    digitalWrite(LED_J1, 0);
    }

  
  if (cuentaJ1<7 && cuentaJ2==7){
    
  }
}
