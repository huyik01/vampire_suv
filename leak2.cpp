
#ifndef SDL_NO1__H
#define SDL_NO1__H
#endif // SDL_NO1__H
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"SDL_no1.h"
using namespace std;
const int SCREEN_WIDTH=800;
const int SCREEN_HEIGHT=600;
const string SCREEN_TITLE="nitro";
struct Box
{
    int x;int y;
    int size=10;int stepX=0;int stepY=0;
    void move(){
    x+=stepX;
    y+=stepY;

    }
    void turnleft()
    {
        stepX=-5;
        stepY=0;

    }
    void turnright()
    {
        stepX=5;
        stepY=0;
    }
    void turndown()
    {
        stepY=5;
        stepX=0;
    }
    void turnup()
    {
        stepY=-5;
        stepX=0;
    }
    void render(SDL_Renderer*renderer)
    {
    SDL_Rect filled_rect;
    filled_rect.x=x;
    filled_rect.y=y;
    filled_rect.w=size;
    filled_rect.h=size;
    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_RenderFillRect(renderer,&filled_rect);

    }
    bool inside(int minX,int minY,int maxX,int maxY)
    {
        return(minX<=x&&minY<=y&&x+size<=maxX&&y+size<=maxY);
    }
};
int main(int argv,char*argc[])
{
    SDL_Window*window;
    SDL_Renderer*renderer;
    initSDL(window,renderer);
    SDL_Texture*background=loadTexture("Nitro_Wallpaper_01_3840x2400.jpg",renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //Vẽ hcn màu
Box box;
box.x=10;
box.y=10;
 SDL_Event e;
//while cho đk dừng khi chạm tới cạnh mh
while(box.inside(0,0,SCREEN_WIDTH,SCREEN_HEIGHT)){
box.move();
SDL_SetRenderDrawColor(renderer,255,255,255,255);
SDL_RenderClear(renderer);
box.render(renderer);
       SDL_RenderPresent(renderer);




        // Đợi 10 mili giây
        SDL_Delay(40);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
        if ( SDL_PollEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu có một phím được nhấn, thì xét phyím đó là gì để xử lý tiếp
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break; // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        		// Nếu phím mũi tên trái, dịch sang trái
    	        // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
        		case SDLK_LEFT: box.turnleft();
        			break;
        		// Tương tự với dịch phải, xuống và lên
            	case SDLK_RIGHT: box.turnright();
            		break;
            	case SDLK_DOWN: box.turndown();
					break;
            	case SDLK_UP:box.turnup();
            		break;
        		default: break;
			}}


}

    quitSDL(window,renderer);
    return 0;
}

