//#pragma once
//#include"ECS/ECS.h"
//#include"ECS/TransformComponent.h"
//#include"ECS/SpriteComponent.h"
//#include"SDL2/SDL.h"
//class TileComponent:public Component
//{
//public:
//    TransformComponent*transforms;
//    SpriteComponent* sprite;
//    SDL_Rect tileRect;
//    char*path;
//    int tileID;
//    TileComponent()=default;
//    TileComponent(int x,int y,int w,int h,int id)
//    {
//        tileRect.x=x;
//        tileRect.y=y;
//        tileRect.w=w;
//        tileRect.h=h;
//        tileID=id;
//        switch(tileID)
//        {
//        case -1:
//            path="water.png";
//            break;
//        case 1:
//            path="dirt.png";
//            break;
//        case 3:
//            path="white.png";
//            break;
//        case 2:
//            path="grass.png";break;
//            default:break;
//        }
//    }
//    void init()override
//    {
//        entity->addComponent<TransformComponent>(tileRect.x,tileRect.y,tileRect.w,tileRect.h,1);
//        transforms=&entity->getComponent<TransformComponent>();
//        entity->addComponent<SpriteComponent>(path);
//        sprite=&entity->getComponent<SpriteComponent>();
//    }
//};
