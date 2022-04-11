#pragma once

#include <SDL.h>

class App
{
public:
    static App* inst()
    {
        static App* instance = nullptr;
        if (!instance) { instance = new App(); }
        return instance;
    }

    bool init();
    void destroy();
    void present();

    void poll_events();

    int window_width();
    int window_height();

    int draw_width();
    int draw_height();

    SDL_Window* window();
    SDL_GLContext context();

    void exit();
    bool running();

private:
    SDL_Window* m_window;
    bool m_running;
    SDL_GLContext m_context;
};
