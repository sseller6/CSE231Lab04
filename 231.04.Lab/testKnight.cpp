/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       P   P         7
 * 6     P       P       6
 * 5        (N)          5
 * 4     P       P       4
 * 3       P   P         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   White white(PAWN);
   
   board.board[2][6] = board.board[4][6] = &white;
   board.board[1][5] = board.board[5][5] = &white;
   board.board[1][3] = board.board[5][3] = &white;
   board.board[2][2] = board.board[4][2] = &white;
   
   knight.fWhite = true;
   knight.position.set(3, 4);
   set <Move> moves;
   
   // EXERCISE
   knight.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 0); // no friendly fire!
   
   // TEARDOWN
   board.board[2][6] = board.board[4][6] = nullptr;
   board.board[1][5] = board.board[5][5] = nullptr;
   board.board[1][3] = board.board[5][3] = nullptr;
   board.board[2][2] = board.board[4][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (N)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   Black black(PAWN);
   
   board.board[2][6] = board.board[4][6] = &black;
   board.board[1][5] = board.board[5][5] = &black;
   board.board[1][3] = board.board[5][3] = &black;
   board.board[2][2] = board.board[4][2] = &black;
   
   knight.fWhite = true;
   knight.position.set(3, 4);
   set <Move> moves;
   
   // EXERCISE
   knight.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(Move("d5c7p")) != moves.end());
   assertUnit(moves.find(Move("d5e7p")) != moves.end());
   assertUnit(moves.find(Move("d5b6p")) != moves.end());
   assertUnit(moves.find(Move("d5f6p")) != moves.end());
   assertUnit(moves.find(Move("d5b4p")) != moves.end());
   assertUnit(moves.find(Move("d5f4p")) != moves.end());
   assertUnit(moves.find(Move("d5c3p")) != moves.end());
   assertUnit(moves.find(Move("d5e3p")) != moves.end());
   
   // TEARDOWN
   board.board[2][6] = board.board[4][6] = nullptr;
   board.board[1][5] = board.board[5][5] = nullptr;
   board.board[1][3] = board.board[5][3] = nullptr;
   board.board[2][2] = board.board[4][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (N)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   Black black(PAWN);
   knight.fWhite = true;
   knight.position.set(3, 4);
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // MANY possible moves
   assertUnit(moves.find(Move("d5c7")) != moves.end());
   assertUnit(moves.find(Move("d5e7")) != moves.end());
   assertUnit(moves.find(Move("d5b6")) != moves.end());
   assertUnit(moves.find(Move("d5f6")) != moves.end());
   assertUnit(moves.find(Move("d5b4")) != moves.end());
   assertUnit(moves.find(Move("d5f4")) != moves.end());
   assertUnit(moves.find(Move("d5c3")) != moves.end());
   assertUnit(moves.find(Move("d5e3")) != moves.end());
} // TEARDOWN

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     .               3
 * 2       .             2
 * 1  (N)                1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   Black black(PAWN);
   knight.fWhite = true;
   knight.position.set(0, 0);
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("a1b3")) != moves.end());
   assertUnit(moves.find(Move("a1c2")) != moves.end());
} // TEARDOWN

/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP
   Knight k = Knight(0, 0, true);
   
   // EXERCISE
   PieceType kType = k.getType();
   
   // VERIFY
   assertUnit(kType == KNIGHT);
   
}  // TEARDOWN
