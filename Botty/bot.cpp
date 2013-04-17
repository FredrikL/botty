#include <iostream>
#include "bot.h"
#include "config.h"
#include "log.h"
#include "server.h"


namespace botty {

	Bot::Bot() {
	}

	Bot::~Bot() {
		for(auto pair : servers) {
			delete pair.second;
		}
	}

	botty::configuration::config Bot::getConfig() {
		botty::configuration::configparser parser;
		parser.load();

		botty::log::info("config loaded");
		
		return parser.getConfig();
	}

	void Bot::start() {
		auto config = getConfig();

		for(auto s : config.servers) {
			auto srv =  new server(s.nickname, s.hostname, s.port, s.channels);
			servers[s.name] = srv;
			
			srv->connect();
		}
	}

	void Bot::shutdown() {
		for(auto pair : servers) {
			pair.second->disconnect();
		}
	}
};