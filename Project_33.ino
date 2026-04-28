
int x = 0;
int y = 0;
int readX(){
  int xr = 0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);
  digitalWrite(A3, HIGH);
  delay(5);
  xr = analogRead(0);
  return xr;
}


int readY(){
  int yr = 0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  digitalWrite(14, LOW);
  digitalWrite(16, HIGH);
  delay(5);
  yr = analogRead(1);
  return yr;
}

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = readX();
  Serial.print("X = ");
  Serial.println(x);
  y = readY();
  Serial.print("Y = ");
  Serial.println(y);
  //delay(500);
  int light = y/4;
  analogWrite(6, light);
  }

