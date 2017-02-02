#include "Media.h"
#include <iostream>
using namespace std;

Media::Media(string callNumber, string title, string subjects):m_callNumber(callNumber),
  m_title(title), m_subjects(subjects)
{}

bool Media::compareByTitle(const string& title) const
{
  if(m_title.find(title)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}

bool Media::compareBySubject(const string& subject) const
{
  if(m_subjects.find(subject)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}

bool Media::compareBycallNumber(const string& callNumber) const
{
  if(m_callNumber.find(callNumber)!=std::string::npos)
  {
    return true;
  }
  else
    return false;
}

void Media::display() const
{
  cout<<"Call Number: "<<m_callNumber<<endl;
  cout<<"Title: "<<m_title<<endl;
  cout<<"subjects: "<<m_subjects<<endl;
}

Media::~Media()
{}
