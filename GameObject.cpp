#include "GameObject.hpp"
#include "Texture.hpp"


#include <iostream>

GameObject::GameObject(const char* textureSheet, int x, int y)
{
    texture = Texture::LoadTexture(textureSheet);
    //initial positions on screen
    mPosX = x = 0;
    mPosY = y = 0;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}


void GameObject::update()
{
    
    srcR.h = 23;
    srcR.w = 23;
    
    srcR.x = 0;
    srcR.y = 0;
    
    destR.x = mPosX;
    destR.y = mPosY;
    
    destR.w = srcR.w ;
    destR.h = srcR.h ;
    
   
}


void GameObject::render()
{
    //source rect is set to null since entire image is used; png file is 32x32 pixels
    SDL_RenderCopy(Game::sdlRenderer, texture, NULL, &destR);
}


void GameObject::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= PIC_VEL; break;
            case SDLK_DOWN: mVelY += PIC_VEL; break;
            case SDLK_LEFT: mVelX -= PIC_VEL; break;
            case SDLK_RIGHT: mVelX += PIC_VEL; break;
            default: break;
                
        }
    }
    
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += PIC_VEL; break;
            case SDLK_DOWN: mVelY -= PIC_VEL; break;
            case SDLK_LEFT: mVelX += PIC_VEL; break;
            case SDLK_RIGHT: mVelX -= PIC_VEL; break;
            default: break;
        }
    }
}


int GameObject::getXPos()
{
    return GameObject::mPosX;
}

int GameObject::getYPos()
{
    return GameObject::mPosY;
}



void GameObject::move()
{
    //Move the dot left or right
    mPosX += mVelX;
    
    //Move the dot up or down
    mPosY += mVelY;
    
    
    //screen edge case 1
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + PIC_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
    
    //screen edge case 2
    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + PIC_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
    
     //the following are map edge cases for walls
    
    //map1
    if(  ( mPosY > 32 ) &&  (mPosY < 160 ) && ( mPosX < 32 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > -32 ) &&  (mPosY < 128 ) && ( mPosX > 32 ) && ( mPosX < 160 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > -32 ) &&  (mPosY < 32 ) && ( mPosX > 0 ) && ( mPosX < 64 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map2
    if(  ( mPosY > 128 ) &&  (mPosY < 288 ) && ( mPosX < 32 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 192 ) &&  (mPosY < 320 ) && ( mPosX > 32 ) && ( mPosX < 96 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 160 ) &&  (mPosY < 320 ) && ( mPosX > 64 ) && ( mPosX < 128 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 128 ) &&  (mPosY < 320 ) && ( mPosX > 96 ) && ( mPosX < 160 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
     //map3
    if(  ( mPosY > 320 ) &&  (mPosY < 480 ) && ( mPosX > 0 ) && ( mPosX < 64 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 288 ) &&  (mPosY < 480 ) && ( mPosX > 32 ) && ( mPosX < 160 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map4
    
    if(  ( mPosY > 480 ) &&  (mPosY < 640 ) && ( mPosX < 32 ) )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 480 ) &&  (mPosY < 544 ) && ( mPosX > 0 ) && ( mPosX < 128 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 448 ) &&  (mPosY < 512 ) && ( mPosX > 32 ) && ( mPosX < 96 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 544 ) &&  (mPosY < 640 ) && ( mPosX > 32 ) && ( mPosX < 96 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map 5
    if(  ( mPosY > 608 ) &&  (mPosY < SCREEN_HEIGHT ) && ( mPosX < 32 ) )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 640 ) &&  (mPosY < 768 ) && ( mPosX > 32 ) && ( mPosX < 160 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map 6
    
    
    if(  ( mPosY > -32 ) &&  (mPosY < 128 ) && ( mPosX > 128 ) && ( mPosX < 288 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > -32 ) &&  (mPosY < 96 ) && ( mPosX > 256 ) && ( mPosX < 320 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map7
    
    if(  ( mPosY > 128 ) &&  (mPosY < 192 ) && ( mPosX > 128 ) && ( mPosX < 256 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 192 ) &&  (mPosY < 256 ) && ( mPosX > 128 ) && ( mPosX < 192 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 192 ) &&  (mPosY < 256 ) && ( mPosX > 192 ) && ( mPosX < 320 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //section is a part of map8
    if(  ( mPosY > 256 ) &&  (mPosY < 352 ) && ( mPosX > 192 ) && ( mPosX < 288 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map 8
    
    
    if(  ( mPosY > 288 ) &&  (mPosY < 480 ) && ( mPosX > 128 ) && ( mPosX < 192 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 352 ) &&  (mPosY < 448 ) && ( mPosX > 256 ) && ( mPosX < 320 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    

    
    
    
    //map 9
    
    if(  ( mPosY > 480 ) &&  (mPosY < 640 ) && ( mPosX > 128 ) && ( mPosX < 224 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 448 ) &&  (mPosY < 640 ) && ( mPosX > 192 ) && ( mPosX < 256 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //goes to 14
    if(  ( mPosY > 448 ) &&  (mPosY < 640 ) && ( mPosX > 256 ) && ( mPosX < 384 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map 10
    
    if(  ( mPosY > 640 ) &&  (mPosY < 768 ) && ( mPosX > 128 ) && ( mPosX < 192 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 608 ) &&  (mPosY < 768 ) && ( mPosX > 160 ) && ( mPosX < 224 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 640 ) &&  (mPosY < 768 ) && ( mPosX > 192 ) && ( mPosX < 256 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 672 ) &&  (mPosY < 768 ) && ( mPosX > 224 ) && ( mPosX < 288 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }

    if(  ( mPosY > 608 ) &&  (mPosY < 768 ) && ( mPosX > 256 ) && ( mPosX < 320 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }

    
    //map11
    
    if(  ( mPosY > 0 ) &&  (mPosY < 160 ) && ( mPosX > 320 ) && ( mPosX < 480 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map12
    
    if(  ( mPosY > 128 ) &&  (mPosY < 224 ) && ( mPosX > 320 ) && ( mPosX < 480 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    
    if(  ( mPosY > 160 ) &&  (mPosY < 256 ) && ( mPosX > 288 ) && ( mPosX < 352 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //goes to 13
    if(  ( mPosY > 256 ) &&  (mPosY < 448 ) && ( mPosX > 288 ) && ( mPosX < 352 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //goes to 13
    if(  ( mPosY > 192 ) &&  (mPosY < 384 ) && ( mPosX > 352 ) && ( mPosX < 416 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //extends to 13/17/18
    
    if(  ( mPosY > 224 ) &&  (mPosY < 352 ) && ( mPosX > 416 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    
    //map13
    
    if(  ( mPosY > 224 ) &&  (mPosY < 352 ) && ( mPosX > 416 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 320 ) &&  (mPosY < 384 ) && ( mPosX > 320 ) && ( mPosX < 384 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 384 ) &&  (mPosY < 448 ) && ( mPosX > 320 ) && ( mPosX < 384 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //goes to 18
    
    if(  ( mPosY > 384 ) &&  (mPosY < 480 ) && ( mPosX > 384 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
     //goes to 18
    
    if(  ( mPosY > 352 ) &&  (mPosY < 480 ) && ( mPosX > 416 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map14
    if(  ( mPosY > 480 ) &&  (mPosY < 608 ) && ( mPosX > 384 ) && ( mPosX < 480 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //to 15/19/20
    
    if(  ( mPosY > 544 ) &&  (mPosY < SCREEN_HEIGHT ) && ( mPosX > 416 ) && ( mPosX < 544 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    

    
    //map15
    
    if(  ( mPosY > 672 ) &&  (mPosY < SCREEN_HEIGHT ) && ( mPosX > 320 ) && ( mPosX < 480 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 704 ) &&  (mPosY < 786 ) && ( mPosX > 288 ) && ( mPosX < 384 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    if(  ( mPosY > 608 ) &&  (mPosY < 672 ) && ( mPosX > 320 ) && ( mPosX < 384 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 608 ) &&  (mPosY < 672 ) && ( mPosX > 384 ) && ( mPosX < 448 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map16
    
    if(  ( mPosY > 0 ) &&  (mPosY < 96 ) && ( mPosX > 480 ) && ( mPosX < 640 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > -32   ) && ( mPosY < 32  ) && ( mPosX > 576 ) && ( mPosX < SCREEN_WIDTH )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > 64   ) && ( mPosY < 160  ) && ( mPosX > 544 ) && ( mPosX < 608 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > 96   ) && ( mPosY < 160  ) && ( mPosX > 576 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > 0   ) && ( mPosY < 96  ) && ( mPosX > 448 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > 128   ) && ( mPosY < 224  ) && ( mPosX > 448 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map17
    
    
    if(  (mPosY > 128   ) && ( mPosY < 352  ) && ( mPosX > 512 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  (mPosY > 288   ) && ( mPosY < 384  ) && ( mPosX > 544 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //map19
    
    if(  ( mPosY > 480 ) &&  (mPosY < 544 ) && ( mPosX > 448 ) && ( mPosX < 512 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    //edges
    
    if(  ( mPosY > -32 ) &&  (mPosY < SCREEN_HEIGHT ) && ( mPosX > 736 ) && ( mPosX < SCREEN_WIDTH )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 736 ) &&  (mPosY < SCREEN_HEIGHT ) && ( mPosX > 480 ) && ( mPosX < SCREEN_WIDTH )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    
    //map21
    
    
    if(  ( mPosY > 32 ) &&  (mPosY < 64 ) && ( mPosX > 704 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    
    
    
    if(  ( mPosY > 160 ) &&  (mPosY < 224 ) && ( mPosX > 672 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 96 ) &&  (mPosY < 160 ) && ( mPosX > 672 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    

    
    if(  ( mPosY > 288 ) &&  (mPosY < 352 ) && ( mPosX > 672 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    

    
    if(  ( mPosY > 352 ) &&  (mPosY < 416 ) && ( mPosX > 672 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 224 ) &&  (mPosY < 288 ) && ( mPosX > 672 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 416 ) &&  (mPosY < 480 ) && ( mPosX > 672 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 448 ) &&  (mPosY < 512 ) && ( mPosX > 704 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 480 ) &&  (mPosY < 544 ) && ( mPosX > 672 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 512 ) &&  (mPosY < 576 ) && ( mPosX > 672 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //bottom solo piece
    
    if(  ( mPosY > 704 ) &&  (mPosY < 768 ) && ( mPosX > 544 ) && ( mPosX < 608 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map25
    if(  ( mPosY > 704 ) &&  (mPosY < 768 ) && ( mPosX > 640 ) && ( mPosX < SCREEN_WIDTH )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 640 ) &&  (mPosY < 704 ) && ( mPosX > 544 ) && ( mPosX < 608 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 640 ) &&  (mPosY < 704 ) && ( mPosX > 608 ) && ( mPosX < SCREEN_WIDTH )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 672 ) &&  (mPosY < 736 ) && ( mPosX > 672 ) && ( mPosX < 768 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map24
    
    if(  ( mPosY > 608 ) &&  (mPosY < 672 ) && ( mPosX > 544 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 576 ) &&  (mPosY < 640 ) && ( mPosX > 544 ) && ( mPosX < 736 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 512 ) &&  (mPosY < 576 ) && ( mPosX > 544 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 480 ) &&  (mPosY < 544 ) && ( mPosX > 512 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
   
    if(  ( mPosY > 448 ) &&  (mPosY < 512 ) && ( mPosX > 512 ) && ( mPosX < 640 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    //map23
    if(  ( mPosY > 416 ) &&  (mPosY < 480 ) && ( mPosX > 512 ) && ( mPosX < 576 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 416 ) &&  (mPosY < 480 ) && ( mPosX > 576 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 384 ) &&  (mPosY < 448 ) && ( mPosX > 512 ) && ( mPosX < 576 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
    if(  ( mPosY > 384 ) &&  (mPosY < 448 ) && ( mPosX > 576 ) && ( mPosX < 672 )  )
    {
        mPosX -= mVelX;
        mPosY -= mVelY;
    }
    
}


