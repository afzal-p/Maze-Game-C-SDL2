#pragma once
#include "Game.hpp"
#include<string>
using namespace std;

//this class is responsible for reading map data from text files, also for loading map tiles
class Map
{
public:
    
    Map();
  
    static const int rows = 25;
    static const int cols = 25;

    int defaultLevel[25][25];
    
    void loadMap(std::string path);
    void drawMap();
    

    
private:
    SDL_Texture* water;
    SDL_Texture* grassWall;
    SDL_Texture* floor;
    SDL_Texture* shadow;
    SDL_Texture* text;
    SDL_Texture* raft;
    
    SDL_Rect srcRect, destRect;
    
    

    
};


