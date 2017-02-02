#ifndef STRINGSUB_H
#define STRINGSUB_H

#include "TrackingDeque.h"
#include "custStream.h"
#include <string>

class stringSub
{
   private:
      custStream stream;
      string oldStr;
      string newStr;
      string fileName;
      int string_index;
      bool replace_get;
      bool search_get;
      int oldStrLnth;
      int actualLength;
      int newStrLnth;
   public:
      stringSub& get(char& ch);
      void put(char ch);
      bool eof();
      stringSub(std::string , std::string , std::string);
      ~stringSub();
      bool currently_replacing();
      void found_partial_match(int ,char& );
      void matched_searched_string();
};
#endif
