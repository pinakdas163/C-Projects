#ifndef BOOK_H
#define BOOK_H
#include<string>
#include "Media.h"

class Book : public Media{
  public:
    Book(std::string callNumber, std::string title, std::string subjects, std::string author,
      std::string description, std::string publisher, std::string city, std::string year,
        std::string series, std::string notes);
    bool compareByOthers(const std::string& others) const;
    void display() const;
    ~Book();
  private:
    std::string m_author;
    std::string m_description;
    std::string m_publisher;
    std::string m_city;
    std::string m_year;
    std::string m_series;
    std::string m_notes;
};

#endif
