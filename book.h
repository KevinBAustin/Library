/**
 * @file book.h
 * @author Matthew Lannom
 * @date 2023-11-01
 * @brief Book struct
 * 
 * This file contains the definition of book
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>


/**
 * This struct represents a book, and so it contains all data associated with the book
 *
 * @class book book.h "Library/book.h"
 * @brief Book struct
 *
 */
struct book {
  std::string Title; //The title of the book
  std::string AuthorName; //The name of the book's author
  int Pages; //The number of pages the book has
  std::string isbn; //The isbn number of the book
  float Coverprice; //The price of the book
  int Year; //The year in which the book was released/published
};
#endif //BOOK_H
