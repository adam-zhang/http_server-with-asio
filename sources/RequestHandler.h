#ifndef __REQUESTHANDLER__H
#define __REQUESTHANDLER__H

#include <string>

namespace Http
{
	class RequestHandler
	{
		public:
			RequestHandler(const std::string& docRoot);
			~RequestHandler();
	};
}

#endif//__REQUESTHANDLER__H
