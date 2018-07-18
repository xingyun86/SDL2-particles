
#include "SDL2/SDL.h"
#include "ParticleExample.h"

int main(int, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    auto win = SDL_CreateWindow("SDL2 Particle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);
    auto ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    auto p = new ParticleExample();
    p->setRenderer(ren);
    p->setPosition(512, 0);
    p->setStyle(ParticleExample::SNOW);

    while (1)
    {
        SDL_PollEvent(NULL);
        SDL_RenderClear(ren);
        p->draw();
        SDL_RenderPresent(ren);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    delete p;

    return 0;
}

