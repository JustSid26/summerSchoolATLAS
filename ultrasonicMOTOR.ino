#define motorPin1 13
#define motorPin2 12
#define motorPWM 11
#define trigger 6
#define echo 7
long time;
float distance;
void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPWM, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigger, LOW);
  delay(100);
  
  digitalWrite(trigger, HIGH);
  delay(100);
  
  digitalWrite(trigger, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.034 / 2;
  Serial.println(distance);
  if (distance < 10){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(motorPWM, 200);
  }else{
    analogWrite(motorPWM, 0);
  }
}


