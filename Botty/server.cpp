#include <boost/bind.hpp>
#include "connection.h"
#include "server.h"

namespace botty {
	server::server(std::string nick, std::string host, int prt, std::vector<std::string> chan) :
		nickname(nick), hostname(host), port(prt), channels(chan), state(ConnectionState::DISCONNECTED)
	{
		connection = new Connection(nickname, hostname, port);

		connection->on_data.connect(boost::bind(&server::on_data, this, _1));
		connection->on_connected.connect(boost::bind(&server::on_connected, this));
	}

	server::~server()
	{
		delete connection;
	}

	void server::connect() {
		state = ConnectionState::CONNECTING;
		
		connection->connect();
	}

	void server::disconnect() {
		state = ConnectionState::DISCONNECTED;
		connection->send("QUIT bye bye!");
		connection->disconnect();
	}

	void server::on_data(std::string data) {
		std::cout << data << std::endl;
		auto response = engine.process_message(data);
		if(response.length() > 0)
			connection->send(response);
	}

	void server::on_connected() {
		state = ConnectionState::CONNECTED;
		connection->send("NICK " + nickname);
		connection->send("USER " + nickname + " 0 * :botty the bot");
		state = ConnectionState::AUTHED;
	}
}