#ifndef __CONNECTION__H
#define __CONNECTION__H


namespace Http
{
	class ConnectionManager;

	class Connection : public std::enable_shared_from_this<Connection>
	{
		public:
			Connection(const Connection&);
			Connection& operator=(const Connection&);
			Connection(boost::asio::ip::tcp::socket, ConnectionManager& manager, RequestHandler& handler);
			~Connection();
			void start();
			void stop();
		private:
			void read();
			void write();
			boost::asio::ip::tcp::socket socket_;
			ConnectionManager& manager_;
			std::array<char, 8192> buffer_;
			Request request_;
			RequestParser parser_;
			RequestHandler handler_;
			Reply reply_;
	};
}

#endif//__CONNECTION__H
