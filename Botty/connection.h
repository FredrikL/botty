#pragma once

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/signal.hpp>
#include <deque>

namespace botty {

	enum class ConnectionState { DISCONNECTED , CONNECTING, CONNECTED, AUTHED, ONLINE };

	class IConnection {
	public:
		virtual void connect() = 0;
		virtual void disconnect() = 0;
		virtual void send(std::string) = 0;
		boost::signal<void(std::string)> on_data;
		boost::signal<void()> on_connected;
	};

	class Connection : public IConnection {
	public:
		Connection(std::string nick, std::string host, int prt);
		~Connection();
		void connect();
		void disconnect();		
		void send(std::string);

	private:
		void on_connect(const boost::system::error_code& error);
		void on_read(const boost::system::error_code& error, std::size_t bytes);
		void on_close();
		void do_send(std::string);
		void on_sent(const boost::system::error_code& error);
		void async_read_until();
		bool ends_with_crlf(std::string const &);
		void process_outbox();

	private:
		std::string nickname;
		std::string hostname;
		int port;

		boost::asio::io_service* service;
		boost::asio::ip::tcp::socket* socket;
		boost::thread* service_thread;
		boost::asio::streambuf buffer;
		std::deque<std::string> outbox;
	};
};