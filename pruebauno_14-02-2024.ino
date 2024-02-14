

const int TriggerP = 12; //Trigger
const int EchoP = 11;   // Echo 

int in1 = 10;  // Pin que controla el sentido de giro Motor A
int in2 = 9;  // Pin que controla el sentido de giro Motor A
//int EnA = 6;
int in3= 8;  // Pin que controla el sentido de giro Motor A
int in4 = 7;

int tiempoEspera = 1000 ;
int cm = 0 ;
/* ************************************************* **
* Avanzar
************************************************** * */
void  Avanzar () {

  digitalWrite(in1, LOW); // A
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);  //B
  digitalWrite(in4, LOW);

  delay(tiempoEspera);
 
}

void  Detener () {
  
  digitalWrite(in1, LOW); // A
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  //B
  digitalWrite(in4, LOW);

  delay(tiempoEspera);
 
}
void  Retroceder () {
  
  digitalWrite(in1, HIGH); // A
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  //B
  digitalWrite(in4, HIGH);

  delay(tiempoEspera);
 
}
void setup ()

{
  Serial.begin(9600);
  pinMode(TriggerP, OUTPUT);
  pinMode(EchoP, INPUT);
  
  pinMode(in1, OUTPUT);    // Configura  los pines como salida
  pinMode(in2, OUTPUT);
  //pinMode(EnA, OUTPUT);
  pinMode(in3, OUTPUT);    // Configura  los pines como salida
  pinMode(in4, OUTPUT);
}
void loop()
{
  
  cm = ping(TriggerP, EchoP);
  Serial.print("Distancia medida: ");
  Serial.println(cm);
  delay(1000);

  Avanzar ();
  Detener ();
  Retroceder ();
  Detener ();
  
}
//Cálculo para la distancia
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
    
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
    
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
    
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
