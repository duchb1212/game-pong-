#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SDL2/SDL.h>

class Paddle {
public:
    int x, y;
    int w, h;
    int score;

    Paddle(int x_pos, int window_height);
    void update(int window_height, const Uint8* state, SDL_Scancode up_key, SDL_Scancode down_key);
    bool collides(const SDL_Rect& ball_rect) const;
};

#endif