#ifndef CARDCATALOG_H
#define CARDCATALOG_H
#include <string>
#include <vector>
#include "Media.h"
#include "Book.h"
#include "Periodical.h"
#include "Film.h"
#include "Video.h"

class CardCatalog
{
  public:
    CardCatalog();
    std::vector<Media*> searchByTitle(const std::string& str) const;
    std::vector<Media*> searchByCallNumber(const std::string& str) const;
    std::vector<Media*> searchBySubject(const std::string& str) const;
    std::vector<Media*> searchByOther(const std::string& str) const;
    void display(const std::vector<Media*> &results) const;
    ~CardCatalog();
  private:
    std::vector<Media*> cards;
    void readBookfile();
    void readPeriodicalfile();
    void readFilmfile();
    void readVideofile();
};

#endif
