#ifndef STAMP_BUFFER_H
#define STAMP_BUFFER_H

#include <iostream>
#include "stamp.h"

class stampbuf : public std::streambuf
{
   private:
     int buffer_length;
     int current_cols, current_rows;
   public:
     char *buffer;
     stampbuf(int cols, int rows);
     ~stampbuf();
     int sync();
     int overflow(int ch);
     void endrowhelper() { current_rows ++; }
     void set_row(int rowp) { current_rows = rowp; }
     void set_column(int colsp) { current_cols = colsp; }
};


#endif
