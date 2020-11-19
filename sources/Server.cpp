#include "Server.h"


namespace Http
{
	Server::Server(const std::string& address
			, const std::string& port
			, const std::string& docRoot)
		:context_(1)
		 , signals_(context_)
		 , acceptor_(context_)
		 , handler_(docRoot)
	{
		signals_.add(SIGINT);
		signals_.add(SIGTERM);
#ifdef SIGQUIT
		signals_.add(SIGQUIT);
#endif
		waitStop();
		boost::asio::ip::tcp::resolver resolver(context_);
		boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(address, port).begin();
		acceptor_.open(endpoint.protocol());
		acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
		acceptor_.bind(endpoint);
		acceptor_.listen();

		accept();
	}

	Server::~Server()
	{
	}

	void Server::run()
	{
		context_.run();
	}

	void Server::accept()
	{
		acceptor_.async_accept(
				[this](boost::system::error_code code, boost::asio::ip::tcp::socket socket)
				{

					if (!acceptor_.is_open())
						return;
					if(!code)
					{
						auto p = std::shared_ptr<Connection>(std::move(socket), manager_, handler_);
						manager_.start(p));
						accept();
					}
				}
				);
	}

	void Server::waitStop()
	{
		signals_.async_wait(
				[this](boost::system::error_code, int)
					acceptor_.close();
					manager_.stopAll();
				)
	}
}
