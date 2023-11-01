/**
 * @file library.h
 * @author Kevin Austin
 * @date 2023-10-31
 * @brief Library Class Header
 * 
 * Defines variables and functions to be used by the library class 
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <iostream>
#include <string>
#include <list>

class library {
 private:
  //A list that holds all of the books for the library
  std::list<book> books;
 public:

/**
 * Takes data and puts it at the front of a list
 *
 * @param std::string Title String containing Books Title
 * @param std::string AuthorName String conaining Books Writer
 * @param int Pages Integer containing Books page number
 * @param std::string isbn String containing books isbn
 * @param float Coverprice float containing books price
 * @param int Year integer containing books Release date
 * @pre list has been made
 * @return void 
 * @post list has been changed
 * 
 */
  void push_front(std::string Title, std::string AuthorName, int Pages, std::string isbn, float Coverprice, int Year);

/**
 * Takes data and puts it at the back of a list
 *
 * @param std::string Title String containing Books Title
 * @param std::string AuthorName String conaining Books Writer
 * @param int Pages Integer containing Books page number
 * @param std::string isbn String containing books isbn
 * @param float Coverprice float containing books price
 * @param int Year integer containing books Release date
 * @pre list has been made
 * @return void 
 * @post list has been changed
 * 
 */
  void push_back(std::string Title, std::string AuthorName, int Pages, std::string isbn, float Coverprice, int Year);

/**
 * Reads a document for information and puts it into a list
 *
 * @param std::string filename The file to be read's name
 * @pre 
 * @return void 
 * @post list has been made
 * 
 */
  void read_from_file(std::string filename);

/**
 * writes currently held list to file given
 *
 * @param std::string filename file to be written to
 * @pre 
 * @return void 
 * @post file has been created/changed
 * 
 */
  void write_to_file(std::string filename);

/**
 * inserts given data into the list alphabetically by author's firstname
 *
 * @param std::string Title Books title
 * @param std::string AuthorName books writer
 * @param int Pages books page count
 * @param std::string isbn books isbn
 * @param float Coverprice books price
 * @param int Year books release date
 * @pre list has been made
 * @return void 
 * @post list had been changed
 * 
 */
  void insert_sorted(std::string Title, std::string AuthorName, int Pages, std::string isbn, float Coverprice, int Year);

/**
 * Finds all books written by author
 *
 * @param std::string AuthorName Author to search books for
 * @pre list has been made
 * @return std::string books made by author
 * @post returns books made by author
 * 
 */
  std::string find_author(std::string AuthorName);

/**
 * Finds all books and info about those books written by given author
 *
 * @param std::string AuthorName Author to look up info for
 * @pre list has been made
 * @return std::string returns info about author's books
 * @post returns info about author's books
 * 
 */
  std::string find_album(std::string AuthorName);

/**
 * prints library
 *
 * @pre list has been made
 * @return void 
 * @post 
 * 
 */
  void print();

/**
 * Deletes Author's book
 *
 * @param std::string Title Book to be deleted
 * @param std::string AuthorName Author of said book
 * @pre list has been made
 * @return void 
 * @post list has been changed
 * 
 */
  void Delete(std::string Title, std::string AuthorName);
};
#endif //LIBRARY_H
