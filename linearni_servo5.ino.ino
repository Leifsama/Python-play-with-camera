#include <Servo.h>

Servo motor_predni;        //initialize a servo object for the connected servo  
Servo motor_zadni;                
int angle = 0;
int vysuv_predni = 0; 
int incomingByte = 0;   
//int magnet1 = 0;

void setup() 
{ 
  Serial.begin(9600);
  
  motor_predni.attach(3);      // attach the signal pin of servo to pin9 of arduino
  motor_zadni.attach(6);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
} 
  
void loop() 
{  
  //digitalWrite(magnet1, HIGH);
   while(Serial.available())
    
  { 
    int vysuv_predni = Serial.parseInt();
    int vysuv_zadni = Serial.parseInt();
    int magnetA = Serial.parseInt();
    int magnetB = Serial.parseInt();
  
    //String str = Serial.readString();
  //if (Serial.read="a") digitalWrite(magnet1, HIGH);
  // if (8>5) digitalWrite(magnet1, HIGH);
    //int magnet1 = Serial.readString();
  Serial.println("Ve formatu 0-100 (motor predni) 0-100 (motor zadni) 0-1 (magnet A) 0-1 (magnet B)");
  Serial.print("Motor vpredu:");
  Serial.println(vysuv_predni);
  Serial.print("Motor vzadu:");
  Serial.println(vysuv_zadni);
  Serial.print("Magnet A:");
  Serial.println(magnetA);
  Serial.print("Magnet B:");
  Serial.println(magnetB);
  
    int vysuv_predni2 = vysuv_predni+50;
    int vysuv_zadni2 = vysuv_zadni+50;  
                       
//  Serial.println(str); 
    motor_predni.write(vysuv_predni2);       //command to rotate the servo to the specified angle
   
    //delay(50);   

    motor_zadni.write(vysuv_zadni2);                 //command to rotate the servo to the specified angle
    //delay(50);
       
    
    if (magnetA >= 1)
    digitalWrite(12, HIGH);
    else
    digitalWrite(12, LOW);
   //if (magnetA = 0)
   // digitalWrite(13, HIGH);

   if (magnetB >= 1)
    digitalWrite(13, HIGH);
    else
    digitalWrite(13, LOW);

    
      
  } 
    }  

  
