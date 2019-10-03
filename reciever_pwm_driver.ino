#include <Wire.h>

#include <VirtualWire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
int thumb = 0;
int index = 1;
int middle = 2;
int ring = 3;
int pinky = 4;
const int receive_pin = 8;

struct package
{
  int index = 0.0;
  int middle = 0.0;
  int ring = 0.0;
  int pinky = 0.0;
  int thumb = 0.0;


};
typedef struct package Package;
Package data;
void setup()
{
  Serial.begin(9600);
  // Initialise the IO and ISR
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);   // Bits per sec

  vw_rx_start();  // Start the receiver PLL running
  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);


}
void loop()
{
  uint8_t buf[sizeof(data)];
  uint8_t buflen = sizeof(data);
  if (vw_have_message())  // Is there a packet for us?
  {
    vw_get_message(buf, &buflen);
    memcpy(&data, &buf, buflen);

    Serial.print("  index : ");
    Serial.print(data.index);
    Serial.print("  middle : ");
    Serial.print(data.middle);
    Serial.print("  thumb : ");
    Serial.print(data.thumb);
    Serial.print("  ring : ");
    Serial.print(data.ring);
    Serial.print("  pinky : ");
    Serial.print(data.pinky);
    Serial.println();
    pwm.setPWM(thumb, 0, data.thumb);
    delay(50);
    pwm.setPWM(index, 0, data.index);
    delay(50);
    pwm.setPWM(middle, 0, data.middle);
    delay(50);
    pwm.setPWM(ring, 0, data.ring);
    delay(50);
    pwm.setPWM(pinky, 0, data.pinky);
    delay(50);

  }


}
