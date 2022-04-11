#include "app.h"

#include "input.h"

#include <Windows.h>
#include <iostream>
#include <glad/glad.h>

bool App::init()
{
    m_running = false;

#if _WIN32
    SetProcessDPIAware();
#endif

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) != 0)
    {
        std::cout << "failed to initialize sdl2" << std::endl;
        return false;
    }

    int flags =
        SDL_WINDOW_ALLOW_HIGHDPI |
            SDL_WINDOW_OPENGL;

    // set attribs
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    }

    m_window = SDL_CreateWindow("Raytracer", 0, 0, 1280, 720, flags);

    if (!m_window)
    {
        std::cout << "failed to create window" << std::endl;
        return false;
    }

    SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_GLContext context = SDL_GL_CreateContext(m_window);
    SDL_GL_MakeCurrent(m_window, context);

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "failed to initialize glad" << std::endl;
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    m_running = true;

    return true;
}

void App::destroy()
{
    SDL_GL_DeleteContext(m_context);

    if (m_window)
        SDL_DestroyWindow(m_window);

    SDL_Quit();
}

void App::present()
{
    SDL_GL_SwapWindow(m_window);
    SDL_ShowWindow(m_window);
}

void App::poll_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                App::inst()->exit();
                break;

            case SDL_MOUSEWHEEL:
                Input::inst()->on_mouse_wheel(e.wheel.x, e.wheel.y);
                break;

            case SDL_MOUSEMOTION:
                int spx, spy;
                SDL_GetGlobalMouseState(&spx, &spy);
                Input::inst()->on_mouse_screen_move(spx, spy);
                Input::inst()->on_mouse_move(e.motion.x, e.motion.y);
                break;

            case SDL_MOUSEBUTTONDOWN:
                Input::inst()->on_mouse_down(e.button.button);
                break;

            case SDL_MOUSEBUTTONUP:
                Input::inst()->on_mouse_up(e.button.button);
                break;

            case SDL_KEYDOWN:
                Input::inst()->on_key_down(e.key.keysym.scancode);
                break;

            case SDL_KEYUP:
                Input::inst()->on_key_up(e.key.keysym.scancode);
                break;

            case SDL_TEXTINPUT:
                Input::inst()->on_text_utf8(e.text.text);
                break;

            default:
                break;
        }
    }
}

int App::window_width()
{
    int w;
    SDL_GetWindowSize(m_window, &w, nullptr);
    return w;
}

int App::window_height()
{
    int h;
    SDL_GetWindowSize(m_window, nullptr, &h);
    return h;
}

int App::draw_width()
{
    int w = 0;
    SDL_GL_GetDrawableSize(m_window, &w, nullptr);
    return w;
}

int App::draw_height()
{
    int h = 0;
    SDL_GL_GetDrawableSize(m_window, nullptr, &h);
    return h;
}

SDL_Window* App::window()
{
    return m_window;
}

SDL_GLContext App::context()
{
    return m_context;
}

bool App::running()
{
    return m_running;
}

void App::exit()
{
    m_running = false;
}
