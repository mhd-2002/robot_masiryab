#define sen1A A3
#define sen2A A4
//the rest of sensors
#define fire_detector A1
#define battery_feedback A0
#define green_detector1 A6
#define green_detector2 A7
// digital IOs
#define led A5
#define fan 12
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 11
#define pwm1 10
#define pwm2 9
//
#define pwm_max 150
#define pwm_min 70
//start button
#define sw 1
//variables

bool start = 0;
int pwm = 255;
void setup() {

  configPins();
  Stop();
  digitalWrite(led, 1);
  delay(100);
  digitalWrite(led, 0);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(sw) == 0) {
    digitalWrite(led, 1);
    delay(100);
    digitalWrite(led, 0);
    start = 1;
  }

  while (start) {
    bool sen1 = digitalRead(A2);
    bool sen2 = digitalRead(5);
    bool sen3 = digitalRead(3);
    bool sen4 = digitalRead(4);
    bool sen5 = digitalRead(2);
    bool sen6 = digitalRead(13);


    if ((sen1) && (sen6) && (!sen2) && (!sen3) && (!sen4) && (!sen5)) {

      forward(pwm_max);
    } else if ((sen1) && (sen6) && (sen2) && (!sen3) && (!sen4) && (!sen5)) {
      left(80, 00);

    } else if ((sen1) && (!sen6) && (sen2) && (!sen3) && (!sen4) && (!sen5)) {
      left(80, 00);

    } else if ((!sen1) && (!sen6) && (sen2) && (!sen3) && (sen4) && (!sen5)) {
      left(80, 00);

    } else if ((!sen1) && (!sen6) && (!sen2) && (!sen3) && (sen4) && (!sen5)) {
      left(80, 00);
      /////////////////////////////////////////
    } else if ((sen1) && (!sen6) && (!sen2) && (sen3) && (!sen4) && (sen5)) {
      right(0, 80);

    } else if ((sen1) && (!sen6) && (!sen2) && (sen3) && (!sen4) && (!sen5)) {
      right(0, 80);

    } else if ((!sen1) && (!sen6) && (!sen2) && (sen3) && (!sen4) && (sen5)) {
      right(0, 80);

    } else if ((!sen1) && (!sen6) && (!sen2) && (!sen3) && (!sen4) && (sen5)) {
      right(0, 80);
      
    }else if ((sen1) && (sen6) && (sen2) && (sen3) && (sen4) && (sen5)){
      Stop();
      
      }
  }
}
void forward(char Speed) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  analogWrite(pwm1, Speed);
  analogWrite(pwm2, Speed);
}

void backward(char Speed) {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  analogWrite(pwm1, Speed);
  analogWrite(pwm2, Speed);
}

void right(char Speed1, char Speed2) {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  analogWrite(pwm1, Speed1);
  analogWrite(pwm2, Speed2);
}
void left(char Speed1, char Speed2) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  analogWrite(pwm1, Speed1);
  analogWrite(pwm2, Speed2);
}
void Stop(void) {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 1);
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
}

void configPins(void) {
  for (int i = 6; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(led, OUTPUT);
  for (int i = 2; i < 6; i++) {
    pinMode(i, INPUT);
  }
  pinMode(13, INPUT);
  pinMode(A2, INPUT);
  pinMode(sw, INPUT_PULLUP);
}
