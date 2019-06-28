#include "Texture.hpp"
#include <iostream>
using namespace std;



void Texture::free(SDL_Texture* text)
{
        SDL_DestroyTexture( text );
        text = NULL;
}

SDL_Texture* Texture::LoadTexture(const char* texture)

{
    
    SDL_Surface* tempSurface = IMG_Load(texture);
    
    if( tempSurface == NULL )
    {
        std::cout << IMG_GetError() << std::endl;
    }
    SDL_Texture* playerTex = SDL_CreateTextureFromSurface(Game::sdlRenderer,tempSurface);

    SDL_FreeSurface(tempSurface);
    return playerTex;
};



void Texture::Draw(SDL_Texture* texture, SDL_Rect sR, SDL_Rect dR)
{
    SDL_RenderCopy(Game::sdlRenderer, texture, &sR, &dR);

}
