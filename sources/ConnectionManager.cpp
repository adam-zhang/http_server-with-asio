#include "ConnectionManager.h"
#include "Connection.h"

namespace Http
{
	ConnectionManager::ConnectionManager()
	{
	}

	ConnectionManager::~ConnectionManager()
	{
	}

	
	void ConnectionManager::start(std::shared_ptr<Connection>& value)
	{
		connections_.insert(value);
		value->start();
	}

	void ConnectionManager::stop(std::shared_ptr<Connection>& value)
	{
		connections_.erase(value);
		value->stop();
	}

	void ConnectionManager::stopAll()
	{
		for(auto c : connections_)
			c->stop();
		connections_.clear();
	}

}
