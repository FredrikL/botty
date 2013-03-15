#include "connection.h"
#include <boost\thread.hpp>

namespace botty {
	Connection::Connection(std::string nick, std::string host, int prt, std::vector<std::string> chan) :
		nickname(nick), hostname(host), port(prt), channels(chan) {
	
	}

	Connection::~Connection() {

	}

	void Connection::connect() {
	}

	void Connection::disconnect() {
	}
};