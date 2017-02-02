#include"Video.h"
#include<iostream>
using namespace std;

Video::Video(string callNumber, string title, string subjects,
  string description, string distributor, string notes,
    string series, string label): Media(callNumber, title, subjects), m_description(description),
    m_distributor(distributor), m_notes(notes), m_series(series), m_label(label)
{}

bool Video::compareByOthers(const string& others) const
{
  if(m_description.find(others)!=std::string::npos || m_notes.find(others)!=std::string::npos||
    m_distributor.find(others)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}
void Video::display() const
{
  Media::display();
  cout<<"Description: "<<m_description<<endl;
  cout<<"Distributor: "<<m_distributor<<endl;
  cout<<"Notes: "<<m_notes<<endl;
  cout<<"Series: "<<m_series<<endl;
  cout<<"Label: "<<m_label<<endl;
  cout<<endl;
}

Video::~Video()
{
}
