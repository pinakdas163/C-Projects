#include "custStream.h"
#include <iostream>
#include "unistd.h"
#include "assert.h"
using namespace std;

custStream::custStream(string fileN):getpos(0), putpos(0), eoF(false), filename(fileN)
{
  fstream::open(filename.c_str(),ios::in|ios::out);
}

void custStream::custPush_front(char& c)
{
  deq.push_front(c);
}

istream& custStream::seekg(streampos gp)
{
  assert(gp>=getpos);
  getpos=gp;
  return fstream::seekg(gp);
}

ostream& custStream::seekp(streampos pp)
{
  assert(pp>=putpos);
  putpos=pp;
  return fstream::seekp(pp);
}

custStream& custStream::getChar(char& c)
{
  //int i=0;
  if(!deq.empty())
  {
    c=deq.front();
    deq.pop_front();
  }
  else {
      seekg(getpos);
      fstream::get(c);
      getpos+=1;
    if(fstream::eof())
    {
     eoF=true;
     fstream::clear();
    }
  }
  return *this;
}

void custStream::putChar(char c)
{
  if(putpos==getpos && !eoF)
  {
    char ch='a';
    seekg(getpos);
    fstream::get(ch);
    getpos+=1;
    deq.push_back(ch);
  }
  if(fstream::eof())
  {
    eoF=true;
    fstream::clear();

  }
  fstream::seekp(putpos);
  fstream::put(c);
  putpos+=1;
}

bool custStream::myEof()
{
  if(!deq.empty()) {
    return false;
  } else {
      return eoF;
    }
}

custStream::~custStream()
{
 fstream::close();
 truncate(filename.c_str(),putpos);
}
