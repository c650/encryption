#include "./encrypt.cpp"

int main() {
    std::string s; std::getline(std::cin, s);
    int k; std::cin >> k;

    std::cout << Caesar::encrypt(s, k) << std::endl;
    return 0;
}