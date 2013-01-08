#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include "GameWindow.h"
#include "Breakout.h"
#include "Globals.h"

typedef LARGE_INTEGER BigInt;

int Run();

int main(int argc, char* argv[])
{
  g_GameWindow = new GameWindow(
    g_kScreenWidth,
    g_kScreenHeight,
    g_kBitDepth
  );

  if(g_GameWindow->Init())
  {
    printf("GameWindow Init failed. Closing program.");
  }

  g_ApplicationRunning = true;

  if(Run())
  {
    printf("Application closed unexpectedly.");
  }
  else
  {

  }
  
  // Close the window and clean up its memory.
  g_GameWindow->Close();
  delete g_GameWindow;

  //system("PAUSE");

  return 0;
}

// Main loop runs in this function.
int Run()
{
  Breakout* game = new Breakout();


  // Some variables to help achieve microsecond precision on timing.
  LARGE_INTEGER startTicks;
  LARGE_INTEGER currentTicks;
  LARGE_INTEGER liFreq;
  QueryPerformanceFrequency(&liFreq);
  double delay = 1000.0 / 60.0;
  double frequency = (double)liFreq.QuadPart;
  double loopTime;
  double ticks;
  double delta;

  QueryPerformanceCounter(&startTicks);

  while(g_ApplicationRunning)
  {
    loopTime = 0;
    currentTicks = startTicks;
    QueryPerformanceCounter(&startTicks);

    g_GameWindow->Clear(g_ClearColor);

    delta = (double)(startTicks.QuadPart - currentTicks.QuadPart) *
      1000.0 / frequency;

    game->Update(delta);

    game->Draw();

    // Flip back buffer of game window - Think spritebatch.end()
    g_GameWindow->Flip();

    // Loop until our desired delay has been reached.
    while(loopTime < delay)
    {
      QueryPerformanceCounter(&currentTicks);
      ticks = (double)(currentTicks.QuadPart - startTicks.QuadPart);
      loopTime = ticks * 1000.0 / frequency;
    }
   
  }

  delete game;

  return 0;
}

