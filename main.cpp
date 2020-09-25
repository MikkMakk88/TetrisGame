#include "gameLoopFunctions.hpp"

// definitions
#define width 20
#define height 40


int main()
{
    eDirection dir;
    int score;
    Board board(width, height);
    Tetrominoe tetrominoe(width / 2, 0);

    std::vector< std::vector<int> > gameBoard;
    int blockCoordinates[4][2] = { 0 };

    board.getBoardState(gameBoard);
    // for(int i=0; i<height; i++)
    // {
    //     for(int j=0; j<width; j++)
    //     {
    //         int cell = gameBoard[i][j];
    //     }
    // }




    std::cout<<"hi";
   




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