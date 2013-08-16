#pragma once

#include "messageparser.h"


namespace botty {
	class Engine {
	public:
		Engine();
		~Engine();
		
		void respond_to_message(message msg);
	private:
	};
};