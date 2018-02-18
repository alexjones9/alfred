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
#define ALARM 10


void setup() {

  Serial.begin(9600);
  pinMode(TRIGPIN1, OUTPUT);
  pinMode(ECHOPIN1, INPUT);
  pinMode(TRIGPIN2, OUTPUT);
  pinMode(ECHOPIN2, INPUT);
  pinMode(ALARM,OUTPUT);
  //pinmode everything
  
  
}


 
void DoorCam(){
  //if doorbell = high
    //Serial.print("Doorbell is being rang")
  //send to website
  
  
}




void MotionDetection(int TRIGPIN, int ECHOPIN, int ROOM) {
  float duration, distance;
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 10){ //range could be calculated at setup so room size doesn't affect?
    ++movement;
  }
  //else reset movement

 if movement = 50 {
  digitalWrite(ROOM, LOW);
 }

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
  MotionDetection(TRIGPIN1,ECHOPIN1,ROOM1);
  
  
 }


