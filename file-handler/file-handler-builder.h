#ifndef SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_BUILDER_H
#define SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_BUILDER_H

#include "file-handler-settings.h"

#include <queue>

namespace SausoonTech
{
	namespace FileHandler
	{
		class FileHandlerBuilder
		{
		private:
			std::queue<FileHandlerSettings> file_handlers_settings_;
		public:

		};
	}
}

#endif