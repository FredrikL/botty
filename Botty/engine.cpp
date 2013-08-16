#include "engine.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <locale>
#include "irc_codes.h"

namespace botty {
	std::string Engine::process_message(std::string msg) {

		if(msg.compare(0,4, "PING") == 0) {
			auto loc = msg.find(" ") + 1;
			auto data = msg.substr(loc, msg.length() - loc);
			return "PONG " + data;
		}

		auto parsed_msg = parse_msg(msg);
		if((parsed_msg.num_id == codes::ERR_NOMOTD) ||
			(parsed_msg.num_id == codes::RPL_ENDOFMOTD)) {
			on_authed();
		}

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
			result.num_id = atoi(parts[1].c_str());
			result.command = parts[2];
			result.target = parts[3];
			result.data = parts[4];
		} else {
			result.command = parts[1];
			result.target = parts[2];
			if(parts.size() > 3)
				result.data = parts[3];
		}
		return result;
	}
}; 