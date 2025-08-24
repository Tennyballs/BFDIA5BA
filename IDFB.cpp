#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"
#include <string>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    Window *MainWindow = new Window(":3", 640, 480);
    int x = 0, y = 0;

    do
    {
        MainWindow->PollEvents();
        MainWindow->Clear();

    } while (MainWindow->GetEvents() != SDL_QUIT);

    SDL_Quit();
    return 0;
}