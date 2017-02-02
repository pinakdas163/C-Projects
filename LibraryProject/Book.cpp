#include"Book.h"
#include<iostream>
using namespace std;

Book::Book(string callNumber, string title, string subjects, string author,
  string description, string publisher, string city, string year,
    string series, string notes): Media(callNumber, title, subjects), m_author(author),
    m_description(description), m_publisher(publisher),
    m_city(city), m_year(year), m_series(series), m_notes(notes)
{}

Book::~Book()
{}

bool Book::compareByOthers(const string& others) const
{
  if(m_description.find(others)!=std::string::npos || m_notes.find(others)!=std::string::npos||
    m_year.find(others)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}

void Book::display() const
{
  Media::display();
  cout<<"Author: "<<m_author<<endl;
  cout<<"Description: "<<m_description<<endl;
  cout<<"Publisher: "<<m_publisher<<endl;
  cout<<"City: "<<m_city<<endl;
  cout<<"Year: "<<m_year<<endl;
  cout<<"Series: "<<m_series<<endl;
  cout<<"Notes: "<<m_notes<<endl;
  cout<<endl;
}
