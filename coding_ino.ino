int sensorValue;
char inChar;
int writeStatus = 0;
float vref = 3.3;
float resolution = vref/1023;

void setup() 
{
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() 
{
  serialEvent();

  if(writeStatus ==1)
  {
    onSensor();
  }
  else
  {
    
  }
}

void onSensor()
{
  float sens = analogRead(A0);
  sens = (sens*resolution);
  sens = sens*100;
  Serial.print(sens);
  Serial.print(",");
  Serial.flush();
  delay(1000);
}

void serialEvent()
{
  inChar = (char)Serial.read();
  switch(inChar)
  {
    case 'a':
      writeStatus = 1;
      digitalWrite(D0, 1);
      digitalWrite(D1, 0);
      break;
    case 'b':
      writeStatus = 2;
      digitalWrite(D0, 0);
      digitalWrite(D1, 1);
      break;
  }
}
