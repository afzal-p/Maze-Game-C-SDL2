#include "Game.hpp"
#include <iostream>
#include "SDL2_image/SDL_image.h"
#include "Texture.hpp"
#include "GameObject.hpp"
#include "Map.hpp"


SDL_Rect rect;
GameObject* player;
SDL_Event e;
Map* map;
SDL_Renderer* Game::sdlRenderer = nullptr;

Game::Game()
{}



void Game::init(const char *title, int xPos, int yPos, int width, int height, bool isFullScreen)
{
    int flags = 0;
    
    if(isFullScreen)
    {
        //when game is initialized fullscreen can be determined with flags
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialized ... " << std::endl;
        
        sdlWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        
        //For loading PNG images
        IMG_Init(IMG_INIT_PNG);
        
        if(sdlWindow)
        {
            std::cout << "Window created ..." << std::endl;
            //gScreenSurface1 = SDL_GetWindowSurface( sdlWindow );
        }
        
        
        sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
        
        if(sdlRenderer)
        {
            SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
            std::cout << "Renderer created ..." << std::endl;
            
    }
        
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
           
            std::cout << Mix_GetError() << std::endl;
           running = false;
        }
        
        
        gMusic = Mix_LoadMUS( "FinalGame/assets/audio/bgmByAfzal.mp3" );
        gScratch = Mix_LoadWAV( "FinalGame/assets/audio/teleport.wav" );
        
        if( gMusic == NULL )
        {
             std::cout << Mix_GetError() << std::endl;
            running = false;
        }
        
        if( gScratch == NULL )
        {
            std::cout << Mix_GetError() << std::endl;
            running = false;
        }
        
        
        running = true;
    }
}
    


void Game::init2(){
    player = new GameObject("FinalGame/assets/characters/player.png", 0, 0);
    map = new Map();
    Mix_PlayMusic( gMusic, -1 );
}

void Game::handleGameEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            //game stops on next loop if window closed
            break;
        default:
            break;
    }
    
    
    //handle movement controls
    player->handleEvent(event);
    player->move();
    
    //clears the screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );
    
}


void Game::updateGame()
{
    player->update();
    
}





void Game::renderGame()
{
    SDL_RenderClear(sdlRenderer);
    
    //main menu...
    if( player->getXPos() <= 0 && player->getYPos() <= 0  )
    {
        //map should be rendered first then players after
        map->loadMap("FinalGame/assets/maps/menu.txt");
        map->drawMap();
    }
    
   
  
    Game::teleport();
    
    Game::switchMap();
    


    player->render();
    SDL_RenderPresent(sdlRenderer);
    
}

void Game::teleport(){
    
    //teleporter 1
    
    if(  ( player->getYPos() > 352 ) &&  (player->getYPos() < 416 ) && ( player->getXPos() > 192 ) && ( player->getXPos() < 256 )  )
    {
        Mix_PlayChannel( -1, Game::gScratch, 0 );
        player->mPosX = 288;
        player->mPosY = 768;
        
    }
    
    //teleporter 2
    if(  ( player->getYPos() > 448 ) &&  (player->getYPos() < 512 ) && ( player->getXPos() > 416 ) && ( player->getXPos() < 480 )  )
    {
        Mix_PlayChannel( -1, Game::gScratch, 0 );
        player->mPosX = 544;
        player->mPosY = 0;
    }
    //teleporterer 3
    if(  ( player->getYPos() > 64 ) &&  (player->getYPos() < 96 ) && ( player->getXPos() > 640 ) && ( player->getXPos() < 704 )  )
    {
        
        Mix_PlayChannel( -1, Game::gScratch, 0 );
        player->mPosX = 0;
        player->mPosY = 32;
        
    }
    //teleporter 4
    if(  ( player->getYPos() > 128 ) &&  (player->getYPos() < 192 ) && ( player->getXPos() > 672 ) && ( player->getXPos() < 736 )  )
    {
        Mix_PlayChannel( -1, Game::gScratch, 0 );
        player->mPosX = 32;
        player-> mPosY = 480;
    }
    //teleporter 5
    if(  ( player->getYPos() > 320 ) &&  (player->getYPos() < 384 ) && ( player->getXPos() > 672 ) && ( player->getXPos() < 736 )  )
    {
        Mix_PlayChannel( -1, Game::gScratch, 0 );
        player->mPosX = 0 ;
        player->mPosY = 32;
    }
    //final portal..exit and clean game
    
    if(  ( player->getYPos() > 64 ) &&  (player->getYPos() < 96 ) && ( player->getXPos() > 704 ) && ( player->getXPos() < 768 )  )
    {
        running = false;
    }
}


void Game::switchMap(){
    
    //map column 1
    if( player->getXPos() >= 0 && player->getXPos() < 160 && player->getYPos() > 0 && player->getYPos() < 160 )
    {
        
        map->loadMap("FinalGame/assets/maps/map01.txt");
        map->drawMap();
    }
    
    
    if( player->getXPos() >= 0 && player->getXPos() < 160 && player->getYPos() >= 160 && player->getYPos() < 320 )
    {
        
        map->loadMap("FinalGame/assets/maps/map02.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 0 && player->getXPos() < 160 && player->getYPos() >= 320 && player->getYPos() < 480 )
    {
        
        map->loadMap("FinalGame/assets/maps/map03.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 0 && player->getXPos() < 160 && player->getYPos() >= 480 && player->getYPos() < 640 )
    {
        
        map->loadMap("FinalGame/assets/maps/map04.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 0 && player->getXPos() < 160 && player->getYPos() >= 640 && player->getYPos() < 800 )
    {
        
        map->loadMap("FinalGame/assets/maps/map05.txt");
        map->drawMap();
    }
    
    //map column 2
    
    if( player->getXPos() >= 160 && player->getXPos() < 320 && player->getYPos() >= 0 && player->getYPos() < 160 )
    {
        
        map->loadMap("FinalGame/assets/maps/map06.txt");
        map->drawMap();
    }
    
    
    if( player->getXPos() >= 160 && player->getXPos() < 320 && player->getYPos() >= 160 && player->getYPos() < 320 )
    {
        
        map->loadMap("FinalGame/assets/maps/map07.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 160 && player->getXPos() < 320 && player->getYPos() >= 320 && player->getYPos() < 480 )
    {
        
        map->loadMap("FinalGame/assets/maps/map08.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 160 && player->getXPos() < 320 && player->getYPos() >= 480 && player->getYPos() < 640 )
    {
        
        map->loadMap("FinalGame/assets/maps/map09.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 160 && player->getXPos() < 320 && player->getYPos() >= 640 && player->getYPos() < 800 )
    {
        
        map->loadMap("FinalGame/assets/maps/map10.txt");
        map->drawMap();
    }
    
    
    
    //map column 3
    if( player->getXPos() >= 320 && player->getXPos() < 480 && player->getYPos() >= 0 && player->getYPos() < 160 )
    {
        
        map->loadMap("FinalGame/assets/maps/map11.txt");
        map->drawMap();
    }
    
    
    if( player->getXPos() >= 320 && player->getXPos() < 480 && player->getYPos() >= 160 && player->getYPos() < 320 )
    {
        
        map->loadMap("FinalGame/assets/maps/map12.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 320 && player->getXPos() < 480 && player->getYPos() >= 320 && player->getYPos() < 480 )
    {
        
        map->loadMap("FinalGame/assets/maps/map13.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 320 && player->getXPos() < 480 && player->getYPos() >= 480 && player->getYPos() < 640 )
    {
        
        map->loadMap("FinalGame/assets/maps/map14.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 320 && player->getXPos() < 480 && player->getYPos() >= 640 && player->getYPos() < 800 )
    {
        
        map->loadMap("FinalGame/assets/maps/map15.txt");
        map->drawMap();
    }
    
    
    //map column 4
    
    if( player->getXPos() >= 480 && player->getXPos() < 640 && player->getYPos() >= 0 && player->getYPos() < 160 )
    {
        
        map->loadMap("FinalGame/assets/maps/map16.txt");
        map->drawMap();
    }
    
    
    if( player->getXPos() >= 480 && player->getXPos() < 640 && player->getYPos() >= 160 && player->getYPos() < 320 )
    {
        
        map->loadMap("FinalGame/assets/maps/map17.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 480 && player->getXPos() < 640 && player->getYPos() >= 320 && player->getYPos() < 480 )
    {
        
        map->loadMap("FinalGame/assets/maps/map18.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 480 && player->getXPos() < 640 && player->getYPos() >= 480 && player->getYPos() < 640 )
    {
        
        map->loadMap("FinalGame/assets/maps/map19.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 480 && player->getXPos() < 640 && player->getYPos() >= 640 && player->getYPos() < 800 )
    {
        
        map->loadMap("FinalGame/assets/maps/map20.txt");
        map->drawMap();
    }
    
    
    //map column 5
    
    
    if( player->getXPos() >= 640 && player->getXPos() < 800 && player->getYPos() >= 0 && player->getYPos() < 160 )
    {
        
        map->loadMap("FinalGame/assets/maps/map21.txt");
        map->drawMap();
    }
    
    
    if( player->getXPos() >= 640 && player->getXPos() < 800 && player->getYPos() >= 160 && player->getYPos() < 320 )
    {
        
        map->loadMap("FinalGame/assets/maps/map22.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 640 && player->getXPos() < 800 && player->getYPos() >= 320 && player->getYPos() < 480 )
    {
        
        map->loadMap("FinalGame/assets/maps/map23.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 640 && player->getXPos() < 800 && player->getYPos() >= 480 && player->getYPos() < 640 )
    {
        
        map->loadMap("FinalGame/assets/maps/map24.txt");
        map->drawMap();
    }
    
    if( player->getXPos() >= 640 && player->getXPos() < 800 && player->getYPos() >= 640 && player->getYPos() < 800 )
    {
        
        map->loadMap("FinalGame/assets/maps/map25.txt");
        map->drawMap();
    }
    
}

void Game::cleanGame()
{
    
    SDL_DestroyWindow(sdlWindow);
    SDL_DestroyRenderer(sdlRenderer);
    

    //Destroy window
    sdlWindow = NULL;
    sdlRenderer = NULL;
    
    //Free the sound effects
    Mix_FreeChunk( gScratch );
    gScratch = NULL;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;
    
    //Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    std::cout << "game is cleaned ..." << std::endl;
}





