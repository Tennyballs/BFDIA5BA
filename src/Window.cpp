
#include <SDL.h>
#include <SDL_image.h>
#include "TextureAtlas.h"
#include "Texture.h"
#include "Window.h"

Window::Window(const char *WindowTitle, int WindowWidth, int WindowHeight)
{
    this->WindowWidth = WindowWidth;
    this->WindowHeight = WindowHeight;

    window = SDL_CreateWindow(WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->renderer);
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

void Window::Flush()
{
    SDL_RenderPresent(renderer);
}

void Window::Clear()
{
    SDL_RenderClear(renderer);
}

SDL_Event Window::GetEvents()
{
    return event;
}