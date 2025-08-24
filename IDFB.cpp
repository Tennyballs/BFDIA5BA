#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"
#include <string>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SCREEN_CENTER_X 640 / 2
#define SCREEN_CENTER_Y 480 / 2

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    Window *MainWindow = new Window("BFDIA 5b is a game.", WINDOW_WIDTH, WINDOW_HEIGHT);
    do
    {
        MainWindow->PollEvents();
        MainWindow->Clear();
    } while (MainWindow->GetEvents() != SDL_QUIT);

    SDL_Quit();
    return 0;
}