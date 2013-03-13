#include <iostream>
#include "bot.h"
#include "config.h"


namespace botty {

	Bot::Bot() {
	}

	Bot::~Bot() {
		for(auto pair : connections) {
			delete pair.second;
		}
	}

	void Bot::start() {
		botty::configparser parser;
		parser.load();

		auto config = parser.getConfig();

		// for each server in config.servers create a connection
		for(auto server : config.servers) {
			auto connection = new Connection(server.nickname, server.hostname, 
				server.port, server.channels);
			connections[server.name] = connection;
		}
	}

	void Bot::shutdown() {
		for(auto pair : connections) {
			pair.second->disconnect();
		}
	}
};