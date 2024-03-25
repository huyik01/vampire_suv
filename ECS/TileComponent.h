//#pragma once
//#include"ECS.h"
//#include"TransformComponent.h"
//#include"SpriteComponent.h"
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
//        case 0:
//            path="water.png";
//            break;
//        case 1:
//            path="dirt.png";
//            break;
//        case 2:
//            path="grass.png";
//            break;
//            break;
//            default:break;
//        }
//    }
//    void init()override
//    {
//        entity->addComponent<TransformComponent>((float)tileRect.x,(float)tileRect.y,tileRect.w,tileRect.h,1);
//        transforms=&entity->getComponent<TransformComponent>();
//        entity->addComponent<SpriteComponent>(path);
//        sprite=&entity->getComponent<SpriteComponent>();
//    }
//};
//
