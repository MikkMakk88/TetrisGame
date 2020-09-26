#include "gameLoopFunctions.hpp"

// definitions
#define width 15
#define height 20


int main()
{
    // declare variables
    eDirection dir;
    int score;
    // initialize board and tetrominoe
    Board board(width, height);
    Tetrominoe tetrominoe(width / 2 - 2, 0);
    // create variables to move around the state
    std::vector< std::vector<int> > gameBoard(height, std::vector<int>(width, 0));
    int blockCoordinates[4][2] = { 0 };

    // copy state of objects to variables
    board.getBoardState(gameBoard);
    tetrominoe.getBlockCoordinates(blockCoordinates);

    setup(); 
    draw(width, height, gameBoard, blockCoordinates);
    // while(true)
    // {
    //     draw()
    //     input();
    //     logic();
    //     logic
    // }
    // endwin();
    return 0;
}