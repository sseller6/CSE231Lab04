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
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

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
 * 1  (n)                 1
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

   // TEARDOWN
}

/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP
   
   // EXERCISE
   Knight k = Knight(0, 0, true);
   PieceType kType = k.getType();
   
   // VERIFY
   assertUnit(kType == KNIGHT);
   
}  // TEARDOWN
