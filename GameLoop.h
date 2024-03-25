#ifndef GameLoop_h
#define GameLoop_h
#include<SDL2/SDL.h>
#include<iostream>
#include<vector>
class ColliderComponent;
using namespace std;
class Game{
public:
    Game();
    ~Game();
    void init(const char*title,int xpos,int ypos,int width,int height,bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}
//    static void AddTile(int id,int x,int y);
    static SDL_Renderer*renderer;
    static SDL_Event e;
//    static std::vector<ColliderComponent*>colliders;
private:
    bool isRunning;
    SDL_Window*window;
//    SDL_Renderer*renderer;

};
#endif // GameLoop_h


