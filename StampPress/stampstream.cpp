#include "stampstream.h"
#include <iostream>
using namespace std;


stampstream::stampstream(int r, int c):std::ostream(new stampbuf(r,c)),
  cur_row(0), cur_column(0)
{
  //check constructor of ostream
  //os.redbuf();
}

stampstream::~stampstream()
{
  delete this->rdbuf();
}

std::ostream& endrow(std::ostream& os)
{
  stampbuf* sbp= dynamic_cast<stampbuf*>(os.rdbuf());
  sbp->pubsync();
  sbp->endrowhelper();
  sbp->set_column(0);
  return os;
}

std::ostream& operator<<(std::ostream& os, const row& r)
{
 stampbuf* sbp= dynamic_cast<stampbuf*>(os.rdbuf()); // downcasting
 sbp->pubsync();                            //pubsync will call sync
 sbp->set_row(r.get_row());
 sbp->set_column(0);
 return os;
}
