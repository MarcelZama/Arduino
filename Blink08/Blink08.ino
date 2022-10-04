// Blink08 - multicolour LED nightlight
// David Kelly, IT Carlow 08.03.2021
const int RedLED = 11; // red LED controlled by digital I/O pin 11
const int GreenLED = 10; // green LED controlled by digital I/O pin 10
const int BlueLED = 9; // blue LED controlled by digital I/O pin 9
const int BUTTON = 2; // control switch feeds into digital I/O pin 2
int ledMode = 0; // current mode of RGB LED
void setup() {
 pinMode(RedLED, OUTPUT);
 pinMode(GreenLED, OUTPUT);
 pinMode(BlueLED, OUTPUT);
 pinMode(BUTTON, INPUT);
}
// sets the three leds to values dependent on
// current circuit state to achieve different
// colour mixes
void setMode(int mode) {
 if (mode == 0) { // all off
 digitalWrite(RedLED, LOW);
 digitalWrite(GreenLED, LOW);
 digitalWrite(BlueLED, LOW);
 } else if (mode == 1) { // red output
 digitalWrite(RedLED, HIGH);
 digitalWrite(GreenLED, LOW);
 digitalWrite(BlueLED, LOW);
 } else if (mode == 2) { // green output
 digitalWrite(RedLED, LOW);
 digitalWrite(GreenLED, HIGH);
 digitalWrite(BlueLED, LOW);
 } else if (mode == 3) { // blue output
 digitalWrite(RedLED, LOW);
 digitalWrite(GreenLED, LOW);
 digitalWrite(BlueLED, HIGH);
 } else if (mode == 4) { // purple output
 analogWrite(RedLED, 127);
 analogWrite(GreenLED, 0);
 analogWrite(BlueLED, 127);
 } else if (mode == 5) { // teal output
 analogWrite(RedLED, 0);
 analogWrite(GreenLED, 127);
 analogWrite(BlueLED, 127);
 } else if (mode == 6) { // orange output
 analogWrite(RedLED, 127);
 analogWrite(GreenLED, 127);
 analogWrite(BlueLED, 0);
 } else if (mode == 7) { // white output
 analogWrite(RedLED, 85);
 analogWrite(GreenLED, 85);
 analogWrite(BlueLED, 85);
 }
}
void loop() {
 if (digitalRead(2) == HIGH) { // if the button is pressed ...
 while (digitalRead(2) == HIGH) // while it remains pressed ...
 ; // ... do nothing ...
 ledMode++; // compute the next mode
 if (ledMode == 8) // recycle states if needed
 ledMode = 0;
 setMode(ledMode); // set the new LED colour scheme
 delay(100); // debounce the switch
 }
}
