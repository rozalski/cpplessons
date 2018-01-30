#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	char keyBoard [] = {'q','w','e','r','t','y',
	                    'u','i','o','p','a','s',
	                    'd','f','g','h','j','k',
	                    'l','z','x','c','v','b',
	                    'n','m'
	                   };
	fstream fin, fout;
	fin.open("input", ios::in);
	fout.open("output", ios::out);
	char ch;
	ch = fin.get();
	if(ch=='p') {
		fout << 'a' << endl;
		return 0;
	}
	if(ch=='l') {
		fout << 'z' << endl;
		return 0;
	}
	if(ch=='m') {
		fout << 'q' << endl;
		return 0;
	}
	for(int i=0; i<=25; i++) {
		if(ch == keyBoard[i]) {
			int j=i+1;
			fout << keyBoard[j] << endl;
		}
	}

	fin.close();
	fout.close();
	return 0;
}
