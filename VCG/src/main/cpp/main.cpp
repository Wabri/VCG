#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void stringRequest(string* hereTheResult, string firstInput,
		string inputConfirm) {
	do {
		cout << "### " + firstInput + " ###" << endl;
		cout << " Input: ";
		cin >> *hereTheResult;
		cout << "### You have insert: " << *hereTheResult << " ###" << endl
				<< "### " + inputConfirm + " (Y: yes, N: no) ###" << endl;
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
			cout << "### Confirmed ###" << endl << endl;
			response.~basic_string();
			break;
		} else if ((response == "N") || (response == "n")) {
			cout << "### Not confirmed ###" << endl << endl;
		}
	} while (true);
}

int extractAlphabethFromString(string hereTheResult[], string *extractThis) {
	int *index = new int;
	int counter = 0;
	while (true) {
		int positionComma = extractThis->find(',');
		string newElement = extractThis->substr(0, positionComma);
		hereTheResult[(*index)++] += newElement;
		newElement = extractThis->substr(1 + positionComma,
				extractThis->length());
		*extractThis = newElement;
		counter++;
		if (positionComma == string::npos) {
			delete index;
			return counter;
		}
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << endl << "### Alphabeth ###" << endl;
		string alphabethString;
		stringRequest(&alphabethString,
				"Insert the elements of alphabeth separated with comma (example: 1,2,3,A,B)",
				"Confirm this alphabeth?");
		string *temp = new string[alphabethString.size()];
		int numberOfElementsInAlphabeth = 0;
		numberOfElementsInAlphabeth = extractAlphabethFromString(temp,
				&alphabethString);
		alphabethString.~basic_string();
		string alphabethArray[numberOfElementsInAlphabeth];
		for (int index = 0; index < numberOfElementsInAlphabeth; index++) {
			alphabethArray[index] = temp[index];
		}
		delete[] temp;

		cout << "### Number of characters ###" << endl;
		string characters;
		stringRequest(&characters,
				"How many characters must have a single element of output string? (example: 2 characters 1A, 3 characters B3F)",
				"Confirm this number of characters?");
		int numberOfCharacters = atoi(characters.c_str());
		characters.~basic_string();

		cout << "### Number of elements ###" << endl;
		string elements;
		stringRequest(&elements,
				"How many output elements do you want? (example: 3 elements in output -> AB CD 35, 4 elements in output -> AB CD 35 13)",
				"Confirm this number of elements in output?");
		int numberOfElements = atoi(elements.c_str());
		elements.~basic_string();

		srand(time(0));
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
