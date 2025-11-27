#ifndef __dictionary__
#define __dictionary__
#include <string>

int count_lines_with_length(std::string file_name, int len);

std::string line_with_length_under_number(std::string file_name, int len, int number);

std::string random_line_with_length(std::string file_name, int len);

int add_line(std::string file_name, std::string line);

int line_number(std::string file_name, std::string search_line);

#endif  // !__dictionary__