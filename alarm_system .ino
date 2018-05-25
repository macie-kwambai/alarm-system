const int out=12;
const int in=13;
const int led=9;
const int buz=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buz,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long dur;
  long dis;

  digitalWrite(out,LOW);
  delayMicroseconds(2);

  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);

  dur=pulseIn(in,HIGH);
  dis= (dur/2) / 29.1;

  if (dis>50 && dis<=200 )
 {
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  }
 else {
 digitalWrite(led,LOW);
 }
 if (dis<=50)
 {
  digitalWrite(led,HIGH);
  tone(buz, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
  noTone(buz);     // Stop sound...
  delay(500);        // ...for 1sec
  
 }
  else {
  digitalWrite(led,LOW);
 }
 Serial.print(String(dis));
 Serial.print("cm");
 Serial.println();

 delay(100);}


