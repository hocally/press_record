/*TODO
 * Change digitalRead()s for interrupts
 * Add LED function
 * Make LED function snazzy
 * Add RF comms library
 * Add RF functionality
 * Actually test it lol
*/
#include <Keyboard.h>

#define ON_BUTTON 4 //Pin connected to the "on" button. Vector is PD4
#define OFF_BUTTON 5 //Pin connected to the "off" button. Vector is PC6
#define LED 6 //Pin connected to LED, should probably be wired in series with a 330ish Ohm resistor. Vector is PD7

void setup() {
  // put your setup code here, to run once:
  pinMode(ON_BUTTON, INPUT_PULLUP);
  pinMode(OFF_BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT); digitalWrite(LED, LOW);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
	if(digitalRead(ON_BUTTON) == LOW){
		Keyboard.write('r'); //sends the keyboard shortcut for record
	}
	if(digitalRead(OFF_BUTTON) == LOW){
		Keyboard.write(' '); //sends the keyboard shortcut for stop
	}
}
