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
void convertCelsius();
void convertCurrency();
void determineDays();

#incluse <iostream>
using namespace std;

int main(){

	int choice;
	
	cout << "Please choose from the list below" << endl
		<< "by entering the problem number." << endl
		<< "Enter 0 to end the program." << endl
		<< "312: Celsius to Fahrenheit" << endl
		<< "313: Currency" << endl
		<< "410: Days in a Month" << endl
		<< "511: Population" << endl
		<< "607: Celsius Temperature Table" << endl
		<< "706: Rain or Shine" << endl
		<< "807: Binary String Search" << endl;

	return 0;
)

// Function Definitions

// Chap03_Prob12: Celsius to Fahrenheit
	// Write a program that converts Celsius temperatures to Fahrenheit temperatures.
	// The formula is: F = ((9 / 5) * C) + 32
	// F = degrees Fahrenheit & C = degrees Celsius.
	void convertCelsius(){
		
		// Create degree variables.
		float celc, fahr;
		
		// Get input from user.
		cout << "Please enter a degree in Celsius to convert it to Fahrenheit: ";
		cin >> celc;
		
		// Calculate degree conversion from Celsius to Fahrenheit.
		fahr = ((9 / 5) * celc) + 32;
		
		// Set precision and show decimal point.
		cout << setprecision(2) << fixed << showpoint;
		
		// Display results.
		cout << endl << celc << " degrees Celsius equals " 
			<< fahr << " degrees Fahrenheit." << endl;
		
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
	void convertCurrency(){
	
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
		cout << endl << "$" << dollars << " is equal to " << euroConvert
			<< " Euros and " << yenConvert << " Japanese Yen." << endl;
		
		return 0;	
	}
	
// Chap04_Prob10: Days in a Month
	// Write a program that asks the user to enter the month (letting the user enter an integer
	// in the range of 1 through 12) and the year. The program should then display the number of
	// days in that month. Use the following criteria to identify leap years:
		// 1. Determine whether the year is divisible by 100. If it is, then it is a leap year if
		// 	and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
		// 2. If the year is not divisible by 100, then it is a leap year if and only if it is
		// 	divisible by 4. For example, 2008 is a leap year but 2009 is not.
	// Here is a sample run of the program:
		// Enter a month (1-12): 2[Enter]
		// Enter a year: 2008[Enter]
		// 29 days
	void determineDays(){
			
		// Create variables.
		int month, year, days;
		
		// Get and validate month.
		do{
			// Get month from user.
			cout << "Enter a month (1-12): ";
			cin >> month;
			
			// Prompt user to enter valid data.
			if(month < 1 && > 12){
				cout << "Please enter a valid month (1-12)!" << endl;
			}
			
		}while(month < 1 && > 12);
		
		//Get and validate year.
		do{
			// Get year from user.
			cout << endl << "Enter a year: ";
			cin >> year;
			
			// Prompt user to enter valid data.
			if(year < 0 && > 9999){
				cout << "Please enter a valid year (0-9999)!" << endl;
			}
			
		}while(year < 0 && > 9999);
				
		// Calculate days in month.
		switch(month){
			case 1: // January
				days = 31;
				break;
			case 2: // February
				// Calculate leap year. Note: may have to adjust for years 1-3.
				if(year % 4.0 = 0.0){
					days = 29;
				}else{
					days = 28;
				}
				break;
			case 3: // March
				days = 31;
				break;
			case 4: // April
				days = 30;
				break;
			case 5: // May
				days = 31;
				break;
			case 6: // June
				days = 30;
				break;
			case 7: // July
				days = 31;
				break;
			case 8: // August
				days = 31;
				break;
			case 9: // September
				days = 30;
				break;
			case 10: // October
				days = 31;
				break;
			case 11: // November
				days = 30;
				break;
			case 12: // December
				days = 31;
				break;
		}
			
		// Display number of days in month.
		cout << endl << days << " days" << endl;
	
		return 0:
	}