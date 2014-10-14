#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

struct Stats{
	string name;
	int health;		//	=200
	int base;		//	=200
	int speed;		//	=50
	int power;		//	=20
	string hand;	//	can be equipped
	string chest;	//	can be equipped
	string feet;	//	can be equipped
};

struct Gear{
	string name;	//	name = name
	string type;	//	type = {weapon,armor}
	string wear;	//	wear = {chest,feet,hand}
	int effect;		//	effect = {power(hand),health(chest),speed(feet)}
	float crit;		//	crit = % chance or NULL
	string accTyp;	//	accTyp = {insta,miss,NULL}
	float accVal;	//	accVal = % chance or NULL
};

/*	Create the Player	*/
Stats setPlayer();
string getName();
/*	Default Gear	*/
Gear bareFist();
Gear bareFeet();
Gear tShrt();
/*	Update Player Stats		*/
Stats update(Stats,Stats,Gear,Gear,Gear);
Stats defStats(string);

/*	Display Info and Stats	*/
void showIntro();
void displayStats(Stats);



int main(){
	cout << "WELCOME TO THE END OF THE WORLD!!!\n\n";

	//	Set player default stats
	Stats player1 = setPlayer();
	//	Set default loadout
	Gear hand = bareFist();
	Gear feet = bareFeet();
	Gear chest = tShrt();
	//	Update player stats
	//Stats def = defStats(player1.name);
	//player1 = update(def,player1,hand,feet,chest);
	//	Display intro
	showIntro();
	system("cls");
	//	Level one begins
	cout << "LEVEL 1: GET THE HELL OUT OF THERE!\n\n";
	displayStats(player1);


}

//	Initializes the player
Stats setPlayer(){
	Stats p1 = {
		getName(),	//	player1.name
		200,		//	player1.health
		200,		//	player1.healthBase
		50,			//	player1.speed
		20,			//	player1.power
		"empty",	//	hand
		"empty",	//	chest
		"empty"		//	feet
	};
	return p1;
}
Stats defStats(string name){
	Stats p1 = {
		name,		//	player1.name
		200,		//	player1.health
		200,		//	player1.healthBase
		50,			//	player1.speed
		20			//	player1.power
	};
	return p1;
}

//	Get the name from the user.
string getName(){
	string pName;
	cout << "What's your name?: ";
	cin >> pName;
	cout << endl << endl << "Good luck, " << pName << "!\n\n";
	return pName;
}

//	Shows the intro
void showIntro(){
	ifstream inFile;
	int linePer=22,		//	Number of lines printed per screen.
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

//	Displays Player stats
void displayStats(Stats p1){
	cout << "Current Player Stats:\n"
		<< "Player Name: "	<< p1.name << endl
		<< "Health: "		<< p1.health << endl
		<< "Max Health: "	<< p1.base << endl
		<< "Speed: "		<< p1.speed << endl
		<< "Power: "		<< p1.power << endl
		<< "Hand: "			<< p1.hand << endl
		<< "Chest: "		<< p1.chest << endl
		<< "Feet: "			<< p1.feet << endl;
}

/*	Update player stats		*/
Stats update(Stats d,Stats p1,Gear h,Gear f,Gear c){
	char ans;
	//	if gear is in place for hand
	if(p1.hand != "empty"){
		//	ask user for new equip
		cout << "Do you wish to equip " << h.name << "?\n";
		cin >> ans;
		//	if yes
		if(toupper(ans) == 'Y'){
			//	remove old stats
			p1.hand="empty";
			p1.power=d.power;
			//	update new stats
			p1.hand=h.name;
			p1.power+=h.effect;
		//	if no
		}else{
			//	do nothing
			cout << "Your " << p1.hand << " will remain equipt!\n";
		}
	//	if no gear is in place
	}else{
		//	equip new gear
		p1.hand=h.name;
		p1.power+=h.effect;
	}

	//	if gear is in place for feet
	if(p1.feet != "empty"){
		//	ask user for new equip
		cout << "Do you wish to equip " << f.name << "?\n";
		cin >> ans;
		//	if yes
		if(toupper(ans) == 'Y'){
			//	remove old stats
			p1.feet="empty";
			p1.speed=d.speed;
			//	update new stats
			p1.feet=f.name;
			p1.speed+=f.effect;
		//	if no
		}else{
			//	do nothing
			cout << "Your " << p1.feet << " will remain equipt!\n";
		}
	//	if no gear is in place
	}else{
		//	equip new gear
		p1.feet=f.name;
		p1.speed+=h.effect;
	}

	//	if gear is in place for chest
	if(p1.chest != "empty"){
		//	ask user for new equip
		cout << "Do you wish to equip " << c.name << "?\n";
		cin >> ans;
		//	if yes
		if(toupper(ans) == 'Y'){
			//	remove old stats
			p1.chest="empty";
			p1.base=d.base;
			//	update new stats
			p1.chest=c.name;
			p1.base+=c.effect;
		//	if no
		}else{
			//	do nothing
			cout << "Your " << p1.chest << " will remain equipt!\n";
		}
	//	if no gear is in place
	}else{
		//	equip new gear
		p1.chest=c.name;
		p1.base+=c.effect;
	}
	return p1;
}


/*		Build the Inventory		*/
//	Delault Loadout
Gear bareFist(){
	Gear fist = {
		"Bare Fist",
		"weapon",
		"hand",
		0,
		0.01f,
		"miss",
		0.1f
	};
	return fist;
}
Gear tShrt(){
	Gear shirt = {
		"T-Shirt",
		"armor",
		"chest",
		1,
		NULL,
		NULL,
		NULL
	};
	return shirt;
}
Gear bareFeet(){
	Gear feet = {
		"Bare Feet",
		"armor",
		"chest",
		-5,
		NULL,
		NULL,
		NULL
	};
	return feet;
}