#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace XOR {
	std::vector<unsigned char>
	encrypt(const std::vector<unsigned char> str, const std::string& key)
	{
		std::vector<unsigned char> res(str.begin(), str.end());

		for (int i = 0, n = str.size(), m = key.length(); i < n; i++) {
			res[i] ^= key[i % m];
		}

		return res;
	}

	std::vector<unsigned char>
	decrypt(const std::vector<unsigned char>& str, const std::string& key)
	{
		return encrypt(str,key);
	}
};