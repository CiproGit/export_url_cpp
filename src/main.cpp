#include "bifile.h"
#include <iostream>

int main(void) {
	std::string input_file_path;
	std::string output_file_path;

	std::cout << "******************\n";
	std::cout << "*   EXPORT URL   *\n";
	std::cout << "******************" << std::endl;

	std::cout << "\nInsert the input file including path:" << std::endl;
	std::cin >> input_file_path;

	std::cout << "\nInsert the output file including path:" << std::endl;
	std::cin >> output_file_path;

	bifile::Bifile bifile(input_file_path, output_file_path);
	if (!bifile.is_really_open()) {
		std::cerr << "Error opening files" << std::endl;
		exit(EXIT_FAILURE);
	}

	bifile.export_url();
	bifile.reopen();
	bifile.count_url();

	bifile.~Bifile();

	return EXIT_SUCCESS;
}
