#include <LiquidCrystal.h> 
// this constant won't change:
//const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int interruptPin = 2; // the button

const int Contrast=100;
//If want expand on number of LEDs, add shift register 74HC595N
const int ledA = 10;       // yellow; the pin that the LED is attached to
const int ledB = 9;
const int ledC = 8;
const int min_led = 8;
const int max_led = 11;
int randNum = 0; 
int score = 0;
boolean flag = false;
LiquidCrystal lcd(13, 12, 5, 4, 3, 7);  
int buttonValue; //Stores analog value when button is pressed

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //Serial.begin(9600);

  //set leds to light up
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT); 
  pinMode(ledC, OUTPUT); 
  
  //get a random number seed
  randomSeed(analogRead(0));
  
  //start with a random LED lighted up
  randNum = random(min_led,max_led);
  digitalWrite(randNum, HIGH);

  //Start the LCD with score 0
  analogWrite(6,Contrast);
  lcd.begin(16, 7);
  score = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.setCursor(0, 1);
  lcd.print(score);
}

// the loop function runs over and over again forever
void loop() {
  // read the pushbutton input pin:
  //buttonState = digitalRead(buttonPin);
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  //Serial.print(buttonValue);
  if (buttonValue >= 900 && buttonValue <= 999){ //determine whether button pressed is same as lighting led
    if (randNum == ledA){
      score++;
      resetStuff();
      delay (500);
    }
  }
  else if (buttonValue >=800 && buttonValue <= 899){
    if (randNum == ledB){
      score++;
      resetStuff();
      delay (500);
    }
  } 
  else if  (buttonValue >=700 && buttonValue <= 799){
    if (randNum == ledC){
      score++;
      resetStuff();
      delay (500);
    } 
  }
  //delay(5000);
}

void blink1(){ 
  digitalWrite(randNum, LOW);
  score++;
  flag = true;
  //Serial.println("inside1");
}

void resetStuff(){
  digitalWrite(randNum, LOW); //clears old led#include <LiquidCrystal.h> 

const int Contrast=100;
//If want expand on number of LEDs, add shift register 74HC595N
const int ledA = 11;       // yellow; the pin that the LED is attached to
const int ledB = 10;
const int ledC = 9;
const int ledD = 8;
const int min_led = 8;
const int max_led = 12;
int randNum = 0; 
int score = 0;
LiquidCrystal lcd(13, 12, 5, 4, 3, 7);  
int buttonValue; //Stores analog value when button is pressed


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //Serial.begin(9600);

  //set leds to light up
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT); 
  pinMode(ledC, OUTPUT); 
  pinMode(ledD, OUTPUT);
  
  //get a random number seed
  randomSeed(analogRead(1));
  
  //start with a random LED lighted up
  randNum = random(min_led,max_led);
  digitalWrite(randNum, HIGH);

  //Start the LCD with score 0
  analogWrite(6,Contrast);
  lcd.begin(16, 7);
  score = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.setCursor(0, 1);
  lcd.print(score);
}

// the loop function runs over and over again forever
void loop() {
  // read the pushbutton input pin:
  //buttonState = digitalRead(buttonPin);
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  //Serial.print(buttonValue);
  if (buttonValue >= 900 && buttonValue <= 999){ //determine whether button pressed is same as lighting led
    if (randNum == ledD){
      score++;
      resetStuff();
      delay (50);
    }
  }
  else if (buttonValue >=800 && buttonValue <= 899){
    if (randNum == ledC){
      score++;
      resetStuff();
      delay (50);
    }
  } 
  else if  (buttonValue >=700 && buttonValue <= 799){
    if (randNum == ledB){
      score++;
      resetStuff();
      delay (50);
    } 
  }
  else if  (buttonValue >=600 && buttonValue <= 699){
    if (randNum == ledA){
      score++;
      resetStuff();
      delay (50);
    } 
  }
  //delay(5000);
}

void resetStuff(){
  digitalWrite(randNum, LOW); //clears old led
  int oldRand = randNum;
  while (oldRand == randNum) { //makes sure new LED is not the same
    randNum = random(min_led,max_led);
  }
  digitalWrite(randNum, HIGH); //lights new led

  //Shows new status on lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.setCursor(0, 1);
  lcd.print(score);
}
  int oldRand = randNum;
  while (oldRand == randNum) { //makes sure new LED is not the same
    randNum = random(min_led,max_led);
  }
  digitalWrite(randNum, HIGH); //lights new led

  //Shows new status on lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.setCursor(0, 1);
  lcd.print(score);
}
