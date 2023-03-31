#ifndef FORMAT_HPP
#define FORMAT_HPP

#include "Commons.hpp"

class Format{

	public:

		std::string color_yellow();
		std::string color_reset();
		std::string NewPrompt();
		void display_menu();
		bool check_eof();
		void msg_exiting_program(void);
		void msg_invalid_cmd(void);
		void display_header(std::string header);
		std::string column(std::string text);
		bool whitespaces(std::string input);
};

#endif