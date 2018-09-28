#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

namespace {
const char* VERSION = "1.0.1";
const char* NO_CONFIG_FILE = "-no-config-file-";
}

using namespace std;

bool responseIsYesOrNot(const string& response) {
	return ((response == "ye") || (response == "Ye") || (response == "yE")
			|| (response == "YE") || (response == "yES") || (response == "YeS")
			|| (response == "yeS") || (response == "yEs") || (response == "yes")
			|| (response == "YES") || (response == "YEs") || (response == "Yes")
			|| (response == "Y") || (response == "y") || (response == "N")
			|| (response == "n") || (response == "no") || (response == "nO")
			|| (response == "No") || (response == "NO"));
}

bool confirmationRequest(const string& inputConfirm) {
	cout << "### " + inputConfirm + " (Y: yes, N: no) ###" << endl;
	cout << " Input: ";
	string response;
	cin >> response;
	while (!responseIsYesOrNot(response)) {
		cout << "### You have to insert Y or N ###" << endl;
		cout << " Input: ";
		cin >> response;
	}
	if (responseIsYesOrNot(response)) {
		cout << "### Confirmed ###" << endl << endl;
		return true;
	} else if ((response == "N") || (response == "n")) {
		cout << "### Not confirmed ###" << endl << endl;
		return false;
	}
	return false;
}

void stringRequest(string* hereTheResult, const string& firstInput,
		const string& inputConfirm) {
	do {
		cout << "### " + firstInput + " ###" << endl;
		cout << " Input: ";
		cin >> *hereTheResult;
		cout << "### You have insert: " << *hereTheResult << " ###" << endl;
	} while (!confirmationRequest(inputConfirm));
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

void extractStringOutputFromAlphabeth(string *hereTheResult, string alphabeth[],
		int sizeOfAlphabeth, int numberOfElements, int numberOfCharacters) {
	srand(time(0));
	for (int var = 0; var < numberOfElements; ++var) {
		for (int rip = 0; rip < numberOfCharacters; ++rip) {
			*hereTheResult += alphabeth[rand() % sizeOfAlphabeth];
		}
		*hereTheResult += " ";
	}
}

int* extractNumberOfOutputElementsFromTerminal() {
	cout << "### Number of elements ###" << endl;
	string elements;
	stringRequest(&elements,
			"How many output elements do you want? (example: 3 elements in output -> AB CD 35, 4 elements in output -> AB CD 35 13)",
			"Confirm this number of elements in output?");
	int* numberOfElements = new int;
	*numberOfElements = atoi(elements.c_str());
	elements.~basic_string();
	return numberOfElements;
}

int* extractNumberOfCharactersOfSingleElementFromTerminal() {
	cout << "### Number of characters ###" << endl;
	string characters;
	stringRequest(&characters,
			"How many characters must have a single element of output string? (example: 2 characters 1A, 3 characters B3F)",
			"Confirm this number of characters?");
	int* numberOfCharacters = new int;
	*numberOfCharacters = atoi(characters.c_str());
	characters.~basic_string();
	return numberOfCharacters;
}

string* extractArrayAlphabeth(int* numberOfElementsInAlphabeth,
		string* temporaryAlphabeth) {
	string* alphabethArray = new string[*numberOfElementsInAlphabeth];
	for (int index = 0; index < *numberOfElementsInAlphabeth; index++) {
		alphabethArray[index] = temporaryAlphabeth[index];
	}

	return alphabethArray;
}

int* extractAlphabethFromTerminal(string*& alphabethArray) {
	cout << endl << "### Alphabeth ###" << endl;
	string alphabethString;
	stringRequest(&alphabethString,
			"Insert the elements of alphabeth separated with comma (example: 1,2,3,A,B)",
			"Confirm this alphabeth?");
	string* cleanAlphabethString = new string[alphabethString.size()];
	int* numberOfElementsInAlphabeth = new int;
	*numberOfElementsInAlphabeth = extractAlphabethFromString(
			cleanAlphabethString, &alphabethString);
	alphabethString.~basic_string();
	alphabethArray = extractArrayAlphabeth(numberOfElementsInAlphabeth,
			cleanAlphabethString);
	delete[] cleanAlphabethString;
	return numberOfElementsInAlphabeth;
}

void mainRequest(const string& configFileName) {
	if (string(configFileName) == NO_CONFIG_FILE) {
		string* alphabethArray;
		int* numberOfElementsInAlphabeth = extractAlphabethFromTerminal(alphabethArray);
		int* numberOfCharacters = extractNumberOfCharactersOfSingleElementFromTerminal();
		int* numberOfElements = extractNumberOfOutputElementsFromTerminal();
		string output;
		extractStringOutputFromAlphabeth(&output, alphabethArray,
				*numberOfElementsInAlphabeth, *numberOfElements,
				*numberOfCharacters);
		cout << "### Output ###" << endl << output << endl;
		output.~basic_string();
		delete numberOfElements;
		delete numberOfCharacters;
		delete[] alphabethArray;
		delete numberOfElementsInAlphabeth;
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		mainRequest(NO_CONFIG_FILE);
	} else if (argc == 2) {
		if (string(argv[1]) == "--help") {
			cout << "usage: VCG [--version] [--help] " << endl;
		} else if (string(argv[1]) == "--version" || string(argv[1]) == "-v") {
			cout << "VCG version" + string(VERSION) << endl;
		} else if (string(argv[1]) == "--config" || string(argv[1]) == "-c") {
			cout << "You have to insert the name of the file:" << endl
					<< " VCG [-c <path>] [--config <path>]" << endl;
		}
	} else if (argc == 3) {
		ifstream configFile;
		if (string(argv[1]) == "--config" || string(argv[1]) == "-c") {
			cout << "Try open file: " << argv[2] << endl;
			configFile.open(argv[2]);
			if (configFile.is_open()) {
				cout << "Successfully open" << endl;
			} else {
				cout << "Unsuccessfully open" << endl;
				if (confirmationRequest(
						"Do you want to create new configuration file?")) {
					mainRequest(argv[2]);
					return 0;
				}
			}
			configFile.close();
		}
	}
	return 0;
}
