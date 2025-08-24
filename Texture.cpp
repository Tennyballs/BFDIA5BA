#include <SDL_image.h>
#include "Texture.h"

Texture::Texture(SDL_Renderer *renderer, char *filePath)
{
    Renderer = renderer;

    Image = IMG_LoadTexture(Renderer, filePath);
    SDL_QueryTexture(Image, NULL, NULL, &ImageWidth, &ImageHeight);
    Rect.x = 0;
    Rect.y = 0;
    Rect.w = ImageWidth;
    Rect.h = ImageHeight;
}

void Texture::Draw()
{
    SDL_RenderCopy(Renderer, Image, NULL, &Rect);
}

Texture::~Texture()
{
    SDL_DestroyTexture(Image);
}

void Texture::SetScale(float f)
{
    Rect.w *= f;
    Rect.h *= f;
    Rect.x += f / 2;
    Rect.y += f / 2;
}

void Texture::ZoomTo(int w, int h)
{
    Rect.w = w;
    Rect.h = h;
}

void Texture::XY(int x, int y)
{
    Rect.x = x;
    Rect.y = y;
}
