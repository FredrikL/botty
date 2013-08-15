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
		std::string process_message(std::string);
		message parse_msg(std::string);
		boost::signal<void()> on_authed;
	};
};