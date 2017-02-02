#ifndef FILM_H
#define FILM_H
#include<string>
#include "Media.h"

class Film : public Media{
  public:
    Film(std::string callNumber, std::string title, std::string subjects,
      std::string director, std::string notes, std::string year);
    bool compareByOthers(const std::string& others) const;
    void display() const;
    ~Film();
  private:
    std::string m_director;
    std::string m_notes;
    std::string m_year;
};

#endif
