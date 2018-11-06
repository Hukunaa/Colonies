#include <Window.h>
#include <iostream>

Window::Window()
    : m_window{nullptr}, m_width{1280}, m_height{720}, m_mouseFocus{false},
      m_keyboardFocus{false}, m_fullScreen{false}, m_minimized{false}
{
    Init();
    std::cout << "Starting Window\n";
}

Window::~Window()
{
    SDL_DestroyWindow(m_window);
    std::cout << "Quitting Window\n";
}

bool Window::Init()
{
    //Create window
    m_window = SDL_CreateWindow("Colonies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window != nullptr)
    {
        m_mouseFocus = true;
        m_keyboardFocus = true;
    }

    return m_window != nullptr;
}

void Window::HandleEvent(const SDL_Event &event)
{
    //Window event occured
    if (event.type == SDL_WINDOWEVENT)
    {
        //Caption update flag
        bool updateCaption = false;

        switch (event.window.event)
        {
        //Get new dimensions and repaint on window size change
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            m_width = event.window.data1;
            m_height = event.window.data2;
            break;

        //Mouse entered window
        case SDL_WINDOWEVENT_ENTER:
            m_mouseFocus = true;
            updateCaption = true;
            break;

        //Mouse left window
        case SDL_WINDOWEVENT_LEAVE:
            m_mouseFocus = false;
            updateCaption = true;
            break;

        //Window has keyboard focus
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            m_keyboardFocus = true;
            updateCaption = true;
            break;

        //Window lost keyboard focus
        case SDL_WINDOWEVENT_FOCUS_LOST:
            m_keyboardFocus = false;
            updateCaption = true;
            break;

        //Window minimized
        case SDL_WINDOWEVENT_MINIMIZED:
            m_minimized = true;
            break;

        //Window maxized
        case SDL_WINDOWEVENT_MAXIMIZED:
            m_minimized = false;
            break;

        //Window restored
        case SDL_WINDOWEVENT_RESTORED:
            m_minimized = false;
            break;
        }

        (void)updateCaption;
        /*if (updateCaption)
        {
            std::cout << "Events - MouseFocus:" << ((m_mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((m_keyboardFocus) ? "On" : "Off") << '\n';
        }*/
    }
}

// Getters

SDL_Window*  Window::GetWindow()
{
    return m_window;
}

SDL_Window*  Window::GetWindow() const
{
    return m_window;
}

int Window::GetWidth()
{
    return m_width;
}

int Window::GetHeight()
{
    return m_height;
}

bool Window::HasMouseFocus()
{
    return m_mouseFocus;
}

bool Window::HasKeyboardFocus()
{
    return m_keyboardFocus;
}

bool Window::IsMinimized()
{
    return m_minimized;
}
