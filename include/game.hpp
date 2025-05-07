#ifndef GAME_HPP
#define GAME_HPP

#include "paddle.hpp"
#include "ball.hpp"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr int MAX_SCORE = 9;
constexpr int PADDLE_WIDTH = 10;
constexpr int PADDLE_HEIGHT = 80;
constexpr int BALL_SIZE = 20;

class Game {
public:
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;
    bool running;

    Game();
    void update();
};

#endif