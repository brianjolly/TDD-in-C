#include "bowling_game.h"

static int score;

void bowling_game_init() {
}

void bowling_game_roll(int pins) {
    score += pins;
}

int bowling_game_score() {
    return score;
}
