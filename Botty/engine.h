#pragma once

#include <string>

namespace botty {
	struct message {
		std::string source;
		std::string command;
		std::string target;
		std::string data;
	};

	class Engine {
	public:
		std::string process_message(std::string);

	private:
		message parse_msg(std::string);
	};
};