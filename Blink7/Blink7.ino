// Blink07 - multicolour LED nightlight
// David Kelly, IT Carlow 05.03.2021
const int RedLED = 11; // red LED controlled by digital I/O pin 11
const int GreenLED = 10; // green LED controlled by digital I/O pin 10
const int BlueLED = 9; // blue LED controlled by digital I/O pin 9
const int BUTTON = 2; // control switch feeds into digital I/O pin 2
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0; // current mode of RGB LED
void setup() {
 pinMode(RedLED, OUTPUT);
 pinMode(GreenLED, OUTPUT);
 pinMode(BlueLED, OUTPUT);
 pinMode(BUTTON, INPUT);
}
// Pass the last button state to the debounce function and read
// the present button state. If there is a change in state then
// delay and reread the button state (debounce the switch).
// return the new button state.
boolean debounce(boolean last) {
 boolean current = digitalRead(BUTTON);
 if (last != current){
 delay(5);
 current = digitalRead(BUTTON);
 }
 return current;
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
 currentButton = debounce(lastButton); // get current button state
 if (lastButton == LOW && currentButton == HIGH) // if pressed ..
 ledMode++; // set next mode
 lastButton = currentButton; // update last state
 if (ledMode == 8) // recycle states if needed
 ledMode = 0;
 setMode(ledMode); // set LED colour scheme
}
