#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

namespace DictionaryScanner {

	bool load(const std::string& file_path, std::vector<std::string>& dictionary)  {
		
		std::ifstream fp(file_path);

		if (!fp) {
			std::cout << "[*] Error opening dictionary file at " << file_path
				<< ".\n";
			return false;
		}

		std::string tmp;
		while(fp >> tmp) {
			dictionary.push_back(tmp);
		}

		fp.close();

		return true;
	}

	static bool find (const std::string& text, const std::string& s) {
		int text_len = text.length(), s_len = s.length();

		int j,k;
		for (int i = 0; i < text_len; i++) {
			j = i;
			k = 0;
			while(k < s_len && j < text_len && tolower(text[j]) == tolower(s[k])) {
				/*std::cout << "\ttext[j] == s[k]: " << text[j]
					<< " == " << s[k] << std::endl;*/
				j++;k++;
			}
			if (k == s_len && j <= text_len)
				return true;
		}

		return false;
	}

	int scan(const std::string& text, const std::vector<std::string>& dictionary) {
		
		int found = 0;

		for (auto& s : dictionary) {
			//std::cout << "checking " << s << std::endl;
			if ( find(text, s) )
				found++;
		}

		return found;
	}
};