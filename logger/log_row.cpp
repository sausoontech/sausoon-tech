#include "log_row.h"
#include "log_message_type_enum.h"

#include <string>

namespace SausoonTech
{
	namespace Logger
	{
		LogRow::LogRow(const LogMessageTypeEnum* log_message_type, const std::string* message)
		{
			log_message_type_ = *log_message_type;
			message_ = *message;
		}

		LogMessageTypeEnum LogRow::get_log_message_type() const
		{
			return log_message_type_;
		}

		std::string LogRow::get_message() const
		{
			return message_;
		}
	}
}