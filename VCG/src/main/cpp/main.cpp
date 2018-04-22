#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "### Missing an alphabeth to work with ###" << endl;
		string alphabethString;
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
		string characters;
		do {
			cout
					<< "### How many characters must have a single element of output string? (example: 2 characters 1A, 3 characters B3F)###"
					<< endl;
			cout << " Input: ";
			cin >> characters;
			cout << "### You have insert: " << characters << " ###" << endl
					<< "### Confirm this number of characters? (Y: yes, N: no) ###"
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
				cout << "### Number of characters confirmed ###" << endl;
				response.~basic_string();
				break;
			} else if ((response == "N") || (response == "n")) {
				cout << "### Number of characters not confirmed ###" << endl;
			}
		} while (true);
		int numberOfCharacters = atoi(characters.c_str());
		characters.~basic_string();
		string elements;
		do {
			cout
					<< "### How many output elements do you want? (example: 3 elements in output -> AB CD 35, 4 elements in output -> AB CD 35 13)###"
					<< endl;
			cout << " Input: ";
			cin >> elements;
			cout << "### You have insert: " << elements << " ###" << endl
					<< "### Confirm this number of elements in output? (Y: yes, N: no) ###"
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
				cout << "### Number of elements in output confirmed ###"
						<< endl;
				response.~basic_string();
				break;
			} else if ((response == "N") || (response == "n")) {
				cout << "### Number of elements in output not confirmed ###"
						<< endl;
			}
		} while (true);
		int numberOfElements = atoi(elements.c_str());
		elements.~basic_string();
		string output;
		for (int var = 0; var < numberOfElements; ++var) {
			for (int rip = 0; rip < numberOfCharacters; ++rip) {
				output += alphabethArray[rand() % 15];
			}
			output += " ";
		}
		cout << "### Output ###" << endl << output << endl;
	}
	return 0;
}
