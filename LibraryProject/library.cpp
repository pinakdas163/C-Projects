#include<iostream>
using namespace std;
#include <vector>
#include "CardCatalog.h"

void displayMenu()
{
  cout<<"Type title to search by title"<<endl;
  cout<<"Type subject to search by subject"<<endl;
  cout<<"Type callnumber to search by call number"<<endl;
  cout<<"Type other for searching by others"<<endl;
  cout<<"Type quit to quit"<<endl;
  cout<<"Enter your choice"<<endl;
}

int main()
{
  CardCatalog cc;
  string choice, title, subject, callNo, other;
  displayMenu();
  while(cin>>choice)
  {
    int books=0;
    int videos=0;
    int periodic=0;
    int films=0;
    std::vector<Media*> results;
    if(choice=="title"){
        cout<<"Enter title:";
        cin>>title;
        results= cc.searchByTitle(title);
        //cout<<"Results found: "<<results.size()<<endl;
        cc.display(results);
    }
    else if(choice=="subject")
    {
        cout<<"Enter subject:";
        cin>>subject;
        results= cc.searchBySubject(subject);
        //cout<<"Results found: "<<results.size()<<endl;
        cc.display(results);
      }
    else if(choice=="callnumber")
    {
        cout<<"Enter call number:";
        cin>>callNo;
        results= cc.searchByCallNumber(callNo);
        //cout<<"Results found: "<<results.size()<<endl;
        cc.display(results);
    }
    else if(choice=="other")
    {
        cout<<"Enter your string:";
        cin>>other;
        results=cc.searchByOther(other);
        //cout<<"Results found: "<<results.size()<<endl;
        cc.display(results);
    }
    else if(choice=="quit")
    {
      return 0;
    }
    else{
      cout<<"Invalid choice"<<endl;
    }
    cout<<endl;
    for(unsigned int i=0;i<results.size();i++)
    {

      if(dynamic_cast<Book*>(results[i]))
      {
        books++;
      }
      else if(dynamic_cast<Periodical*>(results[i]))
      {
        periodic++;
      }
      else if(dynamic_cast<Video*>(results[i]))
      {
        videos++;
      }
      else if(dynamic_cast<Film*>(results[i]))
      {
        films++;
      }
    }
    if(choice=="title" || choice=="callnumber" || choice=="subject" || choice=="other")
    {
      cout<<"Results found: "<<results.size()<<endl;
      cout<<"Book: "<<books<<endl;
      cout<<"Periodical: "<<periodic<<endl;
      cout<<"Video: "<<videos<<endl;
      cout<<"Film: "<<films<<endl;
      results.clear();
      cout<<endl;
    }
    displayMenu();
  }

  return 0;
}
