#pragma once
#include"Components.h"
#include"SDL2/SDL.h"
#include"../TextureManage.h"
#include"TransformComponent.h"
#include"Animation.h"
#include<map>
class SpriteComponent:public Component
{
private:

SDL_Texture*texture;
    SDL_Rect srcRect,destRect;

bool animated=false;
int frames=0;
int speed=100;

public:
    int animIndex=0;
    std::map<const char*,Animation> animations;
    SDL_RendererFlip spriteFlip=SDL_FLIP_NONE;

    TransformComponent *transforms;

    SpriteComponent()=default;
    SpriteComponent(const char*path)
    {
        setTex(path);
    }
    SpriteComponent(const char*path,bool isAnimated)
    {
        animated=isAnimated;
        Animation idle=Animation(0,3,100);
        Animation walk=Animation(1,4,100);

        animations.emplace("Idle",idle);
        animations.emplace("Walk",walk);
        Play("Idle");


        setTex(path);
    }
    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }

    void setTex(const char * path)
    {
        texture=TextureManage::LoadTexture(path);
    }
    void init()override
    {
        transforms=&entity->getComponent<TransformComponent>();
        srcRect.x=srcRect.y=0;
        srcRect.w=transforms->width;
        srcRect.h=transforms->height;
//        destRect.w=destRect.h=64;
    }
    void update()override
    {
        if(animated)
        {
            srcRect.x=srcRect.w*static_cast<int>((SDL_GetTicks()/speed)%frames);
        }
        srcRect.y=animIndex*transforms->height;

        destRect.x=static_cast<int>(transforms->position.x);
        destRect.y=static_cast<int>(transforms->position.y);
        destRect.w=transforms->width*transforms->scale;
        destRect.h=transforms->height*transforms->scale;
    }
    void draw()override
    {
        TextureManage::Draw(texture,srcRect,destRect,spriteFlip);
    }
    void Play(const char* animName)
    {
        frames=animations[animName].frames;
        animIndex=animations[animName].index;
        speed=animations[animName].speed;
    }
};
