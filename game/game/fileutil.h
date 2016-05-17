#pragma once

#include<string>
#include<fstream>

namespace game {

	class FileUtilits {
	public:
		static std::string read_file(const char* filepath)
		{
			FILE *file = fopen(filepath, "rt"); // as it is faster than fstream library
			fseek(file, 0, SEEK_END); // go to end of file
			unsigned long length = ftell(file); //no of bytes
			char* data = new char[length + 1];
			memset(data, 0, length + 1); // it will read file properly remove and see
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}
	};
}