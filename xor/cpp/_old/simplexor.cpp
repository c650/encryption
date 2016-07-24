#include <stdlib.h>
#include <iostream>

#define XOR_KEY 0xff

std::string& xor_mutate(std::string& s) {

	for (int i = 0, n = s.size(); i < n; i++) {
		s[i] ^= XOR_KEY;
	}

	return s;
}
int main() {
	std::cout << "Please input string to encrypt:" << std::endl;

	std::string s; std::getline(std::cin,s);

	xor_mutate(s);

	std::cout << "Encrypted::: " << s << std::endl;

	xor_mutate(s);

	std::cout << "Decrypted::: " << s << std::endl;

}