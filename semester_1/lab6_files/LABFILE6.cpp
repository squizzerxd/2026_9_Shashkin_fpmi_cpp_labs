#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

bool isValidIP(const std::string& ip) {
    std::vector<std::string> parts;
    std::string part = "";

    for (std::size_t i = 0; i <= ip.size(); ++i) {
        if (i == ip.size() || ip[i] == '.') {
            parts.push_back(part);
            part = "";
        }
        else {
            part += ip[i];
        }
    }

    if (parts.size() != 4) return false;

    for (int j = 0; j < 4; ++j) {
        std::string p = parts[j];

        if (p.empty()) return false;
        if (p.size() > 1 && p[0] == '0') return false;

        int number = 0;
        for (int k = 0; k < (int)p.size(); ++k) {
            if (p[k] < '0' || p[k] > '9') return false;
            number = number * 10 + (p[k] - '0');
        }

        if (number > 255) return false;
    }
    return true;
}

int main() {
    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";

    try {
        std::ifstream fin{ input_filename };
        if (!fin.is_open()) {
            throw std::runtime_error("Could not open input file \"" + input_filename + "\"");
        }

        std::ofstream fout{ output_filename };
        if (!fout.is_open()) {
            throw std::runtime_error("Could not open output file \"" + output_filename + "\"");
        }

        std::string line;
        while (std::getline(fin, line)) {
            std::string word = "";
            std::string result = "";

            for (std::size_t i = 0; i <= line.size(); ++i) {
                if (i == line.size() || line[i] == ' ') {
                    if (!word.empty()) {
                        if (isValidIP(word)) {
                            if (!result.empty()) result += " ";
                            result += word;
                        }
                        word = "";
                    }
                }
                else {
                    word += line[i];
                }
            }

            if (!result.empty()) {
                fout << "Найденные IP-адреса: " << result << std::endl;
            }
            else {
                fout << "Корректных IP-адресов не найдено." << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
