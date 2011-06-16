#include "bowling_game.h"

enum { max_rolls = 21 };
static int rolls[max_rolls];
static int current_roll;

void bowling_game_init() {
    for (int i=0; i<max_rolls; i++)
        rolls[i] = 0;
    current_roll = 0;
}

void bowling_game_roll(int pins) {
    rolls[current_roll++] = pins;
}

int bowling_game_score() {
    int score = 0;
    for (int i=0; i<max_rolls; i++)
        score += rolls[i];
    return score;
}
