
#include <iostream>
#include "library.h"

using namespace std;

void driver(int &choice);

int main() {
  int choice=0;
  library lib;
  string in_library;
  string out_library;
  
  while(choice!=8){
    driver(choice);
    if(choice==1){
      cout<<"Enter file to be read: ";
      cin>>in_library;
      lib.read_from_file(in_library);
    }
    if(choice==2){
      cout<<"Enter file to write library to: ";
      cin>>out_library;
      lib.write_to_file(out_library);
    }
    if(choice==3){
      cout<<"Printing library";
      lib.print();
    }
    if(choice==4){
      string AuthorName;
      cout<<"Enter Author's name";
      cin.get();
      getline(cin, AuthorName);
      cout<<"Searching"<<endl;
      string AuthorWork=lib.find_author(AuthorName);
      cout<<AuthorName<<" has written: "<<AuthorWork<<endl;
    }
    if(choice==5){
      string AuthorName;
      cout<<"Enter Author's name";
      cin.get();
      getline(cin, AuthorName);
      cout<<"Searching"<<endl;
      string AuthorWork=lib.find_album(AuthorName);
      cout<<AuthorName<<"'s books and information"<<endl;
      cout<< AuthorWork<<endl;
    }
    /*
    if(choice==6){
      string first, last, number;
      cout<<"Enter first name";
      cin>>first;
      cout<<"Enter last name";
      cin>>last;
      cout<<"Enter number";
      cin>>number;
      phone.insert_sorted(first, last, number);
      cout<<"User added"<<endl;
    }
    
    if(choice==7){
      string AuthorName;
      cout<<"Enter name of to be deleted Author";
      cin>>AuthorName;
      lib.Delete(AuthorName);
    }
    */
    if(choice==8){
      cout<<"Alright exiting. Have a Great Life:)"<<endl;
    }
  }
  
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
