#include "Film.h"
#include <iostream>
using namespace std;

Film::Film(string callNumber, string title, string subjects,
  string director, string notes, string year): Media(callNumber, title, subjects),
  m_director(director), m_notes(notes), m_year(year)
  {

  }

bool Film::compareByOthers(const string& others) const
{
  if(m_notes.find(others)!=std::string::npos || m_director.find(others)!=std::string::npos||
    m_year.find(others)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}
void Film::display() const
{
  Media::display();
  cout<<"Director: "<<m_director<<endl;
  cout<<"Notes: "<<m_notes<<endl;
  cout<<"Year: "<<m_year<<endl;
  cout<<endl;
}

Film::~Film()
{

}
