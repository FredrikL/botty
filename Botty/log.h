#pragma once

#include <string>

namespace botty{
	namespace log {
		void print(std::string msg) {
			std::cout << msg << std::endl;
		}

		void debug(std::string msg) {
			print(msg);
		}

		void info(std::string msg) {
			print(msg);
		}

		void error(std::string msg) {
			print(msg);
		}
	}
}