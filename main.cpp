#include "gameLoopFunctions.hpp"

// definitions
#define width 15
#define height 20

int main()
{
    // declare variables
    eDirection dir;
    int score;
    bool gameOver = false;
    // initialize board and tetrominoe
    Board board(width, height);
    Tetrominoe tetrominoe(width / 2 - 2, 0);


    setup(); 
    while(!gameOver)
    {
        draw(board, tetrominoe);
        input(dir, gameOver);
        logic(board, tetrominoe, dir, gameOver);
    }
    endwin();
    return 0;
}

