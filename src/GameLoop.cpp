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

  for(int i = 0; i < 10000; ++i)
  {
    Dot* dot_node = new Dot;
    //dot_node.m_rect.x = m_window.GetWidth() / 2;
    //dot_node.m_rect.y = m_window.GetHeight() / 2;

    if(rand() % 100 < 10)
    {
      dot_node->is_sick = true;
    }

    Dots_array.push_back(dot_node);
  }
  for(int j = 0 ; j < dots_nb; ++j)
  {
    Dots_array[j]->is_alive = true;

  }
}

void GameLoop::CreateDot(Dot* parent)
{
  Dot* dot_node;
  dot_node = nullptr;
  int d;
  while(Dots_array[d]->is_alive == true)
  {
  	++d;
  }
  if(Dots_array[d]->is_alive == false)
  {
    dot_node = Dots_array[d];
    return;
  }

  if(dot_node != nullptr)
  {
    dot_node->is_alive = true;

    dot_node->m_rect.x = parent->m_rect.x + ((rand() % 3) - 1) * 4;
    dot_node->m_rect.y = parent->m_rect.y + ((rand() % 3) - 1) * 4;

    for(unsigned int n = 0;  Dots_array[n]->is_alive == true; ++n)
    {
      if(Dots_array[n]->is_alive == true && dot_node->m_rect.x == Dots_array[n]->m_rect.x
        && dot_node->m_rect.y == Dots_array[n]->m_rect.y)
        {
          return;
        }
      }
      if(parent->is_sick == true)
      {
        if(rand() % 10 < 5)
        {
          dot_node->is_sick = true;
        }
      }
  }

}

void GameLoop::UpdateDot()
{
	if(last_frame <= current_time)
	{
	  for(unsigned int n = 0; Dots_array[n]->is_alive == true; ++n)
	  {
  		//if(Dots_array[n].is_alive == true)
  		//{
  		  ++Dots_array[n]->life;

  		  if(Dots_array[n]->life > 25 || Dots_array[n]->is_sick == true)
  		  	Dots_array[n]->is_alive = false;

  		  if(rand() % 100 < 20 && Dots_array[n]->life > 20)
  		  {
  		    CreateDot(Dots_array[n]);
  		  }
  		  std::cout << " Debugging " << n << '\n';
  		//}q
	  }
	  last_frame = current_time + 100;
	}
  std::partition(Dots_array.begin(), Dots_array.end(), [](Dot* d) {return d->is_alive;});

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
			//if(Dots_array[j].is_alive == true)
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
