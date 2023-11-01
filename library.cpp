#include "library.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <list>
#include <fstream>

using namespace std;

void library::push_front(string Title, string AuthorName, int Pages, string isbn, float Coverprice, int Year){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  temp.Pages = Pages;
  temp.isbn = isbn;
  temp.Coverprice = Coverprice;
  temp.Year = Year;
  books.push_front(temp);
}

void library::push_back(string Title, string AuthorName, int Pages, string isbn, float Coverprice, int Year){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  temp.Pages = Pages;
  temp.isbn = isbn;
  temp.Coverprice = Coverprice;
  temp.Year = Year;
  books.push_back(temp);
}

void library::read_from_file(string filename){
  ifstream inFile;
  inFile.open(filename);
  string Title, AuthorName, isbn;
  int Pages, Year;
  float Coverprice;
  getline(inFile, Title);
  getline(inFile, AuthorName);
  inFile >> Pages >> isbn >> Coverprice >> Year;
  inFile.get();

  while(inFile){
    insert_sorted(Title, AuthorName, Pages, isbn, Coverprice, Year);
    getline(inFile, Title);
    getline(inFile, AuthorName);
    inFile >> Pages >> isbn >> Coverprice >> Year;
    inFile.get();
  }

  inFile.close();
}

void library::write_to_file(string filename){
  ofstream outFile;
  outFile.open(filename);

  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++){
    outFile << it -> Title << endl;
    outFile << it -> AuthorName << endl;
    outFile << it -> Pages << endl;
    outFile << it -> isbn << endl;
    outFile << it -> Coverprice << endl;
    outFile << it -> Year << endl;
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
    books.push_front(temp);
  }
  else{
    it = books.begin();
    while(it != books.end() && it -> AuthorName < AuthorName){
      it++;
    }
    books.insert(it, temp);
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
      booksByThisAuthor += it->Title;
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
      info += it->Title;
      info += "\nPages: ";
      info += to_string(it->Pages);
      info += "\nisbn: ";
      info += it->isbn;
      info += "\nPrice: ";
      info += to_string(it->Coverprice);
      info += "\nYear released: ";
      info += to_string(it->Year);
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
    cout << "There are no books in the library." << endl;
    cout << endl;
  }
  else {
    for(it = books.begin(); it != books.end(); it++) {
      cout << "List item: " << it -> AuthorName << " - " << it -> Title << " Pages: " << it -> Pages << " isbn: " << it -> isbn << " Price: " << it -> Coverprice << " Year: " << it -> Year <<  endl;
    }
    cout << endl;
  }
}

void library::Delete(string Title, string AuthorName){
  list<book>::iterator it;
  it = books.begin();
  while(it != books.end() && it -> Title != Title) {
    it++;
  }
  if(it -> AuthorName != AuthorName){
    cout << "Book not found." << endl;
    cout << endl;
  }
  else {
    books.erase(it);
    cout << Title << " has been deleted." << endl;
    cout << endl;
  }
}
