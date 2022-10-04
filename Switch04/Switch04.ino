/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
#define button 4
#define blue 5
#define white 6
#define yellow 7 
#define green 8 
#define red 9

int state = 0 ;
int old = 0 ; 
int buttonPoll = 0 ;


void setup() 
{

pinMode(button, INPUT); // set pin 4 up for input
pinMode(blue, OUTPUT); // set pin 5 up for output
pinMode(white, OUTPUT); // set pin 6 up for output
pinMode(yellow, OUTPUT); // set pin 7 up for output
pinMode(green, OUTPUT); // set pin 8 up for output
pinMode(red, OUTPUT); // set pin 9 up for output

digitalWrite(blue,LOW);
digitalWrite(white,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
digitalWrite(red,LOW);

}


void loop() 
{  
  buttonPoll = digitalRead(button);
  if(buttonPoll == 1)
  {
    delay (50);
    buttonPoll = digitalRead(button);
    if(buttonPoll == 0)
    {
      state = old + 1;
    }
  }
 else 
 {
  delay(100);
 }
 switch(state)
 {
  case 1:
      digitalWrite(blue,HIGH);
      digitalWrite(white,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
    old = state;
    break;
  case 2:
      digitalWrite(blue,LOW);
      digitalWrite(white,HIGH);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
    old = state;
    break;
  case 3:
      digitalWrite(blue,LOW);
      digitalWrite(white,LOW);
      digitalWrite(yellow,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
    old = state;
    break;
  case 4:
      digitalWrite(blue,LOW);
      digitalWrite(white,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
    old = state;
    break;
  case 5:
      digitalWrite(blue,LOW);
      digitalWrite(white,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
    old = state;
    break;
    old = state;
    break;
  default:
    digitalWrite(blue,LOW);
      digitalWrite(white,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
     old = 0;
    break;
 }
}
