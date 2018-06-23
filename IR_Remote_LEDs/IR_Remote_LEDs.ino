#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

          switch(results.value){
            case 0xFF30CF:
            Serial.println("1");
            analogWrite(9, 255);
            break ;
            case 0xFF18E7:
            Serial.println("2");
            analogWrite(10, 255);
            break ;
            case 0xFF38C7:
            Serial.println("5");
            analogWrite(9, 0);
            break ;
            case 0xFF5AA5:
            Serial.println("6");
            analogWrite(10, 0);
            break ;
            }
        key_value = results.value;
        irrecv.resume();

  }
}
