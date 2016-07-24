#include "dict-scan.cpp"
#include "encrypt.cpp"
#include <utility>
#include <algorithm>

#define RED "\033[0;31m"
#define NORMAL "\033[0;39m"

int main(int argc, char** argv) {
	if (argc != 3 && argc != 2) {
		std::cout << "Usage: ./brute2 /path/to/dict [optional: # results to output]\n";
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

    std::vector< std::pair<int,int> > found_table(26);
    //std::pair<int,int> max_found(0,0); // key, num_found
    std::string tmp;
    std::cout << RED << "[*] Scanning brute forces...\n" << NORMAL;

    for (int i = 0; i < 26; i++) {
    	tmp = Caesar::decrypt(s, i);
    	found_table[i] = std::make_pair(i, DictionaryScanner::scan( tmp, dictionary ) );
    }

    std::sort(found_table.begin(), found_table.end());
    int outputs = argc == 3 ? atoi(argv[2]) : 1, n = found_table.size();

    for (int i = n - outputs; i < n; i++) {
        std::cout << RED << "[ key: " << found_table[i].first << ", found: " << found_table[i].second
                << " ] " << NORMAL << Caesar::decrypt(s, found_table[i].first) << std::endl;
    }
    return 0;
}