#include <iostream>
#include "bot.h"
#include "config.h"
#include "server.h"
#include "engine.h"

namespace botty {

	Bot::Bot() {
		_engine = std::unique_ptr<engine>(new engine());
	}

	Bot::~Bot() {
		for(auto pair : servers) {
			pair.second.reset();
		}
	}

	botty::configuration::config Bot::getConfig() {
		botty::configuration::configparser parser;
		parser.load();

		return parser.getConfig();
	}

	void Bot::start() {
		auto config = getConfig();

		for(auto s : config.servers) {
			auto srv =  std::shared_ptr<server>(new server(s.nickname, s.hostname, s.port, s.channels));
			servers[s.name] = srv;
			
			srv->connect();
			
			srv->on_message.connect(boost::bind(&engine::respond_to_message, *_engine, _1, _2));
		}
	}

	void Bot::shutdown() {
		for(auto pair : servers) {
			pair.second->disconnect();
		}
	}
};