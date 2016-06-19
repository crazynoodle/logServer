#ifndef __LOGFILE_H__
#define __LOGFILE_H__

#include "Lock.h"
#include "Timeval.h"

class LogFile
{
public:
	LogFile();
	~LogFile();
	bool 	init();
	bool   	updateLogFilePath();
	bool   	updateLogFileName();
	bool   	updateLogFileId();
	bool 	updateLogFileFD();
	bool 	checkLogFileByteSize();
	bool 	updateLogFileByteSize();
	string 	getLogFilePath();
	string	getLogFileName();
	FILE* 	getLogFileFD();
	int 	getLogFileByteSize();


private:
	static const int LOG_FILE_MAX_BYTE_SIZE = 1024*1024*100;
	CLock LogFileLock;
	string  LogFilePath;
	string  LogFileName;
	int 	LogFileId;
	int 	LogFileByteSize;
	FILE*   LogFileFD;
};

#endif