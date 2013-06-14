#include "connection.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>

namespace botty {
	Connection::Connection(std::string nick, std::string host, int prt, std::vector<std::string> chan) :
		nickname(nick), hostname(host), port(prt), channels(chan), service(0), socket(0), service_thread(0) {
	
	}

	Connection::~Connection() {
		delete service;
		delete socket;
		delete service_thread;
	}

	void Connection::connect() {
		using boost::asio::ip::tcp;

		service = new boost::asio::io_service;

		tcp::resolver resolver(*service);
		tcp::resolver::query query(hostname, std::to_string(port));
		auto iterator = resolver.resolve(query);

		socket = new tcp::socket(*service);

		boost::asio::async_connect(*socket, iterator,
			boost::bind(&Connection::on_connect, this, boost::asio::placeholders::error));

		service_thread = new boost::thread(boost::bind(&boost::asio::io_service::run, service));
	}

	void Connection::disconnect() {
		service->post(boost::bind(&Connection::on_close, this));

		service_thread->join();
	}

	void Connection::async_read_until() {
		boost::asio::async_read_until(*socket, 
				buffer, '\n',
				boost::bind(&Connection::on_read, this, 
					boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

	}

	void Connection::on_connect(const boost::system::error_code& error) {
		if(!error) {
			on_connected();

			async_read_until();
		} else {
			std::cout << "error: " <<  std::endl;
		}
	}

	void Connection::on_read(const boost::system::error_code& error, std::size_t bytes) {
		if(!error) {
			std::cout << "data" << std::endl;
			
			boost::asio::streambuf::const_buffers_type bufs = buffer.data();
			std::string msg(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + bytes);
			buffer.consume(bytes);
			on_data(msg);

			async_read_until();

		} else {

			std::cout << "read error: " << std::endl;
		}
	}

	void Connection::on_close() {
		socket->close();
	}

	// todo: send queue
	void Connection::send(std::string msg) {
		service->post(boost::bind(&Connection::do_send, this, msg));
	}

	void Connection::do_send(std::string msg) {
		boost::asio::async_write(*socket,
			boost::asio::buffer(msg.c_str(), msg.size()),
			boost::bind(&Connection::on_sent, this,
				boost::asio::placeholders::error));

	}

	void Connection::on_sent(const boost::system::error_code& error) {
		if(error) {
			std::cout << "write error" <<std::endl;
		}
	}
};