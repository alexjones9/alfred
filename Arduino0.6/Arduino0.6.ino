//#include <SPI.h>         // needed for Arduino versions later than 0018
//#include <Ethernet.h>
//#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
//IPAddress ip(192, 168, 1, 177);

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
//char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
//char command;


// An EthernetUDP instance to let us send and receive packets over UDP
//EthernetUDP Udp;

int sensorPin = A0;           
unsigned int sensorValue = 0;  
float voltage;
int movement = 0;

#define ECHOPIN1 2
#define TRIGPIN1 3
#define ECHOPIN2 4
#define TRIGPIN2 5
#define ROOM1 6
#define ROOM2 7
#define ROOM3 8
#define ALARM 11
char Mode;

void setup() {
   // start the Ethernet and UDP:
 // Ethernet.begin(mac, ip);
 // Udp.begin(localPort);


  Serial.begin(9600);
  pinMode(TRIGPIN1, OUTPUT);
  pinMode(ECHOPIN1, INPUT);
  pinMode(TRIGPIN2, OUTPUT);
  pinMode(ECHOPIN2, INPUT);
  pinMode(ALARM,OUTPUT);
  //pinmode everything
  
}



void room1On(){
  digitalWrite(ROOM1,HIGH);
}
void room2On(){
  digitalWrite(ROOM2,HIGH);
}
void room3On(){
  digitalWrite(ROOM3,HIGH);
}
void room1Off(){
   digitalWrite(ROOM1,LOW);
}
void room2Off(){
   digitalWrite(ROOM2,LOW);
}
void room3Off(){
   digitalWrite(ROOM3,LOW);
}
void DoorCam(){
  //EnterCamCodeHere
  
  
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
  Serial.println(distance);
  
  if (distance >= 50){ //range could be calculated at setup so room size doesn't affect? 
    movement = movement+1;
  }
  else {
    movement = 0;
    digitalWrite(ROOM1, HIGH);
    Serial.println(ROOM1);
  }
  Serial.println(movement);
 if (movement == 10) {  //placeholder value
    digitalWrite(ROOM, LOW);
 }

}

void HouseAlarm (int TRIGPIN, int ECHOPIN){
  float duration, distance;
  bool turnoff;
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance <= 200){ //range could be calculated at setup so room size doesn't affect?
    tone(ALARM, 2000);
    Serial.println("buzz");
  }
   
  turnoff = Serial.read(); //comman to turn off from website or keypad maybe?
  if (turnoff = true) {
    noTone(ALARM); 
 }

}




void loop(){
  //Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); 

 // Mode = packetBuffer;
 if (Serial.available()>0){
  Mode=Serial.read();
}
  
  switch(Mode){
    //room1On = a
    case 'a':
      room1On();
      break;
    //room2On = b
    case 'b':
      room2On();
      break;
    //room3On = c
    case 'c':
      room3On();
      break;
    //room1Off = d
    case 'd':
      room1Off();
      break;
    //room2Off = e
    case 'e':
      room2Off();
      break;
    //room3Off = f
    case 'f':
     room3Off();
     break;

    //HouseAlarm = h
    case 'h':
     HouseAlarm(TRIGPIN1, ECHOPIN1);
     break;

    //Light Auto off
    case 'm':
     MotionDetection(TRIGPIN1,ECHOPIN1,ROOM1);
     break;
  }
  
 }


