#include <iostream>
#include <string>
#include <vector>

bool isValidIP(const std::string& ip) {
    std::vector<std::string> parts;
    std::string part = "";

    for (std::size_t i = 0; i <= ip.size(); ++i) {
        if (i == ip.size() || ip[i] == '.') {
            parts.push_back(part);
            part = "";
        } else {
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
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите строку с IP-адресами (через пробел): ";
    
    std::string line;
    std::getline(std::cin, line);

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
        } else {
            word += line[i];
        }
    }

    if (!result.empty()) {
        std::cout << "Найденные IP-адреса: " << result << std::endl;
    } else {
        std::cout << "Корректных IP-адресов не найдено." << std::endl;
    }

    return 0;
}
