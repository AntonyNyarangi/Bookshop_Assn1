#include <iostream>
#include <string>
#include <stdlib.h>
#include "Books.h"
using namespace std;

//function prototypes
Books* checkBookAvailability(string bookTitle, string authorName);
void transactionBuyBooks(Books* b);
void transactionPriceUpdate(Books* b);
void bookstoreIntro();

//creating object instances
Books* myBook0 = new Books("Learn Cpp","Antony Nyarangi","publisher",90.00,5);
Books* myBook1 = new Books("Learn C","Clive Nyarangi","publisher",100.00,10);
Books* myBook2 = new Books("Learn Java","Calvin Nyarangi","publisher",110.00,15);
Books* myBook3 = new Books("Learn Ruby","George Nyarangi","publisher",120.00,20);
Books* myBook4 = new Books("Learn Perl","Josephine Nyarangi","publisher",130.00,0);
Books* myBook5 = new Books("Learn Prolog","Victor Nyarangi","publisher",140.00,37);

//main method
int main(){
  cout << "WELCOME TO THE BOOKSTORE!"<< endl;
  bookstoreIntro();
return 0;
}

//introduction
void bookstoreIntro(){
  string title = "";
  string authorName = "";
  int transactionType;
  //prompt user for input
  cout << "\nPlease enter the title of a book: ";
  getline(cin,title);
  cout << "Please enter the name of its author: ";
  getline(cin,authorName);
  //check for book availability, gives error and exits if book does not exist
  Books* b = checkBookAvailability(title,authorName);
  //prompt user for nature of transaction.
  cout << "\nWhat would you like to do with this book?" << endl;
  cout << "1.Buy copies" <<endl;
  cout << "2.Update book price" << endl;
  cout << "Choice: ";
  cin >> transactionType;
  //depending on transaction type, execute respective actions
  if(transactionType == 2){
    transactionPriceUpdate(b);
    cin.ignore();
    bookstoreIntro();
  }else if(transactionType ==1){
    transactionBuyBooks(b);
  }else{
    cout << "Invalid entry...exiting"<<endl;
    exit(0);
  }
}

//Buy book transactions
void transactionBuyBooks(Books* b){
  int copiesNeeded;
  double totalCost;
  char anotherTransaction;
  b->displayBookDetails();
  cout << "\n\nHow many copies do you need?: ";
  cin >> copiesNeeded;
  //call method to calculate total cost and update the stock;
  totalCost = b->calculateTotalCost(copiesNeeded);
  //display results of calculation and new stock available
  cout << "The total cost is: " << totalCost << endl;
  cout << "**Available stock = " << b->stockValue;
  //prompt for another transaction
  cout << "\n\nIf you would like to begin another transaction, enter 'y'. Enter 'n' exit.: ";
  cin >> anotherTransaction;
  //recursive call if the user wants another transaction else, program termination
  if(anotherTransaction == 'y'){
    cin.ignore();
    bookstoreIntro();
  }else if (anotherTransaction =='n'){
    //calling class destructor
    myBook0->Books::~Books();
    myBook1->Books::~Books();
    myBook2->Books::~Books();
    myBook3->Books::~Books();
    myBook4->Books::~Books();
    myBook5->Books::~Books();
    cout << "\n\n**Thank you, Have a nice day.**" << endl;
  }else{
    cout <<"invalid entry...exiting" << endl;;
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
   exit(0);
  }
 }

//method to carry out price update
void transactionPriceUpdate(Books* b){
 char updateBookPrice;
 int newPrice;
   cout << "Please enter the new price: ";
   cin >> newPrice;
   b->doUpdatePrice(newPrice);
 }
