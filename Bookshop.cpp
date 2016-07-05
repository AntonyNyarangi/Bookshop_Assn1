#include <iostream>
#include <string>
#include "Books.h"
using namespace std;

//function prototypes
Books* checkBookAvailability(string bookTitle, string authorName);
void transaction();

//creating object instances
Books* myBook0 = new Books("Learn Cpp","Antony Nyarangi","publisher",90.00,5);
Books* myBook1 = new Books("Learn C","Clive Nyarangi","publisher",100.00,10);
Books* myBook2 = new Books("Learn Java","Calvin Nyarangi","publisher",110.00,15);
Books* myBook3 = new Books("Learn Ruby","George Nyarangi","publisher",120.00,20);
Books* myBook4 = new Books("Learn Perl","Josephine Nyarangi","publisher",130.00,0);
Books* myBook5 = new Books("Learn Prolog","Victor Nyarangi","publisher",140.00,37);

//main method
int main(){
  transaction();
return 0;
}

//transaction method
void transaction(){
  string title = "";
  string authorName = "";
  int copiesNeeded;
  double totalCost;
  char anotherTransaction;
  //prompt user for input --> title and author name of the book the would like
  cout << "\nPlease enter the title of the book" << endl;
  getline(cin,title);
  cout << "Please enter the name of the author" << endl;
  getline(cin,authorName);
  //check for book availability, gives error if book does not exist
  Books* b = checkBookAvailability(title,authorName);
  //  displayBookDetails(b);
  b->displayBookDetails();
  //prompt user to enter the number of copies they need
  cout << "\n\nHow many copies do you need?" << endl;
  cin >> copiesNeeded;
  //call method to calculate total cost and update the stock;
  totalCost = b->calculateTotalCost(copiesNeeded);
  //display results of calculation and new stock available
  cout << "\nThe total cost is: " << totalCost << endl;
  cout << "Stock Updated! Available stock = " << b->stockValue << endl;
  //prompt for another transaction
  cout << "\nwould you like to carry out another transaction? (y/n)" << endl;
  cin >> anotherTransaction;
  //recursive call if the user wants another transaction else, program termination
  if(anotherTransaction == 'y'){
    transaction();
  }else if( anotherTransaction == 'n') {
    cout << "\n\n**Thank you, Have a nice day.**" << endl;
  }
}

// method to check if the book that is being searched for is available
Books* checkBookAvailability(string b_title, string a_name){
   if((b_title.compare(myBook0->bookTitle) == 0) && (a_name.compare(myBook0->authorName)==0)){
     return myBook0;
   }
   else if((b_title.compare(myBook1->bookTitle) == 0) && (a_name.compare(myBook1->authorName)==0)){
    return myBook1;
   }
   else if((b_title.compare(myBook2->bookTitle) == 0) && (a_name.compare(myBook2->authorName)==0)){
     return myBook2;
   }
   else if((b_title.compare(myBook3->bookTitle) == 0) && (a_name.compare(myBook3->authorName)==0)){
     return myBook3;
   }
   else if((b_title.compare(myBook4->bookTitle) == 0) && (a_name.compare(myBook4->authorName)==0)){
     return myBook4;
   }
   else if((b_title.compare(myBook5->bookTitle) == 0) && (a_name.compare(myBook5->authorName)==0)){
     return myBook5;
   }
   else{
     cout << "\n\nStatus: Not Available\nBook does NOT EXIST" << endl;
   }
 }