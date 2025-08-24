#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "IDFB.h"
#include "Window.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SCREEN_CENTER_X 640 / 2
#define SCREEN_CENTER_Y 480 / 2

#define WINDOW_TITLE "BFDIA 5b is a game."

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    Window *MainWindow = new Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    int tw, th;
    SDL_Texture *image = IMG_LoadTexture(MainWindow->renderer, "Source/Images/Hello.png");
    SDL_QueryTexture(image, NULL, NULL, &tw, &th);

    SDL_Rect texr;
    texr.x = 0;
    texr.y = 0;
    texr.w = tw;
    texr.h = th;
    do
    {
        MainWindow->PollEvents();
        MainWindow->Clear();
        SDL_RenderCopy(MainWindow->renderer, image, NULL, &texr);
        SDL_RenderPresent(MainWindow->renderer);
    } while (MainWindow->GetEvents() != SDL_QUIT);

    SDL_DestroyTexture(image);

    MainWindow->~Window();

    SDL_Quit();
    return 0;
}