#define trigger 6
#define echo 7
long time;
float distance;
void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigger, HIGH);
  delay(100);
  digitalWrite(trigger, LOW);
  time = pulseIn(echo, HIGH);
  distance = time * 0.034 / 2;
  Serial.println(distance);
}


