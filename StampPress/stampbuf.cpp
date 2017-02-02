#include "stampbuf.h"
#include "stamp.h"
#include <stdexcept>
using namespace stamping_press;

stampbuf :: stampbuf(int cols, int rows)
:current_cols(0), current_rows(0)
{
   buffer_length = cols/2;
   buffer = new char[buffer_length];
   setp(buffer, buffer+buffer_length );
   insert_plate(cols,rows);
}

stampbuf :: ~stampbuf()
{
    sync();
    delete buffer;
   eject_plate();

}

int stampbuf :: sync()
{
  for(char* i = pbase(); i!= pptr(); i++)
  {
    try{
        set_die(*i);
      }
      catch(std::invalid_argument e)
      {
        if(get_die() != *i)
        {
            current_cols++;
            continue;
        }
      }
      try
      {
        stamp(current_cols, current_rows);
      }
      catch(std::exception e)
      {

      }
    current_cols++;
  }
    setp(pbase(), pptr());
    return 0;
}

int stampbuf:: overflow(int c)
{
  sync();
  sputc(c);
  return 0;
}
