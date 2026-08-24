#include <Servo.h>
#include <Wire.h>
#define nume_sen_front 5
#define MAXVALUE 1000
#define nume_sen_back 3
#define PwmA 2
#define Ain1 22
#define Ain2 23
#define PwmC 5
#define Cin1 26
#define Cin2 27

unsigned int Position = 0;
int leftPower, rightPower;
int error, last_error;
int PIDValue;

int front_pin[7] = { 55, 56, 57, 58, 59, 60, 61 };
int MAX_SENSOR_F[7] = { 995, 993, 995, 994, 996, 993, 995 };
int MIN_SENSOR_F[7] = { 291, 389, 424, 254, 234, 160, 344 };
// int MAX_SENSOR_F[7] = { 997, 993, 994, 995, 998, 988, 998 };
// int MIN_SENSOR_F[7] = { 411, 572, 529, 299, 343, 437, 486 };


int back_pin[3] = { 69, 68, 67 };
int MAX_SENSOR_B[3] = { 991, 994, 995 };
int MIN_SENSOR_B[3] = { 194, 321, 359 };

unsigned int sensorValues[7];
unsigned int sensorValuesB[3];

Servo ms1;
Servo ms2;
Servo ms3;

void setup() {
  Serial.begin(9600);
  ms1.attach(9);
  ms2.attach(10);
  ms3.attach(30);
  smsv1(100, 1);
  smsv2(100, 4);  //100
  smsv3(70, 1);
  // pinMode(2, OUTPUT);
  // digitalWrite(2, HIGH);
  // pinMode(3, OUTPUT);
  // digitalWrite(3, HIGH);
  // Read_eye();
  // displayB();
  //  monitorSensorB();
  // displayValueF(1500);
  //  gujaarn();
}

void loop() {
  // fullcode();
  // if (digitalRead(7) == 1) {
    //   delay(300);
    //   // pink();
    //   // green();
    //   // yellow();
    // smsv2(0, 10);
    // keep_r();
    // b2_cross(80);
  // }
  fullcode_retry();
}

void mc(int speedL, int speedR) {
  constrain(speedL, -255, 255);
  constrain(speedR, -255, 255);

  if (speedL >= 0) {
    digitalWrite(Ain1, HIGH);
    digitalWrite(Ain2, LOW);
    analogWrite(PwmA, speedL);
  } else {
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, HIGH);
    analogWrite(PwmA, speedL * -1);
  }
  if (speedR >= 0) {
    digitalWrite(Cin1, HIGH);
    digitalWrite(Cin2, LOW);
    analogWrite(PwmC, speedR);
  } else {
    digitalWrite(Cin1, LOW);
    digitalWrite(Cin2, HIGH);
    analogWrite(PwmC, speedR * -1);
  }
}

// void mc(int speedL, int speedR) {
//   constrain(speedL, -255, 255);
//   constrain(speedR, -255, 255);
//   if (speedL >= 0) {
//     digitalWrite(Ain1, HIGH);
//     digitalWrite(Ain2, LOW);
//     analogWrite(PwmA, speedL);

//   } else {
//     digitalWrite(Ain1, LOW);
//     digitalWrite(Ain2, HIGH);
//     analogWrite(PwmA, speedL * -1);
//   }

//   if (speedR >= 0) {
//     digitalWrite(Cin1, HIGH);
//     digitalWrite(Cin2, LOW);
//     analogWrite(PwmC, speedR);

//   } else {
//     digitalWrite(Cin1, LOW);
//     digitalWrite(Cin2, HIGH);
//     analogWrite(PwmC, speedR * -1);
//   }
// }

void mct(int speed_L, int speed_R, int t) {
  long looptime;
  looptime = millis();
  while (millis() - looptime <= t) {
    mc(speed_L, speed_R);
  }
  stop();
}

void stop() {
  digitalWrite(Ain1, HIGH);
  digitalWrite(Ain2, HIGH);
  analogWrite(PwmA, 255);
  digitalWrite(Cin1, HIGH);
  digitalWrite(Cin2, HIGH);
  analogWrite(PwmC, 255);
}

void yt(int t) {
  digitalWrite(Ain1, HIGH);
  digitalWrite(Ain2, HIGH);
  analogWrite(PwmA, 255);
  digitalWrite(Cin1, HIGH);
  digitalWrite(Cin2, HIGH);
  analogWrite(PwmC, 255);
  delay(t);
}