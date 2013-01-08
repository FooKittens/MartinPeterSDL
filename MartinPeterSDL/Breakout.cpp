#include "include\SDL.h"

#include "GameWindow.h"
#include "Breakout.h"
#include "Input.h"
#include "Globals.h"
#include "Vector2.h"
#include "Entity.h"
#include "Ball.h"

Breakout::Breakout()
  :PaddleWidth(75), PaddleHeight(25),
   BallWidth(10), BallHeight(10)
{
  inputManager = new Input();

  Vector2 ballPos(g_kScreenWidth / 2, g_kScreenHeight / 2);
  
  SDL_Rect ballRect;
  ballRect.x = (int)ballPos.x - BallWidth / 2;
  ballRect.y = (int)ballPos.y - BallHeight / 2;
  ballRect.w = BallWidth;
  ballRect.h = BallHeight;

  myBall = new Ball(ballPos, ballRect);

  Vector2 paddlePos(g_kScreenWidth / 2, g_kScreenHeight - PaddleHeight- 30);
  SDL_Rect paddleRect;
  paddleRect.x = (int)paddlePos.x - PaddleWidth / 2;
  paddleRect.y = (int)paddlePos.y - PaddleHeight / 2;
  paddleRect.w = PaddleWidth;
  paddleRect.h = PaddleHeight;
}

int Breakout::Update(double deltaTime)
{
  inputManager->Update();

  if(inputManager->KeyDown(SDLK_ESCAPE))
  {
    g_ApplicationRunning = false;
  }

  myBall->Update(deltaTime);


  return 0;
}

int Breakout::Draw()
{
  myBall->Draw(g_GameWindow);

  return 0;
}

Breakout::~Breakout()
{
  delete myBall;
  delete inputManager;
}