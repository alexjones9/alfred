int sensorPin = A0;            
unsigned int sensorValue = 0;  
float voltage;
#define ECHOPIN  3
#define TRIGPIN  2
int YELLOW = 4;
int BUZZ = 5;
int RED = 9;
int GREEN = 8;
int SENSOR = 11;
buttonstate = 0;
const int buttonPin = 12; 

char Mode;
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  digitalWrite(8,LOW);
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode (RED, OUTPUT);
  pinMode (GREEN,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  
  
}
void DoorCam(){
  
  //Serial.print("Doorbell is being rang would you like to activate camera? Enter, Y or N")
  //send too website
  //recieve message and print in serial
  //if Serial.read = "Y"
  // send the output to the website or application
  //Serial.print ("Camera will now send live footage please wait")
  //else
  //Serial.print("Camera deactivated") 
  
}

void PedestrianMode(){
   digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float distance = pulseIn(ECHOPIN, HIGH); // return 0 if no high pulse in 1sec
 distance = distance/58;
 Serial.print(distance);
 Serial.println("cm");
 delay(200);

 
   digitalWrite(RED,HIGH);
        delay(2000);
   digitalWrite(RED,LOW);
         
   digitalWrite (YELLOW,HIGH);
          delay(1000);
   digitalWrite(YELLOW,LOW);
  
  digitalWrite (GREEN,HIGH);
          delay(2000);
   digitalWrite(GREEN,LOW);
  
   digitalWrite (YELLOW,HIGH);
          delay(1000);
   digitalWrite(YELLOW,LOW);
   
 if (distance < 10) {
  int i = 0;
  for (i = 0; i < 10; i += 1){
  digitalWrite (RED, LOW);
  digitalWrite (GREEN,LOW);
  tone(BUZZ,400);
  digitalWrite (YELLOW, HIGH);
  delay (100);
  digitalWrite (YELLOW,LOW);
  delay (100);
  noTone (5);
}
  }
}

void WakeUpAlarm(){
  // get real time
  //Alarm = (ReceiveTime)
  //CurrentTime
  //if RecieveTime = CurrentTime
  //tone(BUZZ,400);
  //noTone (30);
}
void loop(){
  // put your main code here, to run repeatedly:

buttonstate = digitalRead(buttonPin);
if (buttonState == HIGH){
  Serial.print ("d")
  tone(BUZZ,400);
  delay (400)
  noTone
}

if (Serial.available()>0){
  Mode=Serial.read();
}
  switch(Mode){
  
    case 'A':
      WakeUpAlarm();
      break;
     case 'p':
      PedestrianMode();
      break;
     case 'd':
      Doorbell();
      break;
  }
 
}


