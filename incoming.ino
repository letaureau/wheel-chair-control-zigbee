// --------------------------------------------------------------------------- Motors
int motor_left[] = {2, 3};
int motor_right[] = {7, 8};

// --------------------------------------------------------------------------- Zigbee
int incomingByte;      // a variable to read incoming serial data into

// --------------------------------------------------------------------------- Zigbee
int relays[] = {9, 10};

// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);

// Setup motors
int i;
for(i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
pinMode(relays[i], OUTPUT);
}

}

// --------------------------------------------------------------------------- Loop
void loop() { 
if (Serial.available() > 0) 
{
  // read the oldest byte in the serial buffer:
  incomingByte = Serial.read();
  // if it's F , run the wheelchair forwards:
  if (incomingByte == 'F') {
    drive_forward();
    delay(1000);
    motor_stop();
    Serial.println("1");
  } 
  // if it's an B, run the wheelchair backwards:
  else if (incomingByte == 'B') {
    drive_backward();
    delay(1000);
    motor_stop();
    Serial.println("2");
  }
  // if it's an R, turn the wheelchair right:
  else if (incomingByte == 'R') {
    turn_right();
    delay(1000);
    motor_stop();
    Serial.println("4"); 
  } 
  // if it's an L, turn the wheelchair Left:
  else if (incomingByte == 'L') {
    turn_left();
    delay(1000);
    motor_stop();
    Serial.println("3");
  }
  // if it's an X, turn the relays On:
  else if (incomingByte == 'X') {
    relay_ON();
    delay(1000);
    Serial.println("5");
  }
  else if (incomingByte == 'S')
  {
    motor_stop();
    Serial.println("6");
  }
}
}

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void relay_ON(){
digitalWrite(relays[0], HIGH); 
digitalWrite(relays[1], HIGH); 
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

void turn_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}
