#include "bifile.h"
#include <iostream>

namespace bifile {
	#define URL "http"

	Bifile::Bifile(std::string input_file, std::string output_file) {
		this->input_file.open(input_file, std::ifstream::in);
		if (this->input_file.is_open()) this->output_file.open(output_file, std::ofstream::out | std::ofstream::trunc);
	}

	Bifile::~Bifile() {
		this->input_file.close();
		this->output_file.close();
	}

	bool Bifile::is_really_open() const {
		return this->input_file.is_open() && this->output_file.is_open();
	}

	void Bifile::reopen() {
		this->input_file.clear();
		this->input_file.seekg(0);

		this->output_file.clear();
		this->output_file.seekp(0);
	}

	void Bifile::export_url() {
		std::string string;
		std::size_t i;

		while (std::getline(this->input_file, string)) { // Read a line of input from input_file
			i = string.find(URL); // Search URL in string

			if (i != std::string::npos) {
				for (; ; i++) {
					// Write to output_file by truncating
					if (string[i] == '\0' || string[i] == ' ' || string[i] == '"') {
						this->output_file.put('\n');
						break;
					}

					this->output_file.put(string[i]);
				}
			}
		}
	}

	void Bifile::count_url() {
		std::string string;
		std::size_t i;
		unsigned int count = 0;

		while (std::getline(this->input_file, string)) { // Read a line of input from input_file
			i = string.find(URL); // Search URL in string

			if (i != std::string::npos) count++; // Count URLs
		}

		std::cout << "Number of URLs found: " << count << std::endl;
	}
} /* namespace bifile */
