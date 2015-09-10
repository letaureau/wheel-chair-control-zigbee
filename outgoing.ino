const int analogInPin1 = A0;  // Analog input pin 1
const int analogInPin2 = A1;  // Analog input pin 2
const int analogInPin3 = A2;  // Analog input pin 3
const int analogInPin4 = A3;  // Analog input pin 4

int sensorValue1 = 0;        // value read from the Flex1
int sensorValue2 = 0;        // value read from the Flex2
int sensorValue3 = 0;        // value read from the Flex3
int sensorValue4 = 0;        // value read from the Flex4

int outputValue1 = 0;        // value output for Logic
int outputValue2 = 0;        // value output for Logic
int outputValue3 = 0;        // value output for Logic
int outputValue4 = 0;        // value output for Logic

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(analogInPin1);            
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);  
  // read the analog in value:
  sensorValue2 = analogRead(analogInPin2);            
  // map it to the range of the analog out:
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);  
  // read the analog in value:
  sensorValue3 = analogRead(analogInPin3);            
  // map it to the range of the analog out:
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);  
  // read the analog in value:
  sensorValue4 = analogRead(analogInPin4);            
  // map it to the range of the analog out:
  outputValue4 = map(sensorValue4, 0, 1023, 0, 255);  

  if(outputValue1>100&&outputValue2<100&&outputValue3<100&&outputValue4<100)
  {
    Serial.print("F");
  }
  else if(outputValue1<100&&outputValue2>100&&outputValue3<100&&outputValue4<100)
  {
    Serial.print("B");
  }
  else if(outputValue1<100&&outputValue2<100&&outputValue3>100&&outputValue4<100)
  {
    Serial.print("R");
  }
  else if(outputValue1<100&&outputValue2<100&&outputValue3<100&&outputValue4>100)
  {
    Serial.print("L");
  }
  else if((outputValue1>100&&outputValue2>100&&outputValue3<100&&outputValue4<100) || (outputValue1<100&&outputValue2<100&&outputValue3>100&&outputValue4>100))
  {
    Serial.print("X");
  }
  else
  {
    Serial.print("S");
  }
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
