#define forward_signal 10
#define back_signal 11
#define left_signal 12
#define right_signal 13

#define leftFront1 2 //L298n Motor Driver pins
#define leftFront2 3
#define rightFront1 4
#define rightFront2 5
#define leftBack1 6
#define leftBack2 7
#define rightBack1 8
#define rightBack2 9

int forward_val = LOW;
int back_val = LOW;
int left_val = LOW;
int right_val = LOW;

int command = 0;

void setup() {
  
  pinMode(forward_signal, INPUT);
  pinMode(back_signal, INPUT);
  pinMode(left_signal, INPUT);
  pinMode(right_signal, INPUT);

  pinMode(leftFront1 , OUTPUT);
  pinMode(leftFront2 , OUTPUT); 
  pinMode(rightFront1 , OUTPUT);
  pinMode(rightFront2 , OUTPUT);

  pinMode(leftBack1 , OUTPUT);
  pinMode(leftBack2 , OUTPUT);
  pinMode(rightBack1 , OUTPUT);
  pinMode(rightBack2 , OUTPUT);

  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Initialized and Ready");
  
}

void loop() {
  
  forward_val = digitalRead(forward_signal);
  back_val = digitalRead(back_signal);
  left_val = digitalRead(left_signal);
  right_val = digitalRead(right_signal);
      
  //digitalWrite(LED_BUILTIN, forward_val);
  if(forward_val == HIGH){
    command = "1";    
  }
  else if(back_val == HIGH){
    command = "2";    
  }
  else if(left_val == HIGH){
    command = "3";    
  }
  else(right_val == HIGH);{
    command = "4";    
  }
  send_command(command);
    
}

void right(){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , LOW);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , LOW);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , HIGH);
  Serial.println("RIGHT");
}

void left(){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , LOW);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , LOW);
  Serial.println("LEFT");
}

void forward(){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , LOW);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , LOW);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , LOW);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , LOW);
  Serial.println("FORWARD");
}

void reverse(){
  digitalWrite(leftFront1 , LOW);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , LOW);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , LOW);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , LOW);
  digitalWrite(rightBack2 , HIGH);
  Serial.println("REVERSE");
}

void resett(){
  digitalWrite(leftFront1 , HIGH);
  digitalWrite(leftFront2 , HIGH);
  digitalWrite(rightFront1 , HIGH);
  digitalWrite(rightFront2 , HIGH);

  digitalWrite(leftBack1 , HIGH);
  digitalWrite(leftBack2 , HIGH);
  digitalWrite(rightBack1 , HIGH);
  digitalWrite(rightBack2 , HIGH);
  Serial.println("STOP");
}

void send_command(int command){
  switch (command){

     //reset command
     case 0: resett(); break;

     // single command
     case 1: forward(); break;
     case 2: reverse(); break;
     case 3: right(); break;
     case 4: left(); break;

     default: Serial.print("Invalid Command\n");
    }
}
