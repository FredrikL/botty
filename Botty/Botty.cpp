// Botty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "bot.h"
#include <boost/thread.hpp>
#if TESTING
#include <bandit/bandit.h>
#endif

void botthread() {
	botty::IBot* bot = 0;
	
	try {
		bot = new botty::Bot();
	
		bot->start();
	} catch(boost::thread_interrupted&) {
	}
	
	delete bot;
}

int mymain() {
	boost::thread t(botthread);
	char input;

	do {
		std::cout << "press q to terminate" << std::endl;
		input = std::cin.get();
	} while(input != 'q');
	
	t.interrupt();
	t.join();

	return 0;
}

#if _WIN32
int _tmain(int argc, _TCHAR* argv[])
{
#if TESTING
	return bandit::run(argc, nullptr);
#else
	return mymain();
#endif
}
#endif