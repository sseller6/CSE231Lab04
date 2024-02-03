/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
   // SETUP

   // EXERCISE
   Move move;

   // VERIFY
   assertUnit(move.source == Position());
   assertUnit(move.dest == Position());
   assertUnit(move.promote == INVALID);
   assertUnit(move.capture == INVALID);
   assertUnit(move.moveType == move.MOVE_ERROR);
   assertUnit(move.isWhite == false);
   assertUnit(move.text == "");


} // TEARDOWN

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =2,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // SETUP
   
   // EXERCISE
   Move move = Move("e5e6");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 36);
   assertUnit(move.dest.getLocation() == 44);
   assertUnit(move.promote == SPACE);
   assertUnit(move.capture == SPACE);
   assertUnit(move.moveType == move.MOVE);
   assertUnit(move.isWhite == false);
   assertUnit(move.text == "e5e6");
   
} // TEARDOWN


 /*************************************
  * READ simple move
  * Input:  e5d6
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move = Move("e5d6");
   
   // VERIFY
   assertUnit(move.getSource() == 36);
   assertUnit(move.getDestination() == 43);
   assertUnit(move.getMoveType() == move.MOVE);
   
} // TEARDOWN

 /*************************************
  * READ capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move = Move("e5d6r");
   
   // VERIFY
   assertUnit(move.getSource() == 36);
   assertUnit(move.getDestination() == 43);
   assertUnit(move.getMoveType() == move.MOVE);
   assertUnit(move.getCapture() == ROOK);
   
} // TEARDOWN

 /*************************************
  * READ enpassant move
  * Input:  e5d6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::read_enpassant()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move = Move("e5d6E");
   
   // VERIFY
   assertUnit(move.getSource() == 36);
   assertUnit(move.getDestination() == 43);
   assertUnit(move.getMoveType() == move.ENPASSANT);
   
} // TEARDOWN

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move = Move("e1g1c");
   
   // VERIFY
   assertUnit(move.getSource() == 4);
   assertUnit(move.getDestination() == 6);
   assertUnit(move.getMoveType() == move.CASTLE_KING);
   
} // TEARDOWN


 /*************************************
  * READ queen side castle
  * Input:  e1g1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move = Move("e1c1C");
   
   // VERIFY
   assertUnit(move.getSource() == 4);
   assertUnit(move.getDestination() == 2);
   assertUnit(move.getMoveType() == move.CASTLE_QUEEN);
   
} // TEARDOWN

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,0
  *         dest  =2,0
  **************************************/
void TestMove::assign_simple()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move.assignMove("e5e6");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 36);
   assertUnit(move.dest.getLocation() == 44);
   
} // TEARDOWN

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move.assignMove("e5d6r");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 36);
   assertUnit(move.dest.getLocation() == 43);
   assertUnit(move.moveType == move.MOVE);
   assertUnit(move.capture == ROOK);
   
} // TEARDOWN

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5d6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move.assignMove("e5d6E");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 36);
   assertUnit(move.dest.getLocation() == 43);
   assertUnit(move.moveType == move.ENPASSANT);
   
} // TEARDOWN

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move.assignMove("e1g1c");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 4);
   assertUnit(move.dest.getLocation() == 6);
   assertUnit(move.moveType == move.CASTLE_KING);
   
} // TEARDOWN

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1g1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
   // SETUP
   Move move;
   
   // EXERCISE
   move.assignMove("e1c1C");
   
   // VERIFY
   assertUnit(move.source.getLocation() == 4);
   assertUnit(move.dest.getLocation() == 2);
   assertUnit(move.moveType == move.CASTLE_QUEEN);
   
} // TEARDOWN

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Input:  e5e6
  **************************************/
void TestMove::getText_simple()
{
   // SETUP
   Position posSrc(36);
   Position posDes(44);
   Move move = Move(posSrc, posDes, move.MOVE);

   // EXERCISE
   string text = move.getText();
   
   // VERIFY
   assertUnit(text == "e5e6");
   
} // TEARDOWN

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Input:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   // SETUP
   Position posSrc(36);
   Position posDes(44);
   Move move = Move(posSrc, posDes, move.MOVE, ROOK);
   
   // EXERCISE
   string text = move.getText();
   
   // VERIFY
   assertUnit(text == "e5e6r");
   
} // TEARDOWN

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =4,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Input:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   // SETUP
   Position posSrc = Position(36);
   Position posDes = Position(45);
   Move move = Move(posSrc, posDes, move.ENPASSANT, PAWN);
   
   // EXERCISE
   string text= move.getText();
   
   // VERIFY
   assertUnit(text == "e5f6E");
   
} // TEARDOWN

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Input:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   // SETUP
   Position posSrc = Position(4);
   Position posDes = Position(6);
   Move move = Move(posSrc, posDes, move.CASTLE_KING);
   
   // EXERCISE
   string text = move.getText();
   
   // VERIFY
   assertUnit(text == "e1g1c");
   
} // TEARDOWN

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  * Input:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   // SETUP
   Position posSrc = Position(4);
   Position posDes = Position(2);
   Move move = Move(posSrc, posDes, move.CASTLE_QUEEN);
   
   // EXERCISE
   string text = move.getText();
   
   // VERIFY
   assertUnit(text == "e1c1C");
   
} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   // SETUP
   Move move;
   PieceType s;
   char s_char;

   // EXERCISE
   s = SPACE;
   s_char = move.letterFromPieceType(s);

   // VERIFY
   assertUnit(s_char == ' ');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // SETUP
   Move move;
   PieceType p;
   char p_char;

   // EXERCISE
   p = PAWN;
   p_char = move.letterFromPieceType(p);

   // VERIFY
   assertUnit(p_char == 'p');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // SETUP
   Move move;
   PieceType b;
   char b_char;

   // EXERCISE
   b = BISHOP;
   b_char = move.letterFromPieceType(b);

   // VERIFY
   assertUnit(b_char == 'b');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
   // SETUP
   Move move;
   PieceType n;
   char n_char;

   // EXERCISE
   n = KNIGHT;
   n_char = move.letterFromPieceType(n);

   // VERIFY
   assertUnit(n_char == 'n');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
   // SETUP
   Move move;
   PieceType r;
   char r_char;

   // EXERCISE
   r = ROOK;
   r_char = move.letterFromPieceType(r);

   // VERIFY
   assertUnit(r_char == 'r');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
   // SETUP
   Move move;
   PieceType q;
   char q_char;

   // EXERCISE
   q = QUEEN;
   q_char = move.letterFromPieceType(q);

   // VERIFY
   assertUnit(q_char == 'q');

} // TEARDOWN

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
   // SETUP
   Move move;
   PieceType k;
   char k_char;

   // EXERCISE
   k = KING;
   k_char = move.letterFromPieceType(k);

   // VERIFY
   assertUnit(k_char == 'k');

} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // SETUP
   Move move;
   char p;
   PieceType p_pt;
   
   // EXERCISE
   p = 'p';
   p_pt = move.pieceTypeFromLetter(p);

   // VERIFY
   assertUnit(p_pt = PAWN);
} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // SETUP
   Move move;
   char b;
   PieceType b_pt;

   // EXERCISE
   b = 'b';
   b_pt = move.pieceTypeFromLetter(b);

   // VERIFY
   assertUnit(b_pt = BISHOP);
} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Input:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // SETUP
   Move move;
   char n;
   PieceType n_pt;

   // EXERCISE
   n = 'n';
   n_pt = move.pieceTypeFromLetter(n);

   // VERIFY
   assertUnit(n_pt = KNIGHT);
} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Input:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // SETUP
   Move move;
   char r;
   PieceType r_pt;

   // EXERCISE
   r = 'r';
   r_pt = move.pieceTypeFromLetter(r);

   // VERIFY
   assertUnit(r_pt = ROOK);
} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Input:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // SETUP
   Move move;
   char q;
   PieceType q_pt;

   // EXERCISE
   q = 'q';
   q_pt = move.pieceTypeFromLetter(q);

   // VERIFY
   assertUnit(q_pt = QUEEN);
} // TEARDOWN

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Input:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   // SETUP
   Move move;
   char k;
   PieceType k_pt;

   // EXERCISE
   k = 'k';
   k_pt = move.pieceTypeFromLetter(k);

   // VERIFY
   assertUnit(k_pt = KING);
} // TEARDOWN
