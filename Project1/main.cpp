#include "base.h"
#include "test_all.h"
 
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"// support for rotating file logging
#include "spdlog/sinks/basic_file_sink.h"// support for basic file logging
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/async.h" //support for async logging.
using namespace spdlog;

void stdout_example()
{
	// create color multi threaded logger
	auto console = spdlog::stdout_color_st("console");
	auto err_logger = spdlog::stderr_color_mt("stderr");
	spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

auto rotating_logger = rotating_logger_mt("mylog", "logs/rotating.txt", 1048576 * 5, 3);

int main(int, char* [])
{
	/*
	int a = 10000;
	//<1.创建名称为LoggerName1、内容输出到控制台的单线程版本日志记录器
	  spdlog::stdout_color_st("LoggerName1");
	spdlog::get("LoggerName1")->info("test spdlog::get(logger_name)");
	//<2.创建名称为LoggerName2、内容输出到Logs/BasicFileLog.txt的
	//多线程版本日志记录器
	auto logger2 = spdlog::basic_logger_mt("LoggerName2", "Logs/BasicFileLog.txt");
	spdlog::get("LoggerName2")->info("a={}",a);
	//<3.创建名称为LoggerName3、内容输出到Logs/RotatingFileLog.txt的
	// //多线程版本日志记录器
	//参数1024*1024*5设置了文件最大容量为5mb，参数3设置了文件最大数量为3
	//当日志文件存储超过5mb时，将重命名日志文件并且新增另外一个日志文件
	//当日志文件数量超过3时，将删除第一个日志文件

	auto logger3 = spdlog::rotating_logger_mt("LoggerName3", "Logs/RotatingFileLog.txt", 1024 * 1024 * 5, 3);

	//<4.创建名称为LoggerName4、
	// 内容输出到Logs/DailyFileLog.txt的多线程版本日志记录器
	//参数2和30指定每天生成日志文件的时间为凌晨2点30分

	auto logger4 = spdlog::daily_logger_mt("LoggerName4", "Logs/DailyFileLog.txt", 2, 30);

	system("pause");
	*/

	try
	{
		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		console_sink->set_level(spdlog::level::warn);
		console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");

		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
		file_sink->set_level(spdlog::level::trace);

		spdlog::logger logger("multi_sink", { console_sink, file_sink });
		logger.set_level(spdlog::level::debug);
		logger.warn("this should appear in both console and file");
		logger.info("this message should not appear in the console, only in the file");
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cout << "Log initialization failed: " << ex.what() << std::endl;
	}
 
	
	return 1;
}
