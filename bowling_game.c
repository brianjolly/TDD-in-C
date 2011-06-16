#include "bowling_game.h"
#include <stdbool.h>

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

static bool is_spare(int frame_index) {
    return rolls[frame_index] + rolls[frame_index+1] == 10;
}

int bowling_game_score() {
    int score = 0;
    int frame_index = 0;
    for (int frame=0; frame<10; ++frame) {
        if ( is_spare(frame_index) ) {
            score += 10 + rolls[frame_index+2];
            frame_index += 2;
        } else { 
            // normal
            score += rolls[frame_index] + rolls[frame_index+1];
            frame_index += 2;
        }
    }
    return score;
}
