#include "TemporaryFiles.h"
/*#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <cstdio>

using namespace std;

void TemporaryFiles::TempFiles()
{
	int n = 0;
	setlocale(LC_ALL, "Russian");
	namespace temp = experimental::filesystem;
	experimental::filesystem::path path = temp::temp_directory_path();
	cout << "Шлях до директорії: " << path << '\n';
	vector<string> filenames;
	const temp::directory_iterator end{};

	for (temp::directory_iterator iter{ path }; iter != end; ++iter)
	{
		if (temp::is_regular_file(*iter)) 
			filenames.push_back(iter->path().string());
	}

	for (const auto& name : filenames)
	{
		cout << "Видалення файлу: " << name << '\n';
		remove(name.c_str());
		Sleep(50);
		n++;
	}
	cout << "\nВидалено файлів: " << n << '\n';
}

void TemporaryFiles::TempInfo(int sizeBefore, int sizeAfter) {

}

experimental::filesystem::path TemporaryFiles::get_path()
{
	namespace temp = experimental::filesystem;
	experimental::filesystem::path path = temp::temp_directory_path();
	return temp::temp_directory_path();;
}
*/