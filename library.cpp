#include "library.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void library::push_front(string Title, string AuthorName){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  books.push_front(temp);
}

void library::push_back(string Title, string AuthorName){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
  books.push_back(temp);
}

void library::read_from_file(string filename){
  
}

void library::write_to_file(string filename){
}

void library::insert_sorted(string Title, string AuthorName){
  book temp;
  temp.Title = Title;
  temp.AuthorName = AuthorName;
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
  for(it = books.begin(); it != books.end(); it++){
    if(it -> AuthorName == AuthorName){
      booksByThisAuthor += it->Title;
      booksByThisAuthor += " ";
    }
  }
  return booksByThisAuthor;
}

string library::find_album(string AuthorName){
}

void library::print(){
  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++) {
    cout << "List item: " << it -> AuthorName << " - " << it -> Title << endl;
  }
  cout << endl << endl;
}

void library::Delete(string Title, string AuthorName){
}

library::~library(){
}
