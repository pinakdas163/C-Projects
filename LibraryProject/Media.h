#ifndef MEDIA_H
#define MEDIA_H
#include <string>

class Media{
  public:
    Media(std::string callNumber, std::string title, std::string subjects);
    bool compareByTitle(const std::string& title) const;
    bool compareBySubject(const std::string& subject) const;
    bool compareBycallNumber(const std::string& callNumber) const;
    virtual bool compareByOthers(const std::string& others) const=0;
    virtual void display() const;
    virtual ~Media();
  private:
    std::string m_callNumber;
    std::string m_title;
    std::string m_subjects;
};

#endif
