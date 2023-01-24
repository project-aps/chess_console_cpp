#include<iostream>
#include <conio.h>
#include "game.h"


using namespace std;

int main()
{
    
///*
    Game g;
    g.get_board().set_board_initially(); 

    while(g.play_game()){
        
    }
    cout<<"Game Finished!!\n";



//*/

    //4243 3736 8283 4815 
    

    // for check only
    // 5254 5756 6263 4884

    //for checkmate
     //6263 5756 7274 4884

     // for checkmate
     //1213 5756 1314 6835 1415 4866 1516 6662

     //for stalemate
     // 3234 8785 8284 1715 4114 1816 1415 1686 1537 6766 3747 5867 4727 4843 2728 4387 2838 6776 3856

    // for castling
    // 1214 1715 2224 2725 3234 3735 4244 4745 5254 5755 6264 6765 7274 7775 8284 8785 2133 2836 3113 3816 4143 4846 6183 6886 7163 7866
   
    // for promotion
    // 1214 2725 1425 1715 1113 1514 1323 1413 8283 1312 8384
          
    
/*

*/
    //Game g;
    //g.get_board().set_board_initially(); 
    //cout<<g.is_any_piece_can_save_king_from_check(WHITE)<<endl;


    getch();
    return 0;
}