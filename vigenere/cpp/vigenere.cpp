#include "./encrypt.cpp"

int main() {
	std::string s; std::getline(std::cin, s);
	std::string k; std::getline(std::cin, k);

	std::string result = Vigenere::encrypt(s,k);
	std::cout << result << std::endl;

	std::cout << Vigenere::decrypt(result, k) << std::endl;

	return 0;
}