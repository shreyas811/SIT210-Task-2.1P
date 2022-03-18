
const pin_t MY_LED = D7;
const int dot = 1000; // one second dot
const int  dash= 2000; // two second dash



SYSTEM_THREAD(ENABLED);

// The setup() method is called once when the device boots.
void setup() {
	
	pinMode(MY_LED, OUTPUT);
}

void signal(int timingOne){
    // Turn on the LED
	digitalWrite(MY_LED, HIGH);

	
	delay(timingOne);

	// Turn it off
	digitalWrite(MY_LED, LOW);

	
	delay(dot/2);
}

void space(){
    // Turn it off
	digitalWrite(MY_LED, LOW);

	
	delay(dash);
}

//Blinks my first name is morse code on the particle argon
void firstNameInMorse(String val = "SHREYAS"){
    for(int i=0; i<val.length(); i++){
        if(val.charAt(i) == 'S'){
            signal(dot);
            signal(dot);
            signal(dot);
            space();
        }else if(val.charAt(i) == 'H'){
            signal(dot);
            signal(dot);
            signal(dot);
            signal(dot);
            space();
        }else if(val.charAt(i) == 'R'){
            signal(dot);
            signal(dash);
            signal(dot);
            space();
        }else if(val.charAt(i) == 'E'){
            signal(dot);
            space();
        }else if(val.charAt(i) == 'Y'){
            signal(dash);
            signal(dot);
            signal(dash);
            signal(dash);
            space();
        }else if(val.charAt(i) == 'A'){
            signal(dot);
            signal(dash);
            space();
        }else{
            signal(10000);
        }
    }
}

//Blinks my last name is morse code on the particle argon
void lastNameInMorse(String last = "NAIR"){
    for(int i=0; i<last.length(); i++){
        if(last[i] == 'N'){
            signal(dash);
            signal(dot);
            space();
        }else if(last[i] == 'A'){
            signal(dot);
            signal(dash);
            space();
        }else if(last[i] == 'I'){
            signal(dot);
            signal(dot);
        }else if(last[i] == 'R'){
            signal(dot);
            signal(dash);
            signal(dot);
        }else{
            signal(10000);
        }
    }
}





// The loop() method is called frequently.
void loop() {
	
	lastNameInMorse();
	delay(5000);

	// And repeat!
}