int sensorPin = A0;            
unsigned int sensorValue = 0;  
float voltage;

#define ECHOPIN1 2
#define TRIGPIN1 3
#define ECHOPIN2 4
#define TRIGPIN2 5
#define ROOM1 6
#define ROOM2 7
#define ROOM3 8
#define BUZZ 10
#defi
void setup() {

  Serial.begin(9600)
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(BUZZ,OUTPUT);
  //pinmode everything
  
  
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

void LightingRoom1On(){
 digitalWrite(YELLOW1,HIGH); 
}

void LightingRoom2On(){
 digitalWrite(YELLOW2,HIGH);
}


void LightingRoom1Off(){
   // make a delay for 30 mins ish then read IR again 
   // if IRroom1 = low 
   //   digitalWrite(YELLOW1,LOW)
   // 
}

void LightingRoom2Off(){
   // make a delay for 30 mins ish then read IR again use count
   // if IRroom2 = low 
   //   digitalWrite(YELLOW2,LOW)
   // 
}

void HouseAlarm (){
  // if alarmOn = HIGH 
  //    IR1 = HIGH
  //    tone(BUZZ,400);
  //    noTone (30);
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

  
// IR SENSOR USE A COUNT!!!! We need 2 IR sensors and set off the alarm once it has been set 
//int irRead(int readPin, int triggerPin)
//{
 // int halfPeriod = 13; s
  //int cycles = 38; 
  //int i;
 // for (i=0; i <=cycles; i++)
 // {
   // digitalWrite(triggerPin, HIGH); 
   // delayMicroseconds(halfPeriod);
   // digitalWrite(triggerPin, LOW); 
   // delayMicroseconds(halfPeriod - 1);    
 // }
 // return digitalRead(readPin);
//}

  
  
  buttonstate = digitalRead(buttonPin);
  if (buttonstate == HIGH){
    Serial.print ("d");
    tone(BUZZ,400);
    delay (400);
    noTone;
  }

   
}


