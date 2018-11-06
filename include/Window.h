#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL2/SDL.h>

class Window
{
private:
    //Window data
    SDL_Window* m_window;

    //Window dimensions
    int m_width;
    int m_height;

    //Window focus
    bool m_mouseFocus;
    bool m_keyboardFocus;
    bool m_fullScreen;
    bool m_minimized;

 public:
    Window();
    ~Window();

    //Creates window
    bool Init();

    //Handles window events
    void HandleEvent(const SDL_Event&);

    // Getters -----------------------------
    SDL_Window*  GetWindow();
    SDL_Window*  GetWindow() const;

    //Window dimensions
    int GetWidth();
    int GetHeight();

    //Window focii
    bool HasMouseFocus();
    bool HasKeyboardFocus();
    bool IsMinimized();
};

#endif