#ifndef BALL_HPP
#define BALL_HPP

class Ball {
public:
    float x, y;
    float dx, dy;

    Ball(int window_width, int window_height);
    void update(int window_width, int window_height, int& paddle1_score, int& paddle2_score);
};

#endif