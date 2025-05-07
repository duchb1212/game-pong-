#include "render.hpp"
#include <stdexcept>

Renderer::Renderer(SDL_Window* window) {
    renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        throw std::runtime_error("Failed to create renderer");
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer_);
}

void Renderer::drawScore(int score, int x, int y) const {
    SDL_Rect digits[10][7] = {
        {{0, 0, 20, 5}, {20, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 25, 5, 20}, {0, 5, 5, 20}, {0, 0, 0, 0}},
        {{20, 5, 5, 40}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
        {{0, 0, 20, 5}, {20, 5, 5, 20}, {0, 45, 20, 5}, {0, 25, 5, 20}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 25, 20, 5}},
        {{0, 0, 20, 5}, {20, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 25, 20, 5}},
        {{0, 0, 5, 20}, {20, 5, 5, 20}, {20, 25, 5, 20}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 25, 25, 5}, {0, 25, 20, 5}},
        {{0, 0, 20, 5}, {0, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 25, 20, 5}},
        {{0, 0, 20, 5}, {0, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 25, 5, 20}, {0, 0, 0, 0}, {0, 25, 20, 5}},
        {{0, 0, 20, 5}, {20, 5, 5, 40}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
        {{0, 0, 20, 5}, {20, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 25, 5, 20}, {0, 5, 5, 20}, {0, 25, 20, 5}},
        {{0, 0, 20, 5}, {20, 5, 5, 20}, {20, 25, 5, 20}, {0, 45, 20, 5}, {0, 0, 0, 0}, {0, 5, 5, 20}, {0, 25, 20, 5}}
    };

    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    for (int i = 0; i < 7; ++i) {
        if (digits[score][i].w > 0) {
            SDL_Rect rect = {x + digits[score][i].x, y + digits[score][i].y, digits[score][i].w, digits[score][i].h};
            SDL_RenderFillRect(renderer_, &rect);
        }
    }
}

void Renderer::draw(const Game& game) {
   
    SDL_SetRenderDrawColor(renderer_, 10, 20, 40, 255); 
    SDL_RenderClear(renderer_);

    
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); 
    const int borderThickness = 2;
   
    SDL_Rect topBorder = {0, 0, WINDOW_WIDTH, borderThickness};
    SDL_RenderFillRect(renderer_, &topBorder);
   
    SDL_Rect bottomBorder = {0, WINDOW_HEIGHT - borderThickness, WINDOW_WIDTH, borderThickness};
    SDL_RenderFillRect(renderer_, &bottomBorder);
   
    SDL_Rect leftBorder = {0, 0, borderThickness, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer_, &leftBorder);
    
    SDL_Rect rightBorder = {WINDOW_WIDTH - borderThickness, 0, borderThickness, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer_, &rightBorder);

    
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); 
    for (int y = 0; y < WINDOW_HEIGHT; y += 20) {
        SDL_RenderDrawLine(renderer_, WINDOW_WIDTH / 2, y, WINDOW_WIDTH / 2, y + 10);
    }
   

   
    SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255); 
    SDL_Rect paddle1_rect = {game.paddle1.x, game.paddle1.y, game.paddle1.w, game.paddle1.h};
    SDL_RenderFillRect(renderer_, &paddle1_rect);

   
    SDL_SetRenderDrawColor(renderer_, 255, 255, 0, 255); 
    SDL_Rect paddle2_rect = {game.paddle2.x, game.paddle2.y, game.paddle2.w, game.paddle2.h};
    SDL_RenderFillRect(renderer_, &paddle2_rect);

   
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255); 
    int ballX = static_cast<int>(game.ball.x + BALL_SIZE / 2); 
    int ballY = static_cast<int>(game.ball.y + BALL_SIZE / 2); 
    int ballRadius = BALL_SIZE / 2; 
    for (int w = 0; w < BALL_SIZE; w++) {
        for (int h = 0; h < BALL_SIZE; h++) {
            int dx = w - ballRadius;
            int dy = h - ballRadius;
            if (dx * dx + dy * dy <= ballRadius * ballRadius) {
                SDL_RenderDrawPoint(renderer_, ballX + dx, ballY + dy);
            }
        }
    }

    
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    drawScore(game.paddle1.score, WINDOW_WIDTH / 4, 50);
    drawScore(game.paddle2.score, 3 * WINDOW_WIDTH / 4, 50);

    
    SDL_RenderPresent(renderer_);
}