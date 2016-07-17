#include <vector>
#include <string>
#include <iostream>

namespace Caesar {

	std::string encrypt(const std::string& str, const int& key) {
	    
	    std::string s = str;

	    for (auto& c : s) {
	        if (c >= 'a' && c <= 'z') {

	            c = ((c - 'a' + key) % 26) + 'a';

	        } else if (c >= 'A' && c <= 'Z') {

	            c = ((c - 'A' + key) % 26) + 'A';

	        }
	    }

	    return s;
	}

	std::string decrypt(const std::string& str, const int& key) {
	    return encrypt(str, 26 - key);
	}
};