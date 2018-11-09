#include <GameLoop.h>
#include <iostream>
#include <algorithm>
#include <Dot.h>


GameLoop::GameLoop() : m_state{GameState::START}
{
    if (m_device.GetState() != DeviceState::ERROR)
        std::cout << "Starting Game Loop\n";
    else
        std::cout << "ERROR: Game Loop\n";
}

GameLoop::~GameLoop()
{
    std::cout << "Quitting Game Loop\n";
}

void GameLoop::SetupDots()
{
  int dots_nb = 0;
  std::cout << "Enter the number of Blue Dots" << '\n';
  std::cin >> dots_nb;
  std::cout << "You've choosen " << dots_nb << " Dots" << '\n';

  for(int i = 0; i < 100000; ++i)
  {
    Dot* dot_node = new Dot;

    if(rand() % 100 < 10)
    {
      dot_node->is_sick = true;
    }

    Dots_array.push_back(dot_node);
  }
  for(int j = 0 ; j < dots_nb; ++j)
  {
    //Dots_array[j]->m_rect.x = m_window.GetWidth() / 2;
    //Dots_array[j]->m_rect.y = m_window.GetHeight() / 2;
    Dots_array[j]->is_alive = true;

  }
}

void GameLoop::CreateDot(int it)
{
  int d = 0;

  while(Dots_array[d]->is_alive == true)
  {
  	++d;
  }
  if(Dots_array[d]->is_alive == false)
  {
    std::cout << "Found node !\n";
    Dots_array[d]->is_alive = true;
    std::cout << "Parent pos: " << Dots_array[it]->m_rect.x << " | " << Dots_array[it]->m_rect.y << "\n\n";
    Dots_array[d]->m_rect.x = Dots_array[it]->m_rect.x  + ((rand() % 4) - 1) * 4;
    Dots_array[d]->m_rect.y = Dots_array[it]->m_rect.y  + ((rand() % 4) - 1) * 4;

    for(unsigned int n = 0;  Dots_array[n]->is_alive == true; ++n)
    {
      if(Dots_array[n]->is_alive == true && Dots_array[d]->m_rect.x == Dots_array[n]->m_rect.x
                                         && Dots_array[d]->m_rect.y == Dots_array[n]->m_rect.y)
      {
        std::cout << "Can't Create the Node !\n";
        return;
      }
    }
    if(Dots_array[it]->is_sick == true)
    {
      if(rand() % 10 < 5)
      {
        Dots_array[d]->is_sick = true;
      }
    }
  }
}

void GameLoop::UpdateDot()
{
	  for(unsigned int n = 0; Dots_array[n]->is_alive == true; ++n)
	  {
  		  ++Dots_array[n]->life;
        if(last_frame <= current_time)
        {
          std::partition(Dots_array.begin(), Dots_array.end(), [](Dot* h) {return h->is_alive;});
          if(rand() % 100 < 60)
          {
              CreateDot(n);
          }

          if(Dots_array[n]->life > 20 && rand() % 100 < 20)
          {
            std::cout << " Dot will die : " << n << '\n';
            Dots_array[n]->is_alive = false;
          }
          last_frame = current_time + 50;
        }
	  }
}

int GameLoop::Loop()
{
	if (m_device.GetState() == DeviceState::ERROR)
	  return EXIT_FAILURE;


	Texture t_blueDot{m_renderer, "./media/dot_blue.png"};
	t_blueDot.Set(1, 1, m_window.GetWidth() / 2 - 45,
		              m_window.GetHeight() / 2 - 35);

	SetupDots();
	last_frame = SDL_GetTicks();

	while (m_state != GameState::QUITTING)
	{
		current_time = SDL_GetTicks();
    	//std::cout << "Time : " << current_time << '\n';
		m_renderer.Clear();
		HandleEvents();
		UpdateDot();

		for(unsigned int j = 0; Dots_array[j]->is_alive == true; ++j)
		{
			//if(Dots_array[j]->is_alive == true)
				SDL_RenderCopy(m_renderer.GetRenderer(),t_blueDot.GetTexture(), nullptr, &Dots_array[j]->m_rect);
		}

		m_renderer.Present();
	}

	m_device.SetState(DeviceState::QUITTING);
	return EXIT_SUCCESS;
}

void GameLoop::HandleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0)
    {
        m_window.HandleEvent(event);

        if (event.type == SDL_QUIT)
            m_state = GameState::QUITTING;
    }
}
