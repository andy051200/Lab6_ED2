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
/*-----------------------------------------------------------------------------
 ------------------------ PROTOTIPOS DE FUNCIONES ------------------------------
 -----------------------------------------------------------------------------*/
void GPIOF0_vISR(void);   //interrupcion en boton 1, J1
void GPIOF4_vISR(void);   //interrupcion en boton 2, J2
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
  b1 = digitalRead(31);
  b2 = digitalRead(17);
  if (b1==0)
  {
    digitalWrite(LED_J2, 1);
  }
  else
  {
    digitalWrite(LED_J2, 0);
  }
  
  /*
  digitalWrite(LED_J1, 1);
  delay(1000);
  digitalWrite(LED_J1, 0);
  delay(1000);
  //
  digitalWrite(LED_J2, 1);
  delay(1000);
  digitalWrite(LED_J2, 0);
  delay(1000);
  //
  digitalWrite(LED_sem, 1);
  delay(1000);
  digitalWrite(LED_sem, 0);
  delay(1000);
  */
}
