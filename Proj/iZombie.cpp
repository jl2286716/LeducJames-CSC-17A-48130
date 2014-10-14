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

struct Weapon{
	string name;	//	name = weapon name
	string type;	//	type = weapon
	string wear;	//	wear = {bag,self}
	string wield;	//	wield = {single,double}
	int eff1;		//	eff1 = +power
	int eff2;		//	eff2 = +speed
	float critVal;	//	accVal1 = % chance
	string accTyp;	//	accTyp2 = {insta,jam,miss}
	float accVal;	//	accVal2 = % chance
	int weight;		//	weight = -load
	string ammoTyp;	//	ammoTyp = {357mm(Python),39mm(AK-47),9mm(Glock 19,MAC-10),arrow,shell,blunt}
	int ammoCnt;	//	ammoCnt = {0,NULL}
	bool equipped;	//	equipped = {true,false} - Equipped or not
};

struct Equipment{	//	Holds storage and armor.
	string name;	//	name = equipment name
	string type;	//	type = {armor,store,quiv}
	string wear;	//	wear = {chest,feet,back,waist}
	int eff1;		//	eff1 = health(chest,feet)/load(back,waist)
	int eff2;		//	eff2 = speed
	int weight;		//	weight effects the load
	bool equipped;	//	equipped = {true,false}
};

struct Loadout{
	string lHand;	//	can be equipped - default = fist
	string rHand;	//	can be equipped - default = fist
	string back;	//	is switched out; bag size effects load, hence, carried items - default = NULL
	string waist;	//	is switched out - default = NULL
	string chest;	//	coat can go over teflon & kevlar - default = shirt
	string feet;	//	is switched out - default = bare
};
/*	Create the Player	*/
Player setPlayer();
string getName();

/*	Create and Equipt the Weapons	*/
Weapon setWeapon(string);
Loadout setArms(Weapon,Loadout);
Player updateArms(Weapon,Player);

/*	Create and Equipt the Gear	*/
Equipment setEquip(string);
Loadout setGear(Equipment,Loadout);
Player updateGear(Equipment,Player);

/*	Display Info and Stats	*/
void showIntro();
void displayStats(Player);
void displayLoad(Loadout);

int main(){
	int choice;
	string find;
	Weapon magLite;

	cout << "WELCOME TO THE END OF THE WORLD!!!\n\n";

	//	Set player stats
	Player player1 = setPlayer();

	Loadout myGear = {"empty","empty","empty","empty","empty","empty"};

	Weapon bareFist = setWeapon("Bare Fist");
	myGear = setArms(bareFist,myGear);
	player1 = updateArms(bareFist,player1);

	Equipment tShrt = setEquip("T-Shirt");
	myGear = setGear(tShrt,myGear);
	player1 = updateGear(tShrt,player1);

	Equipment bareFeet = setEquip("Bare Feet");
	myGear = setGear(bareFeet,myGear);
	player1 = updateGear(bareFeet,player1);

	showIntro();
	system("cls");

	cout << "LEVEL 1: GET THE HELL OUT OF THERE!\n\n";
	displayStats(player1);
	//	Display inventory.
	displayLoad(myGear);
/*
	do{
		cout << "Fight or flight?" << endl
			<< "1: Look out the window?" << endl
			<< "2: Search for a flashlight?" << endl;
		if(choice != 1 || choice != 2){
			cout << "Please, enter a valid choice (1 or 2)!" << endl;
		}
	}while(choice != 1 || choice != 2);

	switch(choice){
		case 1: {
			cout << "You look out the window...\n"
				<< "and see a woman running from two ghoulish men.\n";

			do{
				choice=0;	//	Reinitialize choice
				cout << "1: Keep watching?" << endl
					<< "2: Run out and help?" << endl
					<< "3: Ignore and grab supplies?" << endl; 
				if(choice != 1 || choice != 2 || choice != 3){
					cout << "Please, enter a valid choice (1, 2 or 3)!" << endl;
				}
			}while(choice != 1 || choice != 2 || choice != 3);

			switch(choice){
				case 1:	//	Complete
					break;
				case 2:	//	Complete
					break;
				case 3:	//	Complete
					break;
			}
			break;
		}
		case 2: {
			cout << "You chose to look for a flashlight...\n";
			do{
				choice=0;	//	Reinitialize choice
				cout << "1: Search the desk?" << endl
					<< "2: Search the entertainment center?" << endl; 
				if(choice != 1 || choice != 2){
					cout << "Please, enter a valid choice (1 or 2)!" << endl;
				}
			}while(choice != 1 || choice != 2);

			switch(choice){
				case 1: {
					find = "Mag-Light";
					magLite = setWeapon(find);
					cout << "You found the " << find << " !" << endl
						<< "You can now see in the darkness!\n\n";
					//	Check inventory.
					//	Ask user to add Mag-Lite to inventory.
					//	Ask user to equipt the Mag-Lite.
					//	Update stats and equipment.
					//	Show updated stats and equipment.
					break;
				}
				case 2: {
					cout << "You found the LED Flishlight!\n"
						<< "You can now see in the darkness!\n\n";
					//	Check inventory.
					//	Ask user to add Mag-Lite to inventory.
					//	Ask user to equipt the Mag-Lite.
					//	Update stats and equipment.
					//	Show updated stats and equipment.
					break;
				}
			}
			break;
		}
		default: cout << "If  this got through, there's a problem!" << endl;
	}
*/
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
		<< "Max Arrows: "	<< p1.arLoadBase << endl << endl;
}

Weapon setWeapon(string name){
	ifstream inFile;
	string line;
	Weapon weap;
	
	//	Open the 'weapons.txt' file
	inFile.open("weapons.txt",ios::in);
	if(inFile.fail()){
		cout << "No weapons for you!\n";
	}

	//	Search the 'weapons.txt' for the 'name' and set the stats
	getline(inFile,line,'\n');
	if(line==name){
		weap.name=line;

		getline(inFile,line,'\n');
		weap.type=line;

		getline(inFile,line,'\n');
		weap.wear=line;

		getline(inFile,line,'\n');
		weap.wield=line;

		getline(inFile,line,'\n');
		const char *eff1 = line.c_str();
		weap.eff1=atoi(eff1);

		getline(inFile,line,'\n');
		const char *eff2 = line.c_str();
		weap.eff2=atoi(eff2);;

		getline(inFile,line,'\n');
		const char *crit = line.c_str();
		weap.critVal=atof(crit);

		getline(inFile,line,'\n');
		weap.accTyp=line;

		getline(inFile,line,'\n');
		const char *acc = line.c_str();
		weap.accVal=atof(acc);

		getline(inFile,line,'\n');
		const char *load = line.c_str();
		weap.weight=atoi(load);

		getline(inFile,line,'\n');
		weap.ammoTyp=line;

		getline(inFile,line,'\n');
		const char *ammo = line.c_str();
		weap.ammoCnt=atoi(ammo);

		getline(inFile,line,'\n');
		const char *val = line.c_str();
		bool eq=false;
		if(val==0) eq=false;
		weap.equipped=eq;
	}

	//	Close the file
	inFile.clear();
	inFile.seekg(0L,ios::beg);
	inFile.close();

	//	Return the structure
	return weap;
}

Equipment setEquip(string name){
	ifstream inFile;
	string line;
	Equipment equip[7];
	
	//	Open the 'equipment.txt' file
	inFile.open("equipment.txt",ios::in);
	if(inFile.fail()){
		cout << "No equipment for you!\n";
	}

	//	Search the 'equipment.txt' for the 'name' and set the stats
	getline(inFile,line,'\n');
	if(line==name){
		for(int i;i<7;i++){
			equip[i]=line;
			line++;
		}
	}

	//	Close the file
	inFile.clear();
	inFile.seekg(0L,ios::beg);
	inFile.close();

	//	Return the structure
	return equip;
}

Loadout setArms(Weapon weap,Loadout gear){
	//	Equipt weapon.
	if(weap.wield == "single"){
		if(gear.rHand == "empty"){
			gear.rHand = weap.name;
		}else if(gear.lHand == "empty"){
			gear.lHand = weap.name;
		}else {unequip();}	//	Still need to write this function
	}else if(weap.wield = "double"){
		if(gear.rHand == "empty" && gear.lHand == "empty"){
			gear.rHand = weap.name;
			gear.lHand = weap.name;
		}else {unequip();}	//	Still need to write this function
	}
	return gear;
}

Loadout setGear(Equipment equip,Loadout gear){
	//	Equipt gear.
	if(equip.type == "armor" && equip.wear == "chest"){
		if(gear.chest == "empty"){
			gear.chest = equip.name;
		}else {unequip();}	//	Still need to write this function
	}else if(equip.type == "armor" && equip.wear == "feet"){
		if(gear.feet == "empty"){
			gear.feet = equip.name;
		}else {unequip();}	//	Still need to write this function
	}else if(equip.type == "store" && equip.wear == "waist"){
		if(gear.waist == "empty"){
			gear.waist = equip.name;
		}else {unequip();}	//	Still need to write this function
	}else if(equip.type == "store" && equip.wear == "back"){
		if(gear.back == "empty"){
			gear.back = equip.name;
		}else {unequip();}	//	Still need to write this function
	}else if(equip.type == "quiv" && equip.wear == "back"){
		if(gear.back == "empty"){
			gear.back = equip.name;
		}else {unequip();}	//	Still need to write this function
	}
		return gear;
}

Player updateArms(Weapon weap,Player p1){
	p1.power += weap.eff1;
	p1.speed += weap.eff2;
	p1.load += weap.weight;

	return p1;
}

Player updateGear(Equipment equip,Player p1){
	if(equip.wear == "chest" || equip.wear == "feet"){
		p1.healthBase += equip.eff1;
		p1.health = p1.healthBase;
	}else if(equip.type == "store"){
		p1.loadBase += equip.eff1;
		p1.load += equip.eff1;
	}else if(equip.type == "quiv"){
		p1.arLoadBase += equip.eff1;
		p1.arLoad += equip.eff1;
	}
	p1.speed += equip.eff2;
	p1.load += equip.weight;

	return p1;
}

void displayLoad(gear){
	cout << "Current Player Loadout:\n"
		<< "Left Hand: "	<< gear.lHand << endl
		<< "Right Hand: "	<< gear.rHand << endl
		<< "Back: "			<< gear.back << endl
		<< "Waist: "		<< gear.waist << endl
		<< "Chest: "		<< gear.chest << endl
		<< "Feet: "			<< gear.feet << endl << endl;
}

int getDefVal(field){	//	Get the default value of a specified field.
	ifstream inFile;
	string line;
	int val;
	
	//	Open the 'defaultStats.txt' file
	inFile.open("defaultStats.txt",ios::in);
	if(inFile.fail()){
		cout << "No stats for you!\n";
	}

	//	Search the 'defaultStats.txt' for the 'field' and set the stat
	do{
		getline(inFile,line,'\n');
		if(line==field){
			getline(inFile,val,'\n');
		}
	}while(line!=field)

	//	Close the file
	inFile.clear();
	inFile.seekg(0L,ios::beg);
	inFile.close();

	//	Return the value
	return val;
}

Loadout unequipArms(Weapon weap,Loadout gear){
	char ans;
	do{
		cout << "Do you want to remove your " << gear.lHand
			<< " and equip the " << weap.name << " you just found?(Y/N): ";
		cin >> ans;
		if(toupper(ans)=='N'){
			cout << gear << " will remain equipt!\n";
		}else if(toupper(ans)=='Y'){
			//	equip
		}else if(toupper(ans)!='Y' || toupper(ans)!='N'){
			cout << "Please enter either 'Y' or 'N'!\n\n";
		}
	}while(toupper(ans)!='Y' || toupper(ans)!='N');
}

Player removeArms(Weapon weap,Player p1){

}

Loadout unequipGear(Equipment equip,Loadout gear){

}

Player removeGear(Equipment equip,Player p1){

}

