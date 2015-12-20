#include <iostream>
#include <fstream>

int countPaper(int l, int w, int h){
	int needed = 0;
	int a = 2*l*w, b = 2*w*h, c = 2*h*l;
	//std::cout << "a: " << a  << " b: " << b <<" c: " << c << " a+b+c: " << a+b+c <<std::endl;
	//std::cout << "slack: " <<(a < b ? (a<c ? a : c) : (b < c ? b : c)) << std::endl;
	needed = a+ b+ c + (l*w < w*h ? (l*w< h*l ? l*w : h*l) : (w*h < h*l ? w*h : h*l));
	return needed;
}

int main(){
	std::ifstream ifs("day2input.txt", std::ifstream::in);
	int paperNeeded = 0;
	char splitter;
	int length = 0, width = 0, height = 0;
	ifs >> length >> splitter >> width >> splitter >> height;
	while(ifs.good()){
		paperNeeded += countPaper(length, width, height);
		ifs >> length >> splitter >> width >> splitter >> height;
	}

	std::cout << "Total paper needed: " << paperNeeded << std::endl;
	return 0;
}