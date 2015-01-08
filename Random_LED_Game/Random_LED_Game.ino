//********************************************/
//  Random LED Game in children day           /  
//  code by Apirak Sang-ngenchai              /
//  08/01/2014  22:50                         /
//  Vcc LED connect to 2 - 10 pin arrduino    / 
//  GND LED connect to GND arduino pin        /
//  Switch connect pin 12 arduino             /
//********************************************/

#define BUTTON  12

int buttonstate = 0;
int delayrandom =  0;

void setup() 
{
  for(int i = 2; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(BUTTON,  INPUT_PULLUP);
}

void loop() 
{
out:
  buttonstate = digitalRead(BUTTON);
  while(buttonstate == 0)
  {
    randomled(delayrandom);
    delayrandom = delayrandom + 5;
    
    if(delayrandom >= 200)
    { 
      buttonstate = 1;
      delayrandom = 0;
      goto out;
    }
  }
}

void randomled(int delaytime)
{
  for(int i=2; i<=11; i++)  digitalWrite(i, LOW);
  delay(delaytime);
  digitalWrite(random(2,12), HIGH);
  delay(delaytime);
}
