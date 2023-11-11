// C++ code
//
#define redLed 13
#define sound 07
#define motor 05
const int LM35 = A0;
int temperatura;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  temperatura = int((float(analogRead(LM35))*5/(1024.0))/0.01);
  
  if(temperatura >= 30){
    
    analogWrite(motor, 255);
    
    if(temperatura >= 50){
      digitalWrite(sound, HIGH);
      digitalWrite(redLed, HIGH);
      
    }else{
      zeroValues(true, true, false);
    }
  }else {
    zeroValues(true, true, true);
  }

}

void zeroValues(bool redLedVal, bool soundVal, bool motorVal){
	
  if(redLedVal) digitalWrite(redLed, 0);
  if(soundVal) digitalWrite(sound, 0);
  if(motorVal) analogWrite(motor, 0);

}