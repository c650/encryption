#include "./encrypt.cpp"
#include <iomanip>

void hex_print(const std::vector<unsigned char>& s) {
	std::cout << std::hex;
	for (auto& c : s) {
		std::cout << int(c) << " ";
	}
	std::cout << std::hex << std::endl;
}

int main() {
	std::string s,k;
	std::getline(std::cin, s);
	std::getline(std::cin, k);

	std::vector<unsigned char> v(s.begin(),s.end());
	v = XOR::encrypt(v,k);

	hex_print(v);

	v = XOR::decrypt(v, k);

	for(auto& c : v) {
		std::cout << c;
	}
	std::cout << std::endl;

	return 0;	
}