#ifndef __CONNECTIONMANAGER__H
#define __CONNECTIONMANAGER__H

#include <set>

namespace Http
{
	class ConnectionManager
	{
		public:
			ConnectionManager(const ConnectionManager&);
			ConnectionManager& operator=(const ConnectionManager&);
			ConnectionManager();
			~ConnectionManager();
		public:
			void start(std::shared_ptr<Connection>& value);
			void stop(std::shared_ptr<Connection>& value);
			void stopAll();

		private:
			std::set<std::shared_ptr<Connection>> connections_;
	};

}

#endif//__CONNECTIONMANAGER__H
