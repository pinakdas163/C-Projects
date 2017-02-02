#ifndef PERIODICAL_H
#define PERIODICAL_H
#include<string>
#include "Media.h"

class Periodical : public Media{
  public:
    Periodical(std::string callNumber, std::string title, std::string subjects, std::string author,
      std::string description, std::string publisher, std::string publishingHistory, std::string series,
        std::string notes, std::string relatedTitles, std::string otherTitles, std::string govtDocNo);
    bool compareByOthers(const std::string& others) const;
    void display() const;
    ~Periodical();
  private:
    std::string m_author;
    std::string m_description;
    std::string m_publisher;
    std::string m_publishingHistory;
    std::string m_series;
    std::string m_notes;
    std::string m_relatedTitles;
    std::string m_otherTitles;
    std::string m_govtDocNo;
};

#endif
