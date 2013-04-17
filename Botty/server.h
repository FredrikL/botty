#pragma once

#include "connection.h"

namespace botty {
	class server
	{
	public:
		server(std::string nick, std::string host, int prt, std::vector<std::string> chan);
		~server();
		void connect();
		void disconnect();

	private:
		void on_data(std::string);


	private:
		IConnection* connection;

		std::string nickname;
		std::string hostname;
		int port;
		std::vector<std::string> channels;

		ConnectionState state;

	};
};