/*	Create the Player	*/
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
string getName(){
	string pName;
	cout << "What's your name?: ";
	cin >> pName;
	cout << endl << endl << "Good luck, " << pName << "!\n\n";
	return pName;
}
Player setPlayer(pName){
	Player p1[9];
		p1.name=pName;
		p1.health=200;
		p1.healthBase=200;
		p1.speed=50;
		p1.power=20;
		p1.load=25;
		p1.loadBase=25;
		p1.arLoad=0;
		p1.arLoadBase=0;
	return p1;
}

/*	Create Equipment	*/
struct Equipment{	//	Holds storage and armor.
	string type;	//	type = {armor,store,quiv}
	string wear;	//	wear = {chest,feet,back,waist}
	int eff1;		//	eff1 = health(chest,feet)/load(back,waist)
	int eff2;		//	eff2 = speed
	int weight;		//	weight effects the load
};
//	Armor Items
Equipment tShrt[5];		//	T-Shirt
	tShrt.type="armor";
	tShrt.wear="chest";
	tShrt.eff1=healthBase+1;
	tShrt.eff2=speed-0;
	tShrt.weight=load-1;
Equipment coat[5];		//	Coat
	coat.type="armor";
	coat.wear="chest";
	coat.eff1=healthBase+10;
	coat.eff2=speed-2;
	coat.weight=load-2;
Equipment teflon[5];	//	Teflon Vest
	teflon.type="armor";
	teflon.wear="chest";
	teflon.eff1=healthBase+50;
	teflon.eff2=speed-3;
	teflon.weight=load-10;
Equipment kevlar[5];	//	Kevlar Vest
	kevlar.type="armor";
	kevlar.wear="chest";
	kevlar.eff1=healthBase+75;
	kevlar.eff2=speed-1;
	kevlar.weight=load-13;
Equipment bare[5];		//	Bare Feet
	bare.type="armor";
	bare.wear="feet";
	bare.eff1=healthBase-5;
	bare.eff2=speed-5;
	bare.weight=load-0;
Equipment slips[5];		//	Slippers
	slips.type="armor";
	slips.wear="feet";
	slips.eff1=healthBase+0;
	slips.eff2=speed-1;
	slips.weight=load-1;
Equipment sneaks[5];	//	Sneakers
	sneaks.type="armor";
	sneaks.wear="feet";
	sneaks.eff1=healthBase+5;
	sneaks.eff2=speed+2;
	sneaks.weight=load-3;
Equipment boots[5];		//	Work Boots
	boots.type="armor";
	boots.wear="feet";
	boots.eff1=healthBase+10;
	boots.eff2=speed-2;
	boots.weight=load-5;
Equipment steels[5];	//	Steel-Toe Boots
	steels.type="armor";
	steels.wear="feet";
	steels.eff1=healthBase+20;
	steels.eff2=speed-5;
	steels.weight=load-8;
			
//	Storage Items
Equipment fanny[5];		//	Fanny Pack
	fanny.type="store";
	fanny.wear="waist";
	fanny.eff1=loadBase+10;
	fanny.eff2=speed-0;
	fanny.weight=load-2;
Equipment quiver[5];	//	Quiver - holds 25 arrows
	quiver.type="quiv";
	quiver.wear="back";
	quiver.eff1=arLoadBase+25;
	quiver.eff2=speed-2;
	quiver.weight=load-2;
Equipment zelda[5];		//	The Zelda - holds 50 arrows
	zelda.type="quiv";
	zelda.wear="back";
	zelda.eff1=arLoadBase+50;
	zelda.eff2=speed-4;
	zelda.weight=load-4;
Equipment bookB[5];		//	Bookbag
	bookB.type="store";
	bookB.wear="back";
	bookB.eff1=loadBase+25;
	bookB.eff2=speed-3;
	bookB.weight=load-3;
Equipment backP[5];		//	Backpack
	backP.type="store";
	backP.wear="back";
	backP.eff1=loadBase+50;
	backP.eff2=speed-5;
	backP.weight=load-5;
Equipment hiker[5];		//	The Hiker - heavy duty hiking backpack
	hiker.type="store";
	hiker.wear="back";
	hiker.eff1=loadBase+75;
	hiker.eff2=speed-10;
	hiker.weight=load-10;

/*	Create Weapons	*/
struct Weapon{
	string type;	//	type = weapon
	string wear;	//	wear = bag
	string wield;	//	wield = {single,double}
	int eff1;		//	eff1 = +power
	int eff2;		//	eff2 = +speed
	float critVal;	//	accVal1 = % chance
	string accTyp;	//	accTyp2 = {insta,jam,miss}
	float accVal;	//	accVal2 = % chance
	int weight;		//	weight = -load
};
Weapon cBow[9];		//	Crossbow
	cBow.type="weapon";
	cBow.wear="bag";
	cBow.wield="double";
	cBow.eff1=power+15;
	cBow.eff2=speed+15;
	cBow.critVal=0.1;		//	10%
	cBow.accTyp="insta";
	cBow.accVal=0.9;		//	90%
	cBow.weight=load-5;
Weapon shovel[9];	//	Shovel
	shovel.type="weapon";
	shovel.wear="bag";
	shovel.wield="double";
	shovel.eff1=power+20;
	shovel.eff2=speed-2;
	shovel.critVal=0.75;	//	75%
	shovel.accTyp="insta";
	shovel.accVal=0.33;		//	33%
	shovel.weight=load-15;
Weapon crowbar[9];	//	Crowbar
	crowbar.type="weapon";
	crowbar.wear="bag";
	crowbar.wield="single";
	crowbar.eff1=power+10;
	crowbar.eff2=speed+8;
	crowbar.critVal=0.5;	//	50%
	crowbar.accTyp="miss";
	crowbar.accVal=0.01;	//	1%
	crowbar.weight=load-5;
Weapon hammer[9];	//	Hammer
	hammer.type="weapon";
	hammer.wear="bag";
	hammer.wield="single";
	hammer.eff1=power+6;
	hammer.eff2=speed+10;
	hammer.critVal=0.15;	//	15%
	hammer.accTyp="miss";
	hammer.accVal=0.02;		//	2%
	hammer.weight=load-3;
Weapon hatchet[9];	//	Hatchet
	hatchet.type="weapon";
	hatchet.wear="bag";
	hatchet.wield="single";
	hatchet.eff1=power+7;
	hatchet.eff2=speed+10;
	hatchet.critVal=0.2;	//	20%
	hatchet.accTyp="miss";
	hatchet.accVal=0.02;	//	2%
	hatchet.weight=load-5;
Weapon magLite[9];	//	Mag-Lite
	magLite.type="weapon";
	magLite.wear="bag";
	magLite.wield="single";
	magLite.eff1=power+5;
	magLite.eff2=speed+9;
	magLite.critVal=0.05;	//	5%
	magLite.accTyp="miss";
	magLite.accVal=0.25;	//	25%
	magLite.weight=load-3;
Weapon defend[9];	//	Defender 1300
	defend.type="weapon";
	defend.wear="bag";
	defend.wield="double";
	defend.eff1=power+35;
	defend.eff2=speed+5;
	defend.critVal=0.8;		//	80%
	defend.accTyp="insta";
	defend.accVal=0.5;		//	50%
	defend.weight=load-10;
Weapon bowie[9];	//	Bowie Knife
	bowie.type="weapon";
	bowie.wear="bag";
	bowie.wield="single";
	bowie.eff1=power+9;
	bowie.eff2=speed+12;
	bowie.critVal=0.7;		//	70%
	bowie.accTyp="miss";
	bowie.accVal=0.01;		//	1%
	bowie.weight=load-3;
Weapon ginsu[9];	//	Ginsu Knife
	ginsu.type="weapon";
	ginsu.wear="bag";
	ginsu.wield="single";
	ginsu.eff1=power+6;
	ginsu.eff2=speed+12;
	ginsu.critVal=0.3;		//	30%
	ginsu.accTyp="miss";
	ginsu.accVal=0.01;		//	1%
	ginsu.weight=load-2;
Weapon glock[9];	//	Glock 19
	glock.type="weapon";
	glock.wear="bag";
	glock.wield="single";
	glock.eff1=power+20;
	glock.eff2=speed+13;
	glock.critVal=0.4;		//	40%
	glock.accTyp="jam";		// 'jam' types miss without losing ammo
	glock.accVal=0.5;		//	50%
	glock.weight=load-2;
Weapon python[9];	//	Python
	python.type="weapon";
	python.wear="bag";
	python.wield="single";
	python.eff1=power+25;
	python.eff2=speed+14;
	python.critVal=0.85;	//	85%
	python.accTyp="insta";
	python.accVal=0.75;		//	75%
	python.weight=load-3;
Weapon sKnife[9];	//	Survival Knife
	sKnife.type="weapon";
	sKnife.wear="bag";
	sKnife.wield="single";
	sKnife.eff1=power+8;
	sKnife.eff2=speed+12;
	sKnife.critVal=0.6;		//	60%
	sKnife.accTyp="miss";
	sKnife.accVal=0.01;		//	1%
	sKnife.weight=load-3;
Weapon ak47[9];		//	AK-47
	ak47.type="weapon";
	ak47.wear="bag";
	ak47.wield="double";
	ak47.eff1=power+30;
	ak47.eff2=speed+20;
	ak47.critVal=0.9;		//	90%
	ak47.accTyp="insta";
	ak47.accVal=0.6;		//	60%
	ak47.weight=load-10;
Weapon mac10[9];	//	MAC-10
	mac10.type="weapon";
	mac10.wear="bag";
	mac10.wield="single";
	mac10.eff1=power+15;
	mac10.eff2=speed+30;
	mac10.critVal=0.35;		//	35%
	mac10.accTyp="insta";
	mac10.accVal=0.05;		//	5%
	mac10.weight=load-7;
Weapon machete[9];	//	MAC-10
	machete.type="weapon";
	machete.wear="bag";
	machete.wield="single";
	machete.eff1=power+10;
	machete.eff2=speed+10;
	machete.critVal=0.5;	//	50%
	machete.accTyp="insta";
	machete.accVal=0.1;		//	10%
	machete.weight=load-7;

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



//	Ammo Items
	//	.357mm Round
	//	.39mm Round
	//	.9mm Round
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
	