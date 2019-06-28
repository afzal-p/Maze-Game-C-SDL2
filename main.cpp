#include "Game.hpp"
#include <iostream>

Game *game = nullptr;


    //limiting frame rate
    const int FPS = 60; //normal for monitors
    const int frameDelay = 1000 / FPS; //max time in bw frames
    Uint32 frameStart;  //large integer
    int frameTime;

//Main Game Loop
int main(int argc, char** args)
{
    game = new Game();

    //game loop
    game->init("C-Mont-Maze-Quake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
    
    game->init2();

    while(game->isRunning())
    {

        //get current running time in ms since SDL init

        frameStart = SDL_GetTicks();

        game->handleGameEvents();
        game->renderGame();
        game->updateGame();
        
        frameTime = SDL_GetTicks() - frameStart; //ms to go through handling events, updating/rendering objects

       if (frameDelay > frameTime)
          SDL_Delay(frameDelay - frameTime);
     }

    //when running is false and found/reached correct box, run cleanGame() from the Game class
    game->cleanGame();

    return 0;
}





