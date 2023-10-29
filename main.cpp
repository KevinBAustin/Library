#include "library.h"
#include <iostream>

using namespace std;

int main() {
  library myLibrary;
  myLibrary.insert_sorted("In Search of Lost Time", "Marcel Proust");
  myLibrary.insert_sorted("Ulysses", "James Joyce");
  myLibrary.insert_sorted("Don Quixote", "Miguel de Cervantes");
  myLibrary.insert_sorted("One Hundred Years of Solitude", "Gabriel Garcia Marquez");
  myLibrary.insert_sorted("The Great Gatsby", "F. Scott Fitzgerald");
  myLibrary.insert_sorted("dododo", "F. Scott Fitzgerald");
  myLibrary.print();
  cout << myLibrary.find_author("F. Scott Fitzgerald");
  
  return 0;
}

