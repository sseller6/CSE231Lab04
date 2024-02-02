/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    <your name here>
 * Summary
 *    test the Move class
 ************************************************************************/

#pragma once

#include "unitTest.h"

 /***************************************************
  * MOVE TEST
  * Test the Move class
  ***************************************************/
class TestMove : public UnitTest
{
public:
   void run() 
   {
      // Constructor
      constructor_default();

      // Assign
      read_simple();
      read_capture();
      read_enpassant();
      read_castleKing();
      read_castleQueen();
      constructString_simple();
      assign_simple();
      assign_capture();
      assign_enpassant();
      assign_castleKing();
      assign_castleQueen();

      // Get Text
      getText_simple();
      getText_capture();
      getText_enpassant();
      getText_castleKing();
      getText_castleQueen();

      // Letter from Piece Type
      letterFromPieceType_space();
      letterFromPieceType_pawn();
      letterFromPieceType_bishop();
      letterFromPieceType_knight();
      letterFromPieceType_rook();
      letterFromPieceType_queen();
      letterFromPieceType_king();

      // Piece Type from Letter
      pieceTypeFromLetter_pawn();
      pieceTypeFromLetter_knight();
      pieceTypeFromLetter_bishop();
      pieceTypeFromLetter_rook();
      pieceTypeFromLetter_king();
      pieceTypeFromLetter_queen();

      report("Move");
   }
private:

   void constructor_default();

   void read_simple();
   void read_capture();
   void read_enpassant();
   void read_castleKing();
   void read_castleQueen();

   void constructString_simple();
   void assign_simple();
   void assign_capture();
   void assign_enpassant();
   void assign_castleKing();
   void assign_castleQueen();

   void getText_simple();
   void getText_capture();
   void getText_enpassant();
   void getText_castleKing();
   void getText_castleQueen();

   void letterFromPieceType_space();
   void letterFromPieceType_pawn();
   void letterFromPieceType_bishop();
   void letterFromPieceType_knight();
   void letterFromPieceType_rook();
   void letterFromPieceType_queen();
   void letterFromPieceType_king();

   void pieceTypeFromLetter_pawn();
   void pieceTypeFromLetter_knight();
   void pieceTypeFromLetter_bishop();
   void pieceTypeFromLetter_rook();
   void pieceTypeFromLetter_king();
   void pieceTypeFromLetter_queen();

};
