#ifndef _BIU_INC_H_
#define _BIU_INC_H_
//c++
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<fstream>
#include<sstream>

//gnu

#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/dir.h>
#include<sys/epoll.h>
#include<sys/select.h>
#include<sys/poll.h>


#define		MAX_PATH		128
// Buffer size
#define		BUF_SIZE_128	128
#define		BUF_SIZE_256	256
#define		BUF_SIZE_512	512
#define 	BUF_SIZE_1K		1024
#define 	BUF_SIZE_2K		2048
#define 	BUF_SIZE_4K		4096
#define 	BUF_SIZE_8K		8192
#define 	BUF_SIZE_20K	20480
#define 	BUF_SIZE_512K	524288
#define 	BUF_SIZE_1M		1048576
#define 	BUF_SIZE_2M		2097152
#define 	BUF_SIZE_10M	10485760
#define 	BUF_SIZE_20M	20971520
#define		BUF_SIZE_40M	41943040

#define NAMESPACE_BEGIN(name) namespace name { 
#define NAMESPACE_END(name) }

#define MAX(a, b)            (((a) > (b)) ? (a) : (b))
#define MIN(a, b)            (((a) < (b)) ? (a) : (b))

static std::map<std::string, int> root_path = {
	std::make_pair("/bin",1),
	std::make_pair("/boot",1),
	std::make_pair("/dev",1),
	std::make_pair("/etc",1),
	std::make_pair("/home",1),
	std::make_pair("/lib",1),
	std::make_pair("/lib64",1),
	std::make_pair("/log",1),
	std::make_pair("/media",1),
	std::make_pair("/mnt",1),
	std::make_pair("/opt",1),
	std::make_pair("/proc",1),
	std::make_pair("/root",1),
	std::make_pair("/run",1),
	std::make_pair("/sbin",1),
	std::make_pair("/srv",1),
	std::make_pair("/sys",1),
	std::make_pair("/tmp",1),
	std::make_pair("/usr",1),
	std::make_pair("/var",1)
};
#endif
