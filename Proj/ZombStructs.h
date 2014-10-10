struct Armor{
	string type;	//	type1 = armor
	string wear;	//	wear = {chest,feet}
	int effect1;	//	effect1 = health
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
	string type2;	//	type2 = regen
	string wear;	//	wear = bag
	int effect;		//	effect1 = regen
	int weight;		//	weight effects the load
};

struct Storage{
	string type1;	//	type1 = storage
	string type2;	//	type2 = {NULL,arrow,regen}
	string wear;	//	wear = {back,waist}
	int effect1;	//	effect1 = load
	int effect2;	//	effect2 = regen
	int effect3;	//	effect3 = speed
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
	int speed;		//	=50
	int power;		//	=20
	int load;		//	=25
};

struct Member{		//	used for team mates and villains
	string name;
	string type;	//	team or foe
	int health;
	int speed;
	int power;
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
	string supply;	//	holds a regen
};


//	Armor Items
	//	Shirt
		type 	= armor;
		wear 	= chest;
		effect1 = +1 health;
		effect2 = 0 speed;
		weight 	= -1 load;
	//	Coat
		type 	= armor;
		wear 	= chest;
		effect1 = +10 health;
		effect2 = -2 speed;
		weight 	= -2 load;
	//	Teflon
		type 	= armor;
		wear 	= chest;
		effect1 = +50 health;
		effect2 = -3 speed;
		weight 	= -10 load;
	//	Kevlar
		type 	= armor;
		wear 	= chest;
		effect1 = +75 health;
		effect2 = -1 speed;
		weight 	= -15 load;
	//	Bare
		type 	= armor;
		wear 	= feet;
		effect1 = -5 health;
		effect2 = -5 speed;
		weight 	= 0 load;
	//	Slippers
		type 	= armor;
		wear 	= feet;
		effect1 = 0 health;
		effect2 = -2 speed;
		weight 	= -2 load;
	//	Sneakers
		type 	= armor;
		wear 	= feet;
		effect1 = 5 health;
		effect2 = +2 speed;
		weight 	= -3 load;
	//	Boots
		type 	= armor;
		wear 	= feet;
		effect1 = 10 health;
		effect2 = -2 speed;
		weight 	= -5 load;
	//	SteelToe
		type 	= armor;
		wear 	= feet;
		effect1 = 20 health;
		effect2 = -5 speed;
		weight 	= -8 load;

//	Ammo Items
	//	357Rnd, 39Rnd, 9Rnd, shell
		type1 	= supply;	//	type1 = supply
		type2 	= round;	//	type2 = {round,box,arrow} - round -> pocket, arrows -> quiver, box -> bag
		qty 	= 1;		//	qty = quantity
		wear 	= pocket;	//	wear = {pocket,bag,quiver}
		weight 	= -1 load;	//	weight effects the load
	//	arrow
		type1 	= supply;
		type2 	= arrow;
		qty 	= 1;
		wear 	= quiver;
		weight 	= -2 load;
	//	357Box, 9Box, shellLBox
		type1 	= supply;
		type2 	= box;
		qty 	= 25;
		wear 	= bag;
		weight 	= -3 load;
	//	39Box
		type1 	= supply;
		type2 	= box;
		qty 	= 20;
		wear 	= bag;
		weight 	= -3 load;
	//	shellBox
		type1 	= supply;
		type2 	= box;
		qty 	= 15;
		wear 	= bag;
		weight 	= -2 load;
	//	shellSBox
		type1 	= supply;
		type2 	= box;
		qty 	= 5;
		wear 	= bag;
		weight 	= -1 load;
