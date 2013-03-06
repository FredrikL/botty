// Botty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "bot.h"
#include "config.h"


int _tmain(int argc, _TCHAR* argv[])
{
	botty::configparser parser;
	parser.load();

	auto config = parser.getConfig();

	std::cout <<  config.version;
	

/*	botty::IBot* bot = new botty::Bot();

	delete bot;
	*/
	return 0;
}

