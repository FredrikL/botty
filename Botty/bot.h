#pragma once

#include <map>
#include <string>
#include "connection.h"

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
		std::map<std::string, IConnection*> connections;
	}; 
};