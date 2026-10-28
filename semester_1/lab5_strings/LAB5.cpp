#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidIP(const string& ip) {
    vector<string> parts;
    string part = "";

    for (size_t i = 0; i <= ip.size(); ++i) {
        if (i == ip.size() || ip[i] == '.') {
            parts.push_back(part);
            part = "";
        } else {
            part += ip[i];
        }
    }

    if (parts.size() != 4) return false;

    for (int j = 0; j < 4; ++j) {
        string p = parts[j];

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
    string line;
    getline(cin, line);

    string word = "";
    string result = "";

    for (size_t i = 0; i <= line.size(); ++i) {
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

    cout << result << endl;
    return 0;
}
