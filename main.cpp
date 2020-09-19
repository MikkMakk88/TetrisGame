#include <iostream>
#include "main.hpp"

// declarations
bool gameOver;
int score, fps;


// definitions
#define width 20
#define height 40


int main()
{
    setup();
    draw();
    input();
    logic();

    endwin();
    return 0;
}