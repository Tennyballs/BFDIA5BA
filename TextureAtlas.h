#ifndef TEXTUREATLAS_H
#define TEXTUREATLAS_H

#include <vector>

class TextureAtlas
{
private:
    int index;
    int ImageWidth, ImageHeight;
    //
    SDL_Rect CropTranslate;
    SDL_Rect PosScale;
    //
    SDL_Renderer *renderer;
    SDL_Texture *MyImage;
    // the owos (positions)
    std::vector<SDL_Rect> owos = std::vector<SDL_Rect>(); // Stop with the furry shit

public:
    TextureAtlas(SDL_Renderer *, char *, char *);
    ~TextureAtlas();

    void Draw();

    void SetScale(float);
    void ZoomTo(int, int);
    void XY(int, int);

    void Translate(int, int, int, int);
    void Crop(int, int, int, int);

    void SetIndex(size_t);
};

#endif // TEXTUREATLAS_H