/* TODO
 * Make LED function snazzy
 * Add RF functionality
 * Actually test it lol
*/

#include <NRFLite.h>
#include <Keyboard.h>

#define ON_BUTTON 2 //Pin connected to the "on" button. 
#define OFF_BUTTON 3 //Pin connected to the "off" button. 
#define LED 6 //Pin connected to LED, should probably be wired in series with a 330ish Ohm resistor. Vector is PD7

enum connection_state { //Not sure if this will be useful, but could make it way eaiser to do LED stuff
    NO_CONNECTION,
    SCANNING,
    CONNECTED,
    PACKET_SENT,
    PACKET_RECIEVED
};

NRFLite radio;
uint8_t data;

bool stateChange;

connection_state state = NO_CONNECTION;

void setup() {
    // put your setup code here, to run once:
    pinMode(ON_BUTTON, INPUT_PULLUP); attachInterrupt(digitalPinToInterrupt(ON_BUTTON), record, LOW);
    pinMode(OFF_BUTTON, INPUT_PULLUP); attachInterrupt(digitalPinToInterrupt(OFF_BUTTON), pause, LOW);  
    pinMode(LED, OUTPUT); digitalWrite(LED, LOW);
    Keyboard.begin();
    Serial.begin(115200);
    radio.init(1, 9, 10);
    state = NO_CONNECTION;
    stateChange = true;
}

void loop() {
    // put your main code here, to run repeatedly:
    while(radio.hasData()) {
        //Function should do comms stuff here
    }
    if(stateChagnge) {
    stateChange = false;
    ledState(state);
    }
}

void ledState(int i) {
    switch (i) {
        case 0:
            //Need to do something cool here with hardware timers
            break;
        case 1:
            //Need to do something cool here with hardware timers
            break;
        case 2:
            //Need to do something cool here with hardware timers
            break;
        case 3:
            //Need to do something cool here with hardware timers
            break;
        case 4:
            //Need to do something cool here with hardware timers
            break;
        default:
            //Need to do something cool here with hardware timers
    }
}

void record() {
  //Pretty sure this serial call will take too long but IDK
  Keyboard.write('r'); //sends the keyboard shortcut for record
}

void pause() {
  //Pretty sure this serial call will take too long but IDK
  Keyboard.write(' '); //sends the keyboard shortcut for stop
}
