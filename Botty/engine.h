#pragma once

#include "messageparser.h"
#include "server.h"

namespace botty {
	class Engine {
	public:
		Engine() { };
		~Engine() { };
		
		void respond_to_message(message, server*);
	};
};