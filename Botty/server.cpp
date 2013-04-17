#include "server.h"

namespace botty {
	server::server(std::string nick, std::string host, int prt, std::vector<std::string> chan) :
		nickname(nick), hostname(host), port(prt), channels(chan)
	{
		connection = new Connection(nickname, hostname, port, channels);
	}


	server::~server()
	{
		delete connection;
	}

	void server::connect() {
		connection->connect();
	}

	void server::disconnect() {
		connection->disconnect();
	}
}