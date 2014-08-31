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


	return 0;
)

// Function Definitions

// Chap03_Prob12: Celsius to Fahrenheit
	// Write a program that converts Celsius temperatures to Fahrenheit temperatures.
	// The formula is: F = ((9 / 5) * C) + 32
	// F = degrees Fahrenheit & C = degrees Celsius.
	int Chap03_Prob12(){
		
		// Create degree variables.
		float celc, fahr;
		
		// Get input from user.
		cout << "Please enter a degree in Celsius to convert it to Fahrenheit: ";
		cin >> celc;
		
		// Calculate degree conversion from Celsius to Fahrenheit.
		fahr = ((9 / 5) * celc) + 32;
		
		// Display results.
		cout << endl << celc << " degrees Celsius equals " << fahr << " degrees Fahrenheit.";
		
		return 0;
	}

// Chap03_Prob13: Currency
	// Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
	// storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
	// To get the most up-to-date exchange rates, search the Internet using the term
	// "currency exchange rate". If you cannot find the most recent exchange rates,
	// use the following: 1 Dollar = 98.93 Yen ; 1 Dollar = 0.74 Euros.
	// Format your currency amounts in fixed-point notation, with two decimal places of
	// precision, and be sure the decimal point is always displayed.
	int Chap03_Prob13(){
	
		// Create conversion constants. Most current conversions as of 08/30/2014.
		const float YEN_PER_DOLLAR = 104.08, EUROS_PER_DOLLAR = 0.76;
	
		// Create currency variables.
		float dollars, euroConvert, yenConvert;
	
		// Get input from user.
		cout << "Please enter a U.S Dollar amount to convert into Euros and Japanese Yen: $";
		cin >> dollars;
		
		// Calculate conversion.
		euroConvert = dollars * EUROS_PER_DOLLAR;
		yenConvert = dollars * YEN_PER_DOLLAR;
		
		// Set precision and show decimal point.
		cout << setprecision(2) << fixed << showpoint;
		
		// Display results.
		cout << endl << "$" << dollars << " is " << euroConvert << " Euros and " << yenConvert << " Japanese Yen.";
		
		return 0;	
	}