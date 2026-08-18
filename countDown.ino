‎#include <EEPROM.h>
‎#include <RTClib.h>
‎
‎RTC_DS1307 rtc;
‎
‎int A = 2, B = 3, C = 4, D = 5, E = 6, F = 7, G = 8, DP = 9, D1 = 10, D2 = 11, D3 = 12, D4 = 13, buzzer = A1, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0, digit_position= -1;
unsigned long start = 0, stop = 0;
‎
‎int seg_outputs [8] = {A, B, C, D, E, F, G, DP};
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
int digit[4]  = {digit1, digit2, digit3, digit4};

‎void setDisplay(int input, int digit_position){
‎   for (int i=0; i<(sizeof(digits_output)/sizeof(digits_output[0])); i++){
‎        if (i == digit_position){
‎           continue;
‎        }else{
‎          digitalWrite(digits_output[digit_position], LOW);
‎          }
‎        digitalWrite(digits_output[digit_position], HIGH);
‎   for (int i=0; i<(sizeof(segs[0])/sizeof(segs[0][0])); i++){
‎        digitalWrite(seg_outputs[i], segs[input][i]);
‎     }
‎   }
}
‎
‎void setup(){
‎     for (int i = 0; i < (sizeof(seg_outputs)/sizeof(seg_outputs[0])); i++){
‎         pinMode(seg_outputs[i], OUTPUT);
‎         digitalWrite(seg_outputs[i], LOW);

      for (int i = 0; i<(sizeof(digit)/sizeof(digit[0])); i++){
         pinMode(digits_output[i], OUTPUT);
         digitalWrite(digits_output[i], OUTPUT);
      }
      digitalWrite(buzzer, LOW);
      pinMode(buzzer, OUTPUT);
‎      Serial.begin(9600);
‎      rtc.begin();
      EEPROM.get(0, stop);
‎         
‎      while (!Serial){;}
‎       }
‎}
‎
‎void loop(){
‎     DateTime now = rtc.now();
     currentTime = now.unixtime();
     if (currentTime >= stop){
       for (int i = 0; i< (sizeof(digit)/sizeof(digit[0])); i++){
         input = 0;
         setDisplay(input, digit_position);
         digit[digit_position+=1] = input;

        while(true){
         analogWrite(buzzer, HIGH);
         while(Serial.available()==0){;}
         buzzer_input = Serial.println("Type 'STOP' to shut off alarm")

         if (buzzer_input == "STOP"){
           break;
         }else{
            Serial.println("Buzzer input not recognized.");
         }
        }
     }else if ((currentTime<stop) && (currentTime>0)){
        
     }
     Serial.println("Enter hr/min/sec based on countdown duration");
     timeUnit = Serial.readStringUntil('\n');
‎     if ((timeUnit == "hr") || (timeUnit == "Hr") || (timeUnit == "hR") || (timeUnit == "HR")){
‎        Serial.println("Enter the hour (First digit)");
‎        while(Serial.available() == 0){;}
‎        input = Serial.parseint();
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       Serial.println("Enter the hour (Second digit)");
‎       while(Serial.available() == 0){;}
‎       input = Serial.parseint();
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎      Serial.println("Enter the minute (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎      Serial.println("Enter the minute (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;

       hours = (digit1 * 10 + digit2) * 60 * 60;
       mins = (digit3 * 10 + digit4) * 60;
       start = now.unixtime();
       stop = start + hours + mins;
       EEPROM.put(0, stop);
‎  }else if ((timeUnit == "min") || (timeUnit == "Min") || (timeUnit == "MIN")){
‎       Serial.println("Enter the min (First digit)");
‎       while(Serial.available() == 0){;}
‎        input = Serial.parseint();
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       Serial.println("Enter the min (Second digit)");
‎       while(Serial.available() == 0){;}
‎       input = Serial.parseint();
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎      Serial.println("Enter the sec (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎     Serial.println("Enter the sec (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;

      mins = (digit1 * 10 + digit2) * 60;
      secs = (digit3 * 10 + digit4);
      start = now.unixtime();
      stop = start + mins + secs;
      EEPROM.put(0, stop);
‎    }else if((timeUnit == "sec") || (timeUnit == "Sec") || timeUnit = "SEC")){
‎        input = 0;
‎        setDisplay(input, digit_position);
‎        digit[digit_position+=1] = input;
‎
‎       input = 0;
‎       setDisplay(input, digit_position);
‎       digit[digit_position+=1] = input;
‎  
‎       Serial.println("Enter the sec (First digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;
‎
‎     Serial.println("Enter the sec (Second digit)");
‎      while(Serial.available() == 0){;}
‎      input = Serial.parseint();
‎      setDisplay(input, digit_position);
‎      digit[digit_position+=1] = input;

      secs = (digit3 * 10 + digit4);
      start = now.unixtime();
      stop = start + secs;
      EEPROM.put(0, stop);
‎      }
‎
‎      while(true){
‎           for (int i=0; i<(sizeof(digit)/sizeof(digit[0])); i++){
‎              digit_position = i;
‎              setDisplay(digit[i], digit_position);
‎           }
‎           
‎            while(Serial.available() >0){
‎              String command =
‎              Serial.readStringUntil('\n');
‎              if (command == "STOP"){
‎                digit_position = 1;
‎                break;
‎              }else{
‎                 Serial.println("Request not recorded");
               }
            }
‎       }
}
