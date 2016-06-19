#include "LogFile.h"

LogFile::LogFile()
	:LogFilePath(""),
	 LogFilePath(""),
{

}

bool LogFile::init()
{

	LogFileName = string();//getTime
	LogFileId = 0;

	char buf[32] = "";
	itoa(LogFileId,buf,10);

	LogFileName += string(buf);

	//TODO:Finish this thread


}