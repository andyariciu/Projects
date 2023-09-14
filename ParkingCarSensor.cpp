#define trigPin 2
#define echoPin 3
// Define variables:
float duration;
float distance;
void setup() {
// Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(11, OUTPUT); // RED LED
  pinMode(12, OUTPUT); // YELLOW LED
  pinMode(13, OUTPUT); // GREEN LED
  
//Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
// Clear the trigPin by setting it LOW:  
  //Senzor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.34 / 2;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" mm");
  if(distance >= 91)
  {
  digitalWrite(11, LOW); //RED LED OFF
  digitalWrite(12, LOW); //YELLOW LED OFF
  digitalWrite(13, HIGH); //GREEN LED ON
  } else if (distance <= 90)
  {
    if(distance >= 50)
    {
    digitalWrite(11, LOW); //RED OFF
    digitalWrite(12, HIGH); //YELLOW LED ON
    digitalWrite(13, LOW);  //GREEN OFF
    Serial.print("Too close! Try to move forward!");
    } else if (distance <=49){
      digitalWrite(11, HIGH); //RED LED ON
      digitalWrite(12, LOW);  //YELLOW LED OFF
      digitalWrite(13, LOW);  //GREEN LED OFF
      Serial.print("STOP! VERY CLOSE!");
    }
  }
// Reprint the results every second
delay(500);
}
