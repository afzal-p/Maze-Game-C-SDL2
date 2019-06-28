#pragma once
#include "Game.hpp"


//this class is responsible for loading the player, check for collision on the map, and handling movements on screen through arrow key presses
class GameObject {
    
public:
 
    GameObject(const char* textureSheet, int x, int y);
  
    void update();
    void render();
    
    
    //screen dimensions
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 800;
    
    //The dimensions of the player
    static const int PIC_WIDTH = 5;
    static const int PIC_HEIGHT = 5;
    
    //Maximum velocity of the player
    static const int PIC_VEL = 2.75;
    
    
    //Takes key presses and adjusts the players velocity
    void handleEvent( SDL_Event& e);
    
    //Moves the dot
    void move();
    
    //The X and Y coords of player
    int mPosX, mPosY;

    int getXPos();
    int getYPos();
    
private:
    
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    
    //source and destination rectangles
    SDL_Rect srcR, destR;
    
    SDL_Event event1;
    

    //The velocity of the player
    int mVelX, mVelY;

    
};
