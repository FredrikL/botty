#include <iostream>
#include "bot.h"
#include "config.h"


namespace botty {
	void Bot::start() {
		botty::configparser parser;
		parser.load();

		auto config = parser.getConfig();

		// for each server in config.servers create a connection
	}

	void Bot::shutdown() {
	}
};