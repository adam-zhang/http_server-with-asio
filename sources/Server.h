#ifndef __SERVER__H
#define __SERVER__H

#include <boost/asio.hpp>
#include <string>
#include "Connection.h"
#include "ConnectionManager.h"
#include "RequestHandler.h"

namespace Http
{
	class Server
	{
		public:
			Server(const Server&);
			Server& operator=(const Server&);
			Server(const std::string& address, const std::string& port, const std::string& doc_root);
			~Server();

			void run();
		private:
			void accept();
			void waitStop();
			boost::asio::io_context context_;
			boost::asio::signal_set signals_;
			boost::asio::ip::tcp::acceptor acceptor_;
			ConnectionManager manager_;
			RequestHandler handler_;
	};
}
#endif//__SERVER__H
