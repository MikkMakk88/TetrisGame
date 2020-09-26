#include "gameLoopFunctions.hpp"

// definitions
#define width 10
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
    // copy state of board to gameboard variable
    // board.printSelf();
    // std::cout<<std::endl;

    tetrominoe.printSelf();
    tetrominoe.rotate();
    tetrominoe.commitShape();
    tetrominoe.printSelf();
    tetrominoe.newTetrominoe();
    tetrominoe.printSelf();
    tetrominoe.rotate();
    tetrominoe.commitShape();
    tetrominoe.printSelf();
    // std::cout<<std::endl;

    // tetrominoe.getBlockCoordinates(blockCoordinates);
    // board.setTetrominoe(blockCoordinates);
    // board.printSelf();

   

    // setup(); 
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