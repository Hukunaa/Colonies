#ifndef __DOT__
#define __DOT__

#include <Texture.h>

class Dot
{
private:

public:

  SDL_Rect m_rect;

  int life;
  int m_speed;
  bool is_alive;
  bool is_sick;

  Dot()
  {
    m_rect = {1,1,4,4};
    is_alive = false;
    is_sick = false;
    life = 0;
  };

  ~Dot() {};

};


#endif
