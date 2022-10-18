#define STBY 6
#define PWMB 9
#define PWMA 3
#define AIN2 4
#define AIN1 5
#define BIN1 7
#define BIN2 8
#define trigPin 11
#define echoPin 10
int i=0;
long sure, uzaklik;
void setup() {
  // put your setup code here, to run once:
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, INPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(STBY, HIGH);
digitalWrite(AIN1, LOW);
digitalWrite(AIN2, HIGH);
digitalWrite(BIN1, LOW);
digitalWrite(BIN2, HIGH);
analogWrite(PWMA, 100);
analogWrite(PWMB, 100);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
uzaklik = sure / 58.2;
Serial.println(uzaklik);
if(15<uzaklik){
ileri();
}
else if((5<uzaklik) && (uzaklik<15)){
sag();
delay(150);
sol();
}
else{
  geri();
}
}
void ileri(){
digitalWrite(AIN1, HIGH);
digitalWrite(AIN2, LOW);
analogWrite(PWMA, 150);

digitalWrite(BIN1, HIGH);
digitalWrite(BIN2, LOW);
analogWrite(PWMB, 150);
}
void sol(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 150);
}

void sag(){
digitalWrite(AIN1, HIGH);
digitalWrite(AIN2, LOW);
analogWrite(PWMA, 150);

digitalWrite(BIN1, HIGH);
digitalWrite(BIN2, LOW);
analogWrite(PWMB, 0);
}
void geri(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 150);

   digitalWrite(BIN1, LOW);
   digitalWrite(BIN2, HIGH);
  digitalWrite(PWMB, 150);
}
