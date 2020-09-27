#include "gameLoopFunctions.hpp"

// definitions
#define width 15
#define height 20

int main()
{
    // declare variables
    eDirection dir;
    int score, downMoveCnt;
    bool gameOver = false;
    bool debug = true;
    // initialize board and tetrominoe
    Board board(width, height);
    Tetrominoe tetrominoe(width / 2 - 2, 0);

    downMoveCnt = 0;
    setup(); 
    while(!gameOver)
    {
        draw(board, tetrominoe, debug);
        input(dir, gameOver);
        logic(board, tetrominoe, dir, gameOver);
        // dictates game speed by forcing tetrominoe to move down
        if(downMoveCnt == 15)
        {
            dir = DOWN;
            logic(board, tetrominoe, dir, gameOver);
            downMoveCnt = 0;
        }
        downMoveCnt++;
    }
    endwin();
    return 0;
}

