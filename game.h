#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

#include "board.h"
#include "dead_board.h"

#include "game_status.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

int exit_from_piece = 0;

class Game
{
    // create a playable chess board
    Board b;

    // to create the deadboard for each player
    Dead_Board white;
    Dead_Board black;

    // to show the game_status in each turn
    Game_staus game_staus;

    // to store whose turn is it
    Color turn;

    // store the location of piece which has given the check to print the check by details
    int check_by_piece_x;
    int check_by_piece_y;

    // to store the condition if required white pieces are moved for castling process
    bool is_white_king_moved;
    bool is_white_left_rook_moved;
    bool is_white_right_rook_moved;

    // to store the condition if required black pieces are moved for castling process
    bool is_black_king_moved;
    bool is_black_left_rook_moved;
    bool is_black_right_rook_moved;

public:
    // Castling class is friend class of Game Class i.e. Castling Class can acces the methods and data members of Game class from Castling Class;
    // friend class Castling;

    /////////////////////////////////////////////////////////////////////////////////////
    // constructor
    Game()
    {
        // is_castling_available=true;
        this->turn = WHITE;

        this->white.set_color_dead_board(WHITE);
        this->black.set_color_dead_board(BLACK);

        this->check_by_piece_x = 0;
        this->check_by_piece_y = 0;

        this->game_staus == ACTIVE;

        this->is_white_king_moved = false;
        this->is_white_left_rook_moved = false;
        this->is_white_right_rook_moved = false;

        this->is_black_king_moved = false;
        this->is_black_left_rook_moved = false;
        this->is_black_right_rook_moved = false;
    }

    Game(Board &c)
    {
        // is_castling_available=true;
        this->b = c;
        this->turn = WHITE;
        this->white.set_color_dead_board(WHITE);
        this->black.set_color_dead_board(BLACK);

        this->game_staus == ACTIVE;

        this->check_by_piece_x = 0;
        this->check_by_piece_y = 0;

        this->is_white_king_moved = false;
        this->is_white_left_rook_moved = false;
        this->is_white_right_rook_moved = false;

        this->is_black_king_moved = false;
        this->is_black_left_rook_moved = false;
        this->is_black_right_rook_moved = false;
    }

    Game(Color tn)
    {
        // is_castling_available=true;
        this->turn = tn;
        this->white.set_color_dead_board(WHITE);
        this->black.set_color_dead_board(BLACK);

        this->game_staus == ACTIVE;

        this->check_by_piece_x = 0;
        this->check_by_piece_y = 0;

        this->is_white_king_moved = false;
        this->is_white_left_rook_moved = false;
        this->is_white_right_rook_moved = false;

        this->is_black_king_moved = false;
        this->is_black_left_rook_moved = false;
        this->is_black_right_rook_moved = false;
    }

    /////////////////////////////////////////////////////////////////////////////////////

    // it starts the each turn of game and runs each time turn has come and print the board each time the player turn has come

    bool play_game()
    {
        system("cls"); // each time it types this string cls to terminal and thus it prints board every time

        // this->print_game_staus(game_staus);

        white.print_dead_board();
        b.print_board();
        black.print_dead_board();

        return do_move();
    }
    /////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////
    // it starts the move function and here it inputs the start and end postiion

    // this function is called each time player turn has come
    // this function return false if checkmate condition is found and game is ended also returns false to playgame() function
    // else it calls make_move function
    bool do_move()
    {

        // determine the game status i.e either king is in check or checkamte or stalemate
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // it finds king is in check or not if found print the status of KING IS IN CHECK
        // if king is in check then it checks for the checkamte condition
        // if checkmate condition is found it exits the game showing dialog box of winner status.
        if (check_king(turn) == true)
        {
            if (turn == WHITE)
            {
                cout << "\nWHITE KING IS IN CHECK!!\n";
                this->print_check_by_piece_details();
            }
            else
            {
                cout << "\nBLACK KING IS IN CHECK!!\n";
                this->print_check_by_piece_details();
            }

            // CHECKMATE FUNCTION after king is in check
            // if checkmate found return false to exit fron this do_move function and further execution stops
            if (checkmate(turn) == true)
            {
                if (turn == WHITE)
                {
                    cout << "CHECKMATE!!\n";
                    cout << "Black Wins\n";
                    game_staus = BLACK_WINS;
                    return false;
                }
                else if (turn == BLACK)
                {
                    cout << "CHECKMATE!!\n";
                    cout << "White Wins\n";
                    game_staus == WHITE_WINS;
                    return false;
                }
            }
            else
            {
                // cout << "no checkmate !! (do_move function)\n";
            }
        }

        // STALEMATE Condition
        //  if players has no legal moves and king is not in check then stalemate i.e. known as draw
        //  checkmate without check of king makes stalemate i.e. DRAW
        if (checkmate(turn) == true)
        {
            if (turn == WHITE)
            {
                cout << "\nSTALEMATE!!\n";
                cout << "DRAW\n";
                cout << "As there is no legal moves of WHITE and its KING is not in check too.\n";
                game_staus = DRAW;
                return false;
            }
            else if (turn == BLACK)
            {
                cout << "\nSTALEMATE!!\n";
                cout << "DRAW\n";
                cout << "As there is no legal moves of BLACK and its KING is not in check too.\n";
                game_staus = DRAW;
                return false;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // makes the user inout the move positions

        // enter string to input
        string move;

        // string data is analyzed and changed into int
        int start_x;
        int start_y;
        int end_x;
        int end_y;

        bool stop = false;

        while (!stop)
        {

            cout << endl;
            // printing whose turn is

            cout << "-----------\n";
            if (turn == WHITE)
            {
                cout << "TURN: "
                     << "WHITE" << endl;
            }
            else
            {
                cout << "TURN: "
                     << "BLACK" << endl;
            }
            cout << "-----------\n";
            /// ////////////////

            cout << "Enter move as a single four integer value.\n";
            cout << "Enter x-coordinates first and then y-cordinates\n";
            cin >> move;

            if (move.length() != 4)
            {
                cout << "4 digits are only allowed\n";
                continue;
            }

            start_x = move[0] - 48; // -48 means changing ASCII value to integer value
            start_y = move[1] - 48;
            end_x = move[2] - 48;
            end_y = move[3] - 48;

            // if input value is out of range then it makes the user to re-input by continuing the loop from start
            if (start_x < 1 || start_y < 1 || start_x > 8 || start_y > 8 || end_x < 1 || end_y < 1 || end_x > 8 || end_y > 8)
            {
                cout << "Input values are out of limits\n";
                continue;
            }
            else
            {
            }

            // makes the cell pointer of src and dest by the user's data to analyze the cell
            Cell *src = b.get_cell_pointer(start_x, start_y);
            Cell *dest = b.get_cell_pointer(end_x, end_y);

            // if the src->piece is of whose turn color then analyze the move and proced to make_move function
            if (src->get_color() == turn)
            {
                ///////////////////////

                // if src and dest position is same then show cannot move to own position.
                if (start_x == end_x && start_y == end_y)
                {
                    cout << "Cannot move to same position. Try again\n";

                    continue;
                }

                //////////////////////

                //////////////////////

                // if dest is on the own piece then show cannot move to own piece.
                if ((dest->get_color() == src->get_color()) && (dest->get_color() != NONE))
                {
                    cout << "Cannot move to own piece. Try again\n";
                    continue;
                }

                // if castling possible then does the castling process else further checks for that piece movement
                if ((do_castling(start_x, start_y, end_x, end_y, src, dest, b, turn) == true) || (this->en_passing(start_x, start_y, end_x, end_y, b) == true))
                {
                    // while checking the condition of do_castling if it is possible it makes castling
                    stop = true;
                }
                else
                {

                    //////////////////////////////////////////////////////////////////////////////////////////

                    // if user input postion from src to dest is valid then proceeds for moving the piece
                    //  it calls another function for checking the valid move by finding valid move as per src->piece
                    if (is_make_move_possible(start_x, start_y, end_x, end_y, src, dest) == true)
                    {

                        // while moving the piece from src to dest if king is in check then show king will be in check and that move is invalid
                        //  as it is not legal moves because it makes own king is in check
                        if (move_check_back_return_check(src, dest) == true)
                        {
                            cout << "\nYour KING will be in CHECK!!\n";
                            continue;
                        }
                        // if desired move doesn't makes the king in check then start the process to makes move
                        else
                        {
                            // it makes the piece move to destination by calling another function
                            make_move(start_x, start_y, end_x, end_y, src, dest);
                            stop = true;
                            break;
                        }
                    }
                    // if move is not valid as checking for the required piece valid move it throws errror move.
                    else
                    {

                        cout << "ERROR!!\n";
                        cout << "Invalid Move. Try again\n";
                        continue;
                    }
                }
            }
            // if user input's src is pointing to other player piece then it throws showing not your piece
            else
            {
                cout << "It is not your piece. Try again\n";
                continue;
            }
        }

        // checks for the promotion and if so implements the promotion
        promotion(turn);

        // here it changes the turn and repeats continously
        if (turn == WHITE)
        {
            turn = BLACK;
        }
        else
        {
            turn = WHITE;
        }

        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // checks the make move if can move return true else return false
    // it checks the valid move by pointing src->piece and check for that piece is valid move from moving src to dest.
    bool is_make_move_possible(int start_x, int start_y, int end_x, int end_y, Cell *src, Cell *dest)
    {

        Piece_type src_piece = src->get_piece();

        King k1;
        Knight n1;
        Rook r1;
        Bishop b1;
        Queen q1;
        Pawn p1;

        // cout<<"SRC PIECE: "<<src_piece<<endl;

        switch (src_piece)
        {
        case KING:
            ///*
            // King k1;

            if (k1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {
                return false;
            }
            break;
            //*/

        case KNIGHT:
            ///*
            // Knight n1;

            if (n1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {

                return false;
            }
            break;
            //*/

        case ROOK:
            ///*
            // Rook r1;
            if (r1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {
                return false;
            }
            break;
            //*/

        case BISHOP:
            ///*
            // Bishop b1;
            if (b1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {
                return false;
            }
            break;
            //*/

        case QUEEN:
            ///*
            // Queen q1;
            if (q1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {
                return false;
            }
            break;
            //*/

        case PAWN:
            ///*
            // Pawn p1;
            if (p1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                return true;
                // move(src, dest);
            }
            else
            {
                return false;
            }
            // add promotion feature
            break;
            //*/

        case EMPTY:
            cout << "No piece is at origin.\n";
            return false;
            break;

        default:
            cout << "Switch case Piece not Found\n";
            return false;
            break;
        }
        return false;
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////

    // it makes the move according to the piecetype of that inital position
    // it does not return anything as it is of void return type
    void make_move(int start_x, int start_y, int end_x, int end_y, Cell *src, Cell *dest)
    {

        Piece_type src_piece = src->get_piece();

        King k1;
        Knight n1;
        Rook r1;
        Bishop b1;
        Queen q1;
        Pawn p1;

        // cout<<"SRC PIECE: "<<src_piece<<endl;

        switch (src_piece)
        {
        case KING:
            ///*
            // King k1;
            if (k1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                Color piece_color = src->get_color();
                move(src, dest);

                // changing the value of king_moved of respective color
                if (piece_color == WHITE)
                {
                    this->is_white_king_moved = true;
                }
                else if (piece_color == BLACK)
                {
                    this->is_black_king_moved = true;
                }
            }
            else
            {
                return;
            }
            break;
            //*/

        case KNIGHT:
            ///*
            // Knight n1;

            if (n1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                move(src, dest);
            }
            else
            {

                return;
            }
            break;
            //*/

        case ROOK:
            ///*
            // Rook r1;
            if (r1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                Color piece_color = src->get_color();
                move(src, dest);

                // changing the value of king_moved of respective color

                // for white rook
                if (piece_color == WHITE)
                {

                    // white left rook
                    if ((start_y == starting_cell_y) && (start_x == starting_cell_x))
                    {
                        this->is_white_left_rook_moved = true;
                    }

                    // white right rook
                    if ((start_y == starting_cell_y) && (start_x == ending_cell_x))
                    {
                        this->is_white_right_rook_moved = true;
                    }
                }
                // for black rook
                if (piece_color == BLACK)
                {

                    // black left rook
                    if ((start_y == ending_cell_y) && (start_x == starting_cell_x))
                    {
                        this->is_black_left_rook_moved = true;
                    }

                    // black right rook
                    if ((start_y == ending_cell_y) && (start_x == ending_cell_x))
                    {
                        this->is_black_right_rook_moved = true;
                    }
                }
            }
            else
            {
                return;
            }
            break;
            //*/

        case BISHOP:
            ///*
            // Bishop b1;
            if (b1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                move(src, dest);
            }
            else
            {
                return;
            }
            break;
            //*/

        case QUEEN:
            ///*
            // Queen q1;
            if (q1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                move(src, dest);
            }
            else
            {
                return;
            }
            break;
            //*/

        case PAWN:
            ///*
            // Pawn p1;
            if (p1.valid_move(start_x, start_y, end_x, end_y, b))
            {
                move(src, dest);
            }
            else
            {
                return;
            }
            // add promotion feature
            break;
            //*/

        case EMPTY:
            cout << "No piece is at origin.\n";
            return;
            break;

        default:
            cout << "Switch case Piece not Found\n";
            return;
            break;
        }
        // return true;
    }
    /////////////////////////////////////////////////////////////////////////////////////////
    // it does not return anything as it is of void return type
    // it simply moves the piece from src to dest and dest to dead_board as its piece is killed

    void move(Cell *src, Cell *dest)
    {

        // move dest to dead board
        // move src to dest

        // setting dest to dead_board of respective color
        Color dest_color = dest->get_color();
        Piece_type dest_piece_type = dest->get_piece();
        if (dest->get_piece() == EMPTY)
        {
        }
        else
        {
            if (dest_color == WHITE)
            {
                white.set_cell_dead_board(dest_piece_type, dest_color);
            }
            if (dest_color == BLACK)
            {
                black.set_cell_dead_board(dest_piece_type, dest_color);
            }
        }
        // setting dest to src

        Cell *temp = new Cell;
        *temp = *dest;

        *dest = *src;
        dest->set_pos_x(temp->get_pos_x());
        dest->set_pos_y(temp->get_pos_y());

        delete temp;

        // setting src cell to empty type
        Cell *empty = new Cell(EMPTY, NONE, src->get_pos_x(), src->get_pos_y());
        *src = *empty;
    }

    /////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////
    // it first move the piece from src to dest then find if king is in check after moving the piece and again sets the piece back to original postion
    // it return the value either king will be in check or not after moving the piece from src to dest
    bool move_check_back_return_check(Cell *src, Cell *dest)
    {

        // makes move
        ////////////////////////////////////////////////////
        // move dest to dead board
        // move src to dest

        // setting value of destiantion to temp variable
        Cell temp_dest = *dest;
        Cell temp_src = *src;

        // setting dest to src
        Cell *temp2 = new Cell;
        *temp2 = *dest;

        *dest = *src;
        // setting pos_x pos_y in dest by its own positon_x and position_y if we will not do this pox_x and pos_y is copied from src;
        dest->set_pos_x(temp2->get_pos_x());
        dest->set_pos_y(temp2->get_pos_y());

        delete temp2;

        // setting src cell to empty type
        Cell *empty = new Cell(EMPTY, NONE, src->get_pos_x(), src->get_pos_y());
        *src = *empty;

        // does check for the king and if so return true and false to the fucntion
        ////////////////////////////////////////////////////
        bool return_check = false;
        if (check_king(turn) == true)
        {
            return_check = true;
        }
        else
        {
            return_check = false;
        }

        // it moves back to the normal position
        ////////////////////////////////////////////////////

        // setting dest to src i.e. back to original
        *src = temp_src;
        *dest = temp_dest;

        // return if it is in check or not after moving the piece and again sets back to the position

        return return_check;
    }

    /////////////////////////////////////////////////////////////////////////////

    // it promotes the pawn to user type piece
    // it shows dialog to user to choose which piece to replace with pawn if respective location is reached by pawn
    // promotion available
    void promotion(Color color)
    {
        if (color == WHITE)
        {
            for (int x = start_x; x <= (start_x + 7); x++)
            {
                Cell *cell_pointer_last_row = this->b.get_cell_pointer(x, start_y + 7);

                if ((cell_pointer_last_row->get_piece() == PAWN) && (cell_pointer_last_row->get_color() == WHITE))
                {
                again:
                    char promote_piece;
                    cout << "PROMOTION TO:\n";
                    cout << "Enter r/n/b/q (Rook/Knight/Bishop/Queen)\n";
                    cin >> promote_piece;

                    // change white pawn to white of respective piece

                    switch (promote_piece)
                    {
                    case 'r':
                        // sets white rook to that position
                        cell_pointer_last_row->set_cell(ROOK, color, x, start_y + 7);
                        // set white pawn to dead_board
                        this->white.set_cell_dead_board(PAWN, color);
                        break;
                    case 'n':
                        // sets white rook to that position
                        cell_pointer_last_row->set_cell(KNIGHT, color, x, start_y + 7);
                        // set white pawn to dead_board
                        this->white.set_cell_dead_board(PAWN, color);
                        break;
                    case 'b':
                        // sets white rook to that position
                        cell_pointer_last_row->set_cell(BISHOP, color, x, start_y + 7);
                        // set white pawn to dead_board
                        this->white.set_cell_dead_board(PAWN, color);
                        break;
                    case 'q':

                        // sets white rook to that position
                        cell_pointer_last_row->set_cell(QUEEN, color, x, start_y + 7);
                        // set white pawn to dead_board
                        this->white.set_cell_dead_board(PAWN, color);
                        break;
                    default:

                        cout << "Enter valid piece character\n";
                        goto again;
                        break;
                    }
                }
            }
        }

        else if (color == BLACK)
        {
            for (int x = start_x; x <= (start_x + 7); x++)
            {
                Cell *cell_pointer_first_row = this->b.get_cell_pointer(x, start_y);

                if ((cell_pointer_first_row->get_piece() == PAWN) && (cell_pointer_first_row->get_color() == BLACK))
                {
                again2:
                    char promote_piece;
                    cout << "PROMOTION TO:\n";
                    cout << "Enter r/n/b/q (Rook/Knight/Bishop/Queen)\n";
                    cin >> promote_piece;

                    // change white pawn to white of respective piece

                    switch (promote_piece)
                    {
                    case 'r':
                        // sets black rook to that position
                        cell_pointer_first_row->set_cell(ROOK, color, x, start_y);
                        // set black pawn to dead_board
                        this->black.set_cell_dead_board(PAWN, color);
                        break;
                    case 'n':
                        // sets black rook to that position
                        cell_pointer_first_row->set_cell(KNIGHT, color, x, start_y);
                        // set black pawn to dead_board
                        this->black.set_cell_dead_board(PAWN, color);
                        break;
                    case 'b':
                        // sets black rook to that position
                        cell_pointer_first_row->set_cell(BISHOP, color, x, start_y);
                        // set white pawn to dead_board
                        this->black.set_cell_dead_board(PAWN, color);
                        break;
                    case 'q':

                        // sets black rook to that position
                        cell_pointer_first_row->set_cell(QUEEN, color, x, start_y);
                        // set black pawn to dead_board
                        this->black.set_cell_dead_board(PAWN, color);
                        break;
                    default:

                        cout << "Enter valid piece character\n";
                        goto again2;
                        break;
                    }
                }
            }
        }
        else
        {
            return;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////

    // getter of cell of king piece_type
    Cell *get_cell_pointer_of_king(Color color)
    {
        for (int i = start_x + 0; i <= start_x + 7; i++)
        {
            for (int j = start_y + 0; j <= start_y + 7; j++)
            {

                if (this->b.get_cell_pointer(i, j)->get_color() == color)
                {

                    if (this->b.get_cell_pointer(i, j)->get_piece() == KING)
                    {
                        // cout<<"get_cell_king_func_ king is at: "<<i<<j<<endl;
                        // cout<<"get_cell_king_func_ king is at of piece's inside x and y: "<<this->b.get_cell_pointer(i,j)->get_pos_x()<<this->b.get_cell_pointer(i,j)->get_pos_y()<<endl;

                        return this->b.get_cell_pointer(i, j);
                        // break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    // find if king is in check or not
    bool check_king(Color turn)
    {
        // if turn_king mathi opponent turn ko piece ko valid move turn_king ko cell ma paryo bhane then its check for turn turn_king

        int turn_king_x = this->get_cell_pointer_of_king(turn)->get_pos_x();
        int turn_king_y = this->get_cell_pointer_of_king(turn)->get_pos_y();

        // cout<<"color: "<<turn <<"'s king is in :"<<turn_king_x<<turn_king_y<<endl;

        Color opponent_color = get_opponent_color(turn);
        //  cout<<"opponent color :"<<opponent_color<<endl;
        King k3;
        Queen q3;
        Bishop bs3;
        Knight n3;
        Rook r3;
        Pawn p3;
        Pawn p4;
        bool chech;

        for (int i = start_x + 0; i <= start_x + 7; i++)
        {
            for (int j = start_y + 0; j <= start_y + 7; j++)
            {
                Cell *this_cell = this->b.get_cell_pointer(i, j);
                if (this_cell->get_color() == opponent_color)
                {

                    Piece_type found_piece = this_cell->get_piece();
                    // cout<<"piece_type: "<<found_piece<<"at :"<<i<<j<<endl;
                    // cout<<"color: "<<turn <<"'s king is in :"<<turn_king_x<<turn_king_y<<endl;

                    switch (found_piece)
                    {
                    case KING:

                        if (k3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {

                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: KING at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case QUEEN:

                        if (q3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {
                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: QUEEN at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case BISHOP:

                        if (bs3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {
                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: BISHOP at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case KNIGHT:

                        if (n3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {
                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: KNIGHT at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case ROOK:

                        if (r3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {
                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: ROOK at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case PAWN:

                        // chech=p4.valid_move(i,j,turn_king_x,turn_king_y,b);
                        // cout<<"pawn can show valid when final is king_x and king_y "<<chech<<endl;

                        if (p3.valid_move(i, j, turn_king_x, turn_king_y, b) == true)
                        {
                            this->check_by_piece_x = i;
                            this->check_by_piece_y = j;
                            // cout << "CHECK BY:\n";
                            // cout << "PIECE_TYPE: PAWN at" << i << j << endl;
                            // cout << "can kill the piece at" << turn_king_x << turn_king_y << endl;
                            return true;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case EMPTY:

                        continue;

                    default:
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////
    // find if king is in checkmate or not
    bool checkmate(Color color)
    {

        // first find that king is in check or not
        // if king is in check state then it can go for the checkmate condition
        // checkmate if
        // no pieces is present to save the king from check and no valid moves are present for the king

        if ((this->is_king_moves_present(color) == false) && (this->is_any_piece_can_save_king_from_check(color) == false))
        {
            // cout << "checkmate in function checkmate\n";
            return true;
        }
        else
        {
            // cout << "no checkmate in function checkmate\n";
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////
    // find if there is any valid moves of king or not
    bool is_king_moves_present(Color color)
    {

        King king;

        Cell *king_position = this->get_cell_pointer_of_king(color);

        for (int i = start_x + 0; i <= start_x + 7; i++)
        {
            for (int j = start_y + 0; j <= start_y + 7; j++)
            {
                Cell *dest = this->b.get_cell_pointer(i, j);
                if (king.valid_move(king_position->get_pos_x(), king_position->get_pos_y(), i, j, b) == true)
                {
                    if (this->b.get_cell_pointer(i, j)->get_color() != color)
                    {
                        if (this->move_check_back_return_check(king_position, dest) == false)
                        {
                            return true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////
    // find if any piece can save the king from check
    bool is_any_piece_can_save_king_from_check(Color color)
    {

        King king;
        Queen queen;
        Bishop bishop;
        Knight knight;
        Rook rook;
        Pawn pawn;

        // cout<<"----------------------------------------------------\n";
        // cout << "\ninside the is_any_piece_can_save function:\n";

        for (int src_x = start_x; src_x <= start_x + 7; src_x++)
        {
            for (int src_y = start_y; src_y <= start_y + 7; src_y++)
            {

                Cell *src = this->b.get_cell_pointer(src_x, src_y);
                Piece_type src_piece = src->get_piece();

                if (src->get_color() == color)
                {

                    for (int des_x = start_x; des_x <= start_x + 7; des_x++)
                    {
                        for (int des_y = start_y; des_y <= start_y + 7; des_y++)
                        {

                            Cell *des = this->b.get_cell_pointer(des_x, des_y);

                            // cout<<"\nPriting values\n";
                            // cout<<"src "<<src_x<<src_y<<" des "<<des_x<<des_y<<endl;
                            // cout<<endl;

                            switch (src_piece)
                            {
                            case KING:
                                if (king.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {

                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case QUEEN:
                                if (queen.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {
                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case BISHOP:
                                if (bishop.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {
                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case KNIGHT:
                                if (knight.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {
                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case ROOK:
                                if (rook.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {
                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case PAWN:
                                if (pawn.valid_move(src_x, src_y, des_x, des_y, this->b))
                                {
                                    if (this->move_check_back_return_check(src, des) == false)
                                    {
                                        // cout << "piece at " << src_x << src_y << "can move to " << des_x << des_y << endl;

                                        return true;
                                    }
                                }
                                break;

                            case EMPTY:
                                break;

                            default:
                                break;
                            }
                            // switch case closed
                        }
                    }

                    // exits from inner loop
                }
                else
                {
                }
            }
        }

        // exits from all loop

        // cout<<"----------------------------------------------------\n";
        return false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////

    // to do the castling as per user turn color
    bool do_castling(int start_x, int start_y, int final_x, int final_y, Cell *src, Cell *dest, Board &board, Color color)
    {

        // src and dest cell pointer as per users input
        // Cell *src = board.get_cell_pointer(start_x, start_y);
        // Cell *dest = board.get_cell_pointer(final_x, final_y);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // if color is white and src piece_color is white then
        if (color == WHITE && src->get_color() == WHITE)
        {
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            // left ROOK and KING Castling
            if ((this->is_white_king_moved == false) && (this->is_white_left_rook_moved == false) && (this->check_king(color) == false) && (this->move_check_back_return_check(src, dest) == false) && (src->get_color() == color) && (start_y == starting_cell_y) && (final_y == starting_cell_y) && (start_x == starting_cell_x + 4) && (final_x == starting_cell_x + 4 - 2))
            {
                // after meeting the necessary postion criteria it does the castling

                bool no_pieces_between_king_and_rook = true;

                // to find there is no pieces between king amd rook
                for (int i = starting_cell_x + 1; i <= starting_cell_x + 3; i++)
                {
                    Cell *cell = board.get_cell_pointer(i, starting_cell_y);

                    if (cell->get_piece() != EMPTY)
                    {
                        no_pieces_between_king_and_rook = false;
                        break;
                    }
                }

                if (no_pieces_between_king_and_rook == true)
                {
                    // moving king from src to dest
                    move(src, dest);

                    // moving rook to its respective position
                    Cell *rook_src = board.get_cell_pointer(start_x - 4, start_y);
                    Cell *rook_dest = board.get_cell_pointer(start_x - 1, start_y);

                    move(rook_src, rook_dest);

                    // after castling (moving the king and rook to specified location) is done return true
                    return true;
                }
                else
                {
                    return false;
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            // right ROOK and KING Castling
            else if ((this->is_white_king_moved == false) && (this->is_white_right_rook_moved == false) && (this->check_king(color) == false) && (this->move_check_back_return_check(src, dest) == false) && (src->get_color() == color) && (start_y == starting_cell_y) && (final_y == starting_cell_y) && (start_x == starting_cell_x + 4) && (final_x == starting_cell_x + 4 + 2))
            {
                // after meeting the necessary postion criteria it does the castling

                bool no_pieces_between_king_and_rook = true;

                // to find there is no pieces between king amd rook
                for (int i = starting_cell_x + 4 + 1; i <= starting_cell_x + 3 + 3; i++)
                {
                    Cell *cell = board.get_cell_pointer(i, starting_cell_y);

                    if (cell->get_piece() != EMPTY)
                    {
                        no_pieces_between_king_and_rook = false;
                    }
                }

                if (no_pieces_between_king_and_rook == true)
                {
                    // moving king from src to dest
                    this->move(src, dest);

                    // moving rook to its respective position
                    Cell *rook_src = board.get_cell_pointer(start_x + 3, start_y);
                    Cell *rook_dest = board.get_cell_pointer(start_x + 1, start_y);
                    this->move(rook_src, rook_dest);

                    // after castling (moving the king and rook to specified location) is done return true
                    return true;
                }
                else
                {
                    return false;
                }
            }
            // if conditons is not meet return castling is not possible and return false
            else
            {
                return false;
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // if color is black and src piece_color is black then
        else if (color == BLACK && src->get_color() == BLACK)
        {
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            // left ROOK and KING Castling
            if ((this->is_black_king_moved == false) && (this->is_black_left_rook_moved == false) && (this->check_king(color) == false) && (this->move_check_back_return_check(src, dest) == false) && (src->get_color() == color) && (start_y == ending_cell_y) && (final_y == ending_cell_y) && (start_x == starting_cell_x + 4) && (final_x == starting_cell_x + 4 - 2))
            {
                // after meeting the necessary postion criteria it does the castling

                bool no_pieces_between_king_and_rook = true;

                // to find there is no pieces between king amd rook
                for (int i = starting_cell_x + 1; i <= starting_cell_x + 3; i++)
                {
                    Cell *cell = board.get_cell_pointer(i, ending_cell_y);

                    if (cell->get_piece() != EMPTY)
                    {
                        no_pieces_between_king_and_rook = false;
                        break;
                    }
                }

                if (no_pieces_between_king_and_rook == true)
                {
                    // moving king from src to dest
                    move(src, dest);

                    // moving rook to its respective position
                    Cell *rook_src = board.get_cell_pointer(start_x - 4, start_y);
                    Cell *rook_dest = board.get_cell_pointer(start_x - 1, start_y);

                    move(rook_src, rook_dest);

                    // after castling (moving the king and rook to specified location) is done return true
                    return true;
                }
                else
                {
                    return false;
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            // right ROOK and KING Castling
            else if ((this->is_black_king_moved == false) && (this->is_black_right_rook_moved == false) && (this->check_king(color) == false) && (this->move_check_back_return_check(src, dest) == false) && (src->get_color() == color) && (start_y == ending_cell_y) && (final_y == ending_cell_y) && (start_x == starting_cell_x + 4) && (final_x == starting_cell_x + 4 + 2))
            {
                // after meeting the necessary postion criteria it does the castling

                bool no_pieces_between_king_and_rook = true;

                // to find there is no pieces between king amd rook
                for (int i = starting_cell_x + 4 + 1; i <= starting_cell_x + 3 + 3; i++)
                {
                    Cell *cell = board.get_cell_pointer(i, ending_cell_y);

                    if (cell->get_piece() != EMPTY)
                    {
                        no_pieces_between_king_and_rook = false;
                    }
                }

                if (no_pieces_between_king_and_rook == true)
                {
                    // moving king from src to dest
                    this->move(src, dest);

                    // moving rook to its respective position
                    Cell *rook_src = board.get_cell_pointer(start_x + 3, start_y);
                    Cell *rook_dest = board.get_cell_pointer(start_x + 1, start_y);
                    this->move(rook_src, rook_dest);

                    // after castling (moving the king and rook to specified location) is done return true
                    return true;
                }
                else
                {
                    return false;
                }
            }
            // if conditons is not meet return castling is not possible and return false
            else
            {
                return false;
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // if color is none then return false
        else
        {
            return false;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // it prints the piece location which gives the king check
    void print_check_by_piece_details()
    {
        cout << "CHECK BY:\n";
        cout << "PIECE_AT: " << this->check_by_piece_x << this->check_by_piece_y << endl;
        cout << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////
    // print game_staus
    void print_game_status_word(Game_staus gs)
    {
        switch (gs)
        {
        case ACTIVE:
            cout << "ACTIVE";
            break;
        case ERROR:
            cout << "ERROR";
            break;
        case CHECK:
            cout << "CHECK";
            break;
        case DRAW:
            cout << "DRAW";
            break;
        case BLACK_WINS:
            cout << "BLACK_WINS";
            break;
        case WHITE_WINS:
            cout << "WHITE_WINS";
            break;

        default:
            break;
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    // print whole game status block
    void print_game_staus(Game_staus gs)
    {

        cout << endl;
        cout << "                                    --------------- ";

        cout << endl;
        cout << "                                    STATUS: ";
        print_game_status_word(gs);
        cout << endl;
        cout << "                                    --------------- ";
        cout << endl;
    }


    //////////////////////////////////////////////////////////////////////////////////////////
    //check en-passant
    bool check_en_passant(int start_x, int start_y, int final_x, int final_y, Board &board){

        Piece p;
        int x = (p.diff_x(start_x, final_x));
        int y = (p.diff_y(start_y, final_y));
        
        Cell* src=board.get_cell_pointer(start_x,start_y);
        Cell* dest=board.get_cell_pointer(final_x,final_y);

        return true;

    }

    //////////////////////////////////////////////////////////////////////////////////////////
    // en passant function
    bool en_passing(int start_x, int start_y, int final_x, int final_y, Board &board)
    {

        // if en_passant possible then
        if (check_en_passant(start_x,start_y,final_x,final_y,b))
        {

            Piece p;
            int x = (p.diff_x(start_x, final_x));
            int y = (p.diff_y(start_y, final_y));

            Cell *src = board.get_cell_pointer(start_x, start_y);
            Cell *dest = board.get_cell_pointer(final_x, final_y);

            // for white pawn
            if ((src->get_piece() == PAWN) && (src->get_color() == WHITE))
            {
                // for black pawn available at right side and criss cross movement right side of white pawn at level 5
                if (y == 1 && x == 1 && (start_y = ending_cell_y - 3))
                {

                    Color src_color = src->get_color();
                    Cell *src_one_step_right = board.get_cell_pointer(start_x + 1, start_y);

                    
                    
                    if ((dest->get_piece() == EMPTY) && (src_one_step_right->get_piece() == PAWN) && (src_one_step_right->get_color() == BLACK))
                    {

                        this->move(src, src_one_step_right);
                        this->move(src_one_step_right, dest);
                        return true;
                    }
                }
                // for black pawn available at left side and criss cross movement left side of white pawn at level 5
                if (y == 1 && x == -1 && (start_y = ending_cell_y - 3))
                {

                    Color src_color = src->get_color();
                    Cell *src_one_step_left = board.get_cell_pointer(start_x - 1, start_y);

                    if ((dest->get_piece() == EMPTY) && (src_one_step_left->get_piece() == PAWN) && (src_one_step_left->get_color() == BLACK))
                    {

                        this->move(src, src_one_step_left);
                        this->move(src_one_step_left, dest);
                        return true;
                    }
                }
            }

            // for black pawn
            if ((src->get_piece() == PAWN) && (src->get_color() == BLACK))
            {
                // for white pawn available at right side and criss cross movement right side of black pawn at level 5
                if (y == -1 && x == 1 && (start_y = starting_cell_y + 3))
                {

                    Color src_color = src->get_color();
                    Cell *src_one_step_right = board.get_cell_pointer(start_x + 1, start_y);

                    if ((dest->get_piece() == EMPTY) && (src_one_step_right->get_piece() == PAWN) && (src_one_step_right->get_color() == WHITE))
                    {

                        this->move(src, src_one_step_right);
                        this->move(src_one_step_right, dest);
                        return true;
                    }
                }
                // for black pawn available at left side and criss cross movement left side of white pawn at level 5
                if (y == -1 && x == -1 && (start_y = starting_cell_y + 3))
                {

                    Color src_color = src->get_color();
                    Cell *src_one_step_left = board.get_cell_pointer(start_x - 1, start_y);

                    if ((dest->get_piece() == EMPTY) && (src_one_step_left->get_piece() == PAWN) && (src_one_step_left->get_color() == WHITE))
                    {

                        this->move(src, src_one_step_left);
                        this->move(src_one_step_left, dest);
                        return true;
                    }
                }
            }
        }
        // if enpassant is not possible then return false
        else
        {
            return false;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////
    // getter of board
    Board get_board()
    {
        return this->b;
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // getter of turn
    Color get_turn()
    {
        return this->turn;
    }

    //////////////////////////////////////////////////////////////////////////////////////////

    // getter of board pointer
    Board *get_board_pointer()
    {
        return &(this->b);
    }

    //////////////////////////////////////////////////////////////////////////////
    // get opponent color
    Color get_opponent_color()
    {

        if (this->turn == WHITE)
        {
            return BLACK;
        }
        else if (this->turn == BLACK)
        {
            return WHITE;
        }
    }

    Color get_opponent_color(Color color)
    {

        if (color == WHITE)
        {
            return BLACK;
        }
        else if (color == BLACK)
        {
            return WHITE;
        }
    }
    /////////////////////////////////////////////////////////////////////////////
};

#endif