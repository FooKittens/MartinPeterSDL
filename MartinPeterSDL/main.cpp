#include <iostream>
#include "SDL.h"
#include "GameWindow.h"
#include "Breakout.h"
#include "Globals.h"

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

  while(g_ApplicationRunning)
  {
    g_GameWindow->Clear(g_ClearColor);

    game->Update();

    game->Draw();

    // Flip back buffer of game window - Think spritebatch.end()
    g_GameWindow->Flip();

    SDL_Delay(g_kDelayTime);
  }

  delete game;

  return 0;
}

