#include "library.h"
#include <iostream>
#include "library.h"

using namespace std;

void driver(int &choice);

int main() {
  library myLibrary;
  myLibrary.push_front("In Search of Lost Time", "Marcel Proust", 67, "tuiwtoeto", 35.00, 1985);
  /*

  myLibrary.insert_sorted("Ulysses", "James Joyce");
  myLibrary.insert_sorted("Don Quixote", "Miguel de Cervantes");
  myLibrary.insert_sorted("One Hundred Years of Solitude", "Gabriel Garcia Marquez");
  myLibrary.insert_sorted("The Great Gatsby", "F. Scott Fitzgerald");
  myLibrary.insert_sorted("dododo", "F. Scott Fitzgerald");
  myLibrary.print();
  cout << myLibrary.find_author("F. Scott Fitzgerald");
  */
  myLibrary.print();
  return 0;
}

void driver(int &choice){
  cout<<"Welcome to the UTM Library!  You may select one of the following options:"<<endl;
  cout<<"1 Read a Library from a file \n";
  cout<<"2 Write the Library to a file \n";
  cout<<"3 Print the Library \n";
  cout<<"4 Search for all books that an authors has \n";
  cout<<"5 Search for all information for all books an author has \n";
  cout<<"6 Add an author \n";
  cout<<"7 Delete an author \n";
  cout<<"8 Exit this program"<<endl<<endl;
  
  cout<<"Please enter your choice now: "<<endl;

  cin>>choice;
}
