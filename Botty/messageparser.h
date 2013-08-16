#pragma once

#include <string>

namespace botty {
	struct message {
		std::string source;
		int num_id;
		std::string command;
		std::string target;
		std::string data;
	};

	class MessageParser {
	public:
		MessageParser() {};
		~MessageParser() {};
		message process_message(std::string);
	private:
		message parse_msg(std::string);
	};
};