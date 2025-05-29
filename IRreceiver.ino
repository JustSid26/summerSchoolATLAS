#include<IRremote.h>
#define IRreceiver 2
#define buzzer 7
IRrecv irrecv(IRreceiver);
decode_results results;
void setup() {
  pinMode(buzzer, OUTPUT);  
  Serial.begin(9600);
  irrecv.enableIRIn();
}-

void loop() {
  if(irrecv.decode(&results)){
    delay(100);
    if(results.value){
      digitalWrite(buzzer, HIGH);
      delay(3000);
      digitalWrite(buzzer, LOW);
    }
    irrecv.resume();
  }
}
