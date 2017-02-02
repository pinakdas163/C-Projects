#include "Periodical.h"
#include <iostream>
using namespace std;

Periodical::Periodical(string callNumber, string title, string subjects, string author,
  string description, string publisher, string publishingHistory, string series,
    string notes, string relatedTitles, string otherTitles, string govtDocNo):
    Media(callNumber, title, subjects), m_author(author), m_description(description),
    m_publisher(publisher), m_publishingHistory(publishingHistory), m_series(series),
    m_notes(notes), m_relatedTitles(relatedTitles), m_otherTitles(otherTitles), m_govtDocNo(govtDocNo)
{}

bool Periodical::compareByOthers(const string& others) const
{
  if(m_description.find(others)!=std::string::npos || m_notes.find(others)!=std::string::npos||
    m_series.find(others)!=std::string::npos || m_relatedTitles.find(others)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}

void Periodical::display() const
{
  Media::display();
  cout<<"Author: "<<m_author<<endl;
  cout<<"Description: "<<m_description<<endl;
  cout<<"Publisher: "<<m_publisher<<endl;
  cout<<"Publishing History: "<<m_publishingHistory<<endl;
  cout<<"Series: "<<m_series<<endl;
  cout<<"Notes: "<<m_notes<<endl;
  cout<<"Related Titles: "<<m_relatedTitles<<endl;
  cout<<"Other Titles: "<<m_otherTitles<<endl;
  cout<<"Govt Document Number: "<<m_govtDocNo<<endl;
  cout<<endl;
}
Periodical::~Periodical()
{}
