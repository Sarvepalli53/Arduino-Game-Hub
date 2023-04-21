
#include <Servo.h>
Servo sx;
Servo sy;//defining our servos for maze game
//defining joystick pins
int joyx=A0;
int joyy=A1;
int joyval;//variable to read value from analog pins

float checkdistance_0_1()//function for the detection of hands by ultrasonic sensor 
{
digitalWrite(0, LOW);
delayMicroseconds(2);
digitalWrite(0, HIGH);
delayMicroseconds(10);
digitalWrite(0, LOW);
float distance = pulseIn(1, HIGH) / 58.00;
delay(10);
return distance;
}
Servo servo_7;
Servo servo_4;
Servo servo_6;//three servos for rock ,paper and scissor
volatile long  A;//variable for choosing random servo motor

void setup()
{
  
sx.attach(3);//attaching digital pins 
sy.attach(5);
pinMode(0, OUTPUT);
pinMode(1, INPUT);
servo_7.attach(7);    // rock
servo_4.attach(4);    // paper
servo_6.attach(6);     // scissor
servo_7.write(179);
servo_4.write(179);
servo_6.write(179);
Serial.begin(9600);
}


void loop()
{ 
  //code for maze game
   //read the value of joystick (between 0 to 1023)
  joyval=analogRead(joyx);
  joyval=map(joyval,0,1023,0,180);
  sx.write(joyval);//set the servo position according to the joystick value
  joyval=analogRead(joyy);
  joyval=map(joyval,0,1023,0,180);
  sy.write(joyval);
//  delay(15);
  //code for rock paper scissor game
if (checkdistance_0_1() < 10)//getting input from ultrasonic sensor 
{
A = random(0, 4);//randomly choosing one of the servo motors
switch (A) {
case 1:
servo_7.write(120);
delay(1000);
servo_7.write(179);
delay(500);
break;
case 2:
servo_4.write(120);
delay(1000);
servo_4.write(179);
delay(500);
break;
case 3:
servo_6.write(120);
delay(1000);
servo_6.write(179);
delay(500);
break;
}
}
}
