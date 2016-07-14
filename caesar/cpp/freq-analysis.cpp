#include "./encrypt.cpp"

#define REG_MAX 4 // the index of 'e' in alpha ('a' = 0)

int main() {
	std::string s; std::getline(std::cin, s);

	std::vector<unsigned int> freq(26, 0);

	/*
		Collect frequencies
	*/
	for (auto& c : s) {
		if (c >= 'a' && c <= 'z') {
			freq[c - 'a']++;
		} else if (c >= 'A' && c <= 'Z') {
			freq[c - 'A']++;
		}
	}

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

	std::cout << Caesar::decrypt(s, key) << std::endl;
}