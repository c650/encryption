#include "dict-scan.cpp"
#include "encrypt.cpp"
#include <utility>

#define RED "\033[0;31m"
#define NORMAL "\033[0;39m"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./brute2 /path/to/dict\n";
		exit(1);
	}

    std::string s; std::getline(std::cin, s);
    
    std::vector<std::string> dictionary;
    if (!DictionaryScanner::load(std::string(argv[1]), dictionary)) {
    	exit(1);
    } else {
	    std::cout << RED << "[*] Loaded dictionary at "
	    	<< NORMAL << argv[1] << std::endl;
    }

    std::pair<int,int> max_found(0,0);
    std::string tmp;
    int found;
    std::cout << RED << "[*] Scanning brute forces...\n" << NORMAL;

    for (int i = 0; i < 26; i++) {
    	tmp = Caesar::decrypt(s, i);
    	found = DictionaryScanner::scan( tmp, dictionary );
    	if (found > max_found.second) {
    		max_found.second = found;
    		max_found.first = i;
    	}
    }

	std::cout << RED << "[ key: " << max_found.first << ", found: " << max_found.second
	    		<< " ] " << NORMAL << Caesar::decrypt(s, max_found.first) << std::endl;
    return 0;
}