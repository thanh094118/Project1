#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    unordered_set< string> dulieu;
    string chuoi;
    while (getline( cin, chuoi) && chuoi != "*") {
        dulieu.insert(chuoi);
    }
    while (getline( cin, chuoi) && chuoi != "***") {
        string dieukien = chuoi.substr(0, chuoi.find(' '));
        string key = chuoi.substr(chuoi.find(' ') + 1);
        if (dieukien == "find") {
            if (dulieu.find(key) != dulieu.end()) {
                 cout << "1\n";
            } else {
                 cout << "0\n";
            }
        } else if (dieukien == "insert") {
            auto result = dulieu.insert(key);
            if (result.second) {
                 cout << "1\n"; 
            } else {
                 cout << "0\n"; 
            }
        }
    }

    return 0;
}
