#ifndef __MIMETYPES__H
#define __MIMETYPES__H

namespace Http
{
	class MimeTypes
	{
		private:
			MimeTypes();
			~MimeTypes();
		public:
			static std::string extentionToType(const std::string& extention);
	};
}
#endif//__MIMETYPES__H
