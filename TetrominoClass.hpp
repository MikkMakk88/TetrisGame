#include <cstring>      // for memcpy
#include "tetrominoeShapes.hpp"
#include <iostream>


class Tetrominoe
{
        int x, y;
        int shape[4][4];
        int newShape[4][4];

    public:
        Tetrominoe(char shapeIn, int initialX);
        void rotate();
        void moveLeft();
        void moveRight();
        void moveDown();
        void getBlockCoordinates(int arr[][2]);
        void commitShape();
        void printSelf();
};

// definitions for Tetrominoe methods
Tetrominoe::Tetrominoe(char shapeIn, int initialX)
{
    // x & y represent the upper left corner of the shape.
    x = initialX;
    y = 0;

    int * selectedShape;
    switch(shapeIn)
    {
        case 'I':   selectedShape = &I[0][0];
            break;
        case 'O':   selectedShape = &O[0][0];
            break;
        case 'T':   selectedShape = &T[0][0];
            break;
        case 'J':   selectedShape = &J[0][0];
            break;
        case 'L':   selectedShape = &L[0][0];
            break;
        case 'S':   selectedShape = &S[0][0];
            break;
        case 'Z':   selectedShape = &Z[0][0];
            break;
    }
    std::memcpy(newShape, selectedShape, 16*sizeof(int));
}

void Tetrominoe::rotate()
{
    int tempShape[4][4] = {0};
    for(int row=0; row<4; row++)
    {
        for(int column=0; column<4; column++)
        {
            if(shape[row][column] == 1)
            {
                tempShape[column][3 - row] = 1;
            }
        }
    }
    std::memcpy(newShape, tempShape, 16*sizeof(int));
}

void Tetrominoe::moveLeft()
{
    x--;
}

void Tetrominoe::moveRight()
{
    x++;
}

void Tetrominoe::moveDown()
{
    y++;
}

// arr[4][2]
void Tetrominoe::getBlockCoordinates(int arr[][2])
{
    int offsetX, offsetY;
    int cnt = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(shape[i][j] == 1)
            {
                offsetX = j;
                offsetY = i;
                arr[cnt][0] = x + offsetX;
                arr[cnt][1] = y + offsetY;
                cnt++;
            }
        }
    }
}

void Tetrominoe::commitShape()
{
    std::memcpy(shape, newShape, 16*sizeof(int));
}

void Tetrominoe::printSelf()
{
    std::cout<<"x: "<<x<<", y: "<<y<<std::endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(shape[i][j] == 1)
            {
                std::cout<<"# ";
            }else
            {
                std::cout<<". ";
            }
        }
        std::cout<<std::endl;
    }
}