#include "ConnectionManager.h"

namespace Http
{
	ConnectionManager::ConnectionManager()
	{
	}

	ConnectionManager::~ConnectionManager()
	{
	}

	
	void ConnectionManager::start(std::shared_ptr<ConnectionManager>& value)
	{
		connections_.insert();
		value->start();
	}

	void ConnectionManager::stop(std::shared_ptr<ConnectionManager>& value)
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
