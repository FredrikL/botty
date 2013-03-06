#pragma once

#include <string>

namespace botty {

	struct config {
		std::string version;
		std::string ident;
		std::string name;
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