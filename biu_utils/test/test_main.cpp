#include "biu_file.h"


int main(int argc,char** argv) {
	std::string path(argv[0]);
	std::cout << path << std::endl;
	io::FILE::clean_path(path);
	io::PATH p;
	io::FILE::spilt(p, path);

	std::cout << p.dir << "   " << p.file << std::endl;

	std::cout << path << std::endl;
	//system("pause");

	std::string content;
	io::FILE::read(content, p.file);
	//std::cout << content << std::endl;
	io::FILE::change_type(p.file, ".out", ".log");
	std::cout <<"\n"<< p.file << std::endl;
	io::FILE::write(p.file, "asdfahds",io::FILE::TRUNCATE);
	io::FILE::write(p.file, "asdfahds");
	std::cout << "__________________\n";
	io::FILE::read(content, p.file);
	std::cout << content << std::endl;
	LOG("%s", "a;dlkfjasdfajdfaaidjfaod");
	std::string dir("/test_dir/log/a");
	io::FILE::mkdir(dir);

	sleep(10);
	return 0;

}