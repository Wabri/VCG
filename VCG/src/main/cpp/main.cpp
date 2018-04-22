#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
//	if (argc > 2) {
//		srand(time(0));
//		string alphabeth[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
//				"B", "C", "D", "E", "F", "0" };
//		string output = "";
//		int limit = atoi(argv[1]);
//		int numberOfDigit = atoi(argv[2]);
//		if (limit > 0 && numberOfDigit > 0) {
//			for (int var = 0; var < limit; ++var) {
//				for (int rip = 0; rip < numberOfDigit; ++rip) {
//					output += alphabeth[rand() % 15];
//				}
//				output += " ";
//			}
//			cout << output << endl;
//		} else {
//			cout << "Must be enter a positive integer arguments" << endl;
//		}
//	}

	if (argc == 1) {
		cout << "### Missing an alphabeth to work with ###" << endl;
		string alphabethString = "";
		do {
			cout
					<< "### Insert the elements of alphabeth separated with comma (example: 1,2,3,A,B) ###"
					<< endl;
			cout << " Input: ";
			cin >> alphabethString;
			cout << "### You have insert: " << alphabethString << " ###" << endl
					<< "### Confirm this alphabeth? (Y: yes, N: no) ###"
					<< endl;
			cout << " Input: ";
			string response;
			cin >> response;
			while (!((response == "Y") || (response == "y") || (response == "N")
					|| (response == "n"))) {
				cout << "### You have to insert Y or N ###" << endl;
				cout << " Input: ";
				cin >> response;
			}
			if ((response == "Y") || (response == "y")) {
				cout << "### Alphabeth confirmed ###" << endl;
				response.~basic_string();
				break;
			} else if ((response == "N") || (response == "n")) {
				cout << "### Alphabeth not confirmed ###" << endl;
			}
		} while (true);
		string alphabethArray[alphabethString.size()];
		int *index = new int;
		while (true) {
			int positionComma = alphabethString.find(',');
			string newElement = alphabethString.substr(0, positionComma);
			alphabethArray[(*index)++] += newElement;
			newElement = alphabethString.substr(1 + positionComma,
					alphabethString.length());
			alphabethString = newElement;
			if (positionComma == string::npos) {
				break;
			}
		}
		alphabethString.~basic_string();
		delete index;
		cout << "### How many character must have a single element of output string? ###" << endl;
	}
	return 0;
}
