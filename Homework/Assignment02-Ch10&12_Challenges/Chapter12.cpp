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
	void punchLine();
/*		Challenge 4		*/
	void tailPro();
/*		Challenge 5		*/
	void lineNum();

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
		case 1203:	punchLine();
			system("pause");
			system("cls");
			break;
		case 1204:	tailPro();
			system("pause");
			system("cls");
			break;
		case 1205:	lineNum();
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
	
	//	Open file with fail condition.
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
		}
	}while(failed==true);
	
	//	Count the number of lines in the file and output the results.
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
		lineCnt=0;	//	Line counter initialized to zero.
	string line,	//	Stores the lines to be written to the console.
		fName;		//	Holds the file name entered by the user.
	
	//	File opening check.
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
		}
	}while(failed==true);

	//	Count the number of lines in the file.
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		lineCnt++;
	}

	//	Go to the beninning of the file.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	//	Iterate through and display the file.
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
	bool failed;		//	Is 'true' if file opening fails.
	string line;		//	Stores the lines to be written to the console.
	long int bytes=0;	//	Counts the bytes of the punchline.txt file.
	char ch,			//	Character placeholder.
		val,			//	Array character placeholder.
		*punch;			//	Array to hold the punchline file.
	int lines=0,		//	Line counter.
		idx;			//	Array index placeholder.
	
	//	File opening check.
	do{	failed=false;	//	Set the flag to 'false' for a fresh start.
		//	Test the opening of the 'joke.txt' file.
		inFile.open("joke.txt",ios::in);
		if(inFile.fail()){
			cout << "Where's the joke?\n";
			failed=true;
		}
	}while(failed==true);
	
	//	Read and write joke.txt to the console.
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		cout << line << endl;
	}
	system("pause");
	inFile.clear();
	inFile.close();

	//	File opening check.
	do{	failed=false;	//	Set the flag to 'false' for a fresh start.
		//	Test the opening of the 'punchline.txt' file.
		inFile.open("punchline.txt",ios::in);
		if(inFile.fail()){
			cout << "Where's the punchline?\n";
			failed=true;
		}
	}while(failed==true);
	
	//	Count the file bytes
	inFile.seekg(0L,ios::end);
	bytes = inFile.tellg();

	//	Go to the beninning of the file.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	// Create and fill the 'punch' array
	punch=new char[bytes];
	for(int i=0;i<bytes;i++){
		inFile.get(ch);
		punch[i]=ch;
	}
	inFile.close();

	//	Count lines
	for(int j=0;j<bytes;j++){
		if(punch[j]=='\n'){
			lines++;
		}
	}

	//	Output the punchline
	idx=bytes;
	do{
		val=punch[idx];
		idx--;
	}while(val != '\n');
	for(idx;idx<bytes;idx++){
		cout << punch[idx];
	}
	cout << endl;
}

//	Programming Challenge #4. Tail Program
//		Write a program that asks the user for the name of a file. The program should display 
//		the last 10 lines of the file on the screen (the "tail" of the file). If the file has 
//		fewer than 10 lines, the entire file should be displayed, with a message indicating 
//		the entire file has been displayed.
void tailPro(){
	ifstream inFile;
	bool failed;		//	Is 'true' if file opening fails.
	string line,		//	Stores the lines to be written to the console.
		fName;			//	Holds the name entered by the user.
	long int bytes=0;	//	Counts the bytes of the punchline.txt file.
	char ch,			//	Character placeholder.
		val,			//	Array character placeholder.
		*arr;			//	Array to hold the file.
	int lines=1,		//	Line counter.
		lnBack=0,
		backCnt=0,
		idx;			//	Array index placeholder.

	//	File opening check.
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
		}
	}while(failed==true);

	//	Count the file bytes
	inFile.seekg(0L,ios::end);
	bytes = inFile.tellg();

	//	Go to the beninning of the file.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	// Create and fill the array.
	while(!inFile.eof()){
		arr=new char[bytes];
		for(int i=0;i<bytes;i++){
			inFile.get(ch);
			arr[i]=ch;
		}
	}
	inFile.close();

	//	Count lines
	for(int j=0;j<bytes;j++){
		if(arr[j]=='\n'){
			lines++;
		}
	}

	//	Display last 10 lines
	if(lines<10){
		for(idx=0;idx<(bytes-(lines-1));idx++){		//	Subtract lines-1 because for some reason, it's adding that amount of extra crap.
			cout << arr[idx];
		}
		cout << endl << endl << "The entire file has been displayed." << endl;
	}else{
		for(idx=bytes;lnBack<10;idx--){
			if(arr[idx]=='\n'){
				lnBack++;
			}
			backCnt++;
		}
		for(int ind=(bytes-backCnt);ind<(bytes-(lines-1));ind++){
			cout << arr[ind];
		}
		cout << endl << endl << "The 10 lines above make up the 'TAIL' of the '" << fName << "' file.\n";
	}
}

//	Programming Challenge #5. Line Numbers
//		(This assignment should be done as a modification to Programming Challenge 2.)
//		Write a program that asks the user for the name of a file. The program should display 
//		the contents of the file on the screen. Each line of screen output should be preceded 
//		with a line number, followed by a colon. The line numbering should start at 1. 
//		Here is an example:
//			1:George Rolland
//			2:127 Academy Street
//			3:Brasstown, NC 28706
//		If the file's contents won't fit on a single screen, the program should display 24 
//		lines of output at a time, and then pause. Each time the program pauses, it should 
//		wait for the user to strike a key before the next 24 lines are displayed.
void lineNum(){
	ifstream inFile;
	bool failed;	//	Is 'true' if file opening fails.
	int linePer=24,	//	Number of lines printed per screen.
		lineCnt=0,	//	Line counter initialized to zero.
		lines=1;	//	New line counter initialized to zero.
	string line,	//	Stores the lines to be written to the console.
		fName;		//	Holds the file name entered by the user.
	
	//	File opening check.
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
		}
	}while(failed==true);
	inFile.close();
	
	//	Count the number of lines in the file.
	inFile.open(fName.c_str(),ios::in);
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		lineCnt++;
	}

	//	Go to the beninning of the file.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	//	Iterate through and display the file.
	while(!inFile.eof()){
		if(lineCnt<linePer){
			for(int j=0;j<lineCnt;j++){
				getline(inFile,line,'\n');
				cout << lines << ": " << line << endl;
				lines++;
			}
		}else if(lineCnt>=linePer){
			for(int i=0;i<linePer;i++){
				getline(inFile,line,'\n');
				cout << lines << ": " << line << endl;
				lineCnt--;
				lines++;
			}
			system("pause");
		}
	}
	inFile.close();
}