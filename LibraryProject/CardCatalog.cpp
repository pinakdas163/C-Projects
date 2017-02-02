#include "CardCatalog.h"
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

CardCatalog::CardCatalog()
{
  readBookfile();
  readPeriodicalfile();
  readFilmfile();
  readVideofile();
}

void CardCatalog::readBookfile()
{
  std::ifstream iFile;
  iFile.open("book.txt");
  if(iFile.is_open())
  {
    std::string callNo;
    while(!std::getline(iFile, callNo, '|').eof())
    {
      std::string title, subjects, author, description, publisher, city, year,
        series, notes;
        std::getline(iFile, title, '|');
        std::getline(iFile, subjects, '|');
        std::getline(iFile, author, '|');
        std::getline(iFile, description, '|');
        std::getline(iFile, publisher, '|');
        std::getline(iFile, city, '|');
        std::getline(iFile, year, '|');
        std::getline(iFile, series, '|');
        std::getline(iFile, notes);
        Media * type_book= new Book(callNo, title, subjects, author, description,
          publisher, city, year, series, notes);
          cards.push_back(type_book);
    }
    iFile.close();
  }
  else
  {
    cout<<"Couldn't read from book file"<<endl;
    return;
  }
}

void CardCatalog::readPeriodicalfile()
{
  std::ifstream iFile;
  iFile.open("periodic.txt");
  if(iFile.is_open())
  {
    string callNo;
    while(!std::getline(iFile, callNo, '|').eof())
    {
      string title, subjects, author, description, publisher, publishingHistory,
        series, notes, relatedTitles, otherTitles, govtDocNo;
        std::getline(iFile, title, '|');
        std::getline(iFile, subjects, '|');
        std::getline(iFile, author, '|');
        std::getline(iFile, description, '|');
        std::getline(iFile, publisher, '|');
        std::getline(iFile, publishingHistory, '|');
        std::getline(iFile, series, '|');
        std::getline(iFile, notes, '|');
        std::getline(iFile, relatedTitles, '|');
        std::getline(iFile, otherTitles, '|');
        std::getline(iFile, govtDocNo);
        Media * type_periodic= new Periodical(callNo, title, subjects, author,
          description, publisher, publishingHistory, series, notes, relatedTitles,
          otherTitles, govtDocNo);
          cards.push_back(type_periodic);
    }
    iFile.close();
  }
  else
  {
    cout<<"Couldn't read from periodic file"<<endl;
    return;
  }

}

void CardCatalog::readFilmfile()
{
  std::ifstream iFile;
  iFile.open("film.txt");
  if(iFile.is_open())
  {
    string callNo;
    while(!std::getline(iFile, callNo, '|').eof())
    {
      string title, subjects, author, director, notes, year;
        std::getline(iFile, title, '|');
        std::getline(iFile, subjects, '|');
        std::getline(iFile, director, '|');
        std::getline(iFile, notes, '|');
        std::getline(iFile, year);
        Media * type_film= new Film(callNo, title, subjects, director,
          notes, year);
          cards.push_back(type_film);
    }
    iFile.close();
  }
  else
  {
    cout<<"Couldn't read from film file"<<endl;
    return;
  }
}

void CardCatalog::readVideofile()
{
  std::ifstream iFile;
  iFile.open("video.txt");
  if(iFile.is_open())
  {
    string callNo;
    while(!std::getline(iFile, callNo, '|').eof())
    {
      string title, subjects, description, distributor, notes,
        series, label;
        std::getline(iFile, title, '|');
        std::getline(iFile, subjects, '|');
        std::getline(iFile, description, '|');
        std::getline(iFile, distributor, '|');
        std::getline(iFile, notes, '|');
        std::getline(iFile, series, '|');
        std::getline(iFile, label);
        Media * type_video= new Video(callNo, title, subjects, description, distributor,
          notes,series, label);
          cards.push_back(type_video);
    }
    iFile.close();
  }
  else
  {
    cout<<"Couldn't read from video file"<<endl;
    return;
  }
}

vector<Media*> CardCatalog::searchByTitle(const string& str) const
{
  std::vector<Media*> results;
  int sz=cards.size();
  for(int i=0;i<sz;i++)
  {
    Media* obj=cards[i];
    bool returned=obj->compareByTitle(str);
    if(returned==true)
    {
      results.push_back(obj);
    }
  }
  return results;
}

vector<Media*> CardCatalog::searchByCallNumber(const string& str) const
{
  std::vector<Media*> results;
  int sz=cards.size();
  for(int i=0;i<sz;i++)
  {
    Media* obj=cards[i];
    bool returned=obj->compareBycallNumber(str);
    if(returned==true)
    {
      results.push_back(obj);
    }
  }
  return results;
}
vector<Media*> CardCatalog::searchBySubject(const string& str) const
{
  std::vector<Media*> results;
  int sz=cards.size();
  for(int i=0;i<sz;i++)
  {
    Media* obj=cards[i];
    bool returned=obj->compareBySubject(str);
    if(returned==true)
    {
      results.push_back(obj);
    }
  }
  return results;
}
vector<Media*> CardCatalog::searchByOther(const string& str) const
{
  std::vector<Media*> results;
  int sz=cards.size();
  for(int i=0;i<sz;i++)
  {
    Media* obj=cards[i];
    bool returned=obj->compareByOthers(str);
    if(returned==true)
    {
      results.push_back(obj);
    }
  }
  return results;
}

void CardCatalog::display(const vector<Media*> &results) const
{
  for(unsigned int i=0;i<results.size();i++)
  {
    results[i]->display();
  }
}

CardCatalog::~CardCatalog()
{
  int sz=cards.size();
  for(int i=0;i<sz;i++)
  {
    delete cards[i];
  }
  cards.clear();
}
