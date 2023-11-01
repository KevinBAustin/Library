#include "library.h"
#include <iostream>
#include "library.h"

using namespace std;

void driver(int &choice);

int main() {
  library lib;
  lib.insert_sorted("The Great Gatsby", "F. Scott Fitzgerald", 67, "rtyrty", 35.00, 1919);
  lib.insert_sorted("dododo", "F. Scott Fitzgerald", 234, "2wtt34t34", 68.00, 1959);
  int choice = 0;
  string in_library;
  string out_library;
  while(choice!=8){
    driver(choice);
    if(choice==1){
      cout << "Enter file to be read: ";
      cin >> in_library;
      cout << endl;
      lib.read_from_file(in_library);
    }
    
    if(choice==2){
      cout << "Enter file to write library to: ";
      cin >> out_library;
      cout << endl;
      lib.write_to_file(out_library);
    }
    
    if(choice==3){
      cout << "Printing library" << endl;
      cout << endl;
      lib.print();
    }
    
    if(choice==4){
      string AuthorName;
      cout << "Enter Author's name: ";
      cin.get();
      getline(cin, AuthorName);
      string AuthorWork = lib.find_author(AuthorName);
      if(AuthorWork != "This author could not be found."){
	cout << AuthorName << " has written: " << endl << AuthorWork << endl;
      }
      else {
	cout << endl << AuthorWork << endl << endl;
      }
    }
    
    if(choice==5){
      string AuthorName;
      cout << "Enter Author's name: ";
      cin.get();
      getline(cin, AuthorName);
      string AuthorWork = lib.find_album(AuthorName);
      if(AuthorWork != "This author could not be found."){
	cout << AuthorName << "'s books and information: ";
	cout << AuthorWork << endl;
      }
      else {
	cout << endl << AuthorWork << endl << endl;
      }
    }
    
    if(choice==6){
      string Title, AuthorName, isbn;
      int Pages, Year;
      float Coverprice;
      cout << "Enter book title: ";
      cin.get();
      getline(cin, Title);
      cout << endl;
      cout << "Enter author name: ";
      getline(cin, AuthorName);
      cout << endl;
      cout << "Enter number of pages: ";
      cin >> Pages;
      cout << endl;
      cout << "Enter isbn number: ";
      cin >> isbn;
      cout << endl;
      cout << "Enter the price: ";
      cin >> Coverprice;
      cout << endl;
      cout << "Enter the year: ";
      cin >> Year;
      cout << endl;
      lib.insert_sorted(Title, AuthorName, Pages, isbn, Coverprice, Year);
      cout << Title << " has been added." << endl;
      cout << endl;
    }
    
    if(choice==7){
      string Title, AuthorName;
      cout << "Enter book Title: ";
      cin.get();
      getline(cin, Title);
      cout << endl;
      cout << "Enter author name: ";
      getline(cin, AuthorName);
      cout << endl;
      lib.Delete(Title, AuthorName);
    }
    
    if(choice==8){
      cout << "Alright, exiting. Have a Great Life:)" << endl;
    }
  }
  return 0;
}

void driver(int &choice){
  cout << "Welcome to the UTM Library!  You may select one of the following options:" << endl;
  cout << "1 Read a Library from a file" << endl;
  cout << "2 Write the Library to a file" << endl;
  cout << "3 Print the Library" << endl;
  cout << "4 Search for all books that an authors has" << endl;
  cout << "5 Search for all information for all books an author has" << endl;
  cout << "6 Add a book " << endl;
  cout << "7 Delete a book" << endl;
  cout << "8 Exit this program" << endl << endl;
  
  cout << "Please enter your choice now: " << endl;

  cin >> choice;
}
