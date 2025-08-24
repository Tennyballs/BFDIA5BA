#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
#include "Texture.h"
#include "TextureAtlas.h"
TextureAtlas::TextureAtlas(SDL_Renderer *renderer, char *image_filename, char *atlas_filename)
{
    MyImage = IMG_LoadTexture(renderer, image_filename);
    SDL_QueryTexture(MyImage, NULL, NULL, &ImageWidth, &ImageHeight);

    FILE *FileData;
    size_t FileSize;

    FileData = fopen(atlas_filename, "rb");

    fseek(FileData, 0, SEEK_END);
    FileSize = ftell(FileData);
    fseek(FileData, 0, SEEK_SET);

    char *str = (char *)malloc(sizeof(char) * FileSize + 1);
    bool isOpen = fread(str, 1, FileSize, FileData);
    if (!isOpen)
    {
        printf("We encountered an error in the TextureAtlas File. (ln:23)");
        return;
    }

    str[FileSize] = '\0';
    size_t amt = 0;
    char *strings = strtok(str, ";");
    while (strings != NULL)
    {
        strings = strtok(NULL, ";");
        amt++;
        printf("%ld\n", amt);
    }

    fclose(FileData);
}

TextureAtlas::~TextureAtlas()
{
    SDL_DestroyTexture(MyImage);
}

void TextureAtlas::Draw()
{
    SDL_RenderCopy(renderer, MyImage, &CropTranslate, &PosScale);
}

void TextureAtlas::SetScale(float f)
{
    PosScale.w *= f;
    PosScale.h *= f;
    PosScale.x += f / 2;
    PosScale.y += f / 2;
}

void TextureAtlas::ZoomTo(int w, int h)
{
    PosScale.w = w;
    PosScale.h = h;
}

void TextureAtlas::XY(int x, int y)
{
    PosScale.x = x;
    PosScale.y = y;
}

void TextureAtlas::Crop(int x, int y, int w, int h)
{
    CropTranslate =
        {
            .x = x,
            .y = y,
            .w = w,
            .h = h,
        };
}

void TextureAtlas::Translate(int x, int y, int w, int h)
{
    PosScale =
        {
            .x = x,
            .y = y,
            .w = w,
            .h = h,
        };
}