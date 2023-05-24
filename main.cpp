#include <iostream>
#include <conio.h>
#include "game.h"

using namespace std;

int main()
{

    ///*
    Game g;
    g.get_board().set_board_initially();

    while (g.play_game())
    {
    }
    cout << "Game Finished!!\n";

    //*/

    // d2d3 c7c6 h2h3 d8a5

    // for check only
    // e2e4 e7e6 f2f3 d8h4

    // for checkmate
    // f2f3 e7e6 g2g4 d8h4

    // for checkmate
    // a2a3 e7e6 a3a4 f8c5 a4a5 d8f6 a5a6 f6f2

    // for stalemate
    //  c2c4 h7h5 h2h4 a7a5 d1a4 a8a6 a4a5 a6h6 a5c7 f7f6 c7d7 e8f7 d7b7 d8d3 b7b8 d3h7 b8c8 f7g6 c8e6

    // for castling
    // a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5 b1c3 b8c6 c1a3 c8a6 d1d3 d8d6 f1h3 f8h6 g1f3 g8f6

    // for promotion
    // a2a4 b7b5 a4b5 a7a5 a1a3 a5a4 a3b3 a4a3 h2h3 a3a2 h3h4

    // for white enpassing
    //  b2b4 h7h6 b4b5 c7c5

    // for black enpassing
    //  h2h3 c7c5 h3h4 c5c4 b2b4

    /*

    */
    // Game g;
    // g.get_board().set_board_initially();
    // cout<<g.is_any_piece_can_save_king_from_check(WHITE)<<endl;

    getch();
    return 0;
}