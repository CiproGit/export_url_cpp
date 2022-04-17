#include "bifile.h"
#include <iostream>

using namespace std;

namespace bifile {
	Bifile::Bifile(string input_file, string output_file) {
		this->input_file.open(input_file, ifstream::in);
		if (this->input_file.is_open()) this->output_file.open(output_file, ofstream::out | ofstream::trunc);
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
		string string;
		size_t i;

		while (getline(this->input_file, string)) { // Read a line of input from input_file
			i = string.find(URL); // Search URL in string

			if (i != string::npos) {
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
		string string;
		size_t i;
		unsigned int count = 0;

		while (getline(this->input_file, string)) { // Read a line of input from input_file
			i = string.find(URL); // Search URL in string

			if (i != string::npos) count++; // Count URLs
		}

		cout << "Number of URLs found: " << count << endl;
	}
} /* namespace bifile */
