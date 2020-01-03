#include <LiquidCrystal.h> 

const int Contrast=100; //visibility of led
//If want expand on number of LEDs, add shift register 74HC595N
const int ledA = 8;       // red; the pin that the LED is attached to
const int ledB = 9;       // goes in +1 number in pin
const int ledC = 10;
const int ledD = 11;
const int min_ledA = 8;
const int max_ledA = 12;
int randNumA = 0; 
int scoreA = 0;
const int led1 = 38;       // yellow; the pin that the LED is attached to
const int led2 = 39;
const int led3 = 40;
const int led4 = 41;
const int min_led1 = 38;
const int max_led1 = 42;
int randNum1 = 0; 
int score1 = 0;
int diff = 30; //difference between ledA and led1 (starting) pin num for calculations
LiquidCrystal lcd(13, 12, 5, 4, 3, 7);  
int buttonValue = 0; //Stores analog value when button is pressed

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);

  //set leds to light up
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT); 
  pinMode(ledC, OUTPUT); 
  pinMode(ledD, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT);
  
  //get a random number seed
  randomSeed(analogRead(1));

  //start with a random red LED lighted up
  randNumA = random(min_ledA,max_ledA);
  digitalWrite(randNumA, HIGH);
  //start with a random yellow LED lighted up
  randNum1 = random(min_led1,max_led1);
  while ((randNum1-diff)==randNumA) { //makes sure new LED is not the same
    randNum1 = random(min_led1,max_led1);
    //Serial.print(randNum1);
  }
  digitalWrite(randNum1, HIGH);

  //Start the LCD with score 0
  analogWrite(6,Contrast);
  lcd.begin(16, 7);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ScoreA:");
  lcd.setCursor(8,0);
  lcd.print("ScoreB:");
  lcd.setCursor(0, 1);
  lcd.print(scoreA);
  lcd.setCursor(8, 1);
  lcd.print(score1);
}

// the loop function runs over and over again forever
void loop() {
  // read the pushbutton input pin:
  //buttonState = digitalRead(buttonPin);
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  //Serial.print(buttonValue);
  if (buttonValue >= 900 && buttonValue <= 999){ //determine whether button pressed is same as lighting led
    if (randNumA == ledA){
      scoreA++;
      randNumA = resetStuff(randNumA, min_ledA, max_ledA);
      //Serial.print("A");
      delay (50);
    }
    if (randNum1 == led1){
      score1++;
      randNum1 = resetStuff(randNum1, min_led1, max_led1);
      //
      Serial.print("B");
      delay (50);
    }
  }
  else if (buttonValue >=800 && buttonValue <= 899){
    if (randNumA == ledB){
      scoreA++;
      randNumA = resetStuff(randNumA, min_ledA, max_ledA);
      delay (50);
    }
    if (randNum1 == led2){
      score1++;
      randNum1 = resetStuff(randNum1, min_led1, max_led1);
      delay (50);
    }
  } 
  else if  (buttonValue >=700 && buttonValue <= 799){
    if (randNumA == ledC){
      scoreA++;
      randNumA = resetStuff(randNumA, min_ledA, max_ledA);
      delay (50);
    } 
    if (randNum1 == led3){
      score1++;
      randNum1 = resetStuff(randNum1, min_led1, max_led1);
      delay (50);
    }
  }
  else if  (buttonValue >=600 && buttonValue <= 699){
    if (randNumA == ledD){
      scoreA++;
      randNumA = resetStuff(randNumA, min_ledA, max_ledA);
      delay (50);
    } 
    if (randNum1 == led4){
      score1++;
      randNum1 = resetStuff(randNum1, min_led1, max_led1);
      delay (50);
    }
  }
  //delay(5000);
}

int resetStuff(int randNum, int min_led, int max_led){
  digitalWrite(randNum, LOW); //clears old led
  while (randNumA == randNum || (randNum1-diff) == (randNum-diff)|| (randNum1-diff)==randNum || (randNum-diff)==randNumA) { //makes sure new LED is not the same
    randNum = random(min_led,max_led);
    Serial.print(randNum);
  }
  digitalWrite(randNum, HIGH); //lights new led

  //Shows new status on lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ScoreA:");
  lcd.setCursor(8,0);
  lcd.print("ScoreB:");
  lcd.setCursor(0, 1);
  lcd.print(scoreA);
  lcd.setCursor(8, 1);
  lcd.print(score1);

  return randNum;
}
