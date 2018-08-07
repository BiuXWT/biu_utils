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
	
	while()

}

void FILE::mkdir(char * dir)
{
}


NAMESPACE_END(io)

