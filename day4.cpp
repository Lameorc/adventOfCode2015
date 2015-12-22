#include <iostream>
#include <string>
#include "md5.h"
#include "windows.h"

int main()
{
	std::string base = "iwrupvqb";
	int endInt = 2286468;
	std::string end = std::to_string(endInt);
	std::string together = base + end;
    auto a = md5(together);
    while(a.substr(0, 6) != "000000"){
    	++endInt;
    	end = std::to_string(endInt);
    	together = base + end;
    	a = md5(together);
    	//std::cout << endInt << " and hash substr: " << a.substr(0,6) << std::endl;
    	//system("pause");
    }
    std::cout << endInt << std::endl;
    return 0;
}