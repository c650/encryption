#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::string s; std::cin >> s;
    int k; std::cin >> k;

    for (auto& c : s) {
        if (c >= 'a' && c <= 'z') {

            c = ((c - 'a' + k) % 26) + 'a';

        } else if (c >= 'A' && c <= 'Z') {

            c = ((c - 'A' + k) % 26) + 'A';

        }
    }

    std::cout << s << std::endl;
    return 0;
}