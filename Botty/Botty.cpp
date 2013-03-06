// Botty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "bot.h"

int _tmain(int argc, _TCHAR* argv[])
{
	botty::IBot* bot = new botty::Bot();

	delete bot;

	return 0;
}

