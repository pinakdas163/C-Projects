#include "stringSub.h"
#include "unistd.h"
#include <iostream>

stringSub::stringSub(string oldString, string newString, string file): oldStr(oldString),
  newStr(newString), fileName(file), stream(file), string_index(0), search_get(false),
  replace_get(false), oldStrLnth(0), newStrLnth(0), actualLength(0)
{
}

stringSub::~stringSub()
{
}

stringSub& stringSub::get(char& ch)
{
  if(newStrLnth>0)
  {
    ch=newStr[actualLength-newStrLnth];
    newStrLnth--;
    replace_get=true;
  }
  else if (oldStrLnth>0) {
    ch=oldStr[actualLength-oldStrLnth];
    oldStrLnth--;
    search_get=true;
  }
  else
  {
    stream.getChar(ch);
    replace_get=false;
    search_get=false;
  }
  return *this;
}

void stringSub::put(char ch)
{
  stream.putChar(ch);
}

bool stringSub::eof()
{
  return stream.myEof();
}

bool stringSub::currently_replacing()
{
  return replace_get;
}
void stringSub::found_partial_match(int noCharMatch,char& ch)
{
  if(search_get==true)
  {
    string_index++;
  }
  else
  {
    string_index=0;
    stream.custPush_front(ch);
    actualLength=noCharMatch;
  }
  put(oldStr[string_index]);
  oldStrLnth=(actualLength-1)-string_index;
}

void stringSub::matched_searched_string() {
  newStrLnth=newStr.length();
  actualLength=newStr.length();
}
