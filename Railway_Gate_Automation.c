#include <servo.h>
#include <liquidcrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int IRsensorPin1 = 8; // IR sensor 1 pin
int IRsensorPin2 = 9; // IR sensor 2 pin
int buzzerPin = 7; // buzzer pin
Servo myservo1;
void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.print("Automatic Gate");
pinMode(IRsensorPin1, INPUT);
pinMode(IRsensorPin2, INPUT);
pinMode(buzzerPin, OUTPUT);
myservo1.attach(6); // Servo motor 1 pin connected to D6
}
void loop() {
int sensorValue1 = digitalRead(IRsensorPin1); // read IR sensor 1
value
int sensorValue2 = digitalRead(IRsensorPin2); // read IR sensor 2
value
lcd.setCursor(0, 1); // set the cursor to column 0, line 1
if (sensorValue1 == HIGH && sensorValue2 == LOW ) { // check if IR sensor 1 is triggered and gate is closed
lcd.print("Train Approaching");
digitalWrite(buzzerPin, HIGH); // turn on the buzzer
lcd.clear(); // clear the LCD
myservo1.write(90); // sets the servo at 0 degree position
} else if (sensorValue2 == HIGH && sensorValue1 == LOW) { // check
if IR sensor 2 is triggered and gate is open
lcd.print("Train Passed");
lcd.clear(); // clear the LCD
digitalWrite(buzzerPin, LOW); // turn off the buzzer
myservo1.write(0); // sets the servo at 90 degree position
} else { // display the default message
lcd.print("No Train");
}
delay(100); // wait for 100 milliseconds before reading the IR sensors again
}