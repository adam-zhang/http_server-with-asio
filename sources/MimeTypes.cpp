#include "MimeTypes.h"
#include <map>

namespace Http
{
	MimeTypes::MimeTypes()
	{
	}

	MimeTypes::~MimeTypes()
	{
	}

	std::map<std::string, std::string> getMap()
	{
		static std::map<std::string, std::string> m
		{
			{"gif", "image/gif"},
				{"htm", "text/html"},
				{"html", "text/html"},
				{"jpg", "image/jpg"},
				{"png", "image/png"}
		};
		return m;
	}

	std::string MimeTypes::extentionToType(const std::string& extention)
	{
		auto m = getMap();
		if (m.find(extention) == m.npos())
			return "text/plain";
		return m[extention];
	}
}
