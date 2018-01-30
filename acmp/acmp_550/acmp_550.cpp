#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	int y;
	std::fstream  fin;
	//fin.open("input", std::ios::in);
	//fin >> y;
	std::cin >> y;
		std::cout <<y<<std::endl;
	bool vskF;
	if(y%4==0) {
		if(y%100==0) {
			if(y%400!=0) {
				vskF = false;
			} else {
				vskF = true;
			}
		} else {
			vskF = true;
		}
	} else {
		vskF = false;
	}
	if(vskF) {
		std::cout << "12/09/"<<y<<std::endl;
	} else {
		std::cout << "13/09/"<<y<<std::endl;
	}
	return 0;
}

