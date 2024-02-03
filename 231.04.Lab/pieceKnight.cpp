/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include <iostream>
using namespace std;

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSSIBLE MOVES
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   cout << "1 GETMOVE" << endl;
   Delta possibleMoves[8] = {
                { 2, -1}, { 2,  1},
      { 1, -2},                    { 1,  2},
      
      {-1, -2},                    { -1,  2},
                {-2, -1}, {-2,  1}
   };
   for (int i = 0; i < 8; i++)
   {
      Delta d = possibleMoves[i];
      Position dest = this->position + d;
      cout << dest.getCol() << ", " << dest.getRow() << endl;
      
      // Cannot move there if it's off the board
      if (dest.getCol() != -1)
      {
         cout << "2 IN_COL" << endl;
         if (dest.getRow() != -1)
         {
            cout << "3 IN_ROW" << endl;
            // or occupied by a piece of same team
            if (board[dest].isWhite() != this->isWhite() || board[dest].getType() == SPACE)
            {
               bool isCapture = board[dest].getType() != SPACE;
               Move move = Move(this->position,
                                dest,
                                move.MOVE,
                                isCapture ? board[dest].getType() : SPACE);
               cout << "4 INSERT: " << move.getText() << endl;
               moves.insert(move);
            }
         }
      }
   }
}
