int ascii_A = 65;
int ascii_B = 66;
int ascii_C = 67;
int ascii_D = 68;
int ascii_E = 69;
int ascii_F = 70;
int ascii_G = 71;
int ascii_H = 72;

int ledPin = 13;

int buttonA_Pin = 22;
int buttonB_Pin = 24;
int buttonC_Pin = 26;
int buttonD_Pin = 28;
int buttonE_Pin = 30;
int buttonF_Pin = 32;
int buttonG_Pin = 34;
int buttonH_Pin = 36;


int peizoA_Pin = 23;
int peizoB_Pin = 25;
int peizoC_Pin = 27;
int peizoD_Pin = 29;
int peizoE_Pin = 31;
int peizoF_Pin = 33;
int peizoG_Pin = 35;
int peizoH_Pin = 37;

unsigned long buttonA_NextDetectTime = 0;
unsigned long buttonB_NextDetectTime = 0;
unsigned long buttonC_NextDetectTime = 0;
unsigned long buttonD_NextDetectTime = 0;
unsigned long buttonE_NextDetectTime = 0;
unsigned long buttonF_NextDetectTime = 0;
unsigned long buttonG_NextDetectTime = 0;
unsigned long buttonH_NextDetectTime = 0;


unsigned long peizoA_BuzzUntillTime = 0;
unsigned long peizoB_BuzzUntillTime = 0;
unsigned long peizoC_BuzzUntillTime = 0;
unsigned long peizoD_BuzzUntillTime = 0;
unsigned long peizoE_BuzzUntillTime = 0;
unsigned long peizoF_BuzzUntillTime = 0;
unsigned long peizoG_BuzzUntillTime = 0;
unsigned long peizoH_BuzzUntillTime = 0;


int nBlinks = 10;
int buzzDuration = 600;
int debounceTime = 700;
int rxMesage = 0;
int buzzDelay = 500; // note this delay is set in program loops not milliseconds
int halfBuzzDelay = buzzDelay/2 ;
int buzzCount = 0; 
int buzzState = 0;





void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonA_Pin, INPUT_PULLUP);
  pinMode(buttonB_Pin, INPUT_PULLUP);
  pinMode(buttonC_Pin, INPUT_PULLUP);
  pinMode(buttonD_Pin, INPUT_PULLUP);
  pinMode(buttonE_Pin, INPUT_PULLUP);
  pinMode(buttonF_Pin, INPUT_PULLUP);
  pinMode(buttonG_Pin, INPUT_PULLUP);
  pinMode(buttonH_Pin, INPUT_PULLUP);
  
  pinMode(peizoA_Pin, OUTPUT);
  pinMode(peizoB_Pin, OUTPUT);
  pinMode(peizoC_Pin, OUTPUT);
  pinMode(peizoD_Pin, OUTPUT);
  pinMode(peizoE_Pin, OUTPUT);
  pinMode(peizoF_Pin, OUTPUT);
  pinMode(peizoG_Pin, OUTPUT);
  pinMode(peizoH_Pin, OUTPUT);

}

void blinkLight()
{
  for (int i = 0 ; i <= nBlinks; i +=1)
  {
    digitalWrite(peizoA_Pin ,HIGH);
    delay(20);
    digitalWrite(peizoA_Pin ,LOW);
    delay(20);
    
  }
}

void checkButtons()
{

if (millis() > buttonA_NextDetectTime & digitalRead(buttonA_Pin) == LOW) {buttonA_NextDetectTime = millis() + debounceTime; Serial.print('A');} 
if (millis() > buttonB_NextDetectTime & digitalRead(buttonB_Pin) == LOW) {buttonB_NextDetectTime = millis() + debounceTime; Serial.print('B');} 
if (millis() > buttonC_NextDetectTime & digitalRead(buttonC_Pin) == LOW) {buttonC_NextDetectTime = millis() + debounceTime; Serial.print('C');} 
if (millis() > buttonD_NextDetectTime & digitalRead(buttonD_Pin) == LOW) {buttonD_NextDetectTime = millis() + debounceTime; Serial.print('D');} 
if (millis() > buttonE_NextDetectTime & digitalRead(buttonE_Pin) == LOW) {buttonE_NextDetectTime = millis() + debounceTime; Serial.print('E');} 
if (millis() > buttonF_NextDetectTime & digitalRead(buttonF_Pin) == LOW) {buttonF_NextDetectTime = millis() + debounceTime; Serial.print('F');} 
if (millis() > buttonG_NextDetectTime & digitalRead(buttonG_Pin) == LOW) {buttonG_NextDetectTime = millis() + debounceTime; Serial.print('G');} 
if (millis() > buttonH_NextDetectTime & digitalRead(buttonH_Pin) == LOW) {buttonH_NextDetectTime = millis() + debounceTime; Serial.print('H');} 

  
}

void confermLoged()
{
 while (Serial.available())
 {
   rxMesage = Serial.read();
   if (rxMesage == ascii_A) {peizoA_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_B) {peizoB_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_C) {peizoC_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_D) {peizoD_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_E) {peizoE_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_F) {peizoF_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_G) {peizoG_BuzzUntillTime = millis() + buzzDuration;}
   if (rxMesage == ascii_H) {peizoH_BuzzUntillTime = millis() + buzzDuration;}

   
 }
}

void pulseBuzzers()
{
 buzzCount += 1;
 if (buzzCount > buzzDelay) {buzzCount = 0;}
 if (buzzCount > halfBuzzDelay) {buzzState = 1; digitalWrite(13,HIGH);}
 else {buzzState = 0;digitalWrite(13,LOW);}
 
if (millis() < peizoA_BuzzUntillTime) {digitalWrite(peizoA_Pin, buzzState);}  
if (millis() < peizoB_BuzzUntillTime) {digitalWrite(peizoB_Pin, buzzState);}  
if (millis() < peizoC_BuzzUntillTime) {digitalWrite(peizoC_Pin, buzzState);}  
if (millis() < peizoD_BuzzUntillTime) {digitalWrite(peizoD_Pin, buzzState);}  
if (millis() < peizoE_BuzzUntillTime) {digitalWrite(peizoE_Pin, buzzState);}  
if (millis() < peizoF_BuzzUntillTime) {digitalWrite(peizoF_Pin, buzzState);}  
if (millis() < peizoG_BuzzUntillTime) {digitalWrite(peizoG_Pin, buzzState);}  
if (millis() < peizoH_BuzzUntillTime) {digitalWrite(peizoH_Pin, buzzState);}  



 
 
 // if millis() < piezroABuzzUntillTime
}

void loop()
{
 checkButtons();
 confermLoged();
 pulseBuzzers();
 //blinkLight();
}


