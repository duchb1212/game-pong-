#include "paddle.hpp"
#include "game.hpp"

constexpr int PADDLE_SPEED = 8;

Paddle::Paddle(int x_pos, int window_height) {
    x = x_pos;
    y = window_height / 2 - PADDLE_HEIGHT / 2;
    w = PADDLE_WIDTH;
    h = PADDLE_HEIGHT;
    score = 0;
}

void Paddle::update(int window_height, const Uint8* state, SDL_Scancode up_key, SDL_Scancode down_key) {
    if (state[up_key] && y > 0) {
        y -= PADDLE_SPEED;
    }
    if (state[down_key] && y < window_height - h) {
        y += PADDLE_SPEED;
    }
}

bool Paddle::collides(const SDL_Rect& ball_rect) const {
    SDL_Rect paddle_rect = {x, y, w, h};
    return SDL_HasIntersection(&ball_rect, &paddle_rect);
}