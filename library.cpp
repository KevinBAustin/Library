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

  while(inFile){
    inFile>>Title>>AuthorName>>Pages>>isbn>>Coverprice>>Year;

    //Comeback when insort done
  }

  inFile.close();
}

void library::write_to_file(string filename){
  ofstream outFile;
  outFile.open(filename);

  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++){
    outFile<<it->Title<<it->AuthorName<<it->Pages<<it->isbn<<it->Coverprice<<it->Year;
  }
  outFile.close();
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
  string info;
  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++){
    if(it->AuthorName == AuthorName){
      info+=it->Title;
      info+=" ";
      info+=it->Pages;
      info+=" ";
      info+=it->isbn;
      info+=" ";
      info+=it->Coverprice;
      info+=" ";
      info+=it->Year;
      info+=" ";
    }
  }

  return info;
}

void library::print(){
  list<book>::iterator it;

  for(it = books.begin(); it != books.end(); it++) {
    cout << "List item: " << it -> AuthorName << " - " << it -> Title << " Pages: " << it -> Pages << " isbn: " << it -> isbn << " Price: " << it -> Coverprice << " Year: " << it -> Year <<  endl;
  }
  cout << endl << endl;
}

void library::Delete(string Title, string AuthorName){

}

library::~library(){

}
