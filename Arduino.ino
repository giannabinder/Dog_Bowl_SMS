//#include <Arduino.h>

//pin setup
//LEDs
int rLED = D2, bLED = D4, gLED = D6;
//Sensors
int capacitor = A0;

//variables to store analog readings
double water;


void setup() {
  //declare output pins
  pinMode(gLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(bLED, OUTPUT);

  //declare input pins
  pinMode(capacitor, INPUT);

  //begin initialization 
  Serial.begin(9600);
}

// the loop function runs over and over again forever
// This determines the behaviour of the cricuit
void loop() {

  //read the water level of the bowl  
  water = analogRead(capacitor);

  //print to monitor for testing purposes
  Serial.print("Moisture: ");
  Serial.println(water);

  //perform interrupt if no water
  //blinks LEDS (testing)
  //when this happens, a text should be sent out
  if (water >= 600){
    for (int num = 0 ; num <= 10; num++){
      analogWrite(gLED, 100); 
      delay(100);                
      analogWrite(gLED, LOW);   
      analogWrite(bLED, 100); 
      delay(100);                
      analogWrite(bLED, LOW);   
      analogWrite(rLED, 100); 
      delay(100);                
      analogWrite(rLED, LOW);
    }
  }

  //don't perform an interrupt otherwise
  //no text should be sent out
  //here the all LEDs are on (testing)
  else{
    analogWrite(gLED, 100);
    analogWrite(bLED, 100);
    analogWrite(rLED, 100);

    //wait 2s before momrving on
    delay(2000);
  }

  //to signify this round of reading is over, turn all LEDs off 
  Serial.println("new round");
  analogWrite(gLED, 0);
  analogWrite(bLED, 0);
  analogWrite(rLED, 0);

  //wait 2s before reading again (testing)
  //don't want to bombard the user with texts, realiztically, the wait time should be longer
  delay(2000);                 
}