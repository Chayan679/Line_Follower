int S_A = 10;  //speed motor a
int M_A1 = 5; //motor a = +
int M_A2 = 4; //motor a = -
int M_B1 = 6; //motor b = -
int M_B2 = 7; //motor b = +
int S_B = 9;  //speed motor b

int R_S = 3; //sincer R
int S_S = 13; //sincer S
int L_S = 2; //sincer L

void setup()
{
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(S_B, OUTPUT);
  pinMode(S_A, OUTPUT);

  pinMode(L_S, INPUT);
  pinMode(S_S, INPUT);
  pinMode(R_S, INPUT);

  analogWrite(S_A, 100);
  analogWrite(S_B, 100);
  delay(200);
}
void loop()
{
  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
    forword();
  }

  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
    turnLeft();
  }
  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
    turnLeft();
  }


  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
    turnRight();
  }

  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
    Stop();
  }
}

void forword() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}


void turnRight() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void turnLeft() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}

void Stop() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}
