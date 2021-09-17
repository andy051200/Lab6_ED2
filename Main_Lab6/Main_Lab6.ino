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
unsigned char cuentaJ1=0,cuentaJ2=0, cuentaSEM;   //variables contadoras para jugadores
bool antirrebote1, antirrebote2, antirrebote0;    //variables para antirrebote
bool encendido;
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
  //-------LIMPIEZA DE VARIABLES
  cuentaJ1=0;
  cuentaJ2=0;
  //-------INIT PUERTO SERIAL MONITOREO
  Serial.begin(9600);
}
/*-----------------------------------------------------------------------------
 ----------------------------- MAIN LOOP --------------------------------------
 -----------------------------------------------------------------------------*/
void loop() 
{
  //-------SE LLAMAN FUNCIONES
  semaforo();     //funcion de semaforo de inicio
  cuenta_j1();    //funcion del boton 1, J1
  cuenta_j2();    //funcion del boton 2, J2
  ganador();
 
}
/*-----------------------------------------------------------------------------
 ----------------------------- MAIN LOOP --------------------------------------
 -----------------------------------------------------------------------------*/
//-------FUNCION DE SEMAFORO INICIAL
void semaforo(void){
  b1 = digitalRead(31);       //se toma la lectura del boton 1
  b2 = digitalRead(17);       //se toma la lectura del boton 2
  if (b1==0 && b2==0){
    antirrebote0=1;
  }
  if (antirrebote0==1 && b1==0 && b2==0){
    antirrebote0=0;
    digitalWrite(LED_sem, 1); //se prende led azul
    digitalWrite(LED_J2, 0);
    digitalWrite(LED_J1, 0);
    delay(1000);
    digitalWrite(LED_J1, 1);  //se prende led rojo
    digitalWrite(LED_J2, 0);
    digitalWrite(LED_sem, 0);
    delay(1000);
    digitalWrite(LED_J2, 1);  //se prende led verde
    digitalWrite(LED_J1, 0);
    digitalWrite(LED_sem, 0);
    delay(1000);
    encendido=1;
  }
  else{
    digitalWrite(LED_J2, 0);
    digitalWrite(LED_J1, 0);
    digitalWrite(LED_sem, 0);
    //encendido=0;
  }
}

//-------FUNCION PARA CUENTA DEL JUGADOR 1
void cuenta_j1 (void){
  b1 = digitalRead(31);       //se toma la lectura del boton 1
  //-------antirrebote1
  if (b1==0 && encendido==1)    //boton apachado
  {
    antirrebote1=1;
  }
  else{
    antirrebote1=0;
  } 
  //-------accion luego del antirrebote1
  if (antirrebote1==1 && b1==0 && encendido==1){
    digitalWrite(LED_J1, 1);
    cuentaJ1++;
    antirrebote1=0;
  }
  else
  {
    digitalWrite(LED_J1, 0);
  }
  
}

//------FUNCION PARA CUENTA DEL JUGADOR 2
void cuenta_j2 (void){
  b2 = digitalRead(17);       //se toma la lectura del boton 2
  //-------antirrebote2
  if (b2==0 && encendido==1)    //boton apachado
  {
    antirrebote2=1;
  }
  else{
    antirrebote2=0;
  } 
  //-------accion luego del antirrebote2
  if (antirrebote2==1 && b2==0 && encendido==1){
    digitalWrite(LED_J2, 1);
    cuentaJ2++;
    antirrebote2=0;
  }
  else
  {
    digitalWrite(LED_J2, 0);
  }
}

//-------FUNCION PARA GANADOR
void ganador (void){
  //-------mensajes durante el juego
  if (cuentaJ1<7 && cuentaJ2<7 && encendido==1){
    Serial.println("---------------------");
    Serial.println("Cuenta J1 | Cuenta J2");
    Serial.print("    ");
    Serial.print(cuentaJ1);
    Serial.print("     |    ");
    Serial.print(cuentaJ2);
    Serial.println("    ");
   
  }
  //-------mensaje si gana J1
  else if (cuentaJ1>7 && cuentaJ2<7 && encendido==1){
    Serial.println("---------------------");
    Serial.println("Cuenta J1 | Cuenta J2");
    Serial.print("    ");
    Serial.print(cuentaJ1);
    Serial.print("     |    ");
    Serial.print(cuentaJ2);
    Serial.println("    ");
    Serial.println("J1 ES EL GANADOR");
    for(int i=0; i<=15;i++ ){
      digitalWrite(LED_J1, 1);
      delay(500);
      digitalWrite(LED_J1, 0);
      delay(500);
    }
    cuentaJ1=0;
    encendido=0;
  }
  //-------mensaje si gana J2
  else if (cuentaJ1<7 && cuentaJ2>7 && encendido==1)
  {
    Serial.println("---------------------");
    Serial.println("Cuenta J1 | Cuenta J2");
    Serial.print("    ");
    Serial.print(cuentaJ1);
    Serial.print("     |    ");
    Serial.print(cuentaJ2);
    Serial.println("    ");
    Serial.println("J2 ES EL GANADOR");
    for(int i=0; i<=15;i++ ){
      digitalWrite(LED_J2, 1);
      delay(500);
      digitalWrite(LED_J2, 0);
      delay(500);
      }
      cuentaJ2=0;
      encendido=0;
  }
}
