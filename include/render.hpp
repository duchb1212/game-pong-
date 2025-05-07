#ifndef RENDER_HPP
#define RENDER_HPP

#include <SDL2/SDL.h>
#include "game.hpp"

class Renderer {
public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();
    void draw(const Game& game);

private:
    SDL_Renderer* renderer_;
    void drawScore(int score, int x, int y) const;
};

#endif