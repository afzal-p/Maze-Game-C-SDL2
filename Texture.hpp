#pragma once
#include "Game.hpp"
#include "SDL2_image/SDL_image.h"

//this class is responsible for loading and drawing textures, primarily PNG files
class Texture

{
    
public:
    
    
    //mem management
    static void free(SDL_Texture* text);
    
    //want to be abke to call as a class rather than memeber funciton, will not need an object to call
    static SDL_Texture* LoadTexture(const char* filePath);
    
    static void Draw(SDL_Texture* texture, SDL_Rect sR, SDL_Rect dR);
    

    
};
