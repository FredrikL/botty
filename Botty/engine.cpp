#include "engine.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <locale>

namespace botty {
	std::string Engine::process_message(std::string msg) {

		if(msg.compare(0,4, "PING") == 0) {
			auto loc = msg.find(" ") + 1;
			auto data = msg.substr(loc, msg.length() - loc);
			return "PONG " + data;
		}

		auto troll = parse_msg(msg);

		return "";
	}

	// TODO: replace with something fancy
	bool is_number(const std::string& s)
	{
		std::locale loc;
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it, loc)) ++it;
		return !s.empty() && it == s.end();
	}

	message Engine::parse_msg(std::string msg) {
		std::vector<std::string> parts;
		boost::split(parts, msg, boost::is_any_of(" "));

		message result;
		result.source = parts[0];
		if(is_number(parts[1])) {
			result.command = parts[2];
			result.target = parts[3];
			result.data = parts[4];
		} else {
			result.command = parts[1];
			result.target = parts[2];
			result.data = parts[3];
		}
		return result;
	}
}; 