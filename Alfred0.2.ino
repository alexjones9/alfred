#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
char command;


// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

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
   // start the Ethernet and UDP:
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);


  Serial.begin(9600);
  pinMode(TRIGPIN1, OUTPUT);
  pinMode(ECHOPIN1, INPUT);
  pinMode(TRIGPIN2, OUTPUT);
  pinMode(ECHOPIN2, INPUT);
  pinMode(ALARM,OUTPUT);
  //pinmode everything
  
  
}

void lights() {
  //Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); 
  command = packetBuffer;
  if (command = "1on"){ 
    digitalWrite(ROOM1,HIGH);
  }
  if (command = "2on"){
    digitalWrite (ROOM2, HIGH);
  }
  if (command = "3on") { 
    digitalWrite(ROOM3,HIGH);
  }
  if (command = "1off"){
    digitalWrite (ROOM1, LOW);
  }
  if (command = "2off") { 
    digitalWrite(ROOM2,LOW);
  }
  if (command = "3off") { 
    digitalWrite(ROOM3,LOW);
  }
}
 
void DoorCam(){
  //if doorbell = high
    //Serial.print("Doorbell is being rang")
  //send to website
  
  
}




void MotionDetection(int TRIGPIN, int ECHOPIN, int ROOM) {
  float duration, distance;
  int movement;
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 200){ //range could be calculated at setup so room size doesn't affect?
    ++movement;
  }
  else {
    movement = 0;
    digitalWrite(ROOM, HIGH);
  }

 if (movement = 50) {  //placeholder value
  digitalWrite(ROOM, LOW);
 }

}

void HouseAlarm (int TRIGPIN, int ECHOPIN){
  float duration, distance;
  int movement;
  bool turnoff;
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance <= 200){ //range could be calculated at setup so room size doesn't affect?
    tone(ALARM, 300);
  }
   
  turnoff = Serial.read(); //comman to turn off from website or keypad maybe?
  if (turnoff = true) {
    noTone(ALARM); 
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
  lights;
  MotionDetection(TRIGPIN1,ECHOPIN1,ROOM1);
  MotionDetection(TRIGPIN2,ECHOPIN2,ROOM2);
  HouseAlarm(TRIGPIN1, ECHOPIN1);
  HouseAlarm(TRIGPIN2, ECHOPIN2);
  
 }

