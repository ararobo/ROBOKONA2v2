#include <Arduino.h>
#include <Ps3Controller.h>
const int MCP = 17;
const int MAP = 16;
const int MDP = 18;
const int MBP = 5;
const int MEP = 21;
const int MFP = 19;
const int MGP = 23;
const int MHP = 22;
int H = 10000;
double on = 25;
int led = 15;
int mode;
int move=0;
int pwm=110;//速度
 void setup() {
  pinMode(13,INPUT);
  pinMode(led, OUTPUT);
  ledcSetup(0, H, 12);
  ledcAttachPin(MAP, 0);
  ledcSetup(1, H, 12);
  ledcAttachPin(MCP, 1);
  ledcSetup(2,H,12); 
  ledcAttachPin(MBP,2);
  ledcSetup(3,H,12); 
  ledcAttachPin(MDP,3);
   ledcSetup(4,H,12); 
  ledcAttachPin(MEP,4);
   ledcSetup(5,H,12); 
  ledcAttachPin(MFP,5);
  ledcSetup(6,H,12);
  ledcAttachPin(MGP,6);
  ledcSetup(7,H,12);
  ledcAttachPin(MHP,7);
    Ps3.begin("29:AE:A4:9C:2D:61");
      Serial.begin(9600);
  }

void loop() { mode=digitalRead(13);
  if( Ps3.event.button_down.triangle &&mode==1){
      for (size_t i = 0; i <= 175; i++)
  {digitalWrite(led, HIGH);
    ledcWrite(0, 0);
    ledcWrite(1, i);
    
     
Serial.print(i);    
    delay(5);
      }
 
delay(2500);
ledcWrite(1, 0);
    ledcWrite(0, 0);
     
    move=1; } 
    if( Ps3.event.button_down.triangle &&mode==0){
      for (size_t i = 0; i <= 175; i++)
  {digitalWrite(led, HIGH);
    ledcWrite(0, i);
    ledcWrite(1, 0);
   
     
Serial.print(i);    
    delay(5); 
      }
  while (mode==0)
  {mode=digitalRead(13);
    Serial.print(mode);   
  
  
 ledcWrite(1, 0);
    ledcWrite(0, 175);}
ledcWrite(1, 0);
    ledcWrite(0, 0);
    
    move=0; } 


 Serial.print(mode);  


     if( Ps3.event.button_down.r1 ){
   for (size_t i = 0; i <= 195; i++)
  {ledcWrite(5,i);//ベルト
  ledcWrite(4, 0);
if (Ps3.event.button_up.r1){
    i=0; break;}
    delay(5);
    }
  } 
        if( Ps3.event.button_down.r2 ){
   for (size_t i = 0; i <= pwm; i++)
  {ledcWrite(6,i);//ローラー
  ledcWrite(7, 0);
if (Ps3.event.button_up.r2){
    i=0; break;}
    delay(5);
    }
  } 


if( Ps3.event.button_up.r1 )
{ledcWrite(5, 0);
    ledcWrite(4,0);
}
if( Ps3.event.button_up.r2 )
{ledcWrite(6, 0);
    ledcWrite(7,0);
}
if(Ps3.event.button_up.select){//未完成なのでつかわないでね
  if(pwm<=190){
    pwm=pwm+1;
      Serial.println(pwm); 
  }else{
    pwm=110;
     Serial.println(pwm);
  }
  
}

}
