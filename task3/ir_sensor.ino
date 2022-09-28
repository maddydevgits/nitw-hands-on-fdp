void setup() {
  pinMode(22,INPUT);
  Serial.begin(9600);
}

void loop() {
  int m=digitalRead(22);
  Serial.println(m);
  delay(500);
}
