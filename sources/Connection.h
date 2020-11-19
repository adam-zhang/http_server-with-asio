#ifndef __CONNECTION__H
#define __CONNECTION__H


namespace Http
{

	class Connection
	{
		public:
			Connection();
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
			Reply reply_;
	};
}

#endif//__CONNECTION__H
