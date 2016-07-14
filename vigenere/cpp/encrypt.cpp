#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>

namespace Vigenere {
	std::string encrypt(const std::string& str, const std::string& key) {
		std::string s = str;
		
		std::vector<int> k(key.length());

		int key_len = key.length();
		int str_len = str.length();

		int i;
		for (i = 0; i < key_len; i++) {
			k[i] = tolower(key[i]) - 'a';
		}

		char sub;
		for (i = 0; i < str_len; i++) {
			if (islower(s[i])) {
				sub = 'a';
			} else if (isupper(s[i])) {
				sub = 'A';
			}
			s[i] = (s[i] - sub + k[i % key_len]) % 26 + sub;
		}

		return s;
	}

	std::string decrypt(const std::string& str, const std::string& key) {
		std::string k = key;

		for (auto& c : k) {
			c = tolower(c) - 'a' - 1;
			c = 'z' - c;
		}

		return encrypt(str,k);
	}
};