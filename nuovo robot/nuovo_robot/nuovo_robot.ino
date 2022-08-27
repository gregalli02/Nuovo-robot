#define A1A 2 //blu nero bianco giallo
#define A1B 3
#define B1A 5
#define B1B 6

const int velocita = 150;
const int Trig = 7;
const int Echo = 8;

long durata;
int distanza;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:

  avanti();
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  durata = pulseIn(Echo, HIGH);
  distanza = durata * 0.0343 / 2;

  digitalWrite(Echo, LOW);

  Serial.println(distanza);

  if(distanza < 30){
    fermo();
    delay(1000);
    indietro();
    delay(800);
    fermo();
    delay(1000);
    destra();
    delay(1000);
    fermo();
    delay(500);
  }
}

void avanti(){
  analogWrite(A1A, velocita);
  analogWrite(A1B, 0);
  analogWrite(B1A, 0);
  analogWrite(B1B, velocita);
}

void indietro(){
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, LOW);
}

void destra(){
  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, LOW);
}

void sinistra(){
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
}

void fermo(){
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
}
