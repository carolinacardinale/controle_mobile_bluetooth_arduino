#include <SoftwareSerial.h> 

SoftwareSerial HC05(10, 11); 

int state = 0;  
int state2 = 0; 
int state3 = 0;

#define azul 4
#define verde 3
#define vermelho 2

void setup()
{
  Serial.begin(9600);        
  HC05.begin(9600);        

  pinMode(verde, OUTPUT);      
  pinMode(azul, OUTPUT);         
  pinMode(vermelho, OUTPUT); 

}
void loop()
{
  
  int readBluetooth = HC05.read();

  switch (readBluetooth)
  { 
  
    case 'a': 
      state = !state; 
      digitalWrite(verde, state); 
      break;

    case 'b':
      state2 = !state2; 
      digitalWrite(vermelho, state2);
      break; 

    case 'c': 
      state3 = !state3;
      digitalWrite(azul, state3);
      break;
  }
}