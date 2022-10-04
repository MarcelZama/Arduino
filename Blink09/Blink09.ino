 // Blink09 - multicolour LED nightlight
// David Kelly, IT Carlow 08.03.2021
const int RedLED = 11; // red LED controlled by digital I/O pin 11
const int GreenLED = 10; // green LED controlled by digital I/O pin 10
const int BlueLED = 9; // blue LED controlled by digital I/O pin 9
const int BUTTON = 2; // control switch feeds into digital I/O pin 2
const int modeCount= 10; // number of colour modes
int ledMode = 0; // current mode of RGB LED
void setup() {
 pinMode(RedLED, OUTPUT);
 pinMode(GreenLED, OUTPUT);
 pinMode(BlueLED, OUTPUT);
 pinMode(BUTTON, INPUT);
 Serial.begin(9600);
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
 } else if (mode == 7) { // bright white output
 analogWrite(RedLED, 255);
 analogWrite(GreenLED, 255);
 analogWrite(BlueLED, 255);
 } else if (mode == 8) { // olive output
 analogWrite(RedLED, 128);
 analogWrite(GreenLED, 128);
 analogWrite(BlueLED, 0);
 } else if (mode == 9) { // silver output
 analogWrite(RedLED, 0xAA); // hexadecimal values
 analogWrite(GreenLED, 0xA9);
 analogWrite(BlueLED, 0xAD);
 }
}
void loop() {
 if (digitalRead(2) == HIGH) { // if the button is pressed ...
 while (digitalRead(2) == HIGH) // while it remains pressed ...
 ; // ... do nothing ...
 Serial.print("Old mode: ");
 Serial.print(ledMode);
 ledMode = ++ledMode % modeCount; // compute the next mode
 setMode(ledMode); // set the new LED colour scheme
 Serial.print("\tNew mode: ");
 Serial.println(ledMode);
 delay(100); // debounce the switch
 }
