#include <iostream>
#include <string>
#include <iomanip>
// Global Encryption Key Var

unsigned char key[] = {
	0xAA,
	0xBB,
	0xCC,
	0xDD,
	0xFA,
	0x13,
	0x61
};
void encrypt(std::string& str) {
	for (int i = 0, n = str.length(); i < n; i++) {
		str[i] ^= key[i % sizeof(key)];
	}
}
void print_str_hex(const std::string& str) {
	for(int i = 0, n = str.length(); i < n; i++) {
		std::cout << "0x" << std::hex <<
			std::uppercase <<
			(int)str[i]
			<< std::nouppercase
			<< std::dec << " ";
	}

	std::cout << std::endl;
}
int main() {
	std::cout << "Please input a phrase to XOR" << std::endl;

	std::string str;

	getline(std::cin, str);

	std::cout << "Unmutated:\n";
	print_str_hex(str);

	encrypt(str);

	std::cout << "Encrypted:\n";
	print_str_hex(str);
}