#include "./encrypt.cpp"

int main() {
    std::string s; std::getline(std::cin, s);
    int k; std::cin >> k;
	k %= 26; // just in case

    std::cout << Caesar::encrypt(s, k) << std::endl;
    return 0;
}
