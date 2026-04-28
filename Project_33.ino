
int x = 0;
int y = 0;
int readX(){
  int xr = 0;
  pinMode(A0, INPUT); //pinmode setup for x inputs on touchscreen to arduino
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW); // write to read one value from -x and +x
  digitalWrite(A3, HIGH);
  delay(5);
  xr = analogRead(0); //assign read  value to xr which is returned
  return xr;
}


int readY(){
  int yr = 0;
  pinMode(A0, OUTPUT); //same setup above but for the y axis
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  digitalWrite(14, LOW);
  digitalWrite(16, HIGH);
  delay(5);
  yr = analogRead(1);
  return yr; //return y value
}

void setup() {
  Serial.begin(9600); //begin setup for monitor
  pinMode(6, OUTPUT);  //setup pinmode for LED
}

void loop() {
  // put your main code here, to run repeatedly:
  x = readX();        //function call to read x value
  Serial.print("X = ");   //print value to see what it is
  Serial.println(x);
  y = readY();          //function call to read y value
  Serial.print("Y = ");   //print to see value read
  Serial.println(y);
  //delay(500);
  int light = y/4;    //variable decalred for light manipulation
  analogWrite(6, light);    //light variable is brightness assigned to pin 6.
  }

