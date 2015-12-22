#include <iostream>
#include <fstream>
#include <map>
#include <utility>
int main(){
	int housesVisited = 1;
	std::ifstream ifs("day3input.txt", std::ifstream::in);
	std::map<std::pair<int, int>, int> m;
	std::pair<int, int> pos(0, 0);
	std::pair<int, int> roboPos(0, 0);
	bool roboTurn = false;
	m.insert(std::make_pair(pos, 1));
	char input = 0;
	ifs>>input;
	while(ifs.good()){

		if(!roboTurn){
			switch(input){
				case '^':
				++pos.first;
				break;
				case '>':
				++pos.second;
				break;
				case 'v':
				--pos.first;
				break;
				case '<':
				--pos.second;
				break;
			}
			roboTurn = true;
		}
		else{
			switch(input){
				case '^':
				++roboPos.first;
				break;
				case '>':
				++roboPos.second;
				break;
				case 'v':
				--roboPos.first;
				break;
				case '<':
				--roboPos.second;
				break;
			}
			roboTurn = false;
		}
		auto tmp = m.insert(std::make_pair(pos,1));
		if(tmp.second != false){
			++housesVisited;
		}
		tmp = m.insert(std::make_pair(roboPos,1));
		if(tmp.second != false){
			++housesVisited;
		}
		ifs>>input;
	}
	std::cout << "Houses visited: " << housesVisited << std::endl;
	return 0;
}