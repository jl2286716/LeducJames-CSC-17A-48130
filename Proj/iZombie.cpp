#include "ZombStructs.h"
#include <iostream>

using namespace std;

void showIntro();

int main(){
	showIntro();
	cout << "Level 1: Get the Hell Outta There!\n\n";
	
	return 0;
}

void showIntro(){
	ifstream inFile;
	int linePer=22,	//	Number of lines printed per screen.
		lineCnt=0;	//	Line counter initialized to zero.
	string line;	//	Stores the lines to be written to the console.
	
	//	Open the 'intro.txt' file.
	inFile.open("intro.txt",ios::in);
	if(inFile.fail()){
		cout << "The introduction is broken!\n";
	}

	//	Count the number of lines.
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		lineCnt++;
	}

	//	Go back to the beninning.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	//	Iterate through and display.
	while(!inFile.eof()){
		if(lineCnt<linePer){
			for(int j=0;j<lineCnt;j++){
				getline(inFile,line,'\n');
				cout << line << endl;
			}
			system("pause");
		}else if(lineCnt>=linePer){
			for(int i=0;i<linePer;i++){
				getline(inFile,line,'\n');
				cout << line << endl;
				lineCnt--;
			}
			system("pause");
		}
	}
	inFile.close();
}