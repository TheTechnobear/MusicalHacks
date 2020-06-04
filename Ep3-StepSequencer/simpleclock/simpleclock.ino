static constexpr unsigned D_CLOCK_PIN = 2;
static constexpr unsigned A_RATE_PIN = 0;

void setup() {
  pinMode(D_CLOCK_PIN, OUTPUT);
}


void loop() {
  unsigned rate = analogRead(A_RATE_PIN); // 0..1023 
  digitalWrite(D_CLOCK_PIN, HIGH);
  delay(1);
  digitalWrite(D_CLOCK_PIN, LOW);
  delay(rate); // mSec
}
