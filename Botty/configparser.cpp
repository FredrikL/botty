#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "config.h"


namespace botty {
	configparser::configparser() {

	}

	configparser::~configparser() {
		delete m_config;
	}

	void configparser::load() {
		m_config = new config;

		using boost::property_tree::ptree;
		ptree pt;

		boost::property_tree::json_parser::read_json("config.json", pt);

		m_config->version = pt.get<std::string>("version");
		
	}

	const config configparser::getConfig() {
		return *m_config;
	}
};