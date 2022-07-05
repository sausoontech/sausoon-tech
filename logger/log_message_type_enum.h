#ifndef SAUSOON_TECH_LOGGER_LOG_MESSAGE_TYPE_ENUM_H
#define SAUSOON_TECH_LOGGER_LOG_MESSAGE_TYPE_ENUM_H

namespace SausoonTech
{
	namespace Logger
	{
		enum LogMessageTypeEnum : unsigned char
		{
			DEBUG = 0,
			INFO = 1,
			WARNING = 2,
			ERROR = 3
		};
	}
}

#endif