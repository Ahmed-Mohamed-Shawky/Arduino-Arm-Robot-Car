
#include <Servo.h>

#define Servo_Speed 10

Servo S1;
Servo S2;
Servo S3;
/* Car Pins */
//Right Motor Pins
#define R_E   2
#define MR_1  3
#define MR_2  4
//Left Motor Pins
#define L_E   7
#define ML_1  6
#define ML_2  5

/* Arm Pins */
//waist Motor Pins
#define Waist_En  13
#define Waist_1   12
#define Waist_2   11
//Servo Motors pin
#define Servo_1 8   //Elbow pin
#define Servo_2 9   //Wrist pin
#define Servo_3 10  //Grip Pin

int Data = 0;
int S1_pos = 0;
int S2_pos = 0;
int S3_pos = 0;

void setup() 
{
  //Set Right Motor Pins as Output Pins
  pinMode(R_E,OUTPUT);
  pinMode(MR_1,OUTPUT);
  pinMode(MR_2,OUTPUT);
  //Set Left Motor Pins as Output Pins
  pinMode(L_E,OUTPUT);
  pinMode(ML_1,OUTPUT);
  pinMode(ML_2,OUTPUT);

  //Set Waist Motor Pins as Output Pins
  pinMode(Waist_En,OUTPUT);
  pinMode(Waist_1,OUTPUT);
  pinMode(Waist_2,OUTPUT);
  //Put Servo 1 --> "Elbow" At point 0
  S1.attach(Servo_1);
  S1.write(0);
  //S1.detach();
  //Put Servo 2 --> "Wrist" At point 0
  S2.attach(Servo_2);
  S2.write(0);
  //S2.detach();
  //Put Servo 3 --> "Grip" At point 0
  S3.attach(Servo_3);
  S3.write(0);
  //S3.detach();

  //Start Uart comm as Serial
  Serial.begin(9600);
  
}

void loop() 
{
  if(Serial.available())
  {
    Data = Serial.read();
    Serial.print("Date : ");
    Serial.println(Data);
    switch(Data)
    {
      // RC Car Bluetooth Control
      case 'F':
        Forward();
        break;
      case 'B':
        Backward();
        break;
      case 'R':
        Right();
        break;
      case 'L':
        Left();
        break;
      case 'S':
        Stop_Car();
        break;
      case '1': // Move DC motor --> "waist" Up
        while(Data='1')
        {
          digitalWrite(Waist_1,HIGH);
          digitalWrite(Waist_2,LOW);
          digitalWrite(Waist_En,HIGH);
          if(Serial.read()=='0')
          {
            digitalWrite(Waist_En,LOW);
            digitalWrite(Waist_1,LOW);
            digitalWrite(Waist_2,LOW);
            break;
          }
        }
        break;
      case '2':  // Move DC motor --> "waist" Down
        while(Data='2')
        {
          digitalWrite(Waist_1,LOW);
          digitalWrite(Waist_2,HIGH);
          digitalWrite(Waist_En,HIGH);
          if(Serial.read()=='0')
          {
            digitalWrite(Waist_En,LOW);
            digitalWrite(Waist_1,LOW);
            digitalWrite(Waist_2,LOW);
            break;
          }
        }
        break;
      // Servo 1 Bluetooth Control
      case '3': // Move Servo 1 --> "Elbow" Up
        while(Data='3')
        {
          if (S1_pos<180)
          {
            S1_pos++;
            Serial.print("Servo 1 pos: ");
            Serial.println(S1_pos);
            //S1.attach(Servo_1);
            S1.write(S1_pos);
            //S1.detach();
            delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
      case '4':  // Move Servo 1 --> "Elbow" Down
        while(Data='4')
        {
          if (S1_pos>0)
          {
          S1_pos--;
          Serial.print("Servo 1 pos: ");
          Serial.println(S1_pos);
          //S1.attach(Servo_1);
          S1.write(S1_pos);
          //S1.detach();
          delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
      // Servo 2 Bluetooth Control
      case '5':  // Move Servo 2 --> "Wrist" Up
        while(Data='5')
        {
          if (S2_pos<180)
          {
            S2_pos++;
            Serial.print("Servo 2 pos: ");
            Serial.println(S2_pos);
            //S2.attach(Servo_2);
            S2.write(S2_pos);
            //S2.detach();
            delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
      case '6':  // Move Servo 2 --> "Wrist" Down
        while(Data='6')
        {
          if (S2_pos>0)
          {
          S2_pos--;
          Serial.print("Servo 2 pos: ");
          Serial.println(S2_pos);
          //S2.attach(Servo_2);
          S2.write(S2_pos);
          //S2.detach();
          delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
      // Servo 3 Bluetooth Control
      case '7':  // Move Servo 3 --> "Grip" Up
        while(Data='7')
        {
          if (S3_pos<180)
          {
            S3_pos++;
            Serial.print("Servo 3 pos: ");
            Serial.println(S3_pos);
            //S3.attach(Servo_3);
            S3.write(S3_pos);
            //S3.detach();
            delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
      case '8':  // Move Servo 3 --> "Grip" Down
        while(Data='8')
        {
          if (S3_pos>0)
          {
            S3_pos--;
            Serial.print("Servo 3 pos: ");
            Serial.println(S3_pos);
            //S3.attach(Servo_3);
            S3.write(S3_pos);
            //S3.detach();
            delay(Servo_Speed);
          }
          if(Serial.read()=='0')
            break;
        }
        break;
    }
  }
  S1.write(S1_pos);
  S2.write(S2_pos);
  S3.write(S3_pos);
}

void Forward()
{
  Serial.println("Moving Forward");
  //Set Right Motor to Forward
  digitalWrite(MR_1,HIGH);
  digitalWrite(MR_2,LOW);
  //Set Left Motor to Forward
  digitalWrite(ML_1,HIGH);
  digitalWrite(ML_2,LOW);
  //Enable Left and Right Motors
  digitalWrite(R_E,HIGH);
  digitalWrite(L_E,HIGH);
}

void Backward()
{
  Serial.println("Moving Backward");

  //Set Right Motor to Forward
  digitalWrite(MR_1,LOW);
  digitalWrite(MR_2,HIGH);
  //Set Left Motor to Forward
  digitalWrite(ML_1,LOW);
  digitalWrite(ML_2,HIGH);
  //Enable Left and Right Motors
  digitalWrite(R_E,HIGH);
  digitalWrite(L_E,HIGH);
}

void Right()
{
  Serial.println("Moving Right");
  //Set Right Motor to Backward
  digitalWrite(MR_1,LOW);
  digitalWrite(MR_2,HIGH);
  //Set Left Motor to Forward
  digitalWrite(ML_1,HIGH);
  digitalWrite(ML_2,LOW);
  //Enable Left and Right Motors
  digitalWrite(R_E,HIGH);
  digitalWrite(L_E,HIGH);
}

void Left()
{
  Serial.println("Moving Left");
  //Set Right Motor to Forward
  digitalWrite(MR_1,HIGH);
  digitalWrite(MR_2,LOW);
  //Set Left Motor to Backward
  digitalWrite(ML_1,LOW);
  digitalWrite(ML_2,HIGH);
  //Enable Left and Right Motors
  digitalWrite(R_E,HIGH);
  digitalWrite(L_E,HIGH);
}

void Stop_Car()
{
  Serial.println("Stop Moving");
  //Stop Left and Right Motors
  digitalWrite(R_E,LOW);
  digitalWrite(L_E,LOW);
  //Set Right Motor to zero
  digitalWrite(MR_1,LOW);
  digitalWrite(MR_2,LOW);
  //Set Left Motor to zero
  digitalWrite(ML_1,LOW);
  digitalWrite(ML_2,LOW);
}
