/* 
  Ir Beam Relay Control
*/
 
#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13

#define SENSORPIN 4 //sensor attached to pin 
#define relay 12 //Relay attached to pin 12



// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

 
void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
  pinMode(relay, OUTPUT);      // Initialize the Atmel GPIO pin as an output
}
 
void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
 
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH); 
    digitalWrite(relay, LOW);    // Turn the relay off by making the voltage LOW = 0
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW);
    digitalWrite(relay, HIGH);   // Turn the relay on (HIGH is the voltage level = 1)
  }
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;
}
