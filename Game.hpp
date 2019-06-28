#pragma once
#include "SDL2/SDL.h"
#include "SDL2_mixer/SDL_mixer.h"

//this class is responsible for updating SDL as the game progresses, and freeing all used resources once the game ends
class Game {
  
public:
    Game();
    
    //sdl initialization
    void init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen);
    
    //loads player to screen
    void init2();
    
    //used in main game loop
    void handleGameEvents();
    //update/render game object
    void updateGame();
    void renderGame();
    
    //in-line; ends game
    bool isRunning() {return running;}
    
    static SDL_Renderer *sdlRenderer;
    
    //memory management
    void cleanGame();

private:
    
    void teleport();
    void switchMap();
    
    bool running;
    
    SDL_Window *sdlWindow;
    
    
    SDL_Rect rect;
    //'rect' defines the dimensions for the bottom-left of the window
    SDL_Rect srcRect, destRect;

    //The music that will be played
    Mix_Music *gMusic;
    
    //The sound effects that will be used
    Mix_Chunk *gScratch ;
    
};


