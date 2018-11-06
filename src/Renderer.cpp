#include <Renderer.h>
#include <cassert>
#include <Window.h>
#include <SDL2/SDL.h>

Renderer::Renderer(const Window &p_window) : m_renderer {nullptr}
{
    assert(p_window.GetWindow() != nullptr);
    m_renderer = SDL_CreateRenderer(p_window.GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
}

void Renderer::Clear()
{
    if (m_renderer != nullptr)
    {
        SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);
        SDL_RenderClear(m_renderer);
    }
}

void Renderer::RenderCopy(Texture& p_texture)
{
    SDL_RenderCopy(m_renderer, p_texture.GetTexture(), nullptr, &p_texture.GetRect());
}

void Renderer::Present()
{
    SDL_RenderPresent(m_renderer);
}

SDL_Renderer* Renderer::GetRenderer() const
{
    return m_renderer;
}
