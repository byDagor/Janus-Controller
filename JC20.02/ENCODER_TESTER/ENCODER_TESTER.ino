//A and B encoder inputs
#define CANAL_A 32
#define CANAL_B 33
#define INDEX 13

//count refers to the number of encoder pulses that occured. You add to this number if the motor is rotating in one direction and substract if it's rotating the other direction
float count = 0, z = 0;
//This is the actual and previous state of the encoder magnet to determine direction of rotation
byte state, statep;
//Variables used in the handleInterrupt funcion to select the current state.
boolean A,B;

void handleInterrupt();
void indexPin();

void setup() {
  //Serial serial communication to computer
  Serial.begin(115200);

  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);

  //Pinmode for index input
  pinMode(INDEX, INPUT);
  attachInterrupt(digitalPinToInterrupt(33), indexPin, CHANGE);
  
  //Pinmodes for encoder inputs
  pinMode(CANAL_A, INPUT);
  pinMode(CANAL_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(CANAL_A), handleInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CANAL_B), handleInterrupt, CHANGE);
}

void loop() {
  float angle = count *360/4096; //Your resolution here
  Serial.print("Times passed through index: ");
  Serial.print(z);
  Serial.print(", Current angle: ");
  Serial.println(angle);
}

void indexPin() {
  int index = digitalRead(33);
  if (index == 1) z += 1;
}

void handleInterrupt() {
    A = digitalRead(CANAL_A);
    B = digitalRead(CANAL_B);

    if ((A==HIGH)&&(B==HIGH)) state = 1;
    if ((A==HIGH)&&(B==LOW)) state = 2;
    if ((A==LOW)&&(B==LOW)) state = 3;
    if((A==LOW)&&(B==HIGH)) state = 4;

    switch (state)
    {
      case 1:
      {
        if (statep == 2) count++;
        if (statep == 4) count--;
        break;
      }
      case 2:
      {
        if (statep == 1) count--;
        if (statep == 3) count++;
        break;
      }
      case 3:
      {
        if (statep == 2) count --;
        if (statep == 4) count ++;
        break;
      }
      default:
      {
        if (statep == 1) count++;
        if (statep == 3) count--;
      }
    }
    statep = state;
}
