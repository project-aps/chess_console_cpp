#ifndef ROOK_H
#define ROOK_H

#include "board.h"
#include <iostream>

class Rook : public Piece
{

public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // constructor
    Rook(){};

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // check is the move valid for this piece Rook

    // it checks that final position Rook is in horizontal or vertical position oder of start position or not
    bool rook_direct(int start_x, int start_y, int final_x, int final_y)
    {
        int x = abs(diff_x(start_x, final_x));
        int y = abs(diff_y(start_y, final_y));

        if (start_x == final_x && start_y == final_y)
        {
            return false;
        }

        
        if (x * y == 0)
        {

            return true;
        }
        else
        {

            return false;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // it checks from start to end postion there is no pieces or not
    // return true if no pieces found in diagonal
    // return false if pieces are found in diagonal

    bool rook_all_clear_before(int start_x, int start_y, int final_x, int final_y, Board board)
    {
        int x = (diff_x(start_x, final_x));
        int y = (diff_y(start_y, final_y));




        /////////////////////////////////////////////
        if (x >= 0 && y == 0)
        {
            for (int i = start_x + 1; i < final_x; i++)
            {

                if (board.get_cell_pointer(i, start_y)->get_piece() != EMPTY)
                {

                    return false;
                }
            }
        }
        /////////////////////////////////////////////
        if (x <= 0 && y == 0)
        {
            for (int i = start_x - 1; i > final_x; i--)
            {

                if (board.get_cell_pointer(i, start_y)->get_piece() != EMPTY)
                {

                    return false;
                }
            }
        }
        /////////////////////////////////////////////
        if (x == 0 && y >= 0)
        {
            for (int j = start_y + 1; j < final_y; j++)
            {

                if (board.get_cell_pointer(start_x, j)->get_piece() != EMPTY)
                {

                    // cout<<j<<endl;
                    return false;
                }
            }
        }
        /////////////////////////////////////////////
        if (x == 0 && y <= 0)
        {
            for (int j = start_y - 1; j > final_y; j--)
            {

                if (board.get_cell_pointer(start_x, j)->get_piece() != EMPTY)
                {

                    return false;
                }
            }
        }
        // returns true if no piece is found horizontally or diagonally
        return true;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // finally makes the decision from above both functions using and operator if all condition is matched
    bool valid_move(int start_x, int start_y, int final_x, int final_y, Board board)
    {
        
        
        Cell* src=board.get_cell_pointer(start_x,start_y);
        Cell* dest=board.get_cell_pointer(final_x,final_y);
        
        if ((dest->get_color() == src->get_color()) && (dest->get_color() != NONE))
        {
            //cout << "Cannot move to own piece. Try again\n";
            return false;
        }

        return (rook_direct(start_x, start_y, final_x, final_y) && rook_all_clear_before(start_x, start_y, final_x, final_y, board));
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};

#endif