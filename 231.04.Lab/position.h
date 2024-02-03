/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE  = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position & rhs) { this->colRow = rhs.colRow; }
   Position() : colRow(0x99)      {              }
   bool isInvalid() const;
   bool isValid()   const;
   void setValid()                { colRow = 0x00; }
   void setInvalid()              { colRow = 0xff; }
   bool operator <  (const Position & rhs) const { return this->colRow < rhs.colRow;  }
   bool operator == (const Position & rhs) const { return this->colRow == rhs.colRow; }
   bool operator != (const Position & rhs) const { return this->colRow != rhs.colRow; }
   const Position & operator =  (const Position & rhs)  { colRow = rhs.colRow; return *this; }
   
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow((uint8_t)(location % 8 * 16 + location / 8)) { }
   int getLocation() const;
   void setLocation(int location);

   
   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow((uint8_t)(c * 16 + r)) {}
   virtual int getCol() const;
   virtual int getRow() const;
   void setRow(int r);
   void setCol(int c);
   void set(int c, int r);

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"
   
   Position(const char * s);
   const Position & operator =  (const char     * rhs);
   const Position & operator =  (const string   & rhs);

   
   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const { return 99; }
   int getY()   const { return 99; }
   void setXY(double x, double y) { }
   double getSquareWidth()  const { return 99; }
   double getSquareHeight() const { return 99; }
   void setSquareWidth (double width )  {  }
   void setSquareHeight(double height)  {  }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position & rhs, const Delta & delta) : colRow(-1) {  }
   void adjustRow(int dRow)   { }
   void adjustCol(int dCol)   { }
   const Position & operator += (const Delta & rhs);
   Position operator + (const Delta & rhs) const;

private:
   void set(uint8_t colRowNew) { colRow = colRowNew; }
   
   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      
