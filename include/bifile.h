#ifndef BIFILE_H_
#define BIFILE_H_

#include <fstream>
#include <string>

namespace bifile {
	const std::string URL = "http";

	class Bifile {
	private:
		std::ifstream input_file;
		std::ofstream output_file;
	public:
		Bifile(std::string input_file, std::string output_file);
		virtual ~Bifile();
		bool is_really_open() const;
		void reopen();
		void export_url();
		void count_url();
	};
} /* namespace bifile */

#endif /* BIFILE_H_ */
