#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// this is the main
int main(int argc, char **argv) {
	if (argc > 2) {
		srand(time(0));
		string alphabeth[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
				"B", "C", "D", "E", "F", "0" };
		string output = "";
		int limit = atoi(argv[1]);
		int numberOfDigit = atoi(argv[2]);
		if (limit > 0 && numberOfDigit > 0) {
			for (int var = 0; var < limit; ++var) {
				for (int rip = 0; rip < numberOfDigit; ++rip) {
					output += alphabeth[rand() % 15];
				}
				output += " ";
			}
			cout << output << endl;
		} else {
			cout << "Must be enter a positive integer arguments" << endl;
		}
	}
	return 0;
}
/* This must
 * be longer
 */
