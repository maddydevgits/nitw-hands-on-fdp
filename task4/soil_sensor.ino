void setup() {
  pinMode(22,INPUT);
  Serial.begin(9600);
}

void loop() {
  int m=digitalRead(22);
  Serial.println(m);
  if(m==1) {
    Serial.println("Dry Soil");
  } else {
    Serial.println("Wet Soil");
  }
  delay(500);
}
