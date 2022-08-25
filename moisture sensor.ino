#include <stdio.h>

//Refrence Values for Capacitive Sensor
int AirValue = 504;
int WaterValue = 194;

//data-in pin for Capacitive Sensor
int capacitive_data_pin = 0;

//Capacitive Sensor value
int capacitive_value = 0;
int capacitive_value_percent = 0;

//Resistive sensor pins 
int sensor_one = 7;
int sensor_two = 6;
int sensor_three = 5;

//Resistive sensor power
int sensor_vcc = 8;

// Resistive sensor value
int sensor_one_value = 0;
int sensor_two_value = 0;
int sensor_three_value = 0;

//delay interval
long int interval = 900000; //15 min 

//display pins
int diod_one = 1;
int diod_two = 2;
int diod_three = 3;
int diod_four = 4;

void setup() {


  //Capacitive sensor Setup value
  pinMode(capacitive_data_pin, INPUT);

  //Resistive sensor vcc and data-in setup
  pinMode(sensor_one, INPUT);
  
  pinMode(sensor_vcc, OUTPUT);
   
  pinMode(sensor_two, INPUT);

  pinMode(sensor_three, INPUT);

  //diod setup
  pinMode(diod_one, OUTPUT);
  pinMode(diod_two, OUTPUT);
  pinMode(diod_three, OUTPUT);
  pinMode(diod_four, OUTPUT);
   Serial.begin(9600);

}

void loop() {
   //power on sensors
  digitalWrite(sensor_vcc,HIGH);
  //reading sensor value
  sensor_one_value = digitalRead(sensor_one);
  sensor_two_value = digitalRead(sensor_two);
  sensor_three_value = digitalRead(sensor_three);

  capacitive_value = analogRead(capacitive_data_pin);
  capacitive_value_percent = map(capacitive_value_percent , AirValue, WaterValue, 0, 100);

  //sensor power off
  digitalWrite(sensor_vcc,LOW);

  //diod display
  if(sensor_one_value){
    digitalWrite(diod_one,HIGH);
  }else{
     digitalWrite(diod_one,LOW);
  }

  if(sensor_two_value){
    digitalWrite(diod_two,HIGH);
  }else{
     digitalWrite(diod_two,LOW);
  }
  
  if(sensor_three_value){
    digitalWrite(diod_three,HIGH);
  }else{
     digitalWrite(diod_three,LOW);
  }

  if(capacitive_value_percent <= 50){
    digitalWrite(diod_four,HIGH);
  }else{
     digitalWrite(diod_four,LOW);
  }
  //15 min delay to retain durability of resistive sensors
  delay(interval);

}
