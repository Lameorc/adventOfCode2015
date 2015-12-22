#include <iostream>
#include <string>
#include <fstream>
#include <regex>

int main(){
	int goodStrings = 0;
	std::string in;
	std::ifstream ifs("day5input.txt");
	std::getline(ifs, in);
	while(ifs.good()){
		std::regex rx(".*(..).*\\1.*");
		if(std::regex_match(in, rx)){
			rx = ".*(.).\\1.*";
			if(std::regex_match(in,rx)){				
					++goodStrings;				
			}
		}
		std::getline(ifs,in);
	}
	std::cout << "Number of \"Good words\" on the list is: " << goodStrings << std::endl;
	return 0;
}