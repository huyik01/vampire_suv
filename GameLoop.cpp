#include"GameLoop.h"
#include<SDL2/SDL_image.h>
#include"TextureManage.h"
#include"GameObject.h"
#include"Map.h"
#include"ECS/Components.h"
#include"Vector2D.h"
#include"Collision.h"
#include"TextureMapManage.h"
#include"TextObject.h"
//GameObject*player;
//GameObject*enemies;
TTF_Font* font_text=NULL;
Map*maps;
Manager manager;
 SDL_Event Game::e;
// std::vector<ColliderComponent*>Game::colliders;
auto&wall(manager.addEntity());
auto&player(manager.addEntity());
enum groupLables:std::size_t
{
  groupMap,
  groupPlayers,
  groupEnemies,
  groupColliders
};
//auto&tile0(manager.addEntity());
//auto&tile1(manager.addEntity());
//auto&tile2(manager.addEntity());

SDL_Renderer*Game::renderer=nullptr;
SDL_Texture*PlayerTexture;
SDL_Rect srcR,destR;
Game::Game() {}
Game::~Game(){}
void Game::init(const char*title,int xpos,int ypos,int width,int height,bool fullscreen)
{
    int flags=0;
    if(fullscreen)flags=SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        cout<<"Subsystem Initialized!"<<endl;
        window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
    if(window)cout<<"Window Created"<<endl;
      renderer=SDL_CreateRenderer(window,-1,0);
      if(renderer)
      {
          cout<<"Renderer created"<<endl;
      SDL_SetRenderDrawColor(renderer,255,255,255,255);
      }
      isRunning=true;}
      else isRunning=false;
//     player=new GameObject("Ảnh chụp màn hình 2024-03-12 231319.png",0,0);
//     enemies=new GameObject("2023-11-19 (1).png",30,30);
     maps=new Map();
//Map::LoadMap("img\p16x16.map",16,16);
//     tile0.addComponent<TileComponent>(200,200,32,32,0);
//     tile1.addComponent<TileComponent>(250,250,32,32,1);
//     tile1.addComponent<ColliderComponent>("dirt");
//
//     tile2.addComponent<TileComponent>(150,150,32,32,2);
//     tile2.addComponent<ColliderComponent>("grass");
     player.addComponent<TransformComponent>(2);
     player.addComponent<SpriteComponent>("img/Không có tiêu đề.png",true);
    player.addComponent<KeyboardController>();
    wall.addComponent<TransformComponent>(300.0f,300.0f,300,20,1);
    wall.addComponent<SpriteComponent>("img/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    player.addComponent<ColliderComponent>("player");
   player.addGroup(groupPlayers);
wall.addGroup(groupMap);
//     player.addComponent<PositionComponent>();
}
void Game::handleEvents()
{

 SDL_PollEvent(&e);
 switch(e.type)
 {
 case SDL_QUIT:
    isRunning=false;
    break;
 }
}
void Game::update()
{
// player->Update();
// enemies->Update();
manager.refresh();
 manager.update();

// for(auto cc:colliders)
// {
// if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
//                    wall.getComponent<ColliderComponent>().collider));
// {
//     player.getComponent<TransformComponent>().scale=1;
//     player.getComponent<TransformComponent>().velocity*-1;
//     std::cout<<"Wall Hit!"<<std::endl;
// }
 }
// player.getComponent<TransformComponent>().position.Add(Vector2D(5,0));
//
//if(player.getComponent<TransformComponent>().position.x>100)
//{
//    player.getComponent<SpriteComponent>().setTex("Ảnh chụp màn hình 2024-03-12 231319.png");
//}

// std::cout<<newPlayer.getComponent<PositionComponent>().x()<<","<<
// newPlayer.getComponent<PositionComponent>().y()<<endl;
auto&players(manager.getGroup(groupPlayers));
auto&enemies(manager.getGroup(groupEnemies));
void Game::render()
{

SDL_RenderClear(renderer);
maps->DrawMap();////player->Render();
//enemies->Render();
//manager.draw();
for(auto&p:players)
{
    p->draw();
}
SDL_RenderPresent(renderer);
}
void Game::clean()
{
SDL_DestroyWindow(window);
SDL_DestroyRenderer(renderer);
SDL_Quit();
cout<<"Game cleaned"<<endl;
}
//void Game::AddTile(int id,int x,int y)
//{
//    auto&tile(manager.addEntity());
//    tile.addComponent<TileComponent>(x,y,32,32,id);
//}
