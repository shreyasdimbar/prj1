#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>     // file handling
#include <sstream>     // splitting string 
#include <algorithm>   // for search & sort algorithms
using namespace std;
void issueBook();
void printtotalRecords();
void printpertrecords();
void IBcopytoFile();



/* 11111111111111111 */
vector<string> AVAbookNames;

void ABcopytoVector() {
	ifstream temp("AVAbookNames.txt"); // file name is temp and accessing available books;
	string line;
	while (getline(temp, line)) {     // will copy names of bookes from the txt file to vector;
		AVAbookNames.push_back(line);
	}                                 // loop is terminated automatically after 'name list' ends;
	temp.close();
}


/*22222222222222222222*/
class information {
public:
	int PRN;
	string bookName;
};
vector<information> issued_boooks;
void IBcopytoVector() {
	ifstream temp("issued_books.txt");    // file name is temp and accessing issued books;
	string line;
	while (getline(temp, line)) {          // will copy information from the txt file to vector;
		string book,prn;                   // ss contains the line from the file;
		stringstream ss(line);             // Create stream from line;
		getline(ss,prn,',');
		getline(ss,book);
		information tempo;
		tempo.PRN = stoi(prn);             // integer as text(string) to integer;
		tempo.bookName = book;
		issued_boooks.push_back(tempo);    // pushed the integer and bookname to vector;
	}                                      // loop is terminated automatically after 'name list' ends;
	temp.close();
}

/*33333333333333333*/

void DisplaydateandTime() {
	time_t now = time(nullptr);            // get current time in seconds
	tm* localTime = localtime(&now);       // convert to local time structure
	cout << endl;
	cout << "                       " << asctime(localTime) << endl;  // convert to readable string
}

/*44444444444444444444*/

void mainMenu1() {
	cout << "   Choose any of the options below ->\n"<< endl;
	cout << "      1. Do you want to issue any Book" << endl;
	cout << "      2. Do you want to see any Perticuler Record" << endl;
	cout << "      3. Want to see total previous Records" << endl;
	cout << "      4. Close Programme" << endl;
}
void mainMenu2(int maina) {
	if(maina == 1) {
		issueBook();
	}
	else if(maina == 2) {
		printpertrecords();
	} else if(maina == 3) {
		printtotalRecords();
	}
}

/*55555555555555555555*/

void issueBook() {
	cout << "Enter the name of the Book you want to issue - " ;
	string tempbookname;
	cin.ignore();
	getline(cin,tempbookname);
	bool proceedornot = false;
	for(int i = 0 ; i < 95 ; i++) {
		if(tempbookname == AVAbookNames[i]) {
			proceedornot = true;
			break;
		}
	}
	if(proceedornot) {
		cout << "The Book is found " << endl << "Do you want to issue this Book : " ;
		string tempyesorno;
		getline(cin , tempyesorno);
		if(tempyesorno == "no" || tempyesorno == "No" || tempyesorno == "NO") {
			cout << "Okay then,\n 1.Do you want another Book \n 2.Return to main menu : ";
			int tempreturnornot;
			cin >> tempreturnornot;
			if(tempreturnornot == 1) {
				issueBook();
			} else {
				return;
			}
		} else {
			cout << "Enter your PRN : " ;
			int tempPRN;
			cin >> tempPRN;
			information tempissuedbook;
			tempissuedbook.PRN = tempPRN;
			tempissuedbook.bookName = tempbookname;
			issued_boooks.push_back(tempissuedbook);
			cout << "Book is issued Successfully" << endl << endl << endl;
		}
		
	} else {
		cout << "The book is not Found\n 1.Do you want another Book \n 2.Return to main menu : ";
		int temp2returnornot;
		cin >> temp2returnornot;
		if(temp2returnornot == 1) {
			issueBook();
		} else {
			return;
		}
	}

}
/* 666666666666666666666666 */

void IBcopytoFile() {
	ofstream temp("issued_books.txt");
	for(const auto& entry : issued_boooks) {
		temp << entry.PRN << "," << entry.bookName << endl;
	}
	temp.close();
}
/* 77777777777777777777777 */

void printtotalRecords() {
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	cout << " SR.No. |   " << " PRN      | " << " Name of The Book            |" << endl;
	cout << "------------------------------------------------------" << endl;
	for(int i = 0 ; i < issued_boooks.size() ; i++) {
		cout << "  " << (i + 1) << ".    |   " << issued_boooks[i].PRN << " |  " << issued_boooks[i].bookName << endl;
	}
}
/* 888888888888888888888888 */
void printpertrecords() {
	cout<< " Enter the PRN : ";
	int target;
	cin >> target;
	cout << "\n The Books issued by : -" << target << "- are ->" << endl;
	for(int i = 0 ; i < issued_boooks.size() ; i++) {
		if(target == issued_boooks[i].PRN) {
			cout << "  " << (i + 1) << ".    |   " << issued_boooks[i].bookName << endl;
		}
	}
}
/*99999999999999999999999999*/
void submitBook(){
	cout << "Enter your PRN : " ;
	int tempPRN;
	cin >> tempPRN;
	bool isFound = false;
	for(int i = 0 ; i < issued_boooks.size() ; i++){
		if(issued_boooks[i].PRN == tempPRN){
			
		}
	}
}
int main() {
	ABcopytoVector();
	IBcopytoVector();
	cout<< endl;
	cout << "                      <------- Welcome ------->"<< endl;

	DisplaydateandTime();
	while(true) {
		cout << endl;

		mainMenu1();
		int maina;
		cin >> maina;

		if (maina == 4) {
			cout << "-----------------------------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "      Closing Programme. Goodbye!" << endl;

			IBcopytoFile(); // Save the data
			break;
		}
		mainMenu2(maina);
		cout << "-----------------------------------------------------" << endl;
		cout << "-----------------------------------------------------" << endl;
	}
	return 0;
}