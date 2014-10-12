//#include "ZombStructs.h"
//#include "zombieFunc.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

struct Player{
	string name;
	int health;		//	=200
	int healthBase;	//	=200
	int speed;		//	=50
	int power;		//	=20
	int load;		//	=25
	int loadBase;	//	=25
	int arLoad;		// 	=0
	int arLoadBase;	//	=0
};

void showIntro();
Player setPlayer();
string getName();
void displayStats(Player);



int main(){
	string myName;
	Player player1;

	cout << "WELCOME TO THE END OF THE WORLD!!!\n\n";

	player1=setPlayer();

	showIntro();
	system("cls");

	cout << "LEVEL 1: GET THE HELL OUT OF THERE!\n\n";
	displayStats(player1);

	
	return 0;
}

Player setPlayer(){
	Player p1 = {
		getName(),	//	player1.name
		200,		//	player1.health
		200,		//	player1.healthBase
		50,			//	player1.speed
		20,			//	player1.power
		25,			//	player1.load
		25,			//	player1.loadBase
		0,			//	player1.arLoad
		0			//	player1.arLoadBase
	};
	return p1;
}

string getName(){
	string pName;
	cout << "What's your name?: ";
	cin >> pName;
	cout << endl << endl << "Good luck, " << pName << "!\n\n";
	return pName;
}

void showIntro(){
	ifstream inFile;
	int linePer=22,	//	Number of lines printed per screen.
		lineCnt=0;		//	Line counter initialized to zero.
	string line;		//	Stores the lines to be written to the console.
	
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

void displayStats(Player p1){
	cout << "Current Player Stats:\n"
		<< "Player Name: "	<< p1.name << endl
		<< "Health: "		<< p1.health << endl
		<< "Max Health: "	<< p1.healthBase << endl
		<< "Speed: "		<< p1.speed << endl
		<< "Power: "		<< p1.power << endl
		<< "Load Room: "	<< p1.load << endl
		<< "Max Load: "		<< p1.loadBase << endl
		<< "Arrow Room:	"	<< p1.arLoad << endl
		<< "Max Arrows: "	<< p1.arLoadBase << endl;
}