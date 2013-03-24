#include <iostream>
#include "bot.h"
#include "config.h"
#include "log.h"


namespace botty {

	Bot::Bot() {
	}

	Bot::~Bot() {
		for(auto pair : connections) {
			delete pair.second;
		}
	}

	config Bot::getConfig() {
		botty::configparser parser;
		parser.load();

		botty::log::info("config loaded");
		
		return parser.getConfig();
	}

	void Bot::start() {
		auto config = getConfig();

		for(auto server : config.servers) {
			auto connection = new Connection(server.nickname, server.hostname, 
				server.port, server.channels);
			connections[server.name] = connection;
			
			connection->connect();
		}
	}

	void Bot::shutdown() {
		for(auto pair : connections) {
			pair.second->disconnect();
		}
	}
};