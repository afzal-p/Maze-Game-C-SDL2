#include "Map.hpp"
#include "Texture.hpp"
#include<iostream>
#include<fstream>


Map::Map()
{
    //load map tile textures
    water = Texture::LoadTexture("FinalGame/assets/tiles/water.png");
    grassWall = Texture::LoadTexture("FinalGame/assets/tiles/grass.png");
    floor = Texture::LoadTexture("FinalGame/assets/tiles/floor.png");
    shadow = Texture::LoadTexture("FinalGame/assets/tiles/shadow.png");
    text = Texture::LoadTexture("FinalGame/assets/tiles/text.png");
    raft = Texture::LoadTexture("FinalGame/assets/tiles/raft.png");
    

    srcRect.x = srcRect.y = 0;
    //dimentions of each map tile
    srcRect.w = destRect.w = 32;
    srcRect.h = destRect.h = 32;
    
    destRect.x = destRect.y = 0;
}

//map data traversal
void Map::loadMap(std::string path)
{
    ifstream in (path);
    
    //error check
    if(!in)
    {
        cout<<"Error...@@@@@.." <<endl;
    }
    
    char preInt;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // preInt equals each one of the tile types, but only one at a time.
            in >> preInt;
            int tile = atoi(&preInt);
            defaultLevel[i][j] = tile;

        }
    }
}
    
void Map::drawMap()
    {
    int type = 0;
    
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            
            type = defaultLevel[row][col];
            //scaled
            destRect.x = col * 32;
            destRect.y = row * 32;
            
            switch (type) {
                case 0:
                    Texture::Draw(water, srcRect, destRect);
                    break;
                case 1:
                    Texture::Draw(grassWall, srcRect, destRect);
                    break;
                case 2:
                    Texture::Draw(floor, srcRect, destRect);
                    break;
                
                case 3:
                    Texture::Draw(raft, srcRect, destRect);
                    break;
                    
                case 4:
                    Texture::Draw(shadow, srcRect, destRect);
                    break;
                    
                case 5:
                    Texture::Draw(text, srcRect, destRect);
                    break;
                default:
                    break;
            }
        }
    }
}




