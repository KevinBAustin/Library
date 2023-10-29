#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

struct book {
  std::string Title;
  std::string AuthorName;
  int Pages;
  std::string isbn;
  float Coverprice;
  int Year;
};
#endif //BOOK_H
