#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ); // create motor #1, 1KHz pwm
AF_DCMotor motor2(2, MOTOR12_1KHZ); // create motor #2, 1KHz pwm
AF_DCMotor motor3(3, MOTOR12_1KHZ); // create motor #3, 1KHz pwm
AF_DCMotor motor4(4, MOTOR12_1KHZ); // create motor #4, 1KHz pwm
int pos;
int LED = 12;
void setup() {
motor1.setSpeed(200);
motor2.setSpeed(200);
motor3.setSpeed(200);
motor4.setSpeed(200);
Serial.begin (9600);
}

void loop() {  
if (Serial.available()) {
  pos = Serial.read();
  //int pos = Serial.parseInt();  //pos can change in range 1-11
  Serial.println (pos);
  
    
  if  (pos =='1'){
    Serial.print("North");
    motor1.run(FORWARD); // EDET VPERED
   motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    digitalWrite(LED, HIGH);
  }
  if  (pos =='2'){
    Serial.print("South");
    motor1.run(BACKWARD); // EDET NAZAD
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  if  (pos =='3'){
    Serial.print("East");
    motor1.run(BACKWARD); // EDET VPRAVO
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
  }
  if  (pos =='4'){
    Serial.print("West");
    motor1.run(FORWARD); // EDET VLEVO
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
  }
  if  (pos =='5'){
    Serial.print("NORTH_EAST");
    motor1.run(RELEASE); // EDET PO DIAGONALI VPRAVO VPERED
    motor2.run(FORWARD);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
  }
  if  (pos =='6'){
    Serial.print("NORTH_WEST");
    motor1.run(FORWARD); // EDET PO DIAGONALI VLEVO VPERED
    motor2.run(RELEASE);
    motor3.run(FORWARD);
    motor4.run(RELEASE);
  }
  if  (pos =='7'){
    Serial.print("SOUTH_WEST");
    motor1.run(RELEASE); // EDET PO DIAGONALI VLEVO NAZAD
    motor2.run(BACKWARD);
    motor3.run(RELEASE);
    motor4.run(BACKWARD);
  }
  if  (pos =='8'){
    Serial.print("SOUTH_EAST");
    motor1.run(BACKWARD); // EDET PO DIAGONALI VPRAVO NAZAD
    motor2.run(RELEASE);
    motor3.run(BACKWARD);
    motor4.run(RELEASE);
  }
  if  (pos =='r'){
    Serial.print("ClockWise");
    motor1.run(BACKWARD); // POVOROT PO CHASOVOY
   motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
  }
  if  (pos =='l'){
    Serial.print("CounterClockWise");
    motor1.run(FORWARD); // POVOROT PROTIV CHASOVOY
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
  }
  if  (pos =='0'){
    Serial.print("stop");
    motor1.run(RELEASE); // STOP
     
    motor2.run(RELEASE);
    motor3.run(RELEASE);
     motor4.run(RELEASE);
     digitalWrite(LED, LOW);
  }

  }
}
