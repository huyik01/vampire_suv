#pragma once
#include"GameObject.h"
#include<string>
#include<SDL2/SDL_ttf.h>
class TextObject: public GameObject
{
public:
   enum TextColor
   {
       RED_TEXT=0,
       WHITE_TEXT=1,
BLACK_TEXT=2,
   };
    TextObject();
    ~TextObject();
    void SetText(const std::string& text)
    {
        str_val_=text;
    }
    void SetColor(const int&type);
    void CreateGameText(TTF_Font*font,SDL_Surface*des);
//    std::string str_val_;
//    SDL_Color text_color_;
private:
    std::string str_val_;
    SDL_Color text_color_;
};
