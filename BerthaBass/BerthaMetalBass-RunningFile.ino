// Tristan Watne
// Metalhead Billy Bass
// Feel free to use, modify, any of this as needed. 
//using Inland Uno r3 Board, Adafruit MotorShield v3, MAX98357A amp, and generic micro SD reader
//If you're readying this and don't have the gear purchased yet, be forwarned any motorshield V1 cannot run two motors concurrently. 

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h> //must use SD card formatted with FAT16 and less than 4 gigs
#define SD_ChipSelectPin 10

//definitions 
const int ButtonPin = 4;    // the number of the Button pin
int buttonState = 0;
int ButtonStateCount = 0; //tracks button presses to cycle through songs.
long buttonCounter;
bool newPress; 
bool functionsRunning; 
bool TimerResult; 


//motors
Adafruit_MotorShield MS = Adafruit_MotorShield(0x60);//was not working without address, default.
Adafruit_DCMotor *body = MS.getMotor(1);
Adafruit_DCMotor *mouth = MS.getMotor(2);

//sound
TMRpcm tmrpcm;


//song functions 
void birthdaySong()
{
   
   Serial.println("birthdaySong function");
   tmrpcm.play("BD.wav");   
   int count;
   int beatCount;
   int beatTemp;   
   bool bodyOrTailHigh; 
   bool MouthOpen;  
   bool beatPass; 
   count = 0;
   beatCount = 0; 
   beatTemp = 0;   
   bodyOrTailHigh = false;  
   MouthOpen = false;
   beatPass = true;
   body->setSpeed(200);// don't go above 210
   mouth->setSpeed(210);

    while(tmrpcm.isPlaying())
    {
      ++count;
      //Serial.println(count);  
      

      if(count > 200) //loose map to BPM
      {
         
        count = 0;
        delay(250); 
        ++beatCount;
        Serial.println(beatCount);  

          
         if(beatCount < 54)   
          {
               if(beatPass == true)
               {
                  body->run(FORWARD); //hold front of body high 
                  beatPass == false; 
               }
               else
               {
                  body->run(BRAKE); //hold front of body high 
               }

               if(beatCount % 2 != 0)
               { //all the DO parts
                  mouth->run(BACKWARD);
               }
               else
               {
                  mouth->run(RELEASE);
               }

          } 
          else
          {                     
              if(bodyOrTailHigh == false)
              {

                    if(beatCount % 10 != 0)
                      {
                          body->setSpeed(200);
                          body->run(FORWARD);
                          bodyOrTailHigh = !bodyOrTailHigh;
                          //Serial.println("beatCount % 2 == 0");

                      }
                    else if(beatCount % 10 == 0)
                      {
                          body->setSpeed(200);
                          body->run(BACKWARD);
                          bodyOrTailHigh = !bodyOrTailHigh;
                          // Serial.println("beatCount % 2 != 0");
                      }  
              } 
              else{
                  body->run(RELEASE);
                  bodyOrTailHigh = !bodyOrTailHigh; 
                  //Serial.println("bodyOrTailHigh Else");
              } 
         }         
                
      }       
        
      
    }
    
      
}

void DuHastSong() //bpm 125
{ 
   //speaking 12-45 seconds 
   //1 minute length song
   tmrpcm.play("ONE.wav");  
   int count;
   int beatCount;
   int beatTemp;   
   bool bodyOrTailHigh; 
   bool MouthOpen;  
   bool beatPass; 
   count = 0;
   beatCount = 0; 
   beatTemp = 0;   
   bodyOrTailHigh = false;  
   MouthOpen = false;
   beatPass = true;
   body->setSpeed(200);// don't go above 210               

    while(tmrpcm.isPlaying())
    {
      ++count;
      

      if(count > 500) //loose map to BPM
      {
        count = 0;
        delay(475); 
        ++beatCount;
        //Serial.println(beatCount);  
           
            if(beatCount > 26 && beatCount < 96)
            { 
               //beatPass = beatCount; //variable to track everyother pass
               if(beatPass == true)
               {
                  body->run(FORWARD); //hold front of body high 
                  beatPass == false; 
               }
               else
               {
                  body->run(BRAKE); //hold front of body high 
               }

               if(beatCount == 28 || beatCount == 31 || beatCount == 35 || beatCount == 44 || beatCount == 47 || beatCount == 51 || beatCount == 60 || beatCount == 63 || beatCount == 67 || beatCount == 76 || beatCount == 80 || beatCount == 84)
               { //all the DO parts
                  mouth->run(BACKWARD);
               }
               else
               {
                  mouth->run(RELEASE);
               }
                 
            
            }              
            else{ 
                                 
                    if(bodyOrTailHigh == false)
                    {

                          if(beatCount % 3 == 0)
                           {
                                body->setSpeed(200);
                                body->run(FORWARD);
                                bodyOrTailHigh = !bodyOrTailHigh;
                                //Serial.println("beatCount % 2 == 0");

                            }
                          else if(beatCount % 3 != 0)
                            {
                                body->setSpeed(175);
                                body->run(BACKWARD);
                                bodyOrTailHigh = !bodyOrTailHigh;
                               // Serial.println("beatCount % 2 != 0");
                            }  
                    } 
                    else{
                        body->run(RELEASE);
                        bodyOrTailHigh = !bodyOrTailHigh; 
                        //Serial.println("bodyOrTailHigh Else");
                    } 
                 }  
                  
      }       
           
      
    }
  
} 

void TypeOSong() 
{
   //45 Seconds song
   //BPM 101 
   Serial.println("type o function");    
   int count;
   int beatCount;
   int beatTemp;   
   bool bodyOrTailHigh; 
   bool MouthOpen;  
   bool beatPass; 
   count = 0;
   beatCount = 0; 
   beatTemp = 0;   
   bodyOrTailHigh = false;  
   MouthOpen = false;
   beatPass = true;
   body->setSpeed(200);// don't go above 210
   mouth->setSpeed(210);
   tmrpcm.play("TWO.wav"); 

    while(tmrpcm.isPlaying())
    {
      ++count;
      //Serial.println(count);  
      

      if(count > 30000) //loose map to BPM
      {
         
        count = 0;
        delay(250); 
        ++beatCount;
        //Serial.println(beatCount);  
           
         if(beatCount >= 45 && beatCount <= 53 || beatCount >= 60 && beatCount <= 70 || beatCount >= 78 && beatCount <= 88 || beatCount >= 95 && beatCount <= 105)   
          {
               if(beatPass == true)
               {
                  body->run(FORWARD); //hold front of body high 
                  beatPass == false; 
               }
               else
               {
                  body->run(BRAKE); //hold front of body high 
               }

               if(beatCount % 2 != 0)
               { //all the DO parts
                  mouth->run(BACKWARD);
               }
               else
               {
                  mouth->run(RELEASE);
               }

          } 
          else
          {                     
              if(bodyOrTailHigh == false)
              {

                    if(beatCount % 10 != 0)
                      {
                          body->setSpeed(200);
                          body->run(FORWARD);
                          bodyOrTailHigh = !bodyOrTailHigh;
                          //Serial.println("beatCount % 2 == 0");

                      }
                    else if(beatCount % 10 == 0)
                      {
                          body->setSpeed(200);
                          body->run(BACKWARD);
                          bodyOrTailHigh = !bodyOrTailHigh;
                          // Serial.println("beatCount % 2 != 0");
                      }  
              } 
              else{
                  body->run(RELEASE);
                  bodyOrTailHigh = !bodyOrTailHigh; 
                  Serial.println("bodyOrTailHigh Else");
              } 
         }         
                  
      }       
           
      
    }
    
    
   
}

//setup 
void setup() 
{
    Serial.begin(115200);           // set up Serial library at 9600 bps
    MS.begin(); 
    pinMode(ButtonPin, INPUT_PULLUP); // Button Press
    pinMode(SD_ChipSelectPin, OUTPUT); // Button Press
    ButtonStateCount = 0; //initial state to play first song.
    newPress = false; //keeps button presses from constantly firing in loop  
    tmrpcm.speakerPin=9;
    SD.begin(SD_ChipSelectPin);


    //hardware Checks
    if(!SD.begin(SD_ChipSelectPin))
    {
    Serial.println("SD fail");
    while (1);
    }
    Serial.println("SD Card found.");

    if (!MS.begin()) {         
      Serial.println("Could not find Motor Shield. Check wiring.");
      while (1);
    }


    Serial.println("Motor Shield found.");
    tmrpcm.setVolume(5.75);
}

//loop
 void loop() 
 { 
    
    if(!tmrpcm.isPlaying()) //save motors 
    {
      body->run(RELEASE);
      mouth->run(RELEASE);
    }
    

    buttonState = digitalRead(ButtonPin);  
 
        if(buttonState == LOW) //button press
        {
            newPress = true; // allows release to be acknowledged
            ++buttonCounter; //Start Counter
            Serial.println(buttonCounter);
            if(buttonCounter >= 500) // 4 second hold Approx
                {
                    //Call birthday song function.
                    birthdaySong();
                    //Serial.println("Birthday function Called");
                    newPress = false; 
                    buttonCounter = 0;
                } 
        }      
        
        if(buttonState == HIGH && newPress == true && buttonCounter >= 10) //button released - tracks new presses to keep from firing on any cycle without a solid press
        {
            newPress = false;
            Serial.println("Button Released");
              if(ButtonStateCount == 3) // hits 3, loop back to 1 call function. 
                {
                    ButtonStateCount = 1; 
                    //Serial.println("ButtonStateCount");
                    //Serial.println(ButtonStateCount);
                    DuHastSong();
                    buttonCounter = 0;
                }
              else // track quick button press add 1 
                {
                    ++ButtonStateCount;
                    if(ButtonStateCount == 1)
                    {
                      DuHastSong();
                      //Serial.println("ButtonStateCount");
                     // Serial.println(ButtonStateCount);
                    }
                    else if(ButtonStateCount == 2)
                    {
                      TypeOSong(); 
                     // Serial.println("ButtonStateCount");
                     // Serial.println(ButtonStateCount);
                    }
                    else
                    {
                      //blank press with no action.
                     // Serial.println("ButtonStateCount");
                     // Serial.println(ButtonStateCount);
                    }
                    buttonCounter = 0;     
                  
                }
            
                          
        }  
    
  } 

  
 

