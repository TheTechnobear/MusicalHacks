static constexpr unsigned D_STEP1_PIN = 2;
static constexpr unsigned D_STEP2_PIN = 3;
static constexpr unsigned D_STEP3_PIN = 4;

static constexpr unsigned D_GATE_PIN = 5;

static constexpr unsigned A_RATE_PIN = 0;

void setup() {
  pinMode(D_STEP1_PIN, OUTPUT);
  pinMode(D_STEP2_PIN, OUTPUT);
  pinMode(D_STEP3_PIN, OUTPUT);
  pinMode(D_GATE_PIN, OUTPUT);
}

static constexpr unsigned MAX_STEP=8;
unsigned step = MAX_STEP;

void loop() {
  // signal gate
  digitalWrite(D_GATE_PIN, HIGH);
  delay(1);
  digitalWrite(D_GATE_PIN, LOW);

  // select step
  step=(step + 1) % MAX_STEP;  
//  step= random(MAX_STEP-1);
//  step = (step == 0 ? MAX_STEP-1 : step - 1);

  // tell mux which step to select
  digitalWrite(D_STEP1_PIN, step & 1);
  digitalWrite(D_STEP2_PIN, step & 2);
  digitalWrite(D_STEP3_PIN, step & 4);
  
  // read pause time between steps
  unsigned rate = analogRead(A_RATE_PIN); // 0..1023 
  delay(rate); // mSec
  
}
