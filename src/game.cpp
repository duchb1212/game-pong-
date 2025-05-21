#include "game.hpp"
#include "ball.hpp"
#include <SDL2/SDL.h>

Game::Game() : paddle1(20, WINDOW_HEIGHT), paddle2(WINDOW_WIDTH - 20 - PADDLE_WIDTH, WINDOW_HEIGHT), ball(WINDOW_WIDTH, WINDOW_HEIGHT) {
    running = true;
}

void Game::update() {
    
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    
    paddle1.update(WINDOW_HEIGHT, state, SDL_SCANCODE_W, SDL_SCANCODE_S);
    paddle2.update(WINDOW_HEIGHT, state, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

    
    ball.update(WINDOW_WIDTH, WINDOW_HEIGHT, paddle1.score, paddle2.score);

    
    SDL_Rect ball_rect = {static_cast<int>(ball.x), static_cast<int>(ball.y), BALL_SIZE, BALL_SIZE};
    if (paddle1.collides(ball_rect) || paddle2.collides(ball_rect)) {
        ball.dx = -ball.dx;
    }

    
    if (paddle1.score >= MAX_SCORE || paddle2.score >= MAX_SCORE) {
        running = false;
    }
}

void Game::reset() {
    paddle1 = Paddle(20, WINDOW_HEIGHT);
    paddle2 = Paddle(WINDOW_WIDTH - 20 - PADDLE_WIDTH, WINDOW_HEIGHT);
    ball = Ball(WINDOW_WIDTH, WINDOW_HEIGHT);
    running = true;
}