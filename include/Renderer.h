#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL2/SDL.h>
#include <Window.h>
#include <Texture.h>

// Forward declaration preventing Recursive Inclusion
class Texture;

class Renderer
{
private:
    SDL_Renderer* m_renderer;

public:
    Renderer(const Window &p_window);
    ~Renderer();

    void Clear();
    void RenderCopy(Texture&);
    void Present();

    SDL_Renderer* GetRenderer() const;
};

#endif