// gcc -std=c99 -Wall bowling_game_test.c && ./a.out

#include "bowling_game.h"
#include "bowling_game.c"

#include <assert.h>
#include <stdbool.h>

static void roll_many(int n, int pins) {
    for (int i=0; i<n; i++)
        bowling_game_roll(pins);
}

static void test_gutter_game() {
    bowling_game_init();
    roll_many(20,0);
    assert( bowling_game_score() == 0
            && "test_gutter_game()" );
}

static void test_all_ones() {
    bowling_game_init();
    roll_many(20,1);
    assert( bowling_game_score() == 20
            && "test_gutter_game()" );
}

int main() {
    test_gutter_game();
    test_all_ones();
}
