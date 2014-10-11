/*	Create the Player	*/
struct Player{
	string name;
	int health;		//	=200
	int healthBase;	//	=200
	int speed;		//	=50
	int power;		//	=20
	int powerBase;	//	=20
	int load;		//	=25
	int loadBase;	//	=25
	int arLoad;		// 	=0
	int arLoadBase;	//	=0
};
string getName(){
	string pName;
	cout << "What's your name?: ";
	cin >> pName;
	cout << endl << endl << "Good luck, " << pName << "!\n\n";
	return pName;
}
/*returnType*/ setPlayer(name){
	const int P_SIZE = 9;
	int player[P_SIZE];
	player[0]=200;
	player[1]=200;
	player[2]=50;
	player[3]=20;
	player[4]=20;
	player[5]=25;
	player[6]=25;
	player[7]=0;
	player[8]=0;
	
	//	Fill the 'Player' structure
	
	//	Return the 'Player' structure
}

struct Equipment{	//	Holds storage and armor.
	string type;	//	type = {armor,store,quiv}
	string wear;	//	wear = {chest,feet,back,waist}
	int eff1;		//	eff1 = health(chest,feet)/load(back,waist)
	int eff2;		//	eff2 = speed
	int weight;		//	weight effects the load
};

struct Ammo{
	string type;	//	type = {round,box,arrow} - rounds -> pocket, arrows -> quiver, box -> bag
	int qty;		//	qty = quantity
	string wear;	//	wear = {pocket,bag,quiver}
	int weight;		//	weight effects the load
};

struct Regen{
	string type;	//	type = {heal,regen}
	string wear;	//	wear = bag
	int effect;		//	effect1 = +health
	int weight;		//	weight effects the load
};

struct Item{
	string type;	//	type = item
	string wear;	//	wear = {pocket,bag}
	string wield;	//	wield = {NULL,single}
	int weight;		//	effects the load
};

struct Weapon{
	string type;	//	type = weapon
	string wear;	//	wear = bag
	string wield;	//	wield = {single,double}
	int effect1;	//	effect1 = +power
	int effect2;	//	effect2 = +speed
	string accTyp1;	//	accTyp1 = crit{power*1.5}
	int accVal1;	//	accVal1 = % chance
	string accTyp2;	//	accTyp2 = {insta,jam}
	int accVal2;	//	accVal2 = % chance
	int weight;		//	weight = -load
};


struct Member{		//	used for team mates and villains
	string name;
	string type;	//	team or foe
	int health;
	int healthBase;
	int speed;
	int power;
	int powerBase;
};

struct Inventory{
	string lHand;	//	can be equipped - default = fist
	string rHand;	//	can be equipped - default = fist
	string back;	//	is switched out; bag size effects load, hence, carried items - default = NULL
	string waist;	//	is switched out - default = NULL
	string chest;	//	coat can go over teflon & kevlar - default = shirt
	string feet;	//	is switched out - default = bare
	string pocket;	//	only 5 load per pocket, 4 pockets = 20 load
};

struct MemInv{		//	team member inventory
	string lHand;
	string rHand;
	string chest;
	string supply;	//	holds a regen/heal
};


//	Armor Items
	//	T-Shirt
		Equipment tShrt[5];
			tShrt.type="armor";
			tShrt.wear="chest";
			tShrt.eff1=healthBase+1;
			tShrt.eff2=speed-0;
			tShrt.weight=load-1;
	//	Coat
		Equipment coat[5];
			coat.type="armor";
			coat.wear="chest";
			coat.eff1=healthBase+10;
			coat.eff2=speed-2;
			coat.weight=load-2;
	//	Teflon Vest
		Equipment teflon[5];
			teflon.type="armor";
			teflon.wear="chest";
			teflon.eff1=healthBase+50;
			teflon.eff2=speed-3;
			teflon.weight=load-10;
	//	Kevlar Vest
		Equipment kevlar[5];
			kevlar.type="armor";
			kevlar.wear="chest";
			kevlar.eff1=healthBase+75;
			kevlar.eff2=speed-1;
			kevlar.weight=load-13;
	//	Bare Feet
		Equipment bare[5];
			bare.type="armor";
			bare.wear="feet";
			bare.eff1=healthBase-5;
			bare.eff2=speed-5;
			bare.weight=load-0;
	//	Slippers
		type 	= armor;
		wear 	= feet;
		effect1 = 0 health base;
		effect2 = -2 speed;
		weight 	= -2 load;
	//	Sneakers
		type 	= armor;
		wear 	= feet;
		effect1 = 5 health base;
		effect2 = +2 speed;
		weight 	= -3 load;
	//	Work Boots
		type 	= armor;
		wear 	= feet;
		effect1 = 10 health base;
		effect2 = -2 speed;
		weight 	= -5 load;
	//	Steel-Toe Boots
		type 	= armor;
		wear 	= feet;
		effect1 = 20 health base;
		effect2 = -5 speed;
		weight 	= -8 load;

//	Storage Items
	//	Fanny Pack
		type	= store;	//	type1 = {armor,store,quiv}
		wear	= waist;	//	wear = {chest,feet,back,waist}
		effect1	= +10 load base;	//	effect1 = health(chest,feet)/load(back,waist)
		effect2	= 0 speed;	//	effect2 = speed
		weight	= -2 load;	//	weight effects the load
	//	Quiver - holds 25 arrows
		type	= quiv;
		wear	= back;
		effect1	= +25 arrow load base;
		effect2	= -2 speed;
		weight	= -2 load;
	//	The Zelda - holds 50 arrows
		type	= quiv;
		wear	= back;
		effect1	= +50 arrow load base;
		effect2	= -4 speed;
		weight	= -4 load;
	//	Bookbag
		type	= store;
		wear	= back;
		effect1	= +25 load base;
		effect2	= -3 speed;
		weight	= -3 load;
	//	Backpack
		type	= store;
		wear	= back;
		effect1	= 50 load base;
		effect2	= -5 speed;
		weight	= -5 load;
	//	The Hiker
		type	= store;
		wear	= back;
		effect1	= 75 load base;
		effect2	= -10 speed;
		weight	= -10 load;

//	Ammo Items
	const int AMSIZE=5;
	//	.357mm Round
		rnd357[AMSIZE];
		rnd357[0]="supply";
		rnd357[1]="
	//	.39mm Round
		rnd39[AMSIZE];
	//	.9mm Round
		rnd9[AMSIZE];
	//	Shotgun Shell
		type1 	= supply;	//	type1 = supply
		type2 	= round;	//	type2 = {round,box,arrow} - round -> pocket, arrows -> quiver, box -> bag
		qty 	= 1;		//	qty = quantity
		wear 	= pocket;	//	wear = {pocket,bag,quiver}
		weight 	= -1 load;	//	weight = -load
	//	Arrow
		type1 	= supply;
		type2 	= arrow;
		qty 	= 1;
		wear 	= quiver;
		weight 	= -1 arLoad;
	//	Bundle of Arrows
		type1 	= supply;
		type2 	= arrow;
		qty 	= 5;
		wear 	= quiver;
		weight 	= -5 arLoad;
	//	Large Bundle of Arrows
		type1 	= supply;
		type2 	= arrow;
		qty 	= 10;
		wear 	= quiver;
		weight 	= -10 arLoad;
	//	Box of .357mm Rounds
	//	Box of .9mm Rounds
	//	Large Box of Shotgun Shells
		type1 	= supply;
		type2 	= box;
		qty 	= 25;
		wear 	= bag;
		weight 	= -3 load;
	//	Box of .39mm rounds
		type1 	= supply;
		type2 	= box;
		qty 	= 20;
		wear 	= bag;
		weight 	= -3 load;
	//	Box of Shotgun Shells
		type1 	= supply;
		type2 	= box;
		qty 	= 15;
		wear 	= bag;
		weight 	= -2 load;
	//	Small Box of Shotgun Shells
		type1 	= supply;
		type2 	= box;
		qty 	= 5;
		wear 	= bag;
		weight 	= -1 load;

//	Regen Items
	//	candy - Candy Bar
		type1	= supply;	//	type1 = supply
		type2 	= heal;		//	type2 = {heal,regen}
		wear 	= pocket;	//	wear = {bag,pocket,waist}
		effect 	= +5 healh;	//	effect1 = +health
		weight 	= -1 load;	//	weight effects the load
	//	Canteen
		type1	= supply;
		type2	= regen;
		wear	= waist;
		effect2	= +2 health per;
		weight	= -2 load;
	//	water - Bottle Water
		type1 	= supply;
		type2 	= heal;
		wear 	= bag;
		effect 	= +5 healh;
		weight	= -2 load;
	//	cann - Canned Goods
		type1 	= supply;
		type2 	= heal;
		wear 	= bag;
		effect 	= +15 healh;
		weight 	= -3 load;
	//	mre - Meal Ready to Eat
		type1 	= supply;
		type2 	= heal;
		wear 	= bag;
		effect 	= +25 healh;
		weight 	= -4 load;
	