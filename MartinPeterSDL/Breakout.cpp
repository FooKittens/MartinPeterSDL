#include "include\SDL.h"

#include "GameWindow.h"
#include "Breakout.h"
#include "Input.h"
#include "Globals.h"
#include "Vector2.h"
#include "GameObject.h"

Breakout::Breakout()
  :PaddleWidth(75), PaddleHeight(25),
   BallWidth(10), BallHeight(10)
{
  ball = new GameObject;
  paddle= new GameObject;

  ball->position.x = g_GameWindow->Width() / 2;
  ball->position.y = g_GameWindow->Height() - PaddleHeight - 30;

  paddle->position.x = g_GameWindow->Width() / 2;
  paddle->position.y = g_GameWindow->Height() - PaddleHeight - 30;

  paddle->rect.x = 0;
  paddle->rect.y = 0;
  paddle->rect.w = PaddleWidth;
  paddle->rect.h = PaddleHeight;

  ball->rect.x = 0;
  ball->rect.y = 0;
  ball->rect.w = BallWidth;
  ball->rect.h = BallHeight;

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

  g_GameWindow->FillRectangle(ball->rect, 0xFF0000);
  g_GameWindow->FillRectangle(paddle->rect, 0x882288);
  return 0;
}

void Breakout::MoveBall()
{

}

void Breakout::MovePaddle()
{

}


Breakout::~Breakout()
{
  delete ball;
  delete inputManager;
}