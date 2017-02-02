#ifndef CUSTSTREAM_H
#define CUSTSTREAM_H
#include"TrackingDeque.h"
#include<string>
#include<fstream>
using namespace std;

class custStream:public fstream
{
  public:
    custStream(string fileN);
    custStream& getChar(char& c);
    bool myEof();
    void putChar(char c);
    istream& seekg(streampos gp);
    ostream& seekp(streampos pp);
    ~custStream();
    void custPush_front(char& c);
  private:
    TrackingDeque<char> deq;
    string filename;
    std::streampos getpos;
    std::streampos putpos;
    char temp;
    bool eoF;
};

#endif
