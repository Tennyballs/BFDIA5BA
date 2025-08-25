#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
#include "Texture.h"
#include "TextureAtlas.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

std::vector<std::string> splitString(const std::string &input, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string segment;

    while (std::getline(ss, segment, delimiter))
    {
        result.push_back(segment);
    }
    return result;
}

TextureAtlas::TextureAtlas(SDL_Renderer *renderer, char *image_filename, char *atlas_filename)
{
    this->renderer = renderer;
    MyImage = IMG_LoadTexture(renderer, image_filename);
    SDL_QueryTexture(MyImage, NULL, NULL, &ImageWidth, &ImageHeight);
    FILE *FileData = fopen(atlas_filename, "rb");            // Open the file
    fseek(FileData, 0, SEEK_END);                            // Go to the end
    size_t FileSize = ftell(FileData);                       // Get the file size
    fseek(FileData, 0, SEEK_SET);                            // go to the start
    char *str = (char *)malloc(sizeof(char) * FileSize + 1); // +1 for the null terminator
    fread(str, 1, FileSize, FileData);                       // read all the file data
    str[FileSize] = '\0';                                    // Terminate the string
    fclose(FileData);                                        // close the file
    std::vector<int> IntArray = std::vector<int>();
    for (std::string a : splitString(str, ';'))
    {
        for (std::string b : splitString(a, ','))
            IntArray.push_back(atoi(b.c_str()));
    }
    for (size_t i = 0; i < IntArray.size(); i += 4)
    {
        SDL_Rect p;
        p.x = IntArray[i];
        p.y = IntArray[i + 1];
        p.w = IntArray[i + 2];
        p.h = IntArray[i + 3];
        owos.push_back(p);
    }
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

void TextureAtlas::SetIndex(size_t index)
{
    CropTranslate = owos[index];
}