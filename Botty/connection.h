#pragma once

#include <iostream>

namespace botty {
	class IConnection {
	public:
		virtual void connect() = 0;
		virtual void disconnect() = 0;
		virtual const std::string getName() = 0;
		virtual const std::string getHostname() = 0;
		virtual const int getPort() = 0;
	};

	class Connection : public IConnection {
	public:
		Connection();
		~Connection();
	};
};