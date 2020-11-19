#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "Server.h"


using namespace std;

bool checkArgument(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: HttpServer <address> <port>\n"
			"Note: this Server just for IPv4.\n";
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if (!checkArgument(argc, argv))
		return 0;

	return 0;
}
