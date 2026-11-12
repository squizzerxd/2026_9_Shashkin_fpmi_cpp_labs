#include <fstream>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <vector>
#include <locale>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
        ? std::put_time(std::gmtime(&time), "%x %X")
        : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

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
    std::ofstream flog{ "log.txt"};
    std::cout.imbue(std::locale("ru_RU.UTF-8"));

    
    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";

    try {
        flog << FormatTime(Now(), false) << '|' << " opening file 'input.txt' " << "\n";
        std::ifstream fin{ input_filename };
        if (!fin.is_open()) {
            throw std::runtime_error("Could not open input file \"" + input_filename + "\"");
        }

        std::ofstream fout{ output_filename };
        if (!fout.is_open()) {
            throw std::runtime_error("Could not open output file \"" + output_filename + "\"");
        }
        flog << FormatTime(Now(), false) << '|' << " file 'input.txt has been opened successfully " << "\n";
        std::string line;
        flog << FormatTime(Now(), false) << '|' << "  reading lines from 'input.txt' " << "\n";
        while (std::getline(fin, line)) {
            std::string word = "";
            std::string result = "";
            flog << FormatTime(Now(), false) << '|' << "  got line: " << line << "\n";
            flog << FormatTime(Now(), false) << '|' << "  finding valid ip " << word << "\n";
            for (std::size_t i = 0; i <= line.size(); ++i) {
                if (i == line.size() || line[i] == ' ') {
                    if (!word.empty()) {
                        if (isValidIP(word)) {
                            if (!result.empty()) result += " ";
                            result += word;
                            flog << FormatTime(Now(), false) << '|' << "  ip found: " << word << "\n";
                        }
                        word = "";
                    }
                }
                else {
                    word += line[i];
                }
            }
            
            if (!result.empty()) {
                flog << FormatTime(Now(), false) << '|' << "  writing numbers to 'output.txt' " << "\n";
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
    flog << FormatTime(Now(), false) << '|' << "  progam has ended with code 0 " << "\n";
    return 0;
}
