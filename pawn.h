#ifndef PAWN_H
#define PAWN_H

#include "board.h"
#include <iostream>

class Pawn : public Piece
{
    bool this_pawn_moved_double;
public:
    /////////////////////////////////////////////////////////////////////////////////////////
    // constructor
    Pawn(){
        this->this_pawn_moved_double=false;
    };

    //////////////////////////////////////////////////////////////////////////////////////////

    // check is the move valid for this piece Pawn

    bool valid_move(int start_x, int start_y, int final_x, int final_y, Board board)
    {
        int x = (diff_x(start_x, final_x));
        int y = (diff_y(start_y, final_y));

        // for white pawn y value increases i.e. 1(all condition) or 2(if at level 2)
        // for black pawn y value increases i.e. -1(all condition) or -2(if at level 7)

        if (start_x == final_x && start_y == final_y)
        {
            return false;
        }

        Cell* src=board.get_cell_pointer(start_x,start_y);
        Cell* dest=board.get_cell_pointer(final_x,final_y);
        
        if ((dest->get_color() == src->get_color()) && (dest->get_color() != NONE))
        {
            //cout << "Cannot move to own piece. Try again\n";
            return false;
        }


        // for white pawn y should be +ve
        Color pawn_color = board.get_cell_pointer(start_x, start_y)->get_color();

        int pawn_location_x = start_x;
        int pawn_location_y = start_y;

        ///////////////////////////////////////////////////////////////////////
        // if pawn color is white
        if (pawn_color == WHITE)
        {

            // pawn at initial level or double movement possible
            if ((pawn_location_y == white_pawn_start_y) && ((y == 2) && (x == 0)))
            {

                // pawn ko agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_one_step_front_of_white_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y + 1)->get_piece();

                // pawn ko 2 step agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_two_step_front_of_white_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y + 2)->get_piece();

                if ((piece_two_step_front_of_white_pawn == EMPTY) && (piece_one_step_front_of_white_pawn == EMPTY))
                {
                    this->this_pawn_moved_double=true;
                    return true;
                }
                else
                {
                }
            }

            // white pawn at all condition
            if ((y == 1) && (x == 0))
            {
                // pawn ko agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_one_step_front_of_white_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y + 1)->get_piece();

                if (piece_one_step_front_of_white_pawn == EMPTY)
                {

                    return true;
                }
                else
                {
                }
            }

            // criss cross movement if own color piece is not there in opponent section
            // white  pawn's opponents section

            // opponent 1 left and 1 step front of its own pawn
            if (x == -1 && y == 1)
            {

                // opponent1 of pawn i.e. at one step up and -1 of x
                int white_pawn_opp1_x = pawn_location_x - 1;
                int white_pawn_opp1_y = pawn_location_y + 1;

                Color color_white_pawn_opp1 = board.get_cell_pointer(white_pawn_opp1_x, white_pawn_opp1_y)->get_color();

                if ((color_white_pawn_opp1 == BLACK)) // && (end_x == white_pawn_opp1_x)  && (end_y ==white_pawn_opp1_y))
                {
                    return true;
                }
                else
                {

                    // cout<<"opp1\n";
                    // cout<<white_pawn_opp1_x<<white_pawn_opp1_y<<endl;
                    // cout<<"opp2\n";
                    // cout<<white_pawn_opp2_x<<white_pawn_opp2_y<<endl;
                }
            }

            // opponent 2 right and 1 step front of its own pawn
            if (x == 1 && y == 1)
            {
                // opponent2 of pawn i.e. at one step up and +1 of x
                int white_pawn_opp2_x = pawn_location_x + 1;
                int white_pawn_opp2_y = pawn_location_y + 1;

                Color color_white_pawn_opp2 = board.get_cell_pointer(white_pawn_opp2_x, white_pawn_opp2_y)->get_color();

                if ((color_white_pawn_opp2 == BLACK)) // && (end_x == white_pawn_opp2_x ) && (end_y ==white_pawn_opp2_y))
                {
                    return true;
                }
                else
                {
                }
            }

            // if nothing condiiton is matched then it cant move to that position
            //cout << "due to white\n";
            return false;
        }

        ///////////////////////////////////////////////////////////////////////

        // for black pawn y should be -ve
        else if (pawn_color == BLACK)
        {

            // pawn at initial level or double movement possible
            if ((pawn_location_y == black_pawn_start_y) && (y == -2 && x == 0))
            {
                // pawn ko agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_one_step_front_of_black_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y - 1)->get_piece();

                // pawn ko 2 step agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_two_step_front_of_black_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y - 2)->get_piece();

                if ((piece_two_step_front_of_black_pawn == EMPTY) && (piece_one_step_front_of_black_pawn == EMPTY))
                {
                    this->this_pawn_moved_double=true;
                    return true;
                }
                else
                {
                }
            }

            // black pawn at all condition
            if ((y == -1) && (x == 0))
            {
                // pawn ko agadi kunai piece hunu bhayena then only it can move forward
                Piece_type piece_one_step_front_of_black_pawn = board.get_cell_pointer(pawn_location_x, pawn_location_y - 1)->get_piece();
                if (piece_one_step_front_of_black_pawn == EMPTY)
                {
                    return true;
                }
                else
                {
                }
            }

            // criss cross movement if own color piece is not there in opponent section
            // black  pawn's opponents section

            // opponent 1 left and front of its own pawn
            if (x == -1 && y == -1)
            {

                // opponent1 of pawn i.e. at one step up and -1 of x
                int black_pawn_opp1_x = pawn_location_x - 1;
                int black_pawn_opp1_y = pawn_location_y - 1;

                Color color_black_pawn_opp1 = board.get_cell_pointer(black_pawn_opp1_x, black_pawn_opp1_y)->get_color();

                if ((color_black_pawn_opp1 == WHITE)) // && (end_x == black_pawn_opp1_x)  && (end_y ==black_pawn_opp1_y))
                {
                    return true;
                }
                else
                {
                    // cout << "opp1\n";
                    // cout << black_pawn_opp1_x << black_pawn_opp1_y << endl;
                    // cout << "opp2\n";
                    // cout << black_pawn_opp2_x << black_pawn_opp2_y << endl;
                }
            }

            // opponent 2 right and front if its own pawn
            if (x == 1 && y == -1)
            {
                // opponent2 of pawn i.e. at one step up and +1 of x
                int black_pawn_opp2_x = pawn_location_x + 1;
                int black_pawn_opp2_y = pawn_location_y - 1;

                Color color_black_pawn_opp2 = board.get_cell_pointer(black_pawn_opp2_x, black_pawn_opp2_y)->get_color();

                if ((color_black_pawn_opp2 == WHITE)) // && (end_x == black_pawn_opp2_x)  && (end_y ==black_pawn_opp2_y))
                {
                    return true;
                }
                else
                {
                }
            }

            // if nothing condiiton is matched then it cant move to that position
            //cout << "due to black\n ";
            return false;
        }
        else
        {
        }
        //cout << "due to none color\n";
        return false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // add promotion feature
    bool get_this_pawn_moved_double(){
        return this->this_pawn_moved_double;
    }
};

#endif