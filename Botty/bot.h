#pragma once

namespace botty{
	class IBot {
	public:
		virtual void start() = 0;
		virtual void restart() = 0;
		virtual void shutdown() = 0;
	};

	class Bot : public IBot {
	public:
		void start();
		void restart();
		void shutdown();
	}; 
};