int notes[] = {262,294,330,349};

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    
}

void loop() {
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    if (keyVal == 1023){
      tone(8, notes[0]);
    }
    else if(keyVal >= 990 && keyVal <= 1010){
      tone(8, notes[1]);
    }
    else if (keyVal >= 505 && keyVal <= 515){
      tone(8, notes[2]);
    }
    else if (keyVal >= 5 && keyVal <= 10){
      tone(8, notes[3]);
    }
    else{
      noTone(8);
    }
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);   
}
