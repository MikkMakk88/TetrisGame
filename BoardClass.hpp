#include <vector>
#include <iostream>

class Board
{
        int height, width;
        std::vector< std::vector<int> > boardState;

    public:
        Board(int widthIn, int heightIn);
        void setTetrominoe(int arr[][2]);
        bool checkCollision(int arr[][2]);
        void removeRows(int numRowsToDelete);
        void getBoardState(std::vector< std::vector<int> > &board);
        int getWidth();
        int getHeight();
        void printSelf();
};


// define Board class methods
Board::Board(int widthIn, int heightIn)
{
    width = widthIn;
    height = heightIn;
    
    

    for(int i=0; i<height; i++)
    {
        std::vector<int> row;
        for(int j=0; j<width; j++)
        {
            row.push_back(0);
        }
        boardState.push_back(row);
    }
}

void Board::removeRows(int numRowsToDelete)
{
    for(int i=0; i<numRowsToDelete; i++)
    {
        std::vector<int> newRow(width, 0);
        boardState.erase(boardState.begin() + height - 1);
        boardState.insert(boardState.begin(), newRow);
    }
}

void Board::setTetrominoe(int arr[][2])
{
    int x, y;
    for(int i=0; i<4; i++)
    {
        x = arr[i][0];
        y = arr[i][1];
        boardState[y][x] = 1;
    }
}

bool Board::checkCollision(int arr[][2])
{
    int x, y;
    for(int i=0; i<4; i++)
    {
        x = arr[i][0];
        y = arr[i][1];
        // check if tetrominoe is colliding with a block
        if(boardState[y][x] == 1)
        {
            return true;
        }
        // check if tetrominoe is colliding with sides of the board
        if(x < 0 || x > width - 1)
        {
            return true;
        }
        // check if tetrominoe is colliding with the bottom of the board
        if(y >= height - 1)
        {
            return true;
        }
    }
    return false;
}

void Board::getBoardState(std::vector< std::vector<int> > &board)
{
    for(int i=0; i<height; i++)
    {
        board[i] = boardState[i];
    }
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

void Board::printSelf()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(boardState[i][j] == 1)
            {
                std::cout<<"# ";
            }else{
                std::cout<<". ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}