#include <IRremote.h>

// Define the IR sensor pin
int irPin = 2;

// Define the LED pin
int ledPin = 6;

// Initialize the IRremote library
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Enable the IR receiver
  irrecv.enableIRIn();
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Check if there's any IR signal received
  if (irrecv.decode(&results)) {
    // Print the received IR signal code to the serial monitor
    Serial.println(results.value, HEX);
    digitalWrite(ledPin, HIGH);
  
    
    // Reset the IR receiver
    irrecv.resume();
  }

  if (irrecv.decode(&results)) {
    // Print the received IR signal code to the serial monitor
    Serial.println(results.value, HEX);
    digitalWrite(ledPin, LOW);
    
    
    // Reset the IR receiver
    irrecv.resume();
  }
  //else{
    //digitalWrite(ledPin, LOW);
    //irrecv.resume();
  //}
  
}
