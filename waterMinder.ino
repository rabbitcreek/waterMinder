/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  This example shows how to use Arduino MKRGSM 1400
  to connect your project to Blynk.
  Note: This requires MKRGSM library
    from https://www.arduino.cc/en/Reference/MKRGSM
  Feel free to apply it to any other example. It's simple!
 *************************************************************/
#define BLYNK_PRINT Serial
#include <MKRGSM.h>
#include <BlynkSimpleMKRGSM.h>
GSMClient client;
GPRS gprs;
GSM gsmAccess;
BlynkTimer timer;

int counter = 0;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "q6jVjwQ3ZTIGaOMgUJRa5FSltNL7Kbr4";

// Your SIM and GPRS credentials
// Leave empty, if missing pin, user or pass
char pin[]  = "";
char apn[]  = "hologram";
char user[] = "";
char pass[] = "";
void endGame(){
  while(1);
}
void myTimerEvent()
{
  if(counter < 6){
 Blynk.email("9072297307@txt.att.net", "waterWarning", "The BarrelEye is Sinking!");
 Blynk.notify("Your Boat is Sinking!!!");
  }
  counter = counter + 1;
 Blynk.virtualWrite(V5, counter);
  
}

 
void setup(){
Serial.begin(9600);
delay(1500); 
Blynk.begin(auth, gsmAccess, gprs, client, pin, apn, user, pass);
  timer.setInterval(60000L, myTimerEvent);

Blynk.email("9072297307@txt.att.net", "waterWarning", "Your Boat is Sinking!");
Blynk.notify("waterWarning--Your Boat is Sinking!");
}
  void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
