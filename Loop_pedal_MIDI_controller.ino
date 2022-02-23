#define button 2
#define LED 8

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;

  i = digitalRead(button);
  digitalWrite(LED, i);
}
