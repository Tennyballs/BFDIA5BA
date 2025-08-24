#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"
#include <string>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    Window *MainWindow = new Window("BFDIA 5b is a game.", 640, 480);
    do
    {
        MainWindow->PollEvents();
        MainWindow->Clear();

    } while (MainWindow->GetEvents() != SDL_QUIT);

    SDL_Quit();
    return 0;
}