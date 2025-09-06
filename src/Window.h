#ifndef WINDOW_H
#define WINDOW_H

class TextureAtlas;

class Texture;
class Window
{
private:
    SDL_Window *window;
    SDL_Event event;

    char *WindowTitle;
    long WindowWidth;
    long WindowHeight;

public:
    SDL_Renderer *renderer;

    Window(const char *window_title, int window_width, int window_height);
    ~Window();

    void Clear();

    void PollEvents();
    SDL_Event GetEvents();

    void Flush();
};

#endif // WINDOW_H