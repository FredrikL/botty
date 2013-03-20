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
		service = new boost::asio::io_service;
	}

	void Connection::disconnect() {
		service_thread->join();
	}
};