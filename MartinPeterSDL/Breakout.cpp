#include "include\SDL.h"

#include "GameWindow.h"
#include "Breakout.h"
#include "Input.h"
#include "Globals.h"
#include "Vector2.h"
#include "Entity.h"

Breakout::Breakout()
  :PaddleWidth(75), PaddleHeight(25),
   BallWidth(10), BallHeight(10)
{

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