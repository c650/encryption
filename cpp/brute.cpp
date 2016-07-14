#include "./encrypt.cpp"

int main() {
    std::string s; std::getline(std::cin, s);
    std::cout << std::endl;
    
    for (int i = 1; i < 26; i++) {
    	std::cout << "[ " << i << " ] "; 
    	std::cout << Caesar::decrypt(s, i) << std::endl;
    }
    return 0;
}