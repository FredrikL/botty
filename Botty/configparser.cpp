#include <boost/property_tree/ptree.hpp>
#include "config.h"


namespace botty {
	configparser::configparser() {

	}

	configparser::~configparser() {
		delete m_config;
	}

	const config configparser::getConfig() {
		return config();
	}
};