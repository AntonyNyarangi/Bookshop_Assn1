#include <iostream>
#include <string>
using namespace std;

// defining the Books class
class Books{
public:
  //public data members
  static int successfulTransactions;
  static int unsuccessfulTransactions;
  string authorName;
  string bookTitle;
  string bookPublisher;
  double bookPrice;
  int stockValue;

  //class constructor
  Books(string bTitle, string aName, string bPublisher, double bPrice, int stock){
    bookTitle = bTitle;
    authorName = aName;
    bookPublisher = bPublisher;
    bookPrice = bPrice;
    stockValue = stock;
    }

    //destructor
    ~Books(){
      
    }

    //method to display the details of a book object
  void displayBookDetails (){
    cout << "\n\nStatus=Available\nBook Details" << endl;
    cout << "\tBook Title: " << bookTitle << endl;
    cout << "\tAuthor Name: " << authorName << endl;
    cout << "\tPublisher: " << bookPublisher << endl;
    cout << "\tUnit Price: " << bookPrice << endl;
    cout << "\tAvailable Stock: " << stockValue << endl;
  }

  //method to calculate the totsl cost of a book transaction given the number of Books needed
  //also updates the book stockValue
  double calculateTotalCost(int needed){
    double cost;
     if (needed > stockValue){
       cout << "Required copies not in stock" << endl;
       cout << "\nTransaction not successful" << endl;
       // countUnsuccessfulTransactions();
     }else{
       cost = needed * bookPrice;
       stockValue = stockValue - needed;
       cout << "\nTransaction successful" << endl;
       //countSuccessfulTransactions();
     }
     return cost;
   }
   //method to call private updatePrice
   void doUpdatePrice(double newPrice){
     updatePrice(newPrice);
   }

   //method to record number of unsuccessful transactions
   static void countUnsuccessfulTransactions (){
     unsuccessfulTransactions = unsuccessfulTransactions + 1;
     return;
   }
   //method to record number of successful transactions
   static void countSuccessfulTransactions(){
     successfulTransactions = successfulTransactions + 1;
     return;
   }

private:
  //private member method
  void updatePrice(double newPrice){
    bookPrice = newPrice;
    cout << "Book price updated. New price = " << bookPrice << endl;
  }
};
