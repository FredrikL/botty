// Botty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "bot.h"


int mymain() {
	botty::IBot* bot = new botty::Bot();
	
	bot->start();
	
	delete bot;

	return 0;
}

#if _WIN32
int _tmain(int argc, _TCHAR* argv[])
{
	return mymain();
}
#endif