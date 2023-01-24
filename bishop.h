#ifndef BISHOP_H
#define BISHOP_H

// #include "piece.h"
#include <iostream>
#include "board.h"

class Bishop : public Piece
{

public:
//////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    Bishop(){};

/////////////////////////////////////////////////////////////////////////////////////////////////////
    //  makes the decision from below both functions using and operator if all condition is matched
    bool valid_move(int start_x, int start_y, int final_x, int final_y, Board board)
    {
        Cell* src=board.get_cell_pointer(start_x,start_y);
        Cell* dest=board.get_cell_pointer(final_x,final_y);
        
        if ((dest->get_color() == src->get_color()) && (dest->get_color() != NONE))
        {
            //cout << "Cannot move to own piece. Try again\n";
            return false;
        }

        return (bishop_direct(start_x, start_y, final_x, final_y) && bishop_all_clear_before(start_x, start_y, final_x, final_y, board));
    }


//////////////////////////////////////////////////////////////////////////////////////////

    // check is the move valid for this piece Knight

    // it checks that final position Bishop is in diagonal oder of start position or not
    bool bishop_direct(int start_x, int start_y, int final_x, int final_y)
    {
        int x = abs(diff_x(start_x, final_x));
        int y = abs(diff_y(start_y, final_y));

        if (start_x == final_x && start_y == final_y)
        {
            return false;
        }

        if (x == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
///////////////////////////////////////////////////////////////////////////////////////
    // it checks from start to end postion there is no pieces or not
    // return true if no pieces found in diagonal
    // return false if pieces are found in diagonal

    bool bishop_all_clear_before(int start_x, int start_y, int final_x, int final_y, Board board)
    {

        int x = (diff_x(start_x, final_x));
        int y = (diff_y(start_y, final_y));

        /////////////////////////////////////////////
        if (x >= 0 && y >= 0)
        {
            for (int i = start_x; i < final_x; i++)
            {
                for (int j = start_y; j < final_y; j++)
                {

                    if (bishop_direct(start_x, start_y, i, j))
                    {
                        if (board.get_cell_pointer(i, j)->get_piece() != EMPTY)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        /////////////////////////////////////////////
        if (x >= 0 && y <= 0)
        {
            for (int i = start_x; i < final_x; i++)
            {
                for (int j = start_y; j > final_y; j--)
                {
                    if (bishop_direct(start_x, start_y, i, j))
                    {
                        if (board.get_cell_pointer(i, j)->get_piece() != EMPTY)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        /////////////////////////////////////////////
        if (x <= 0 && y >= 0)
        {
            for (int i = start_x; i > final_x; i--)
            {
                for (int j = start_y; j < final_y; j++)
                {
                    if (bishop_direct(start_x, start_y, i, j))
                    {
                        if (board.get_cell_pointer(i, j)->get_piece() != EMPTY)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        /////////////////////////////////////////////
        if (x <= 0 && y <= 0)
        {
            for (int i = start_x; i > final_x; i--)

            {
                for (int j = start_y; j > final_y; j--)
                {
                    if (bishop_direct(start_x, start_y, i, j))
                    {
                        if (board.get_cell_pointer(i, j)->get_piece() != EMPTY)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        /////////////////////////////////////////////
        // returns true if no piece is found diagonally
        return true;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
};

#endif