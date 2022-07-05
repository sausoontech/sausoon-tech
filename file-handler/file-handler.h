#ifndef SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_H
#define SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_H

#include "file-handler-settings.h"

#include <thread>

namespace SausoonTech
{
	namespace FileHandler
	{
		class FileHandler
		{
		private:
			FileHandlerSettings file_handler_settings_;
			std::thread data_writer_thread_;
		public:
		};
	}
}

#endif