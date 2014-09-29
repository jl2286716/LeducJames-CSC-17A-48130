/*
*	Author: 	James Leduc
*	Created:	Sep 25, 2014
*	Modified:	Sep 27, 2014
*	Purpose:	A menu-driven program that runs through 5 problems from Gaddis, 8th Edition, Chapter 10.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

//		Prototypes		//
/*		Menu			*/
	int showMenu();
	void menu(int);
/*		Challenge 1		*/
	void strLen();
	int cntChar(char *);
/*		Challenge 2		*/
	void backStr();
	void swap(char *, int);
/*		Challenge 3		*/	
	void wrdCnt();
	int cntWrds(int *);
/*		Challenge 4		*/
	void avNumLet();
	float avLetWrd(int *,int);
/*		Challenge 5		*/
	void sentCap();
	void capFrst(int *);

int main(){
	char ans;
	int choice;
	
	cout << "This program runs through problems 1-5" << endl;
	cout << "in Chapter 10 of Gaddis' 8th Edition." << endl;
	
	do{
		choice = showMenu();
		menu(choice);
		
		cout << "AGAIN? (Y/N)" << endl;
		cin << ans;
		ans = toupper(ans);
	}while(ans=='Y');
	
	cout << "GOODBYE!\n" << endl;
	
	return 0;
}

/*			Definitions			*/

// Run the menu.
int showMenu(){
	int c;	//	Choice
	do{
		cout << "Please, choose from the numbers on the left..." << endl;
		cout << "1001: String Length" << endl;
		cout << "1002: Backward String" << endl;
		cout << "1003: Word counter" << endl;
		cout << "1004: Average Number of Letters" << endl;
		cout << "1005: Sentence Capitalizer" << endl;
		cout << "Enter your choice: ";
		cin >> c;
		cout << endl;
		if(c != 1001 || c != 1002 || c !=1003 || c !=1004 || c !=1005){
			cout << "You have entered an invalid choice!" << endl;
			cout << "Please choose a number from 1001 to 1005." << endl;
			system("pause");
			system("cls");
		}
	}while(c != 1001 || c != 1002 || c !=1003 || c !=1004 || c !=1005);
	cout << endl;
	return c;
}

void menu(int c){
	switch(c){
		case 1001:	strLen();
			system("pause");
			system("cls");
			break;
		case 1002:	backStr();
			system("pause");
			system("cls");
			break;
		case 1003:	wrdCnt();
			system("pause");
			system("cls");
			break;
		case 1004:	avNumLet();
			system("pause");
			system("cls");
			break;
		case 1005:	sentCap();
			system("pause");
			system("cls");
			break;
		default:	cout << endl << "If this got through, THERE'S A PROBLEM!\n\n";
	}
}
		
//	Programming Challenge #1. String Length
//		Write a function that returns an integer and accepts a pointer to a C-string as an argument. 
//		The function should count the number of characters in the string and return that number. 
//		Demonstrate the function in a simple program that asks the user to input a string, 
//		passes it to the function, and then displays the function's return value.
void strLen(){
	// Declare the string pointer and it's array.
	const int SIZE = 101;
	char *str;
		str = new char[SIZE];
	
	int count;
	
	cout << "Please, enter a few words or a phrase \n";
	cout << "(ONLY " << SIZE-1 << " keystrokes TOTAL): \n";
	
	cin.ignore();	//	Clears the buffer
	cin.getline(str,SIZE);
	count = cntChar(str);
	cin.ignore();	//	Clears the buffer
	
	if(count<1){
		cout << "You didn't enter anything!" << endl;
	}else if(count==1){
		cout << "Your string is " << count << " character in length." << endl;
	}else if(count>1){
		cout << "Your string is " << count << " characters in length." << endl;
	}
}

int cntChar(char *s){	//	Counts each character in the string.
//	int c=strlen(s);
	int c=0;	// Counter initialized to 0
	while(s[c] != '\0'){
		c++;
	}
	return c;
}

//	Programming Challenge #2. Backward String
//		Write a function that accepts a pointer to a C-string as an argument and displays 
//		its contents backward. For instance, if the string argument is "Gravity" the function 
//		should display "ytivarG". Demonstrate the function in a program that asks the user to 
//		input a string and then passes it to the function.
void backStr(){
	int size = 101;			// C-String size
	char str[size];			// C-String
	int newSize;
	
	cout << "Enter a string: ";
	cin.ignore();			//	Clears the buffer
	cin.getline(str,size);	//	Get the whole line entered by the user and place it into the C-string 'str' array.
	cout << endl << "You wrote: " << endl;
	cout << "'" << str << "'" << endl;
	
	newSize = strlen(str);	//	Get 'newSize' of user's C-string.
	
	swap(str,newSize);
	cout << endl << "BWAAAAHAHAHAHAHAHAAHAAAAA!" << endl << endl;
}
void swap(char *s, int n){	//	Pass in the C-string 's[]' array as a pointer and it's 'newSize'.
	char temp;				//	Create a temporary holding place for the pointer values.
	char *front;			//	Create the 'front' pointer.
		front = &(s[0]);	//	Make the 'front' pointer point at the first address in the 's[]' array.
	char *back;				//	Create the 'back' pointer.
		back = &(s[n-1]);	//	Make the 'back' pointer point at the last address in the 's[]' array.
							//		-1, taking into account the null terminator '\0'.

	//	This loop cycles through the left and right sides of the 's[]' array.
	//		Starting at its nearest and furthest indexes, working their way inward.
	for(int i=0;i<((n-1)/2);i++){	//	The cycle runs at half the value of the C-string.
		temp = *front;		//	Place the value of where the 'front' pointer is pointing to into 'temp'.
		*front = *back;		//	Place the value of where the 'back' pointer is pointing to into where the 'front' pointer is pointing.
		*back = temp;		//	Place the value of 'temp' into where the 'back' pointer is pointing.
		front++;			//	Move the 'front' pointer forward one index.
		back--;				//	Move the 'back' pointer backward one index.
	}
	cout << "But I flipped it on you!" << endl;
	cout >> s >> endl;		//	Output the C-string 's[]' array in reverse.
}

//	Programming Challenge #3. Word Counter
//		Write a function that accepts a pointer to a C-string as an argument and returns the number of 
//		words contained in the string. For instance, if the string argument is "Four score and 
//		seven years ago" the function should return the number 6. Demonstrate the function in a 
//		program that asks the user to input a string and then passes it to the function. The number 
//		of words in the string should be displayed on the screen.
void wrdCnt(){
	int size = 101;
	char str[size];
	int num;
	
	cout << "Enter a string: ";
	cin.ignore();
	cin.getline(str,size);
	cout << "You wrote: " << endl;
	cout << "'" << str << "'" << endl;
	
	num = cntWrds(str);
	if(num>1){
		cout << "Which is " << num << " words long." << endl;
	}else{
		cout << "Which is " << num << " word long." << endl;
	}
}
int cntWrds(int *s){
	int cnt=1;
	while(*s != '\0'){
		if(*s == " ") cnt++;
		s++;
	}
	return cnt;
}

//	Programming Challenge #4. Average Number of Letters
//		Modify the program you wrote for Challenge 3 (Word Count), 
//		so it also displays the average number of letters in each word.
void avNumLet(){
	int size = 101;
	char str[size];
	int num;
	float avLet;
	
	cout << "Enter a string (" << size-1 << " char max): ";
	cin.ignore();
	cin.getline(str,size);
	cout << "You wrote: " << endl;
	cout << "'" << str << "'" << endl;
	
	num = cntWrds(str);
	if(num>1){
		cout << "Which is " << num << " words long." << endl;
	}else{
		cout << "Which is " << num << " word long." << endl;
	}
	
	avLet = avLetWrd(str,num);
	cout << setprecision(2) << fixed << showpoint;
	cout << "With an average of " << avLet << " letters per word." << endl;
}
float avLetWrd(int *s,int n){	//	'n' is the number of words
	float ave;					//	Average variable
	float len=(strlen(s))-1;	//	Length of the C-string minus the null terminator
	float punct=0;				// 	Punctuation, space, & number counter
	float spcs=n-1;				//	Number of spaces

	// Count non-letters
	while(*s != '\0'){
		if(ispunct(*s)) punct++;
		if(isdigit(*s)) punct++;
		s++;
	}
	
	// Calculate average number of letters per word.
	ave=(len-punct-spcs)/n;
	
	return ave;
}

//	Programming Challenge #5. Sentence Capitalizer
//		Write a function that accepts a pointer to a C-string as an argument and capitalizes 
//		the first character of each sentence in the string. For instance, if the string argument 
//		is "hello. my name is Joe. what is your name?" the function should manipulate the string 
//		so it contains "Hello. My name is Joe. What is your name?" Demonstrate the function in a 
//		program that asks the user to input a string and then passes it to the function. The 
//		modified string should be displayed on the screen.
void sentCap(){
	int size=101;
	char str[size];
	int len;
	
	cout << "Enter a few short uncapitalized sentences (" << size-1 << " char max): " << endl;
	cin.ignore();
	cin.getline(str,size);
	cout << "You wrote: " << endl;
	cout << "'" << str << "'" << endl;
	
	//len=strlen(str);
	
	capFrst(str);

}
void capFrst(int *s){
	while(*s != '\0'){
		if(i==0) s[0]=toupper(s[0]);
		if(ispunct(s[i-2])) s[i]=toupper(s[i]);
		s++;
	}
	cout << endl << "Properly capitalized, your sentences should look like:" << endl;
	cout << "'" << s << "'" << endl;
}
