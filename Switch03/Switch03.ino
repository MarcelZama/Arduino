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

int currentstate = HIGH ; // used to record LED state - ON by default;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 
   pinMode(2, INPUT); // set pin 2 up for input

   pinMode(10, OUTPUT); // set pin 10 up for output

   digitalWrite(10,currentstate); // switch the LED on pin 10 to match currentstate
}

// the loop function runs over and over again forever
void loop() 
{  
        
              if (digitalRead(2) == HIGH){ // if the button is pressed...
                while(digitalRead(2) == HIGH) // while the button remains pressed ..
                ; // ... do nothing - loop ends on release
                currentstate = ! currentstate; // flip the state to the other value
                digitalWrite(10,currentstate);  //.. otherwise,turn the LED off
                delay(100);     // debounce the switch
                      }
              
              

}
