#pragma once

#include <string>
#include <vector>

namespace botty {
	class IConnection {
	public:
		virtual void connect() = 0;
		virtual void disconnect() = 0;
	};

	class Connection : public IConnection {
	public:
		Connection(std::string nickname, std::string hostname, int port, std::vector<std::string> channels);
		~Connection();
		void connect();
		void disconnect();
	};
};