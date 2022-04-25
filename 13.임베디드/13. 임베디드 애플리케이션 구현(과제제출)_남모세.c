// C++ code
//
int PIN_LED11 = 11;
int PIN_LED10 = 10;
int PIN_LED9 = 9;
int PIN_LED8 = 8;
int PIN_TRIGER = 6;
int PIN_ECHO = 7;

void setup()
{
  pinMode(PIN_LED11, OUTPUT);
  pinMode(PIN_LED10, OUTPUT);
  pinMode(PIN_LED9, OUTPUT);
  pinMode(PIN_LED8, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT); 
  
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO, HIGH);
  int cm = distance / 58;
  
  if(cm > 150){
    Serial.println(0);
  	digitalWrite(PIN_LED11, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED8, LOW);
  } else if(cm <= 150 && cm > 120){
    Serial.println(1);
    digitalWrite(PIN_LED11, HIGH);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED8, LOW);
  } else if(cm <= 120 && cm > 90){
    Serial.println(2);
    digitalWrite(PIN_LED11, HIGH);
    digitalWrite(PIN_LED10, HIGH);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED8, LOW);    
  } else if(cm <= 90 && cm > 60){
    Serial.println(3);
    digitalWrite(PIN_LED11, HIGH);
    digitalWrite(PIN_LED10, HIGH);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED8, LOW);
  } else if(cm <= 60) {
    Serial.println(4);
    digitalWrite(PIN_LED11, HIGH);
    digitalWrite(PIN_LED10, HIGH);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED8, HIGH);
  }
}