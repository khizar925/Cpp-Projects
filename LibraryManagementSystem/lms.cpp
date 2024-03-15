#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    int itemID;
public:
    LibraryItem(string _title, int _itemID) : title(_title), itemID(_itemID) {}
    virtual void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Item ID: " << itemID << endl;
    }
};

class Book : public LibraryItem {
private:
    string author;
public:
    Book(string _title, int _itemID, string _author)
        : LibraryItem(_title, _itemID), author(_author) {}
    void displayDetails() {
        LibraryItem::displayDetails();
        cout << "Author: " << author << endl;
    }
};

void submitNewBook() {
    string bookTitle, bookAuthor;
    int bookID;

    cout << "\nEnter the details of the book:" << endl;
    cout << "Title: ";
    getline(cin, bookTitle);
    cout << "Item ID: ";
    cin >> bookID;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Author: ";
    getline(cin, bookAuthor);

    // Create a Book object
    Book book(bookTitle, bookID, bookAuthor);

    // Write book details to the file
    ofstream outputFile("BookNames.txt", ios::app); // Open the file in append mode
    if (outputFile.is_open()) {
        outputFile << bookTitle << " by " << bookAuthor << endl;
        outputFile.close();
        cout << "\nBook details have been saved." << endl;
    } else {
        cout << "Error: Unable to open the file." << endl;
    }

    cout << "\nBook Details:" << endl;
    book.displayDetails();
}
bool membership(string name){
    ifstream inputFile("MembershipHistory.txt");
    string line;

    while (getline(inputFile, line)) {
        if (line.find(name) != string::npos) {
            inputFile.close();
            return true; // Name found in the file
        }
    }

    inputFile.close();
    return false; // Name not found in the file
}
void issueBook() {
    string bookTitle,name;
    int days;
    cout<<"Enter Your First/Last name : ";
    getline(cin,name);
    cout << "Enter the title of the book to be issued: ";
    getline(cin, bookTitle);
    cout<<"Enter how many days for issue book ?  ";
    cin>>days;
    cin.ignore();
    // Search for the book in the library database (BookNames.txt)
    ifstream inputFile("BookNames.txt");
    string line;
    bool bookFound = false;
    while (getline(inputFile, line)) {
        if (line.find(bookTitle) != string::npos) {
            bookFound = true;
            break;
        }
    }
    inputFile.close();

    if (bookFound) {
        cout << "Book \"" << bookTitle << "\" has been issued." << endl;
        if (membership(name)){
            cout<<"Fair = "<<days*50<<endl;
        }
        else{
            cout<<"Fair = "<<days*100<<endl;
        }
    } else {
        cout << "Book \"" << bookTitle << "\" not found in the library." << endl;
    }
}

void makeMembership() {
    string memberName;
    unsigned long long int cnic;
    cout << "\nEnter the details for membership:" << endl;
    cout << "Member Name: ";
    getline(cin, memberName);
    cout<<"Enter Your CNIC : ";
    cin>>cnic;
    cin.ignore(); // Ignore the newline character in the input buffer
    ofstream file;
    file.open("MembershipHistory.txt", ios::app);
    if (file.is_open()){
        file << memberName << " " << cnic << endl;
    }
    file.close();
    cout << "Membership created successfully for " << memberName  << endl;
}

int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Submit new book" << endl;
        cout << "2. Issue book from library" << endl;
        cout << "3. Make membership of library" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character in the input buffer

        switch (choice) {
            case 1:
                submitNewBook();
                break;
            case 2:
                issueBook();
                break;
            case 3:
                makeMembership();
                break;
            case 4:
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    cout << "\nGoodbye!" << endl;
    return 0;
}