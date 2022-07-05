#ifndef SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_SETTINGS_H
#define SAUSOON_TECH_FILE_HANDLER_FILE_HANDLER_SETTINGS_H

#include "file-size-unit-enum.h"

#include <string>

namespace SausoonTech
{
	namespace FileHandler
	{
		class FileHandlerSettings
		{
		private:
			std::string file_path_;
			std::string file_size_;
			FileSizeUnitEnum file_size_unit_;
			int rotation_count_;
		public:
			FileHandlerSettings(const std::string* file_path, const std::string* file_size, const FileSizeUnitEnum* file_size_unit, const int* rotation_count);
			std::string get_file_path() const;
			std::string get_file_size() const;
			FileSizeUnitEnum get_file_size_unit() const;
			int get_rotation_count() const;
		};
	}
}

#endif