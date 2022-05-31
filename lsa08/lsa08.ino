const byte analogPin = 0;   // Connect AN output of LSA08 to analog pin 0
const byte junctionPulse = 4;   // Connect JPULSE of LSA08 to pin 4

int readVal,positionVal;    // Variables to store analog and line position value
unsigned int junctionCount = 0;   // Variable to store junction count value

void setup() {
  pinMode(junctionPulse,INPUT);
  Serial.begin(9600);
}

void loop() {
  // Checking for junction crossing, if juction detected, 
  // keep moving forward
  if(digitalRead(junctionPulse)) {
    while(digitalRead(junctionPulse)) {
      moveForward();
    }
    // Increment junction count by 1 after the junction
    // You can do whatever you want with the junction count
    junctionCount++;
  }

  readVal = analogRead(analogPin);    // Read value from analog pin

  // Convert voltage level into line position value
  positionVal = ((float)readVal/921)*70;

  // Line at left when 0 - 18, move left
  if(positionVal <= 18)
  moveLeft();

  // Line at middle when 19 - 52, move forward
  else if(positionVal <= 52)
  moveForward();

  // Line at right when 53 - 70, move right
  else if(positionVal <= 70)
  moveRight();

  // If no line is detected, stay at the position
  else
  wait();


void moveLeft() {
  Serial.print("left");
}

void moveRight() {
  Serial.print("Right");
}

void moveForward() {
  Serial.print("Center");
}

void wait() {
  Serial.print("No line detected");
}
