#include"Map.h"
#include"TextureManage.h"
#include"GameLoop.h"
#include<fstream>
int lvl1[20][25]={
         {0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,1,2,2,2,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map()
{
  dirt=TextureManage::LoadTexture("img/dirt.png");
  grass=TextureManage::LoadTexture("img/grass.png");
  water=TextureManage::LoadTexture("img/water.png");
  LoadMap(lvl1);
  src.x=src.y=0;
  src.w=dest.w=32;
  src.h=dest.h=32;
  dest.x=dest.y=0;
}
Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
}
void Map::LoadMap(int arr[20][25])
{
    int type=0;
    for(int row=0;row<20;row++)
    {
        for(int column=0;column<25;column++)
        {           map[row][column]=arr[row][column];
        }
    }
}
void Map::DrawMap()
{
    int type=0;
    SDL_RendererFlip cow=SDL_FLIP_NONE;
    for(int row=0;row<20;row++)
    {
        for(int column=0;column<25;column++)
        {
            type=map[row][column];
            dest.x=column*32;
            dest.y=row*32;
            switch(type)
            {
                case 0:TextureManage::Draw(water,src,dest,cow);break;
                case 1:TextureManage::Draw(grass,src,dest,cow);break;
                case 2:TextureManage::Draw(dirt,src,dest,cow);break;
                default:break;
            }
        }}}

