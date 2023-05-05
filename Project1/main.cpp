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
	//<1.��������ΪLoggerName1���������������̨�ĵ��̰߳汾��־��¼��
	  spdlog::stdout_color_st("LoggerName1");
	spdlog::get("LoggerName1")->info("test spdlog::get(logger_name)");
	//<2.��������ΪLoggerName2�����������Logs/BasicFileLog.txt��
	//���̰߳汾��־��¼��
	auto logger2 = spdlog::basic_logger_mt("LoggerName2", "Logs/BasicFileLog.txt");
	spdlog::get("LoggerName2")->info("a={}",a);
	//<3.��������ΪLoggerName3�����������Logs/RotatingFileLog.txt��
	// //���̰߳汾��־��¼��
	//����1024*1024*5�������ļ��������Ϊ5mb������3�������ļ��������Ϊ3
	//����־�ļ��洢����5mbʱ������������־�ļ�������������һ����־�ļ�
	//����־�ļ���������3ʱ����ɾ����һ����־�ļ�

	auto logger3 = spdlog::rotating_logger_mt("LoggerName3", "Logs/RotatingFileLog.txt", 1024 * 1024 * 5, 3);

	//<4.��������ΪLoggerName4��
	// ���������Logs/DailyFileLog.txt�Ķ��̰߳汾��־��¼��
	//����2��30ָ��ÿ��������־�ļ���ʱ��Ϊ�賿2��30��

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
