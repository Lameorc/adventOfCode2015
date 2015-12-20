#include <iostream>
#include <fstream>

int main(){
	std::ifstream file;
	file.open("day1input.txt", std::ifstream::in);
	int floor = 0;
	char tmp;
	file >> tmp;
	while(file.good()){
		if(tmp == '(') ++floor;
		else if(tmp == ')') --floor;
		file >> tmp;
	}
	std::cout << "Target floor is: " << floor << std::endl;
	return 0;
}