#include <Arduino.h>
int led;

//String myString = ""; //接收串口发送过来的值

char x;

int led_state[] = {0,0,0,0,0,0,0};//除第一位外储存引脚状态

int led_ID[] = {0,13,12,14,27,26,25};//将具体引脚转化为1~6


// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  for (int i = 1; i < 7; i++)
  {
    pinMode(led_ID[i],OUTPUT);
    digitalWrite(led_ID[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    //myString = Serial.readStringUntil('\n');
    x = Serial.read();
    led = int (x - '0');
    if (led == 0)
    {

    }
    else if (led > 6||led < 0)
    {
      Serial.println("input error(1~6)");

    }
    else
    {
      if (led_state[led] == 0)
      {
        digitalWrite(led_ID[led], HIGH);
        led_state[led] = 1;
        Serial.print("LED ");
        Serial.print(led);
        Serial.println(" is on");
      }else
      {
        digitalWrite(led_ID[led], LOW);
        led_state[led] = 0;
        Serial.print("LED ");
        Serial.print(led);
        Serial.println(" is off");
      }
    }
  }
}

// put function definitions here:

