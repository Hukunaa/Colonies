#include <GameLoop.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(nullptr));
    GameLoop gl{};
    return gl.Loop();
}
