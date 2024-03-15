#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
int accNo,pin;
using namespace std;
class Menu{
    public:
    void welcome(){
        cout<<"_________________________________________________________"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"|\t\t WELCOME TO MY BANK \t\t\t|"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"_________________________________________________________"<<endl;
    }
    void mainMenu(){
        cout<<"1. Bank"<<endl;
        cout<<"2. ATM"<<endl;
        cout<<"3. Exit"<<endl;
    }
    void subMenuBank(){
        cout<<"1. Open New Acoount"<<endl;
        cout<<"2. Acoount Details"<<endl;
        cout<<"3. Deposit"<<endl;
        cout<<"4. Transfer"<<endl;
        cout<<"5. Exit"<<endl;
    }
};
class Bank{
    public:
    string name1,name2;
    unsigned long long int cnic;
    int accBalance;
    void newAccount(){
        cout<<"Enter your first name : "<<endl;
        cin>>name1;
        cout<<"Enter your last name : "<<endl;
        cin>>name2;
        cout<<"Enter your CNIC (without dashes) : "<<endl;
        cin>>cnic;
        cout<<"Your Account Number = "<<accNo<<endl;
        cout<<"Enter 4 digit new pin = "<<endl;
        cin>>pin;
        accBalance=1000;
        cout<<"_________________________________________________________"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"|         YOUR ACCOUNT HAS BEEN OPENED SUCCESFULLY      |"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"_________________________________________________________"<<endl;
        cout<<"\n"<<endl;
    }
    void saveData() {
	ofstream file;
	file.open("CustomerPrivateData.txt", ios::app);
	file<<accNo;
    file<<endl;
    file<<pin;
    file<<endl;
	file.close();
}
    void saveDetails(){
        ofstream file;
        ofstream file1;
        file1.open("customerBalance.txt",ios::app);
	    file.open("CustomerDetails.txt", ios::app);
	    file<<"Name = ";
        file<<name1<<" "<<name2;
        file<<" CNIC = ";
        file<<cnic;
        file1<<accNo;
        file<<endl;
        file1<<endl;
        file1<<accBalance;
        file1<<endl;
	    file.close();
	    file1.close();
    }
};
class UpdateBalance: public Bank{
    public:
    int lineNo;
    void searchUpdate(int acc_no, int amount) {
        string filePath = "customerBalance.txt";
        ifstream file(filePath);
        if (!file) {
            cerr << "Failed to open the file." << endl;
            return;
        }
        int lineNumber = 0;
        bool found = false;
        string line;
        while (getline(file, line)) {
            lineNumber++;
            int currentValue = stoi(line);  // Convert line to integer
            if (currentValue == acc_no) {
                lineNo = lineNumber + 1;
                found = true;
                break;  // Stop searching after finding the account number
            }
        }
        file.close();
        if (!found) {
            cout << "Incorrect Account Number" << endl;
            return;
        }
        // Open the file for reading and writing
        fstream file2(filePath);
        if (!file2) {
            cerr << "Failed to open the file." << endl;
            return;
        }
        string line1;
        int currentLineNumber = 0;
        stringstream modifiedContent;
        // Read and modify each line in the file
        while (getline(file2, line1)) {
            currentLineNumber++;
            if (currentLineNumber == lineNo) {
                int currentValue = stoi(line1);
                int modifiedValue = currentValue + amount;
                modifiedContent << modifiedValue << endl;
            }
            else {
                modifiedContent << line1 << endl;
            }
        }
        file2.close();
        // Reopen the file in truncation mode to clear the existing content
        file2.open(filePath, ios::out | ios::trunc);
        if (!file2) {
            cerr << "Failed to open the file." << endl;
            return;
        }
        // Write the modified content back to the file
        file2 << modifiedContent.str();
        file2.close();
        cout<<"_________________________________________________________"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"|                   TRANSACTION SUCCESFUL                |"<<endl;
        cout<<"|\t\t\t\t\t\t\t|"<<endl;
        cout<<"_________________________________________________________"<<endl;
        cout<<"\n"<<endl;
    }
};
class Customer{
    public:
    void search(){
        ifstream file("CustomerDetails.txt");
        string searchStr;
        int acc;
        cout << "Enter your first or last name to search: ";
        cin>>searchStr;
        cout<<"Enter Account Number = ";
        cin>>acc;
        if (file) {
            string line;
            while (getline(file, line)) {
                if (line.find(searchStr) != string::npos) {
                    cout<<"\n\n";
                    cout << line ;
                    cout<<" ";
                }
            }
            file.close();
        }
        else {
            cout << "Not Found" << endl;
        }

        int targetInteger;
        targetInteger=acc;  // Integer to search for
        string filePath = "customerBalance.txt";  // Path to the text file
        ifstream file3(filePath);
        if (!file3) {
            cerr << "Failed to open the file." << endl;
        }
        int lineNumber = 0;
        bool found = false;
        string line1;
        while (getline(file3, line1)) {
            lineNumber++;
            int currentValue = stoi(line1);  // Convert line to integer

            if (currentValue == targetInteger) {
                if (getline(file3, line1)) {
                    int nextValue = stoi(line1);
                    cout << "Balance = " << nextValue << endl<<endl;
                    found = true;
                }
                break;  // Stop searching after finding the target integer
        }
    }

    if (!found) {
        cout << "Not found" << endl;
    }

    // Close the file
    file3.close();
    }
};
class loginChecker {
public:
    bool loginCheck(int accountNumber, int password) {
        string filePath = "CustomerPrivateData.txt";  // Path to the text file
        ifstream file(filePath);
        if (!file) {
            cerr << "Failed to open the file." << endl;
            return false;  // Return false if file opening fails
        }

        int lineNumber = 0;
        bool found = false;
        string line;
        while (getline(file, line)) {
            lineNumber++;
            int currentValue = stoi(line);  // Convert line to integer

            if (currentValue == accountNumber) {
                if (getline(file, line)) {
                    int nextValue = stoi(line);
                    if (nextValue == password) {
                        file.close();
                        return true;
                    }
                }
                break;  // Stop searching after finding the target integer
            }
        }

        file.close();
        return false;  // Return false if account not found or password doesn't match
    }
};
int main(){
    Menu m1;
    Bank b1;
    Customer c1;
    UpdateBalance ub1;
    loginChecker lc1;
    int num;
    ifstream newFile1;
    newFile1.open("accNumberStart.txt");
	if(newFile1>>num){
		newFile1 >> num;
		accNo = num;
	}
	else{
		accNo=1000;
	}
	newFile1.close();
    m1.welcome();
    m1.mainMenu();
    int choice;
    cin>>choice;
    while(choice!=3){
        if(choice==1){
            m1.subMenuBank();
            int choice1;
            cin>>choice1;
            while(choice1!=5){
                if(choice1==1){
                    b1.newAccount();
                    b1.saveData();
                    b1.saveDetails();
                    accNo++;
                }
                if(choice1==2){
                    c1.search();
                }
                if(choice1==3){

                    main:
                    cout<<"Enter acc Number = ";
                    int acc_number;
                    cin>>acc_number;
                    cout<<"Enter pin = ";
                    int pass;
                    cin>>pass;
                    cout<<"Enter Amount to Deposit = ";
                    int amount;
                    cin>>amount;
                    if((lc1.loginCheck(acc_number,pass)==true)){
                    if (amount%500==0){
                        ub1.searchUpdate(acc_number,amount);
                    }
                    else{
                        cout<<"Enter a multiple of 500"<<endl;
                        goto main;
                    }
                }
                else{
                    cout<<"\n\nIncorrect"<<endl<<endl;
                    goto main;
                }}
                if(choice1==4){
                    main2:
                    cout<<"Enter acc Number = ";
                    int acc_number;
                    cin>>acc_number;
                    cout<<"Enter pin = ";
                    int pass;
                    cin>>pass;
                    if ((lc1.loginCheck(acc_number,pass)==true)){
                    cout<<"Enter Amount to Transfer = ";
                    int amount,amount2;
                    cin>>amount;
                    amount2=-amount;
                    cout<<"Enter Accout Number in which you want to transfer = ";
                    int acc_number2;
                    cin>>acc_number2;
                    if (amount%500==0){
                        ub1.searchUpdate(acc_number,amount2);
                        ub1.searchUpdate(acc_number2,amount);
                    }
                    else{
                        cout<<"Enter a multiple of 500"<<endl;
                        goto main2;
                    }
                }
                else{
                    cout<<"\n\nIncorrect"<<endl<<endl;
                    goto main2;
                }
                }
                m1.subMenuBank();
                cin>>choice1;
            }
        }
        if(choice==2){
            main3:
            cout<<"Enter Account Number = ";
            int accNumber;
            cin>>accNumber;
            cout<<"Enter pin = ";
                    int pass;
                    cin>>pass;
                    if ((lc1.loginCheck(accNumber,pass)==true)){
                        cout<<"Enter Amount = ";
                        int amount;
                        cin>>amount;
                        amount=-amount;
                        if (amount%500==0){
                            ub1.searchUpdate(accNumber,amount);
                        }
                    else{
                        cout<<"Enter a multiple of 500"<<endl;
                        goto main3;
                     }
        }
        else{
            cout<<"\n\nIncorrect"<<endl<<endl;
            goto main3;
        }
        }
        m1.mainMenu();
        cin>>choice;
    }
ofstream newFile;
newFile.open("accNumberStart.txt", ios::trunc);
newFile << accNo;
newFile.close();
}