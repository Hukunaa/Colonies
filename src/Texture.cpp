#include <Texture.h>
#include <cassert>
#include <iostream>
#include <SDL2/SDL_image.h>

Texture::Texture(const Renderer& p_renderer, const std::string& p_source)
{
    std::cout << "Loading image : " << p_source << '\n';
    assert(p_renderer.GetRenderer() != nullptr);
    m_texture = IMG_LoadTexture(p_renderer.GetRenderer(), p_source.c_str());
    assert(m_texture != nullptr);
}

Texture::~Texture()
{
    if (m_texture != nullptr)
        SDL_DestroyTexture(m_texture);
}

Texture::Texture(const Texture& p_other)
{
    (void)p_other;
}

Texture& Texture::operator=(const Texture& p_other)
{
    (void)p_other;
    return *this;
}

void Texture::SetDimension(const int& p_width, const int& p_height)
{
    m_rect.w = p_width;
    m_rect.h = p_height;
}

void Texture::SetPosition(const int& p_x, const int& p_y)
{
    m_rect.x = p_x;
    m_rect.y = p_y;
}

SDL_Texture* Texture::GetTexture() const
{
    return m_texture;
}

SDL_Rect& Texture::GetRect()
{
    return m_rect;
}