#pragma once

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace botty {
	class IConnection {
	public:
		virtual void connect() = 0;
		virtual void disconnect() = 0;
	};

	class Connection : public IConnection {
	public:
		Connection(std::string nick, std::string host, int prt, std::vector<std::string> chan);
		~Connection();
		void connect();
		void disconnect();

	private:
		std::string nickname;
		std::string hostname;
		int port;
		std::vector<std::string> channels;

		boost::asio::io_service* service;
		boost::asio::ip::tcp::socket* socket;
		boost::thread* service_thread;
	};
};