#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "IDFB.h"
#include "Window.h"
#include "Texture.h"
#include <string>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define SCREEN_CENTER_X WINDOW_WIDTH / 2
#define SCREEN_CENTER_Y SCREEN_CENTER_Y / 2

#define WINDOW_TITLE "BFDIA 5b is a game."

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    Window *MainWindow = new Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    Texture *myTexture = new Texture(MainWindow->renderer, "./Source/Images/bg/bg0000.png");

    myTexture->XY(0, 0);
    myTexture->ZoomTo(WINDOW_WIDTH, WINDOW_HEIGHT);

    do
    {
        MainWindow->PollEvents();
        MainWindow->Clear();
        MainWindow->RenderTexture(myTexture);
        MainWindow->Flush();
    } while (MainWindow->GetEvents() != SDL_QUIT);

    MainWindow->~Window();

    SDL_Quit();
    return 0;
}