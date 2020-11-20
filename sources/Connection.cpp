#include "Connection.h"

namespace Http
{
	Connection::Connection(boost::asio::ip::tcp::socket socket)
			//ConnectionManager& manager,
			//RequestHandler& handler)
		: socket_(socket)
		  //, manager_(manager)
		  //, handler_(handler)
	{

	}

	Connection::~Connection()
	{
	}

	void Connection::start()
	{
		read();
	}

	void Connection::stop()
	{
		socket_.close();
	}

	void Connection::read()
	{

	}
}
