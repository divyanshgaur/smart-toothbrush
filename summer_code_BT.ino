#include <SoftwareSerial.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

int force=A0;
MPU6050 mpu;
SoftwareSerial BTserial(0,1); //RX/TX

int16_t ax, ay, az;
int16_t gx, gy, gz;
float x_acc, gyro;

void setup() {
  // put your setup code here, to run once:
BTserial.begin(9600);
//Serial.println("Initialize MPU");
pinMode(force,INPUT);
mpu.initialize();
}

void loop(){

mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  //Serial.print("ax= "); 
  BTserial.print(ax); 
  BTserial.print("\t\t");
  //Serial.print("ay= "); 
  BTserial.print(ay); 
  BTserial.print("\t\t");
  //Serial.print("az= "); 
  BTserial.print(az); 
  BTserial.print("\t\t");
  //Serial.print("gx= "); 
  BTserial.print(gx); 
  BTserial.print("\t\t");
  //Serial.print("gy= "); 
  BTserial.print(gy); 
  BTserial.print("\t\t");
  //Serial.print("gz= "); 
  BTserial.print(gz); 
  BTserial.print("\t\t");
  //Serial.print("force= "); 
  BTserial.print(analogRead(force));
  delay(100);
  BTserial.println();
}
