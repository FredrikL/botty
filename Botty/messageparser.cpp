#include "messageparser.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <locale>


namespace botty {
	message MessageParser::process_message(std::string msg) {
		auto parsed_msg = parse_msg(msg);

		return parsed_msg;
	}

	// TODO: replace with something fancy
	bool is_number(const std::string& s)
	{
		std::locale loc;
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it, loc)) ++it;
		return !s.empty() && it == s.end();
	}

	message MessageParser::parse_msg(std::string msg) {
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
			if(parts.size() > 2)
				result.target = parts[2];
			if(parts.size() > 3)
				result.data = parts[3];
		}
		return result;
	}
}; 