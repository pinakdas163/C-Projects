#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include "Media.h"

class Video : public Media{
  public:
    Video(std::string callNumber, std::string title, std::string subjects,
      std::string description, std::string distributor, std::string notes,
        std::string series, std::string label);
    bool compareByOthers(const std::string& others) const;
    void display() const;
    ~Video();
  private:
    std::string m_description;
    std::string m_distributor;
    std::string m_notes;
    std::string m_series;
    std::string m_label;
};

#endif
