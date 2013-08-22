#pragma once

#include "connection.h"
#include "messageparser.h"
#include <boost/signal.hpp>

namespace botty {
	class server
	{
	public:
		server(std::string nick, std::string host, int prt, std::vector<std::string> chan);
		~server();
		void connect();
		void disconnect();
		boost::signal<void(message, server*)> on_message;
		void message_response(message);
		const std::string get_nickname();

	private:
		void on_data(std::string);
		void on_connected();
		void on_authed();

	private:
		std::unique_ptr<IConnection> connection;

		std::string nickname;
		std::string hostname;
		int port;
		std::vector<std::string> channels;

		ConnectionState state;
		MessageParser engine;

	};
};