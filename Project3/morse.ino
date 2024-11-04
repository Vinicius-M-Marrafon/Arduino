int UNIT_TIME = 250; // 250ms
String message = "hello world"; // Mensagem
String morseTable[36] = {
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--..",   // Z
  "-----",  // 0
  ".----",  // 1
  "..---",  // 2
  "...--",  // 3
  "....-",  // 4
  ".....",  // 5
  "-....",  // 6
  "--...",  // 7
  "---..",  // 8
  "----.",  // 9
};

int getMorseIndex(char c) {
  if ('0' <= c && c <= '9') {
    return 25 + (c - '0');
  } else if ('a' <= c && c <= 'z') {
    return (c - 'a');
  } else {
    return 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int index = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if (message[index] != ' ') {
    int letterIndex = getMorseIndex(message[index]);
    String morseCode = morseTable[letterIndex];
    Serial.println(morseCode);

    for (int i = 0, n = morseCode.length(); i < n; i++) {
      digitalWrite(13, HIGH);
      if (morseCode[i] == '.') {
        delay(UNIT_TIME);
      } else {
        delay(3 * UNIT_TIME);
      }
      digitalWrite(13, LOW);
      delay(UNIT_TIME);
    }

    index = (index + 1) % (message.length());
    delay(3 * UNIT_TIME);
  } else {
    delay(7 * UNIT_TIME);
    index = (index + 1) % (message.length());
  }
}
