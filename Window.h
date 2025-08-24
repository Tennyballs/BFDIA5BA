#ifndef WINDOW_H
#define WINDOW_H

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

    Window(char *window_title, int window_width, int window_height);
    ~Window();

    void Clear();

    void PollEvents();
    Uint32 GetEvents();
};

#endif // WINDOW_H