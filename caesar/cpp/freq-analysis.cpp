#include "./encrypt.cpp"

#define REG_MAX 4 // the index of 'e' in alpha ('a' = 0)
#define RED "\033[0;31m"
#define WHITE "\033[0;39m"

int main() {
	std::string s; std::getline(std::cin, s);

	std::vector<unsigned int> freq(26, 0);

	/*
		Collect frequencies
	*/
	std::cout << RED << "\n[*] Collecting frequencies...\n";
	for (auto& c : s) {
		if (c >= 'a' && c <= 'z') {
			freq[c - 'a']++;
		} else if (c >= 'A' && c <= 'Z') {
			freq[c - 'A']++;
		}
	}

	std::cout << "\n[*] Approximating Key...\n";
	unsigned int max_idx = 0;
	for (int i = 1; i < 26; i++) {
		if (freq[i] > freq[max_idx]) {
			max_idx = i;
		}
	}

	int key = max_idx - REG_MAX;
	while (key < 0) {
		key += 26;
	}

	std::cout << "\n[*] Key found: " << key 
		<< "\n\n[*] Decrypting... \n\n" << std::endl;

	std::cout << WHITE << Caesar::decrypt(s, key) << std::endl;
}