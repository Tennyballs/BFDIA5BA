typedef struct
{
    int x, y, w, h;
} OwO;

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
    //
    OwO **owos;

public:
    TextureAtlas(SDL_Renderer *, char *, char *);
    ~TextureAtlas();

    void Draw();

    void SetScale(float value);
    void ZoomTo(int w, int h);
    void XY(int x, int y);

    void Translate(int x, int y, int w, int h);
    void Crop(int x, int y, int w, int h);
};