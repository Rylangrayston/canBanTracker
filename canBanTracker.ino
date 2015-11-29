int ascii_A = 65;
int ascii_B = 66;
int ascii_C = 67;
int ascii_D = 68;
int ascii_E = 69;
int ascii_F = 70;
int ascii_G = 71;
int ascii_H = 72;
int ascii_I = 73;

int ledPin = 13;
int ledPinConnection = 22;

int buttonA_Pin = 28; //new 24 26 28, 30 32 34, 36 38 40, 42 44 46
int buttonB_Pin = 34;
int buttonC_Pin = 40;
int buttonD_Pin = 46;
int buttonE_Pin = 4;
int buttonF_Pin = 4;
int buttonG_Pin = 4;
int buttonH_Pin = 4;


int peizoA_Pin = 26;
int peizoB_Pin = 32;
int peizoC_Pin = 38;
int peizoD_Pin = 44;
int peizoE_Pin = 31;
int peizoF_Pin = 33;
int peizoG_Pin = 35;
int peizoH_Pin = 37;

int ledA_Pin = 24; //new 
int ledB_Pin = 30; 
int ledC_Pin = 36; 
int ledD_Pin = 42; 
int ledE_Pin = 3; 
int ledF_Pin = 3; 
int ledG_Pin = 3; 
int ledH_Pin = 3; 


unsigned long timeAtLastConnection = 0;
int checkConnectionPeriod = 10000;
int connectionCount = 0;

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
int buzzDelay = 200; // note this delay is set in program loops not milliseconds
int halfBuzzDelay = buzzDelay/2 ;
int buzzCount = 0; 
int buzzState = 0;





void setup()
{
  Serial.begin(19200);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPinConnection, OUTPUT);
  
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
  
  pinMode(ledA_Pin, OUTPUT); //new
  pinMode(ledB_Pin, OUTPUT); 

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
   if (rxMesage == ascii_I) {digitalWrite(ledPinConnection, HIGH); timeAtLastConnection = millis();}   


   
 }
}

void pulseBuzzers()
{
 buzzCount += 1;
 if (buzzCount > buzzDelay) {buzzCount = 0;}
 if (buzzCount > halfBuzzDelay) {buzzState = 1; digitalWrite(13,HIGH);}
 else {buzzState = 0;digitalWrite(13,LOW);}
 
if (millis() < peizoA_BuzzUntillTime) {digitalWrite(peizoA_Pin, buzzState); digitalWrite (ledA_Pin, HIGH);}  else{digitalWrite(ledA_Pin, LOW);}
if (millis() < peizoB_BuzzUntillTime) {digitalWrite(peizoB_Pin, buzzState); digitalWrite (ledB_Pin, HIGH);}  else{digitalWrite(ledB_Pin, LOW);}  
if (millis() < peizoC_BuzzUntillTime) {digitalWrite(peizoC_Pin, buzzState); digitalWrite (ledC_Pin, HIGH);}  else{digitalWrite(ledC_Pin, LOW);}
if (millis() < peizoD_BuzzUntillTime) {digitalWrite(peizoD_Pin, buzzState); digitalWrite (ledD_Pin, HIGH);}  else{digitalWrite(ledD_Pin, LOW);}  
if (millis() < peizoE_BuzzUntillTime) {digitalWrite(peizoE_Pin, buzzState); digitalWrite (ledE_Pin, HIGH);}  else{digitalWrite(ledE_Pin, LOW);}  
if (millis() < peizoF_BuzzUntillTime) {digitalWrite(peizoF_Pin, buzzState); digitalWrite (ledF_Pin, HIGH);}  else{digitalWrite(ledF_Pin, LOW);}  
if (millis() < peizoG_BuzzUntillTime) {digitalWrite(peizoG_Pin, buzzState); digitalWrite (ledG_Pin, HIGH);}  else{digitalWrite(ledG_Pin, LOW);}
if (millis() < peizoH_BuzzUntillTime) {digitalWrite(peizoH_Pin, buzzState); digitalWrite (ledH_Pin, HIGH);}  else{digitalWrite(ledH_Pin, LOW);}
}


void ping()
{
connectionCount += 1;
if (connectionCount > checkConnectionPeriod)
{
connectionCount = 0;
 Serial.print('I');
 if (millis() - timeAtLastConnection > 1200){ digitalWrite(ledPinConnection, LOW); }
 
}
 
}
 
 
 // if millis() < piezroABuzzUntillTime


void loop()
{
 checkButtons();
 confermLoged();
 pulseBuzzers();
 ping();
 //blinkLight();
}


