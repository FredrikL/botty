#pragma once

#include <map>
#include <string>
#include "config.h"
#include "server.h"
#include "engine.h"

namespace botty{
	class IBot {
	public:
		virtual void start() = 0;
		virtual void shutdown() = 0;
	};

	class Bot : public IBot {
	public:
		Bot();
		~Bot();
		void start();
		void shutdown();

	private:
		botty::configuration::config getConfig();

		std::map<std::string, std::shared_ptr<server>> servers;
		std::unique_ptr<Engine> engine;
	}; 
};