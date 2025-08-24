#ifndef TEXTURE_H
#define TEXTURE_H
class Texture
{
private:
    int ImageWidth, ImageHeight;
    SDL_Rect Rect;
    SDL_Texture *Image;
    //
    SDL_Renderer *Renderer;

public:
    Texture(SDL_Renderer *, char *);
    ~Texture();

    void Draw();

    void SetScale(float value);
    void ZoomTo(int w, int h);
    void XY(int x, int y);
};

#endif // TEXTURE_h
