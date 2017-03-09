#include "./encrypt.cpp"

int main() {

	std::cout << "Message: ";
    std::string s; std::getline(std::cin, s);

	std::cout << "Key [0-25]: ";
	int k; std::cin >> k;
	k %= 26; // just in case

    std::cout << Caesar::encrypt(s, k) << std::endl;
    return 0;
}
