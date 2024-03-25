#pragma once
#include"Components.h"
#include"../Vector2D.h"
class TransformComponent:public Component
{
//private:
//    int xpos;
//    int ypos;
public:
Vector2D position;
Vector2D velocity;
int speed=3;
int height=32;
int width=32;
int scale=1;
TransformComponent()
{
position.Zero();
}
TransformComponent(int sc)
{
position.Zero();
 scale=sc;
}
TransformComponent(int x,int y)
{
position.Zero();
}
TransformComponent(float x,float y,int h,int w,int sc)
{
     position.x=x;
     position.y=y;
     height=h;
     width=w;
     scale=sc;
}
    void init()override
    {
        velocity.Zero();
    }
    void update() override
    {
//        xpos++;
//        ypos++;
position.x+=velocity.x*speed;
position.y+=velocity.y*speed;
    }
//     int x(){return xpos;}
//     void x(int x){xpos=x;}
//    int y(){return ypos;}
//    void y(int y){ypos=y;}
//    void setPos(int x,int y)
//    {
//        xpos=x;
//        ypos=y;
//    }
};

