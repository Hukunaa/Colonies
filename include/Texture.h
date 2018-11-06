#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#include <SDL2/SDL.h>
#include <Renderer.h>

// Forward declaration preventing Recursive Inclusion
class Renderer;

class Texture
{
private:
    SDL_Texture* m_texture {nullptr};
    SDL_Rect m_rect {};

public:
    Texture(const Renderer&, const std::string&);
    Texture(const Texture&);
    ~Texture();

    Texture& operator=(const Texture&);

    void SetDimension(const int& p_width, const int& p_height);
    void SetPosition(const int& p_x, const int& p_y);

    SDL_Texture* GetTexture() const;
    SDL_Rect& GetRect();

    void Set(int w, int h, int x, int y)
    {
        m_rect.x = x;
        m_rect.y = y;
        m_rect.w = w;
        m_rect.h = h;
    }
};

#endif
