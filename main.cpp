#include "gameLoopFunctions.hpp"

// definitions
#define width 12
#define height 20

int main()
{
    // declare variables
    eDirection dir;
    int downMoveCnt;
    bool gameOver = false;
    bool debug = true;
    int score = 0;
    int combo = 0;
    // initialize board and tetrominoe
    Board board(width, height);
    Tetrominoe tetrominoe(width / 2 - 2, 0);

    downMoveCnt = 0;
    setup(); 
    while(!gameOver)
    {
        draw(board, tetrominoe, score, debug);
        input(dir, gameOver);
        logic(board, tetrominoe, dir, gameOver, score, combo);
        // dictates game speed by forcing tetrominoe to move down
        if(downMoveCnt == 15)
        {
            dir = DOWN;
            logic(board, tetrominoe, dir, gameOver, score, combo);
            downMoveCnt = 0;
        }
        downMoveCnt++;
    }
    endwin();
    return 0;
}

