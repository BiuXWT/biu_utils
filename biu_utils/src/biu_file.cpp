#include "biu_file.h"

NAMESPACE_BEGIN(io)

void FILE::spilt(PATH &path, std::string fullpath)
{
	path.dir.clear();
	path.file.clear();
	clean_path(fullpath);
	size_t pos = fullpath.rfind('/');
	path.dir = std::string(fullpath, 0, pos);
	path.file = std::string(fullpath, pos+1,fullpath.size()-1);
}

void FILE::clean_path(std::string &path, bool unix_style/*=true*/)
{
#ifdef CPP17
	for (auto s : path) {
		if (s == '\\') {
			s = '/';
		}
	}
#else
	for (size_t s = 1; s < path.size(); s++) {
		if (path[s]=='\\'){
			path[s] = '/';
		}
	}
#endif
	for (size_t s = 1; s < path.size();) {
		if (path[s] == '/'&&path[s - 1] == '/') {
			path.erase(s, 1);
			continue;
		}
		s++;
	}
}

bool FILE::exist(const std::string &fn)
{
	struct stat st;
	return (0==stat(fn.c_str(),&st));
}

bool FILE::read(std::string & content, const std::string & fn)
{
	content.clear();
	std::ifstream fin(fn);
	if (!fin) {
		return false;
	}
	std::stringstream buf;
	buf << fin.rdbuf();
	content = std::string(buf.str());
	fin.close();
	if (content.size() > 0)
		return true;
	else
		return false;
}

bool FILE::write(std::string & fn, std::string content, MODE mode)
{
	if (mode == APPEND) {

		std::ofstream fout(fn,std::ios::app);
		if (!fout) {
			return false;
		}
		fout << content << std::endl;
		fout.close();
	}
	else {
		std::ofstream fout(fn);
		if (!fout) {
			return false;
		}
		fout << content << std::endl;
		fout.close();
	}
	return true;
}

bool FILE::write(std::string fn, const char* content, MODE mode)
{
	if (mode == APPEND) {

		std::ofstream fout(fn, std::ios::app);
		if (!fout) {
			return false;
		}
		fout << content << std::endl;
		fout.close();
	}
	else {
		std::ofstream fout(fn);
		if (!fout) {
			return false;
		}
		fout << content << std::endl;
		fout.close();
	}
	return true;
}

bool FILE::change_type(std::string &fn, std::string &old_suffix, std::string &new_suffix)
{
	if (size_t pos = fn.rfind(old_suffix))
	{
		fn.replace(pos, fn.size()-1, new_suffix);
		return true;
	}
	return false;
}
bool FILE::change_type(std::string &fn, std::string old_suffix, std::string new_suffix)
{
	if (size_t pos = fn.rfind(old_suffix))
	{
		fn.replace(pos, fn.size()-1, new_suffix);
		return true;
	}
	return false;
}

void FILE::mkdir(std::string &dir)
{
	clean_path(dir);
	size_t pos = dir.size();

	if (!exist(dir)) {
		while ((pos = dir.rfind('/', pos)) != std::string::npos) {

			std::string parent(dir, 0, pos);
			//std::cout << parent << std::endl;
			mkdir(parent);
			break;
		}
		//std::cout << "mkdir:" << dir << std::endl;
		::mkdir(dir.c_str(), 0775);
	}
}

void FILE::mkdir(char * _dir)
{
	std::string dir(_dir);
	clean_path(dir);
	size_t pos = dir.size();

	if (!exist(dir)) {
		while ((pos = dir.rfind('/', pos)) != std::string::npos) {

			std::string parent(dir, 0, pos);
			mkdir(parent);
			break;
		}
		::mkdir(dir.c_str(), 0775);
	}
}

void FILE::deldir(std::string & dir)
{
	if (root_path[dir] == 1) {
		return;
	}
	std::string cmd("rm -rf ");
	cmd += dir;
	//std::cout << cmd << std::endl;
	::FILE* fp = popen(cmd.c_str(), "r");
	char buf[BUF_SIZE_128] = { 0 };
	fgets(buf, BUF_SIZE_128, fp);
	int ret = pclose(fp);
	std::cout << buf<<"  "<<ret << std::endl;

}


NAMESPACE_END(io)

