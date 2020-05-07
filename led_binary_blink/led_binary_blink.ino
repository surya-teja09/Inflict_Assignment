
const unsigned int maximum = 256;    //using 8 LEDs, 2^8 = 256 maximum iterations to be shown on board
const long debounce = 100;           //100 ms debounce added in case of button activation
byte bytepins[] = {5, 6, 7, 8, 9, 10, 11, 12};


void setup() {
    for (int i = 0; i < 9; ++i) {
        pinMode(bytepins[i], OUTPUT);
    }
}

void loop() {
    for (int currentBinaryCount = 0; currentBinaryCount < maximum; ++currentBinaryCount) {
        binaryToLED(currentBinaryCount);
        delay(1000);
    }

}

 void binaryToLED(byte input) {
    for (int i = 0; i < 8; ++i) {
      if (bitRead(input, i) == 1) {
          digitalWrite(bytepins[i], HIGH);
      } 
      else {
        digitalWrite(bytepins[i], LOW);
      }
    }
 }
