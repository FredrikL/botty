#include "engine.h"
#include <vector>
#include <boost/algorithm/string.hpp>

namespace botty {
	std::string Engine::process_message(std::string msg) {

		if(msg.compare(0,4, "PING") == 0) {
			auto loc = msg.find(" ") + 1;

			auto data = msg.substr(loc, msg.length() - loc);
			return "PONG " + data;
		}

		//auto troll = parse_msg(msg);

		return "";
	}

	message Engine::parse_msg(std::string msg) {
		/*std::vector<std::string> parts;
		boost::split(parts, msg, boost::is_any_of(" "));*/

		message result;
		/*result.source = parts[0];
		result.command = parts[1];
		result.target = parts[2];
		result.data = parts[3];*/

		return result;
	}
}; 