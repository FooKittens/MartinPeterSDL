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
  paddle->x = g_GameWindow->Width() / 2 - PaddleWidth / 2;
  paddle->y = g_GameWindow->Height() - PaddleHeight - 30;
  paddle->w = PaddleWidth;
  paddle->h = PaddleHeight;

  ball = new SDL_Rect;
  ball->x = paddle->x + PaddleWidth / 2 - BallWidth / 2;
  ball->y = paddle->y - BallHeight;
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