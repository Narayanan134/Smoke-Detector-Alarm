// Smoke Detector Alarm 

int led = 10; //initialize led to pin 10
int buzzer = 4; //initialize led to pin 4
int smokeSensor = A4;  //initialize led to pin A4
int thresholdVal = 300;  //set threshold value as 300

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeSensor);  // reads the current sensor value
  Serial.print("Pin A4: ");
  Serial.println(analogSensor);
  if (analogSensor > thresholdVal)    // checks if the sensor value is greater than threshold value
  {
    tone(buzzer, 1000);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
  delay(100);
}
