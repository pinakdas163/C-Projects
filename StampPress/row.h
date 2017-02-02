#ifndef ROW_H
#define ROW_H
#include <iostream>
using namespace std;

class row{
  public:
    row(int rowVal) {
      cur_row=rowVal;
    }
    int get_row() const{ return cur_row ; }
  private:
    int cur_row;
};



#endif
