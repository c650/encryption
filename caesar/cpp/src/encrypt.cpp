#include <vector>
#include <string>
#include <iostream>

#include <stdexcept>

namespace Caesar {

	std::string encrypt(const std::string& str, const int& key) {
		if (key < 0)
			throw std::logic_error("Don't use a negative key!");

	    std::string s = str;

		char base;
	    for (auto& c : s) {
	        if (c >= 'a' && c <= 'z') {
				base = 'a';
	        } else if (c >= 'A' && c <= 'Z') {
				base = 'A';
	        } else {
				continue;
			}
			c = ((c - base + key) % 26) + base;
	    }

	    return s;
	}

	std::string decrypt(const std::string& str, const int& key) {
		if (key < 0)
			throw std::logic_error("Don't use a negative key!");
	    return encrypt(str, 26 - key % 26);
	}
};
