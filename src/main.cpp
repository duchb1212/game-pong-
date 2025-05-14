#include <SDL2/SDL.h>
#include "game.hpp"
#include "render.hpp"
#include <stdexcept>

int main(int argc, char* argv[]) {
   
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    
    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    
    Renderer renderer(window);

    
    Game game;

    
    Uint32 frameStart;
    const Uint32 frameDelay = 1000 / 120;
    bool paused = false; 
    while (game.running) {
        frameStart = SDL_GetTicks();

        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game.running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                paused = !paused; 
            }
        }

        
        if (!paused) { 
            game.update();
        }

        
        renderer.draw(game);

        
        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    
    SDL_Quit();
    return 0;
}