/*
*	Author: 	James Leduc
*	Created:	Sep 25, 2014
*	Modified:	Sep 25, 2014
*	Purpose:	A menu driven program that runs through 5 problems from Gaddis, 8th Edition, Chapter 10.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

//	Prototypes
/*		Menu		*/
	int showMenu();
	void menu(int);
/*		Challenge 1	*/
	void strLen();
	int cntChar(char *);
/*		Challenge 2	*/
	void backStr();
string flipStr(string);
void wrdCnt();
void avNumLet();
void sentCap();

int main(){
	cout << "This program runs through problems 1-5" << endl;
	cout << "in Chapter 10 of Gaddis' 8th Edition." << endl;
	
	int choice = showMenu();
	menu(choice);
	
	cout << "GOODBYE!\n" << endl;
	
	return 0;
}

//	Definitions
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
				case 1001:	strLen();	break;
				case 1002:	backStr();	break;
				case 1003:	wrdCnt();	break;
				case 1004:	avNumLet();	break;
				case 1005:	sentCap();	break;
				default:	cout << endl << "If this got through, THERE'S A PROBLEM!\n\n";
			}
		}
		
//	Programming Challenge #1. String Length
//		Write a function that returns an integer and accepts a pointer to a C-string as an argument. 
//		The function should count the number of characters in the string and return that number. 
//		Demonstrate the function in a simple program that asks the user to input a string, 
//		passes it to the function, and then displays the function's return value.
void strLen(){
	const int SIZE = 101;
	//char *str[SIZE];
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
	string str, flipArr;
	int len=0;
	
	cout << "Enter a string: ";
	cin >> str;
	cout << endl << "You wrote: " << endl;
	cout << "'" << str << "'" << endl;
	
	flipArr = flipStr(str);
	
	cout << "But I flipped it on you!" << endl;
	//len = strlen(str)+1;	//	+1 to include the null terminator, '\0'
	while(str[len] != '\0'){
		len++;
	}

	for(int i=0;i<len;i++){
		cout << flipArr[i];
	}
	cout << endl << "BWAAAAHAHAHAHAHAHAAHAAAAA!" << endl;
}
string flipStr(string *s){
	int ln = 0;//strlen(s);
	while(s[ln] != '\0'){
		ln++;
	}

	int j = ln-1;						//	-1 because the index begins at 0
	string *flip = new string[ln+1];	//	+1 to include the null terminator, '\0'
	for(int i=0;i<ln;i++){
		do{
			flip[i] = s[j];
			j--;
		}while(s[i] != '\0' || j<0);
	}
	return flip;
}

//	Programming Challenge #3. Word Counter
void wrdCnt(){


}

//	Programming Challenge #4. Average Number of Letters
void avNumLet(){


}

//	Programming Challenge #5. Sentence Capitalizer
void sentCap(){


}
