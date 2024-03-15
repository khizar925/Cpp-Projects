#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int stud; //global variable for student
struct st {
	string name1[50]; //array size (50) because the average students in a class is approx 50.
	string name2[50];
	int age[50];
	long long int phoneNumber[50];
};
st student = {};
int mainMenu() {
	cout << endl << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << "=======    Main Menu    ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << endl << endl;
	cout << "1. Registration\n2. Quiz\n3. Search by Roll Number\n4. Exit\n";
	int option;
	cin >> option;
	return option;
}
void registration(int st) {
	cout << "Enter First name: ";
	cin >> student.name1[st];
	cout << "Enter Second name: ";
	cin >> student.name2[st];
	cout << "Enter age: ";
	cin >> student.age[st];
	cout << "Enter Phone number (923001234567): ";
	cin >> student.phoneNumber[st];
	cout << "<----------Registered---------->" << endl;
	cout << "Your Roll Number is: " << st + 1 << endl;
}
void saveData() {
	ofstream file;
	file.open("studentData.txt", ios::app);
	file << "Name: ";
	file << student.name1[stud];
	file<<" ";
	file<<student.name2[stud];
	file << " Age: ";
	file << student.age[stud];
	file << " Phone Number: ";
	file << student.phoneNumber[stud] << endl;
	file.close();
}
void generalKnowledge() {
	//questions
	string questions[10] = {
	"Year of Pakistan's Independence?",
	"LGU belongs to which sector?",
	"What is the name of Pakistan Intelligence agency?",
	"Which flower is national flower of Pakistan?",
	"Who laid first step on the Moon?",
	"How many rivers in Punjab?",
	"Ogaden desert is present in__________?",
	"Capital of Pakistan is___________?",
	"Wadi Rum which resemblance to the surface of Mars is located in__________?",
	"Which river is located in Pakistan?"
	};

	//4 possible answers
	string options[10][4] = {
	{"1946","1947","1948","1949"},
	{"Public","Government","Army","None of these"},
	{"MI6","CIA","ISI","N.O.T"},
	{"Jasmine","Rose","Sunflower","None of these"},
	{"LMP Edgar","CMP Stuart","Neil Armstrong","None of them"},
	{"3","4","5","7"},
	{"Europe","Asia","Africa","America"},
	{"Lahore","Karachi","Islamabad","Quetta"},
	{"Argentina","Israel","Jordan","Egypt"},
	{"Indus River","Pacific Ocean","Arctic Ocean","Atlantic"},
	};
	//correct answers
	string correctOptions[10] = {
		"1947","Army","ISI","Jasmine",
		"Neil Armstrong","5","Africa",
		"Islamabad","Jordan","Indus River"
	};

	int userOptions[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int totalQs = 10;
	
	//----- Conducting Quiz -----
	for (int i = 0; i < totalQs; i++) {
		cout << "Question # " << (i + 1) << endl;
		cout << questions[i] << endl;
		cout << "1." << options[i][0] << endl;
		cout << "2." << options[i][1] << endl;
		cout << "3." << options[i][2] << endl;
		cout << "4." << options[i][3] << endl << endl;

		cout << "Select Option (1-4) or 0 to skip and press enter: ";
		cin >> userOptions[i];
		cout << endl << "-----------------------------" << endl << endl;
	}

	//----- Printing Correct Options -----
	cout << "======= ======= ======= ======= " << endl;
	cout << "======= Correct Options ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;

	for (int i = 0; i < totalQs; i++) {
		cout << "Question # " << (i + 1) << endl;
		cout << questions[i] << endl;
		cout << "1." << options[i][0] << endl;
		cout << "2." << options[i][1] << endl;
		cout << "3." << options[i][2] << endl;
		cout << "4." << options[i][3] << endl;

		if (userOptions[i] == 0) {
			cout << "You Skipped this Question." << endl;
		}
		else {
			cout << "You Selected : " << options[i][userOptions[i] - 1] << endl;
		}
		cout << "Correct Option : " << correctOptions[i] << endl << endl;

		cout << "Press any key to continue..." << endl;
		getchar();
		cout << endl << "------------------" << endl;
	}

	//----- Printing Result -----
	cout << endl << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << "=======      Result     ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << endl << endl;

	int correct = 0;
	int incorrect = 0;
	int skipped = 0;
	for (int i = 0; i < totalQs; i++) {
		if (userOptions[i] != 0) {
			if (correctOptions[i] == options[i][userOptions[i] - 1]) {
				correct++;
			}
			else {
				incorrect++;
			}
		}
		else {
			skipped++;
		}
	}
	cout << "Total Questions : " << totalQs << endl;
	cout << "Correct : " << correct << endl;
	cout << "In-Correct : " << incorrect << endl;
	cout << "Skipped : " << skipped << endl;
	getchar();
}
void generalMathematics() {
	//questions
	string questions[10] = {
	"1=1?",
	"2+3=5?",
	"1*0=1?",
	"derivative of 'x'= 1?",
	"Integration of '1' = x?",
	"Integration is anti-derivation?",
	"1+2*7=15?",
	"d/dx() is also represented as f'(x)?",
	"2/4=1?",
	"2%2=0?"
	};
	//2 possibilities
	string options[10][2] = {
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	{"True","False"},
	};
	//correct options
	string correctOptions[10] = {
		"False","True","False","True",
		"True","True","True",
		"True","False","True"
	};
	int userOptions[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int totalQs = 10;

	//----- Conducting Quiz -----
	for (int i = 0; i < totalQs; i++) {
		cout << "Question # " << (i + 1) << endl;
		cout << questions[i] << endl;
		cout << "1." << options[i][0] << endl;
		cout << "2." << options[i][1] << endl;

		cout << "Select Option (1/2) or 0 to skip and press enter: ";
		cin >> userOptions[i];
		cout << endl << "-----------------------------" << endl << endl;
	}

	//----- Printing Correct Options -----
	cout << "======= ======= ======= ======= " << endl;
	cout << "======= Correct Options ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;

	for (int i = 0; i < totalQs; i++) {
		cout << "Question # " << (i + 1) << endl;
		cout << questions[i] << endl;
		cout << "1." << options[i][0] << endl;
		cout << "2." << options[i][1] << endl;

		if (userOptions[i] == 0) {
			cout << "You Skipped this Question." << endl;
		}
		else {
			cout << "You Selected : " << options[i][userOptions[i] - 1] << endl;
		}
		cout << "Correct Option : " << correctOptions[i] << endl << endl;

		cout << "Press any key to continue..." << endl;
		getchar();
		cout << endl << "------------------" << endl;
	}

	//----- Printing Result -----
	cout << endl << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << "=======      Result     ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;

	int correct = 0;
	int incorrect = 0;
	int skipped = 0;
	for (int i = 0; i < totalQs; i++) {
		if (userOptions[i] != 0) {
			if (correctOptions[i] == options[i][userOptions[i] - 1]) {
				correct++;
			}
			else {
				incorrect++;
			}
		}
		else {
			skipped++;
		}
	}
	cout << "Total Questions : " << totalQs << endl;
	cout << "Correct : " << correct << endl;
	cout << "In-Correct : " << incorrect << endl;
	cout << "Skipped : " << skipped << endl;
	getchar();
}
void searchByRoll(int lineNumber) {
	string line;
	ifstream file1;
	file1.open("studentData.txt");
	cout << endl << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << "=======  Search Result  ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << endl << endl;
	for (int i = 1; i <= lineNumber; i++) {
		getline(file1, line);
		if (file1.eof()) {
			cout << "Record not found." << endl;
			break;
		}
	}
	cout << line << endl;
	file1.close();
}
bool hasData(int lineNumber) {
	ifstream file("studentData.txt");
	if (!file.is_open()) {
		return false;
	}

	int currentLine = 1;
	string line;
	while (getline(file, line)) {
		if (currentLine == lineNumber) {
			return !line.empty();
		}
		++currentLine;
	}
	return false;
}
int main() {
	int rollForSearch, num, roll;
	ifstream newFile1;
	newFile1.open("studentRollNumber");
	if(newFile1>>num){
		newFile1 >> num;
		stud = num;
	}
	else{
		num=0;
		ofstream outfile("studentRollNumber.txt");
		outfile<<num;
		outfile.close();
	}
	newFile1.close();
	cout << endl << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << "=======     WELLCOME    ======= " << endl;
	cout << "======= ======= ======= ======= " << endl;
	cout << endl << endl;
	cout << "Welcome to Quiz Taking Program" << endl;
main:
	int option = mainMenu();
	switch (option) {
	case 1:
		registration(stud);
		saveData();
		stud++;
		goto main;
		break;
	case 2:
		cout << "Enter Roll Number: ";
		cin >> roll;
		if ((hasData(roll))) {
			cout << "Select Subject: \n1. General Knowledge\n2. General Mathematics\n";
			int op1;
			cin >> op1;
			switch (op1) {
			case 1:
				generalKnowledge();
				goto main;
				break;
			case 2:
				generalMathematics();
				goto main;
				break;
			}
		}
		else {
			cout << endl << endl;
			cout << "======= ======= ======= ======= " << endl;
			cout << "=======  SEARCH RESULT  ======= " << endl;
			cout << "======= ======= ======= ======= " << endl;
			cout << endl << endl;
			cout << "No Data Against this Roll Number.\nRegister first\n";
			cout << endl;
			goto main;
			break;
		}
	case 3:
		cout << "Enter roll Number: ";
		cin >> rollForSearch;
		searchByRoll(rollForSearch);
		goto main;
	case 4:
		cout << "Thanks For Your Time!";
		break;
	}
	ofstream newFile;
	newFile.open("studentRollNumber", ios::trunc);
	newFile << stud;
	newFile.close();
}