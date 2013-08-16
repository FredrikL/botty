#pragma once

#include <string>
#include <boost/signal.hpp>

namespace botty {
	struct message {
		std::string source;
		int num_id;
		std::string command;
		std::string target;
		std::string data;
	};

	class Engine {
	public:
		Engine() {};
		~Engine() {};
		message process_message(std::string);
	private:
		message parse_msg(std::string);
	};
};