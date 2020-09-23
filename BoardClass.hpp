class Board
{
        int height, width;
        static int * boardState;

    public:
        Board(int height, int width);
        void removeRows(int numRowsToDelete);
        void setBlock(int x, int y);
        int * getState();
};