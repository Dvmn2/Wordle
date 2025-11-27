#include <ctime>
#include <fstream>
#include <iostream>

int count_lines_with_length(std::string file_name, int len) {
    std::ifstream File(file_name);
    if (!File.is_open()) return -1;
    std::string line;
    int count = 0;
    while (std::getline(File, line)) {
        if (line.length() == len ||
            len < 0) {  // If the length is negative, select all lines
            count++;
        }
    }

    File.close();
    return count;
}

std::string line_with_length_under_number(std::string file_name, int len, int number) {
    std::ifstream File(file_name);
    if (!File.is_open()) return "-1";
    std::string line;
    int count = 0;
    while (count < number &&
           std::getline(File, line)) {  // If the length is negative, select all lines
        if (line.length() == len || len < 0) {
            count++;
        }
    }

    File.close();
    if (count == number) return line;
    return "-3";
}

std::string random_line_with_length(std::string file_name, int len) {
    srand(time(0));

    int count_words = count_lines_with_length(file_name, len);
    if (count_words == -1) {
        return "-1";
    } else if (count_words == 0) {
        return "-2";
    }
    int word_number = rand() % count_words + 1;
    std::string word = line_with_length_under_number(file_name, len, word_number);
    if (word.at(0) == '-') {
        return word;
    }

    return word;
}

int add_line(std::string file_name, std::string line) {
    std::ofstream File(file_name, std::ios::app);
    if (!File.is_open()) return -1;
    File << "\n" << line;

    File.close();
    return 0;
}

int line_number(std::string file_name, std::string search_line) {
    std::ifstream File(file_name);
    if (!File.is_open()) return -1;
    std::string line;
    int count = 0;
    while (std::getline(File, line)) {
        count++;
        if (line == search_line) {
            File.close();
            return count;
        }
    }

    File.close();
    return -4;
}