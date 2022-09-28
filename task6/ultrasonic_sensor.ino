// 4 Pins HC-SR04
// Vcc - 5V, Trig - P22, Echo - P23, GND - GND
// GPIO - General Purpose Input Output

int trig=22;
int echo=23;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT); // write
  pinMode(echo,INPUT); // read
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // raising - 0 to 1
  // falling - 1 to 0

  // clean the trigger pin for about 2us
  digitalWrite(trig,0);
  delayMicroseconds(2);

  // trigger falling edge interrupt for about 10us
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  int duration=pulseIn(echo,1); // time interval
  // total time=to_time+fro_time = t+t
  float distance=(duration/2)*(0.034);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");  
}
