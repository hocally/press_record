#include <MIDI.h>
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //TODO assign buttons for the digital reads
  // put your main code here, to run repeatedly:
	if(digitalRead() == LOW){
		Keyboard.write(r) //sends the keyboard shortcut for record
	}
	if(digitalRead() == LOW{
		keyboard.write(' ') //sends the keyboard shortcut for stop
	}
}
