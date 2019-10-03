#include <VirtualWire.h>

const int transmit_pin = 6;
int openA,closeA;
int openB,closeB;
int openC,closeC;
int openD,closeD;
int openE,closeE;
struct package
{int index = 0.0;
  int   middle = 0.0;
  int ring = 0.0;
  int pinky = 0.0;
  int thumb = 0.0;
  
};

typedef struct package Package;
Package data;

void setup()
{
    //pinMode(8,OUTPUT);
    Serial.begin(9600);
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);
    delay(1000);
    Serial.println("intializing");
    Serial.println(".");
    delay(2000);
    openA=analogRead(A0);
     Serial.println(openA);
    delay(200);
    openB=analogRead(A1);
     Serial.println(openB);
    delay(200);
    openC=analogRead(A2);
     Serial.println(openC);
    delay(200);
    openD=analogRead(A3);
     Serial.println(openD);
    delay(200);
    openE=analogRead(A4);
    Serial.println(openE);
    delay(1000);
    Serial.println("now close your fingers");
    //digitalWrite(8,HIGH);
    Serial.println(".");
    delay(1000);
    Serial.println(".");
    delay(1000);
    Serial.println(".");
    delay(1000);
    Serial.println(".");
    delay(1000);



    closeA=analogRead(A0);
     Serial.println(closeA);
    delay(200);
    closeB=analogRead(A1);
     Serial.println(closeB);
    delay(200);
    closeC=analogRead(A2);
     Serial.println(closeC);
    delay(200);
    closeD=analogRead(A3);
     Serial.println(closeD);
    delay(200);
    closeE=analogRead(A4);
    Serial.println(closeE);
    delay(200);
    //digitalWrite(8,LOW);
    Serial.println("done!!!");
    delay(1000);
}

void loop()
{
   // Flash a light to show transmitting
  data.index=map(analogRead(A1),openB, closeB, 0, 180);
  data.index=map(data.index,0, 180, 150, 400);
  if(data.index>400)
    data.index=400;
   else if(data.index < 150 )
    data.index=150;
   Serial.print("\n INDEX : ");
  Serial.print(data.index);
  data.ring=map(analogRead(A3),openD, closeD, 0, 180);
  data.ring=map(data.ring,0, 180, 150, 400);
   Serial.print(" RING : ");
    if(data.ring>400)
    data.ring=400;
   else if(data.ring < 150 )
    data.ring=150;
  Serial.print(data.ring);
  data.middle=map(analogRead(A2), openC, closeC, 0, 180);
  data.middle=map(data.middle, 0, 180, 150, 400);
   if(data.middle>400)
    data.middle=400;
   else if(data.middle < 150 )
    data.middle=150;
  Serial.print(" MIDDLE : ");
  Serial.print(data.middle);
  data.thumb=map(analogRead(A0), openA, closeA, 0, 180);
  data.thumb=map(data.thumb, 0, 180, 150, 400);
   if(data.thumb>400)
    data.thumb=400;
   else if(data.thumb < 150 )
    data.thumb=150;
  Serial.print(" THUMB : ");
  Serial.print(data.thumb);
  data.pinky=map(analogRead(A4), openE , closeE , 0, 180);
  data.pinky=map(data.pinky, 0, 180, 150, 400);
   if(data.pinky>400)
    data.pinky=400;
   else if(data.pinky < 150 )
    data.pinky=150;
   Serial.print(" PINKY : ");
  Serial.print(data.pinky);

  
  vw_send((uint8_t *)&data, sizeof(data));
  vw_wait_tx(); // Wait until the whole message is gone
  
  delay(500);
}
