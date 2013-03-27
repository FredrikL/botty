#pragma once

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>

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
		void on_connect(const boost::system::error_code& error);
		void on_read(const boost::system::error_code& error, std::size_t bytes);
		void on_close();

	private:
		std::string nickname;
		std::string hostname;
		int port;
		std::vector<std::string> channels;

		boost::asio::io_service* service;
		boost::asio::ip::tcp::socket* socket;
		boost::thread* service_thread;
		boost::asio::streambuf buffer;
	};
};