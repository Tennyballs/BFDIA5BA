#ifndef TEXTURE_H
#define TEXTURE_H
class Texture
{
private:
    int w, h;
    SDL_Rect Rect;
    SDL_Texture *Image;

public:
    Texture(SDL_Renderer *Renderer, char *FilePath);
    ~Texture();

    void Draw(SDL_Renderer *renderer);

    void SetScale(float value);
    void ZoomTo(int w, int h);
    void XY(int x, int y);
};

#endif // TEXTURE_h
