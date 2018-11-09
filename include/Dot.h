#ifndef __DOT__
#define __DOT__

#include <Texture.h>
#include <iostream>


class Dot
{
private:

public:

  SDL_Rect m_rect;

  //static int nb_cell;
  int life;
  int m_speed;
  bool is_alive;
  bool is_sick;

  Dot()
  {
    std::cout << "JE SUIS VIVANT MDR\n";
    m_rect = {640,340,4,4};
    is_alive = false;
    is_sick = false;
    life = 0;
    //nb_cell++;
  };

  ~Dot()
  {
    std::cout << "JE MEURS SALE FDP ! \n";
    //nb_cell--;
  };

};
#endif
