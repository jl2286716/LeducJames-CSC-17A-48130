/*
	Programmer: James Leduc
	Program Name: Gaddis_8thEd_Assignment01
	Date Created: 08/30/2014
	Date Modified: 08/30/2014
	Purpose: A menu driven program to run scripts from chapters 3-8 in
		"Starting Out With C++: From Control Structures Through Objects" by Tony Gaddis, 8th Edition:
		3.12 (pg144), 3.13 (pg144), 4.10 (pg221), 5.11 (pg295), 6.7 (pg368), 7.6 (pg449), 8.7 (pg493)
		Two problems from chapters 5 through 8 should include flowcharts.
*/

// Function Prototypes

#incluse <iostream>
using namespace std;

int main(){

)

// Function Definitions

// Chap03_Prob12: Celsius to Fahrenheit
// Write a program that converts Celsius temperatures to Fahrenheit temperatures.
// The formula is: F = ((9 / 5) * C) + 32
// F = degrees Fahrenheit & C = degrees Celsius
int Chap03_Prob12(){
	float celc, fahr; // Create and initialize degree variables
	
	cout << "Please enter a degree in Celsius to convert it to Fahrenheit: ";
	cin >> celc;
	
	fahr = ((9 / 5) * celc) + 32;
	
	cout << endl << celc << " degrees Celsius equals " << fahr << " degrees Fahrenheit.";
	
	return 0;
}