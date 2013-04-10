#pragma once

#include <string>
#include <vector>

namespace botty {
	namespace configuration {
		struct server {
			std::string nickname;
			std::string name;
			std::string hostname;
			int port;
			std::vector<std::string> channels;
		};

		struct config {
			std::string version;
			std::string ident;
			std::string name;

			std::vector<server> servers;
		};


		class configparser {
		public:
			configparser();
			~configparser();
			void load();

			const config getConfig();

		private:
			config* m_config;
		};
	};
};