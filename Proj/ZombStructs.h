struct Equipment{	//	Holds storage and armor.
	string type;	//	type1 = {armor,store,quiv}
	string wear;	//	wear = {chest,feet,back,waist}
	int effect1;	//	effect1 = health(chest,feet)/load(back,waist)
	int effect2;	//	effect2 = speed
	int weight;		//	weight effects the load
};

struct Ammo{
	string type1;	//	type1 = supply
	string type2;	//	type2 = {round,box,arrow} - rounds -> pocket, arrows -> quiver, box -> bag
	int qty;		//	qty = quantity
	string wear;	//	wear = {pocket,bag,quiver}
	int weight;		//	weight effects the load
};

struct Regen{
	string type1;	//	type1 = supply
	string type2;	//	type2 = {heal,regen}
	string wear;	//	wear = bag
	int effect;		//	effect1 = +health
	int weight;		//	weight effects the load
};

struct Item{
	string type1;	//	type1 = supply
	string type2;	//	type2 = item
	string wear;	//	wear = {pocket,bag}
	string wield;	//	wield = {NULL,single}
	int weight;		//	effects the load
};

struct Weapon{
	string type1;	//	weapon
	string type2;	//	supply,NULL
	string wear;	//	bag
	string wield;	//	single,double
	int effect1;	//	power
	int effect2;	//	speed
	string aType1;	//	crit = power*1.5
	int accVal1;	//	% chance
	string aType2;	//	insta,jam
	int accVal2;	//	% chance
	int weight;		//	load
};

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
		type 	= armor;
		wear 	= chest;
		effect1 = +1 health base;
		effect2 = 0 speed;
		weight 	= -1 load;
	//	Coat
		type 	= armor;
		wear 	= chest;
		effect1 = +10 health base;
		effect2 = -2 speed;
		weight 	= -2 load;
	//	Teflon Vest
		type 	= armor;
		wear 	= chest;
		effect1 = +50 health base;
		effect2 = -3 speed;
		weight 	= -10 load;
	//	Kevlar Vest
		type 	= armor;
		wear 	= chest;
		effect1 = +75 health base;
		effect2 = -1 speed;
		weight 	= -15 load;
	//	Bare Feet
		type 	= armor;
		wear 	= feet;
		effect1 = -5 health base;
		effect2 = -5 speed;
		weight 	= 0 load;
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
	//	.357mm Round
	//	.39mm Round
	//	.9mm Round
	//	Shotgun Shell
		type1 	= supply;	//	type1 = supply
		type2 	= round;	//	type2 = {round,box,arrow} - round -> pocket, arrows -> quiver, box -> bag
		qty 	= 1;		//	qty = quantity
		wear 	= pocket;	//	wear = {pocket,bag,quiver}
		weight 	= -1 load;	//	weight effects the load
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
		effect2	= +1 health per;
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
	