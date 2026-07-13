const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

const int buttonPin = 9;

const byte numberPatterns[7][7] = {
  {0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1}  
};

void setup() {
  // Set segment pins as OUTPUT
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  randomSeed(analogRead(0));
  
  digitalWrite(G, HIGH); 
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    
    for (int i = 0; i < 10; i++) {
      int randomDisplay = random(1, 7);
      displayNumber(randomDisplay);
      delay(60); 
    }

    int diceRoll = random(1, 7); 
    displayNumber(diceRoll);

    delay(300); 
  }
}

void displayNumber(int num) {
  digitalWrite(A, numberPatterns[num][0]);
  digitalWrite(B, numberPatterns[num][1]);
  digitalWrite(C, numberPatterns[num][2]);
  digitalWrite(D, numberPatterns[num][3]);
  digitalWrite(E, numberPatterns[num][4]);
  digitalWrite(F, numberPatterns[num][5]);
  digitalWrite(G, numberPatterns[num][6]);
}