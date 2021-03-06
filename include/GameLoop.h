#ifndef __GAMELOOP_H__
#define __GAMELOOP_H__

#include <Device.h>
#include <Window.h>
#include <Renderer.h>
#include <vector>
#include <Dot.h>

enum class GameState : char
{
    START,
    RUNNING,
    PAUSE,
    GAMEOVER,
    QUITTING
};

class GameLoop
{
public:
    GameLoop();
    ~GameLoop();

    Device m_device{};
    Window m_window{};
    Renderer m_renderer{m_window};
    GameState m_state;
    std::vector<Dot*> Dots_array;

    unsigned int current_time;
    unsigned int last_frame;

    int Loop();
    void SetupDots();
    void CreateDot(int it);
    void UpdateDot();
    void HandleEvents();
};

#endif
