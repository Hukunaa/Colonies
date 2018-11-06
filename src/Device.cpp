#include <Device.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Device::Device()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
        m_state = DeviceState::ERROR;
    }
    else
    {
        m_state = DeviceState::RUNNING;
        std::cout << "Starting Device\n";
    }

    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        std::cout << "SDL Image could not initialize! SDL_Error: " << SDL_GetError() << '\n';
        m_state = DeviceState::ERROR;
        SDL_Quit();
    }


}

Device::~Device()
{
    if (m_state == DeviceState::QUITTING)
    {
        IMG_Quit();
        SDL_Quit();
    }

    std::cout << "Quitting Device\n";
}

const DeviceState& Device::GetState() const
{
    return m_state;
}

void Device::SetState(const DeviceState& newState)
{
    m_state = newState;
}