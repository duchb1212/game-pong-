#include "ball.hpp"
#include "game.hpp"
#include <random>

constexpr float BALL_SPEED = 4.0f;

Ball::Ball(int window_width, int window_height) {
    x = window_width / 2.0f;
    y = window_height / 2.0f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    dx = BALL_SPEED;
    dy = dis(gen) == 0 ? BALL_SPEED : -BALL_SPEED;
}

void Ball::update(int window_width, int window_height, int& paddle1_score, int& paddle2_score) {
    x += dx;
    y += dy;

    
    if (y <= 0 || y >= window_height - BALL_SIZE) {
        dy = -dy;
    }

    
    if (x < 0) {
        paddle2_score++;
        x = window_width / 2.0f;
        y = window_height / 2.0f;
        dx = BALL_SPEED;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        dy = dis(gen) == 0 ? BALL_SPEED : -BALL_SPEED;
    } else if (x > window_width) {
        paddle1_score++;
        x = window_width / 2.0f;
        y = window_height / 2.0f;
        dx = -BALL_SPEED;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        dy = dis(gen) == 0 ? BALL_SPEED : -BALL_SPEED;
    }
}