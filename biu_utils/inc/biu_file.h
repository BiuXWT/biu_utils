#ifndef _BIU_FILE_H_
#define _BIU_FILE_H_
#include "biu_inc.h"

#define LOGFILE "log.txt"
#define LOG(format, ...) char buf[2048]={0};   \
						 sprintf(buf, ">>>>>[%s]-[%s]-[%d] " format "<<<<\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);  \
						 fprintf(stdout,"%s",buf);  \
						 io::FILE::write(LOGFILE,buf);

NAMESPACE_BEGIN(io)

class PATH {
public:
	std::string dir;
	std::string file;
};

class FILE {
public:
	enum MODE{
		APPEND ,
		TRUNCATE
	};

	static void spilt(PATH &path, std::string fullpath);
	static void clean_path(std::string &path,bool unix_style=true);
	static bool exist(const std::string &fn);
	static bool read(std::string &content, const std::string &fn);
	static bool write(std::string &fn, std::string content, MODE mode = APPEND);
	static bool write(std::string fn, const char* content, MODE mode = APPEND);
	static bool change_type(std::string &fn, std::string &old_suffix, std::string &new_suffix);
	static bool change_type(std::string &fn, std::string old_suffix, std::string new_suffix);

	static void mkdir(std::string &dir);
	static void mkdir(char* dir);
	static void deldir(std::string &dir);

};

NAMESPACE_END(io)

#endif
