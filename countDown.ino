‎#include <EEPROM.h>
‎#include <RTClib.h>
‎
‎RTC_DS1307 rtc;
‎
‎int A = 2;
‎int B = 3;
‎int C = 4;
‎int D = 5;
‎int E = 6;
‎int F = 7;
‎int G = 8;
‎int DP = 9;
‎int D1 = 10;
‎int D2 = 11;
‎int D3 = 12;
‎int D4 = 13;
‎
‎int seg_outputs [7] = {A, B, C, D, E, F, G, DP};
‎
‎int digits_output [4] = {D1, D2, D3, D4};
‎
‎int segs [10][7] = {
‎  {0,1,1,1,1,1,1,0},
‎  {0,0,1,1,0,0,0,0},
‎  {0,1,1,0,1,1,0,1},
‎  {0,1,1,1,1,0,0,1},
‎  {0,0,1,1,0,0,1,1},
‎  {0,1,0,1,1,0,1,1},
‎  {0,1,0,1,1,1,1,1},
‎  {0,1,1,1,0,0,0,0},
‎  {0,1,1,1,1,1,1,1},
‎  {0,1,1,1,0,0,1,1}
‎};
‎
‎void setDisplay(int input, int digit_position){
‎   for (int i=0; i<(sizeof(digits_output)/sizeof(digits_output[0])):
‎        if (i == digit_position){
‎           continue;
‎        }else{
‎          digitalWrite(digits_output[digit_position], LOW);
‎          }
‎        digitalWrite(digits_output[digit_position], HIGH);
‎   for (int i=0; i<(sizeof(segs[0])/sizeof(segs[0][0])); i++){
‎        digitalWrite(seg_outputs[i], segs[input][i]);
‎     }
‎}
‎
‎int digit_position= -1;
‎
‎int digit1 = 2;
‎int digit2 = 4;
‎int digit3 = 6;
‎int digit4 = 0;
‎int digit[4]  = {digit1, digit2, digit3, digit4};
‎
‎void setup(){
‎     for (int i = 0; i < (sizeof(seg_outputs)/sizeof(seg_outputs[0])); i++;){
‎         pinMode(seg_outputs[i], OUTPUT);
‎         digitalWrite(seg_outputs[i], LOW);
‎         Serial.begin(9600);
‎         rtc.begin();
‎         
‎         while (!serial){;}
‎       }
‎}
‎
‎void loop(){
‎     DateTime now = rtc.now();
‎     if ((timeUnit == "hr") || (timeUnit == "Hr") || (timeUnit == "hR") || (timeUnit == "HR"){
‎        Serial.println("Enter the hour (First digit)");
‎        while(Serial.available() == 0){;}
‎        input = Serial.parseint();
‎        hour_digit1 = input;
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       Serial.println("Enter the hour (Second digit)");
‎       while(Serial.available() == 0){;}
‎       input = Serial.parseint();
‎       hour_digit2 = input;
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎      Serial.println("Enter the minute (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      min_digit1 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎      Serial.println("Enter the minute (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      min_digit2 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎  }else if ((timeUnit == "min") || (timeUnit == "Min") || (timeUnit == "MIN")){
‎       Serial.println("Enter the min (First digit)");
‎       while(Serial.available() == 0){;}
‎        input = Serial.parseint();
‎        min_digit1 = input;
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       Serial.println("Enter the min (Second digit)");
‎       while(Serial.available() == 0){;}
‎       input = Serial.parseint();
‎       min_digit2 = input;
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎      Serial.println("Enter the sec (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      sec_digit1 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎     Serial.println("Enter the sec (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      sec_digit2 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎    }else if((timeUnit == "sec") || (timeUnit == "Sec") || timeUnit = "SEC")){
‎        input = 0;
‎        min_digit1 = input;
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       input = 0;
‎       min_digit2 = input;
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎       Serial.println("Enter the sec (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      sec_digit1 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎     Serial.println("Enter the sec (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      sec_digit2 = input;
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎      }
‎
‎      while(true){
‎           for (int i=0; i<(sizeof(digit)/sizeof(digit[0])); i++;){
‎              digit_position = i;
‎              setDisplay(digit[i], digit_position);
‎           }
‎           
‎            while(Serial.available() == 0){;}
‎            String command =
‎            Serial.readStringUntil('\n');
‎            if (command == "STOP"){
‎              digit_position = 1;
‎              break;
‎            }else{
‎                Serial.println("Request not recorded");
‎             }
