#include "bifile.h"
#include <iostream>

using namespace std;

int main(void) {
	cout << "**********************\n";
	cout << "*     EXPORT URL     *\n";
	cout << "**********************\n" << endl;

	string input_file_path;
	string output_file_path;

	cout << "\nInsert the input file including path:" << endl;
	cin >> input_file_path;

	cout << "\nInsert the output file including path:" << endl;
	cin >> output_file_path;

	bifile::Bifile bifile(input_file_path, output_file_path);
	if (!bifile.is_really_open()) {
		cerr << "Error opening files" << endl;
		return EXIT_FAILURE;
	}

	bifile.export_url();
	bifile.reopen();
	bifile.count_url();

	bifile.~Bifile();

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
