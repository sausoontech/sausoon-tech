#include "../logger/log_row.h"
#include "../logger/log_message_type_enum.h"

#include <iostream>
#include <exception>

int main()
{
	try
	{
		throw 10;
	}
	catch (char* excp)
	{
		std::cout << "Caught " << excp;
	}
	catch (...)
	{
		SausoonTech::Logger::LogRow log_row = SausoonTech::Logger::LogRow(SausoonTech::Logger::LogMessageTypeEnum::INFO, "Default Exception");
		std::cout << (log_row.get_log_message_type() == 1) << " " << log_row.get_message();
	}

	return 0;
}