
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"

Window::Window(char *WindowTitle, int WindowWidth, int WindowHeight)
{
    this->WindowWidth = WindowWidth;
    this->WindowHeight = WindowHeight;

    window = SDL_CreateWindow("BFDIA5B", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 1);
    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderPresent(this->renderer);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
}

void Window::PollEvents()
{
    SDL_PollEvent(&event);
}

void Window::Clear()
{
    SDL_RenderClear(renderer);
}

Uint32 Window::GetEvents()
{
    return event.type;
}