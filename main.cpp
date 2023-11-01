/**
 * @file main.cpp
 * @author Matthew Lannom
 * @date 2023-10-31
 * @brief Library (Driver)
 * 
 * This program lets users interact with a list of library books, doing things such as printing the list, adding or removing a book from the list, finding information on the books, etc. This file serves as the user interface.
 */

#include "library.h"
#include <iostream>

using namespace std;


/**
 * A function which prints a menu that contains various options users can select
 *
 * @param int &choice The user's option choice
 * @pre 
 * @return void 
 * @post Menu has been printed, option has been gotten from the user
 * 
 */
void driver(int &choice);

int main() {
  library lib;
  int choice = 0;
  string in_library;
  string out_library;
  while(choice!=8){
    driver(choice); //Printing menu, prompting user, and getting their choice
    if(choice==1){
      cout << "Enter file to be read: "; //Prompting user
      cin >> in_library; //Getting user filename from user
      cout << endl;
      lib.read_from_file(in_library); //Reading from file
      cout << in_library << " has been read." << endl;
      cout << endl;
    }
    
    if(choice==2){
      cout << "Enter file to write library to: "; //prompting user
      cin >> out_library; //Getting filename from user
      cout << endl;
      lib.write_to_file(out_library); //Writing to file
      cout << "Library has been written to " << out_library << endl;
      cout << endl;
    }
    
    if(choice==3){
      cout << "Printing library" << endl;
      cout << endl;
      lib.print(); //Printing list
    }
    
    if(choice==4){
      string AuthorName;
      cout << "Enter Author's name: "; //Prompting user
      cin.get(); 
      getline(cin, AuthorName); //Getting user input
      string AuthorWork = lib.find_author(AuthorName); //Finding all books by the given author and setting the result equal to AuthorWork
      if(AuthorWork != "This author could not be found."){
	cout << AuthorName << " has written: " << endl << AuthorWork << endl; //Printing result to screen
      }
      else {
	cout << endl << AuthorWork << endl << endl; //Printing result to screen
      }
    }
    
    if(choice==5){
      string AuthorName;
      cout << "Enter Author's name: "; //Prompting user
      cin.get();
      getline(cin, AuthorName); //Getting user input
      string AuthorWork = lib.find_album(AuthorName); //Finding information about all books by the given author and setting the result equal to AuthorWork
      if(AuthorWork != "This author could not be found."){
	cout << AuthorName << "'s books and information: ";
	cout << AuthorWork << endl; //Printing result to screen
      }
      else {
	cout << endl << AuthorWork << endl << endl; //Printing result to screen
      }
    }
    
    if(choice==6){
      string Title, AuthorName, isbn;
      int Pages, Year;
      float Coverprice;
      cout << "Enter book title: "; //Prompting user
      cin.get();
      getline(cin, Title); //Getting user input
      cout << endl;
      cout << "Enter author name: "; //Prompting user
      getline(cin, AuthorName); //Getting user input 
      cout << endl;
      cout << "Enter number of pages: "; //Prompting user
      cin >> Pages; //Getting user input 
      cout << endl;
      cout << "Enter isbn number: "; //Prompting user
      cin.get();
      getline(cin, isbn); //Getting user input 
      cout << endl;
      cout << "Enter the price: "; //Prompting user
      cin >> Coverprice; //Getting user input 
      cout << endl;
      cout << "Enter the year: "; //Prompting user
      cin >> Year; //Getting user input 
      cout << endl;
      lib.insert_sorted(Title, AuthorName, Pages, isbn, Coverprice, Year); //Inserting book into the list
      cout << Title << " has been added." << endl;
      cout << endl;
    }
    
    if(choice==7){
      string Title, AuthorName;
      cout << "Enter book Title: "; //Prompting user
      cin.get();
      getline(cin, Title); //Getting user input
      cout << endl;
      cout << "Enter author name: "; //Prompting user
      getline(cin, AuthorName); //Getting user input
      cout << endl;
      lib.Delete(Title, AuthorName); //Removing book from the list
    }
    
    if(choice==8){
      cout << "Alright, exiting. Have a Great Life:)" << endl;
    }
  }
  return 0;
}

void driver(int &choice){
  //Menu
  cout << "Welcome to the UTM Library!  You may select one of the following options:" << endl;
  cout << "1 Read a Library from a file" << endl;
  cout << "2 Write the Library to a file" << endl;
  cout << "3 Print the Library" << endl;
  cout << "4 Search for all books that an authors has" << endl;
  cout << "5 Search for all information for all books an author has" << endl;
  cout << "6 Add a book " << endl;
  cout << "7 Delete a book" << endl;
  cout << "8 Exit this program" << endl << endl;
  
  cout << "Please enter your choice now: " << endl; //Prompting user

  cin >> choice; //Getting user input
}
