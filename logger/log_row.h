#ifndef SAUSOON_TECH_LOGGER_LOG_ROW_H
#define SAUSOON_TECH_LOGGER_LOG_ROW_H

#include "log_message_type_enum.h"

#include <string>

namespace SausoonTech
{
	namespace Logger
	{
		class LogRow
		{
		private:
			LogMessageTypeEnum log_message_type_;
			std::string message_;
		public:
			LogRow(const LogMessageTypeEnum* log_message_type, const std::string* message);
			LogMessageTypeEnum get_log_message_type() const;
			std::string get_message() const;
		};
	}
}
#endif