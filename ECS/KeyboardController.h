#pragma once
#include"../GameLoop.h"
#include"ECS.h"
#include"Components.h"
class KeyboardController:public Component
{
public:
    TransformComponent *transforms;
    SpriteComponent *sprite;

    void init()override
    {
        transforms=&entity->getComponent<TransformComponent>();
        sprite=&entity->getComponent<SpriteComponent>();

    }
    void update()override
{
    if(Game::e.type==SDL_KEYDOWN)
    {
       switch(Game::e.key.keysym.sym)
       {
       case SDLK_w:
        transforms->velocity.y=-0.5;
        sprite->Play("Walk");
        break;
       case SDLK_a:
        transforms->velocity.x=-0.5;
                sprite->Play("Walk");
sprite->spriteFlip=SDL_FLIP_HORIZONTAL;
        break;
       case SDLK_d:
        transforms->velocity.x=0.5;
                sprite->Play("Walk");

        break;
       case SDLK_s:
        transforms->velocity.y=0.5;
                sprite->Play("Walk");

        break;
        default:break;
       }
    }
    if(Game::e.type==SDL_KEYUP)
        {
       switch(Game::e.key.keysym.sym)
       {
       case SDLK_w:
        transforms->velocity.y=0;
                sprite->Play("Idle");

        break;
       case SDLK_a:
        transforms->velocity.x=0;
                        sprite->Play("Idle");
sprite->spriteFlip=SDL_FLIP_NONE;
        break;
       case SDLK_d:
        transforms->velocity.x=0;
                        sprite->Play("Idle");

        break;
       case SDLK_s:
        transforms->velocity.y=0;
                        sprite->Play("Idle");

        break;
        default:break;
       }
}
}
};
