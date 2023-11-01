/**
 * @file library.cpp
 * @author Matthew Lannom
 * @date 2023-11-01
 * @brief Library (code implementations)
 * 
 * This file contains the code for all methods in the library class.
 */

#include "library.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void library::push_front(string Title, string AuthorName, int Pages, string isbn, float Coverprice, int Year){
  book temp;
  //Setting temp's info equal to the parameters' info
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  temp.Pages = Pages;
  temp.isbn = isbn;
  temp.Coverprice = Coverprice;
  temp.Year = Year;
  books.push_front(temp); //Inserting temp at the front of the list
}

void library::push_back(string Title, string AuthorName, int Pages, string isbn, float Coverprice, int Year){
  book temp;
  //Setting temp's info equal to the parameters' info
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  temp.Pages = Pages;
  temp.isbn = isbn;
  temp.Coverprice = Coverprice;
  temp.Year = Year;
  books.push_back(temp); //Inserting temp at the back of the list
}

void library::read_from_file(string filename){
  ifstream inFile;
  inFile.open(filename); //Opening file
  string Title, AuthorName, isbn;
  int Pages, Year;
  float Coverprice;
  //Priming read
  getline(inFile, Title); //Reading in book title
  getline(inFile, AuthorName); //Reading in author name
  inFile >> Pages; //Reading in number of pages
  inFile.get();
  getline(inFile, isbn); //Reading in isbn number
  inFile >> Coverprice >> Year; //Reading in price and year
  inFile.get();
  while(inFile){
    insert_sorted(Title, AuthorName, Pages, isbn, Coverprice, Year); //Inserting the book into the list
    getline(inFile, Title); //Reading in book title
    getline(inFile, AuthorName); //Reading in author name
    inFile >> Pages; //Reading in number of pages
    inFile.get();
    getline(inFile, isbn); //Reading in isbn number
    inFile >> Coverprice >> Year; //Reading in price and year
    inFile.get();
  }
  inFile.close(); //Closing file
}

void library::write_to_file(string filename){
  ofstream outFile;
  outFile.open(filename); //Opening file
  
  list<book>::iterator it;
  
  for(it = books.begin(); it != books.end(); it++){
    outFile << it -> Title << endl; //Writing title to file
    outFile << it -> AuthorName << endl; //Writing author name to file
    outFile << it -> Pages << endl; //Writing number of pages to file
    outFile << it -> isbn << endl; //Writing isbn to file
    outFile << it -> Coverprice << endl; //Writing price to file
    outFile << it -> Year << endl; //Writing year to file
  }
  outFile.close();
}

void library::insert_sorted(string Title, string AuthorName, int Pages, string isbn, float Coverprice, int Year){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  temp.Pages = Pages;
  temp.isbn = isbn;
  temp.Coverprice = Coverprice;
  temp.Year = Year;
  
  list<book>::iterator it;
  
  if(books.empty()){
    books.push_front(temp); //Inserting temp at the front if the list is empty
  }
  else{
    it = books.begin(); //Setting iterator equal to the front of the list
    while(it != books.end() && it -> AuthorName < AuthorName){
      it++; //Walking through the list
    }
    books.insert(it, temp); //Inserting temp at the position of the iterator
  }
}

string library::find_author(string AuthorName){
  string booksByThisAuthor = "";
  
  list<book>::iterator it;
  
  if(books.empty()){
    booksByThisAuthor = "This author could not be found.";
    return booksByThisAuthor;
  }
  for(it = books.begin(); it != books.end(); it++){
    if(it -> AuthorName == AuthorName){
      booksByThisAuthor += it->Title; //Adding book title to the string
      booksByThisAuthor += "\n";
    }
  }
  if(booksByThisAuthor == ""){
    booksByThisAuthor = "This author could not be found.";
    return booksByThisAuthor;
  }
  return booksByThisAuthor;
}

string library::find_album(string AuthorName){
  string info = "";
  
  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++){
    if(it->AuthorName == AuthorName){
      info += "\nBook Title: ";
      info += it->Title; //Adding book title to info string
      info += "\nPages: ";
      info += to_string(it->Pages); //Adding pages to info string
      info += "\nisbn: ";
      info += it->isbn; //Adding isbn to info string
      info += "\nPrice: ";
      info += to_string(it->Coverprice); //Adding price to info string
      info += "\nYear released: "; 
      info += to_string(it->Year); //Adding year to info string
      info += "\n";
    }
  }
  if(info == ""){
    info = "This author could not be found.";
  }
  return info;
}

void library::print(){
  list<book>::iterator it;
  if(books.empty()){
    cout << "There are no books in the library." << endl; //Letting user know that the list is empty
    cout << endl;
  }
  else {
    for(it = books.begin(); it != books.end(); it++) {
      cout << "List item: " << it -> AuthorName << " - " << it -> Title << endl << "Pages: " << it -> Pages << endl << "isbn: " << it -> isbn << endl << "Price: " << it -> Coverprice << endl << "Year: " << it -> Year << endl; //Printing list
      cout << endl;
    }
    cout << endl;
  }
}

void library::Delete(string Title, string AuthorName){
  list<book>::iterator it;
  
  it = books.begin(); //Setting iterator equal to the front of the list
  while(it != books.end() && it -> Title != Title) {
    it++; //Walking through the list
  }
  if(it -> AuthorName != AuthorName){
    cout << "Book not found." << endl; //Letting user know that the book is not in the list
    cout << endl;
  }
  else {
    books.erase(it); //Deleting the book at the spot of the iterator
    cout << Title << " has been deleted." << endl;
    cout << endl;
  }
}
