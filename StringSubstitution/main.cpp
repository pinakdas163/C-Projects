#include<iostream>
#include<fstream>
#include<cstdlib>
#include "stringSub.h"
using namespace std;

int main(int argc, const char* argv[])
{
  stringSub str(argv[1], argv[2], argv[3]);
  int noCharMatch=0;
  string search_word=argv[1];
  string replace_word=argv[2];
  char temp;
    while(!str.get(temp).eof() )
    {
      if(!str.currently_replacing() && temp==search_word[noCharMatch])
      {
        noCharMatch++;
        if(noCharMatch<search_word.length())
        {
          continue;
        }
      }
      if(noCharMatch==search_word.length())
      {
        str.matched_searched_string();
      }
      else if(noCharMatch>0)
      {
        str.found_partial_match(noCharMatch,temp);
      }
      else {
          str.put(temp);
      }
      noCharMatch=0;
    }
  return 0;
}
