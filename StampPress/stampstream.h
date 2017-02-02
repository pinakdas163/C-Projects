#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include <iostream>
#include "stampbuf.h"
#include "row.h"

class stampstream: public std::ostream
{
  public:
    stampstream(int r, int c);
    ~stampstream();
  private:
    int cur_column;
    int cur_row;
};

std::ostream& endrow(std::ostream& os);
std::ostream& operator<<(std::ostream& os, const row& r);

#endif
