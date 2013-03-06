#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "config.h"


namespace botty {
	configparser::configparser() {
		m_config = new config;
	}

	configparser::~configparser() {
		delete m_config;
	}

	void configparser::load() {
		using boost::property_tree::ptree;
		ptree pt;

		boost::property_tree::json_parser::read_json("config.json", pt);

		m_config->version = pt.get<std::string>("version");
		m_config->ident = pt.get<std::string>("ident");
		m_config->name = pt.get<std::string>("name");
		
	}

	const config configparser::getConfig() {
		return *m_config;
	}
};