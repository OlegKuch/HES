#include <TVout.h>
#include <fontALL.h>

#define DOWN_BTN 5
#define UP_BTN 2
#define LEFT_BTN 4
#define RIGHT_BTN 3

TVout TV;

unsigned long gameTimer = 0, buttonTimer = 0;
bool down,up,left,right;
byte x = 0,y = 0;
byte game = 0, gameSelect = 0;
byte myRacketY = 0,enRacketY = 0;
int speedY, speedX;
byte myScore, enScore;

void setup()
{
  TV.begin(PAL);
  pinMode(DOWN_BTN,INPUT_PULLUP);
  pinMode(UP_BTN,INPUT_PULLUP);
  pinMode(LEFT_BTN,INPUT_PULLUP);
  pinMode(RIGHT_BTN,INPUT_PULLUP);
}

void loop()
{
  if(millis() - buttonTimer >= 20)
  { 
    down = !digitalRead(DOWN_BTN);
    up = !digitalRead(UP_BTN);
    left = !digitalRead(LEFT_BTN);
    right = !digitalRead(RIGHT_BTN);
    buttonTimer = millis();
  }
  switch(game)
  {
    case 0:
      MainMenu();
      break;   
    case 1:
      GreenCubicClassic();
      break;
    case 2:
      Pong();
      break;
  } 
}
