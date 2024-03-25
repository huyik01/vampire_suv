#include"TextureManage.h"
#include<SDL2/SDL_image.h>
SDL_Texture*TextureManage::LoadTexture(const char*texture)
{
     SDL_Surface*tempSurface=IMG_Load(texture);
    SDL_Texture*tex=SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}
void TextureManage::Draw(SDL_Texture*tex,SDL_Rect src,SDL_Rect dest,SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer,tex,&src,&dest,NULL,NULL,flip);
}
