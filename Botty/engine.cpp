#include "engine.h"
#include "server.h"
#include <vector>
#include <boost/algorithm/string.hpp>

namespace botty {
	void engine::respond_to_message(message msg, server *sender) {
		if(msg.command == "PRIVMSG" &&
			msg.target == sender->get_nickname()) {
			message resp;
			resp.command = "PRIVMSG";
			resp.target = get_nick(msg.source);
			resp.data = "HAI";
			sender->message_response(resp);
		}
	}

	std::string engine::get_nick(std::string x) {
		std::vector<std::string> parts;
		boost::split(parts, x.erase(0,1), boost::is_any_of("!"));
		return parts[0];
	}
};