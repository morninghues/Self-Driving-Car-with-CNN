#define leftFront1 2 //L298n Motor Driver pins
#define leftFront2 3
#define rightFront1 4
#define rightFront2 5
#define leftBack1 6
#define leftBack2 7
#define rightBack1 8
#define rightBack2 9

// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  pinMode(leftFront1 , OUTPUT);
  pinMode(leftFront2 , OUTPUT); 
  pinMode(rightFront1 , OUTPUT);
  pinMode(rightFront2 , OUTPUT);

  pinMode(leftBack1 , OUTPUT);
  pinMode(leftBack2 , OUTPUT);
  pinMode(rightBack1 , OUTPUT);
  pinMode(rightBack2 , OUTPUT);
  Serial.begin(115200);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , LOW);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("RIGHT");
  delay(time);
}

void left(int time){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , LOW);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , LOW);
  //Serial.println("LEFT");
  delay(time);
}

void forward(int time){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , LOW);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , LOW);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , LOW);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , LOW);
  //Serial.println("FORWARD");
  delay(time);
}

void reverse(int time){
  digitalWrite(leftFront1 , LOW);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , LOW);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , LOW);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("REVERSE");
  delay(time);
}

/*void forward_right(int time){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , LOW);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , LOW);
  digitalWrite(rightBack1 , LOW);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("FR");
  delay(time);
}

void reverse_right(int time){
  digitalWrite(leftFront1 , LOW);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , LOW);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , LOW);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("RR");
  delay(time);
}

void forward_left(int time){
  digitalWrite(leftFront1 , LOW);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , LOW);

  digitalWrite(leftBack1 , LOW);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , LOW);
  //Serial.println("FL");
  delay(time);
}

void reverse_left(int time){
  digitalWrite(leftFront1 , LOW);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , LOW);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , LOW);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("RL");
  delay(time);
}*/

void reset(){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , HIGH);
  //Serial.println("STOP");
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     //case 6: forward_right(time); break;
     //case 7: forward_left(time); break;
     //case 8: reverse_right(time); break;
     //case 9: reverse_left(time); break;

     default: Serial.print("Invalid Command\n");
    }
}
