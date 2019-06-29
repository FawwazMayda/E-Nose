unsigned long previousMillis = 0;        
unsigned long previousMillis2 = 0;
const long interval = 5000; 
const long interval2 = 70;
bool fanstate = false;
//int smokeA0 = A0;
int sensor0=PA0;
int sensor1=PA1;
int sensor2=PA2;
int sensor3=PA3;
int sensor4=PA4;
int sensor5=PA5;
int sensor6=PA6;
int sensor7=PA7;
int id=1;
int s0,s1,s2,s3,s4,s5,s6,s7;
void setup() {
  // set the digital pin as output:
  
  pinMode(PA10, OUTPUT);
  pinMode(PB0, OUTPUT);
//  pinMode(smokeA0, INPUT);
Serial.begin(9600);
delay(3000);
}

void cetak(){
  s0 = analogRead(sensor0);
  s1 = analogRead(sensor1);
  s2 = analogRead(sensor2);
  s3 = analogRead(sensor3);
  s4 = analogRead(sensor4);
  s5 = analogRead(sensor5);
  s6 = analogRead(sensor6);
  s7 = analogRead(sensor7);
  String s ="";
  s += String(s0);
  s += ",";
  s += String(s1);
  s += ",";
  s += String(s2);
  s += ",";
  s += String(s3);
  s += ",";
  s += String(s4);
  s += ",";
  s += String(s5);
  s += ",";
  s += String(s6);
  s += ",";
  s += String(s7);
  Serial.println(s);
}
void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (fanstate == false) {
        digitalWrite(PA10, HIGH);   // turn the LED on (HIGH is the voltage level)                    // wait for a second
        digitalWrite(PB0, LOW);    // turn the LED off by making the voltage LOW
        fanstate = true;
    } else {
        digitalWrite(PA10, LOW);   // turn the LED on (HIGH is the voltage level)                    // wait for a second
        digitalWrite(PB0, HIGH);
        fanstate = false;
        id++;
    }
    
  }

  if (currentMillis - previousMillis2 >= interval2){
    previousMillis2 = currentMillis;
    cetak();
  }
  }
     
