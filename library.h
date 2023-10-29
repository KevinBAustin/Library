#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

class library {
 private:

 public:

  ~library();
  void push_front(std::string Title, std::string AuthorName);
  void push_back(std::string Title, std::string AuthorName);
  void read_from_file(std::string filename);
  void write_to_file(std::string filename);
  void insert_sorted(std::string Title, std::string AuthorName);
  std::string find_author(std::string Title);
  std::string find_album(std::string AuthorName);
  void print();
  void Delete(std::string Title, std::string AuthorName);
};
#endif //LIBRARY_H
