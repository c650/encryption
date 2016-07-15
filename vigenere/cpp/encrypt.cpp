#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>

namespace Vigenere {
	std::string encrypt(const std::string& str, const std::string& key) {
		std::string s = str;
		
		std::vector<int> k(key.length());

		int key_len = key.length();

		int i;
		for (i = 0; i < key_len; i++) {
			k[i] = tolower(key[i]) - 'a';
		}

		i = 0;
		for (auto& c : s) {
			if (islower(c)) {
				c = (c - 'a' + k[i++ % key_len]) % 26 + 'a';
			} else if (isupper(c)) {
				c = (c - 'A' + k[i++ % key_len]) % 26 + 'A';
			}
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