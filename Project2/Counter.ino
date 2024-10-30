int count = 0;
int mask = 1;
int pinMap[] = {8, 9, 10, 11, 12};

void setup() {
  // Start a serial Console (See it in Serial Monitor)
  Serial.begin(9600);
  // Set the pin modes as output pin (8 9 10 11)
  pinMode( 8, OUTPUT);
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++) {
    if (count & (mask << i)) {
      digitalWrite(pinMap[i], HIGH);
    } else {
      digitalWrite(pinMap[i], LOW);
    }
  }
  delay(500);
  Serial.println(count);
  count = (count + 1)% 32;
}
