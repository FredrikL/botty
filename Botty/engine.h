#pragma once

#include "messageparser.h"
#include "server.h"

namespace botty {
	class engine {
	public:
		engine() { };
		~engine() { };
		
		void respond_to_message(message, server*);
	private:
		std::string get_nick(std::string);
	};
};