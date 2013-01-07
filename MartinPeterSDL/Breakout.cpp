#include "include\SDL.h"

#include "GameWindow.h"
#include "Breakout.h"
#include "Input.h"
#include "Globals.h"
#include "Vector2.h"

Breakout::Breakout()
  :PaddleWidth(75), PaddleHeight(25),
   BallWidth(10), BallHeight(10)
{
  ballPos = new Vector2;
  ballPos->x = g_GameWindow->Width() / 2;
  ballPos->y = g_GameWindow->Height() - PaddleHeight - 30;

  paddlePos = new Vector2;
  paddlePos->x = g_GameWindow->Width() / 2;
  paddlePos->y = g_GameWindow->Height() - PaddleHeight - 30;


  paddle = new SDL_Rect;
  paddle->x = 0;
  paddle->y = 0;
  paddle->w = PaddleWidth;
  paddle->h = PaddleHeight;

  ball = new SDL_Rect;
  ball->x = 0;
  ball->y = 0;
  ball->w = BallWidth;
  ball->h = BallHeight;

  inputManager = new Input();
}

int Breakout::Update()
{
  inputManager->Update();

  if(inputManager->KeyDown(SDLK_ESCAPE))
  {
    g_ApplicationRunning = false;
  }

  
  ball->x = (int)(ballPos->x - BallWidth / 2);
  ball->y = (int)(ballPos->y - BallHeight / 2);

  return 0;
}

int Breakout::Draw()
{

  g_GameWindow->FillRectangle(*ball, 0xFF0000);
  g_GameWindow->FillRectangle(*paddle, 0x882288);
  return 0;
}


Breakout::~Breakout()
{
  delete ball;
  delete inputManager;
}