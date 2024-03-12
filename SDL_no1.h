#include<iostream>
#include<SDL2/SDL.h>
using namespace std;

void logSDLError(std::ostream&os,const std::string&msg,bool fatal=false);
void initSDL(SDL_Window*&window,SDL_Renderer*&renderer);
void quitSDL(SDL_Window*window,SDL_Renderer*renderer);
void WaitUntilKeyPressed();
SDL_Texture*loadTexture(string path,SDL_Renderer*renderer);
