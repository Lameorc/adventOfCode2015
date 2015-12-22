#include <iostream>
#include <fstream>

int main(){
	std::ifstream file;
	file.open("day1input.txt", std::ifstream::in);
	int floor = 0;
	char tmp;
	int firstgroundchar = 1;
	bool basementVisited = false;
	file >> tmp;
	while(file.good()){
		if(tmp == '(') ++floor;
		else if(tmp == ')') --floor;
		if(basementVisited == false){
			if(floor < 0){
				std::cout << "FirstGroundChar: " << firstgroundchar << std::endl;
				basementVisited = true;
			}
			++firstgroundchar;			
		}
		file >> tmp;
	}
	std::cout << "Target floor is: " << floor << std::endl;
	return 0;
}