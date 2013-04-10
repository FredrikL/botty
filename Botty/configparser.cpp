#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "config.h"

namespace botty {
	namespace configuration {
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

			for(auto &v: pt.get_child("servers"))
			{
				auto tree = v.second;
				server s;
				s.name = tree.get<std::string>("name");
				s.nickname = tree.get<std::string>("nickname");
				s.hostname = tree.get<std::string>("hostname");
				s.port = tree.get<int>("port");

				for(auto &vt: tree.get_child("channels")) {
					s.channels.push_back(vt.second.data());
				}

				m_config->servers.push_back(s);
			}
		
		}

		const config configparser::getConfig() {
			return *m_config;
		}
	};
};