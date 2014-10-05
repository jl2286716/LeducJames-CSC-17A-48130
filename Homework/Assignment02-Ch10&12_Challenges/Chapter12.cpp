/*
*	Author: 	James Leduc
*	Created:	Sep 30, 2014
*	Modified:	Oct 01, 2014
*	Purpose:	A menu-driven program that runs through 5 problems from Gaddis, 8th Edition, Chapter 12.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

//		Prototypes		//
/*		Menu			*/
	int showMenu();
	void menu(int);
/*		Challenge 1		*/
	void fileHead();
/*		Challenge 2		*/
	void fileDisp();
/*		Challenge 3		*/
	//void punchLine();
/*		Challenge 4		*/
	//void tailPro();
/*		Challenge 5		*/
	//void lineNum();

int main(){
	char ans;
	int choice;
	
	cout << "This program runs through problems 1-5" << endl;
	cout << "in Chapter 12 of Gaddis' 8th Edition." << endl;
	
	do{
		choice = showMenu();
		menu(choice);
		
		cout << "AGAIN? (Y/N)" << endl;
		cin >> ans;
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
		cout << "1201: File Head Program" << endl;
		cout << "1202: File Display Program" << endl;
		cout << "1203: Punch Line" << endl;
		cout << "1204: Tail Program" << endl;
		cout << "1205: Line Numbers" << endl;
		cout << "Enter your choice: ";
		cin >> c;
		cout << endl;
		if(c < 1201 || c > 1205){
			cout << "You have entered an invalid choice!" << endl;
			cout << "Please choose a number from 1201 to 1205." << endl;
			system("pause");
			system("cls");
		}
	}while(c < 1201 || c > 1205);
	cout << endl;
	return c;
}

void menu(int c){
	switch(c){
		case 1201:	fileHead();
			system("pause");
			system("cls");
			break;
		case 1202:	fileDisp();
			system("pause");
			system("cls");
			break;
		case 1203:	//punchLine();
			system("pause");
			system("cls");
			break;
		case 1204:	//tailPro();
			system("pause");
			system("cls");
			break;
		case 1205:	//lineNum();
			system("pause");
			system("cls");
			break;
		default:	cout << endl << "If this got through, THERE'S A PROBLEM!\n\n";
	}
}
		
//	Programming Challenge #1. File Head Program
//		Write a program that asks the user for the name of a file. The program should 
//		display the first 10 lines of the file on the screen (the "head" of the file). 
//		If the file has fewer than 10 lines, the entire file should be displayed, with 
//		a message indicating the entire file has been displayed.
void fileHead(){
	ifstream inFile;
	bool failed;	//	Is 'true' if file opening fails.
	int lnCnt=0;	//	Line counter initialized to zero.
	string line,	//	Stores the lines to be written to the console.
		fName;		//	Holds the file name from the user.
	
	//	Open file with fail condition. DONT FORGET TO CLOSE THE FILE!!!!!
	do{	failed=false;	//	Set the flag to 'false' for a fresh start.
		//	Get file name from user.
		cout << "Enter the name of the file: ";
		cin >> fName;
		
		cout << endl;
		//	Test file opening.
		inFile.open(fName.c_str(),ios::in);
		if(inFile.fail()){
			cout << "File opening failed! Be sure to include the file extension.\n";
			failed=true;
		}else if(inFile.eof()){
			cout << "This file is empty!" << endl;
			cout << "Give me something with SOMETHING in it!" << endl;
			failed=true;
		}
	}while(failed==true);
	
	
	while(lnCnt<10 && !inFile.eof()){
		//	Get line from file
		getline(inFile,line,'\n');
		//	Write line to console
		cout << line << endl;
		//	Increment counter
		lnCnt++;
	}
	
	if(lnCnt<10){
		cout << endl << "The entire file has been displayed." << endl;
	}else{
		cout << endl << "The 10 lines above make up the 'HEAD' of the '" << fName << "' file.\n";
	}
	
	inFile.close();
}


//	Programming Challenge #2. File Display Program
//		Write a program that asks the user for the name of a file. The program should 
//		display the contents of the file on the screen. If the file's contents won't fit 
//		on a single screen, the program should display 24 lines of output at a time, and 
//		then pause. Each time the program pauses, it should wait for the user to strike 
//		a key before the next 24 lines are displayed.
void fileDisp(){
	ifstream inFile;
	bool failed;	//	Is 'true' if file opening fails.
	int linePer=24,	//	Number of lines printed per screen.
		lineCnt=0,	//	Line counter initialized to zero.
		newCnt=0;	//	New line counter initialized to zero.
	string line,	//	Stores the lines to be written to the console.
		fName;		//	Holds the file name entered by the user.
	char ch;		//	Holds a character from the string.
	
	do{	failed=false;	//	Set the flag to 'false' for a fresh start.
		//	Get file name from user.
		cout << "Enter the name of the file: ";
		cin >> fName;
		cout << endl;
		//	Test file opening.
		inFile.open(fName.c_str(),ios::in);
		if(inFile.fail()){
			cout << "File opening failed! Be sure to include the file extension.\n";
			failed=true;
		}else if(inFile.eof()){
			cout << "This file is empty!" << endl;
			cout << "Give me something with SOMETHING in it!" << endl;
			failed=true;
		}
	}while(failed==true);
	inFile.close();
	
	inFile.open(fName.c_str(),ios::in);
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		lineCnt++;
	}
	inFile.close();

	cout << "There are " << lineCnt << " line(s) in this file.\n";

	inFile.open(fName.c_str(),ios::in);

	//	This loop doesn't work... why?
	while(!inFile.eof()){
		if(lineCnt<linePer){
			for(int j=0;j<lineCnt;j++){
				getline(inFile,line,'\n');
				cout << line << endl;
			}
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

//	Programming Challenge #3. Punch Line
//		Write a program that reads and prints a joke and its punch line from two different 
//		files. The first file contains a joke, but not its punch line. The second file has 
//		the punch line as its last line, preceded by "garbage." The main function of your 
//		program should open the two files and then call two functions, passing each one 
//		the file it needs. The first function should read and display each line in the file 
//		it is passed (the joke file). The second function should display only the last line 
//		of the file it is passed (the punch line file). It should find this line by seeking 
//		to the end of the file and then backing up to the beginning of the last line. Data 
//		to test your program can be found in the joke.txt and punchline.txt files.
void punchLine(){
	ifstream inFile;
	bool failed;	//	Is 'true' if file opening fails.
	int lnCnt=0;	//	Line counter initialized to zero.
	string line;	//	Stores the lines to be written to the console.
	
	//	Open file with fail condition. DONT FORGET TO CLOSE THE FILE!!!!!
	do{	failed=false;	//	Set the flag to 'false' for a fresh start.
		//	Test file opening.
		inFile.open("joke.txt",ios::in);
		if(inFile.fail()){
			cout << "File opening failed!\n";
			failed=true;
		}
	}while(failed==true);
	
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		cout << line << endl;
	}

	inFile.close();
}

//	Programming Challenge #4. Tail Program
//		Write a program that asks the user for the name of a file. The program should display 
//		the last 10 lines of the file on the screen (the "tail" of the file). If the file has 
//		fewer than 10 lines, the entire file should be displayed, with a message indicating 
//		the entire file has been displayed.
	//void tailPro();

//	Programming Challenge #5. Line Numbers
//		(This assignment should be done as a modification to Programming Challenge 2.)
//		Write a program that asks the user for the name of a file. The program should display 
//		the contents of the file on the screen. Each line of scree output should be preceded 
//		with a line number, followed by a colon. The line numbering should start at 1. 
//		Here is an example:
//			1:George Rolland
//			2:127 Academy Street
//			3:Brasstown, NC 28706
//		If the file's contents won't fit on a single screen, the program should display 24 
//		lines of output at a time, and then pause. Each time the program pauses, it should 
//		wait for the user to strike a key before the next 24 lines are displayed.
	//void lineNum();
