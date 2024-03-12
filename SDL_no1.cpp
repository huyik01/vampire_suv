#include<iostream>
#include"SDL_no1.h"
#include<SDL2/SDL_image.h>
using namespace std;
const int SCREEN_WIDTH=800;
const int SCREEN_HEIGHT=600;
const string SCREEN_TITLE="nitro";
void logSDLError(std::ostream& os,const std::string &msg, bool fatal)
{
    os<<msg<<"Error: "<<SDL_GetError()<<endl;
    if(fatal)
    {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window*&window,SDL_Renderer*&renderer)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        logSDLError(std::cout,"SDL_Init",true);
    window=SDL_CreateWindow(SCREEN_TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(window==nullptr)logSDLError(std::cout,"CreateWindow",true);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(renderer==nullptr)logSDLError(std::cout,"CreateRenderer",true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"linear");
    SDL_RenderSetLogicalSize(renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
}
void quitSDL(SDL_Window*window,SDL_Renderer*renderer)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
void WaitUntilKeyPressed()
{
  SDL_Event e;
  while(true)
  {
      if(SDL_WaitEvent(&e)!=0&&(e.type==SDL_KEYDOWN||e.type==SDL_QUIT))
        return;
      SDL_Delay(100);
  }
}
SDL_Texture*loadTexture(string path,SDL_Renderer*renderer)
{
    SDL_Texture*newTexture=nullptr;
    SDL_Surface*loadedSurface=IMG_Load(path.c_str());
    if(loadedSurface==nullptr)
        cout<<"Unable to load imgae"<<path<<"SDL_Image Error"<<IMG_GetError()<<endl;
    else{
        newTexture=SDL_CreateTextureFromSurface(renderer,loadedSurface);
        if(newTexture==nullptr)
            cout<<"Unable to create texture from"<<path<<"SDL Error"<<SDL_GetError()<<endl;
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
