#include "file-handler-settings.h"

#include <string>

namespace SausoonTech
{
	namespace FileHandler
	{
		FileHandlerSettings::FileHandlerSettings(const std::string* file_path, const std::string* file_size, const FileSizeUnitEnum* file_size_unit, const int* rotation_count)
		{
			file_path_ = *file_path;
			file_size_ = *file_size;
			file_size_unit_ = *file_size_unit;
			rotation_count_ = *rotation_count;
		}

		std::string FileHandlerSettings::get_file_path() const
		{
			return file_path_;
		}

		std::string FileHandlerSettings::get_file_size() const
		{
			return file_size_;
		}

		FileSizeUnitEnum FileHandlerSettings::get_file_size_unit() const
		{
			return file_size_unit_;
		}

		int FileHandlerSettings::get_rotation_count() const
		{
			return rotation_count_;
		}
	}
}