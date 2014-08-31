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
		<< "Enter 0 to end the program." << endl << endl
		<< "312: Celsius to Fahrenheit" << endl
		<< "313: Currency" << endl
		<< "410: Days in a Month" << endl
		<< "511: Population" << endl
		<< "607: Celsius Temperature Table" << endl
		<< "706: Rain or Shine" << endl
		<< "807: Binary String Search" << endl << endl
		<< "Your choice: " << endl << endl;
		
	cin >> choice;
	
	switch(choice){
		case 312: convertCelsius();
			break;
		case 313: convertCurrency();
			break;
		case 410: determineDays();
			break;
		case 511: 
			break;
		case 607:
			break;
		case 706: 
			break;
		case 807:
			break;
		case 0: exit(0);
			break;
		default: cout << "Invalid! Please choose from the available choices!";
	}

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
		
		system("pause");
		system("cls"); // or 'clear'
		
		return 0; // May need to remove in 'void' function.
	}

// Chap03_Prob13: Currency
	// Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
	// storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
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
			
		// Add pause & clear.
		
		return 0; // May need to remove in 'void' function.
	}
	
// Chap04_Prob10: Days in a Month
	// Write a program that asks the user to enter the month (letting the user enter an integer
	// in the range of 1 through 12) and the year. The program should then display the number of
	// days in that month.
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
				
		// Determine days in month.
		switch(month){
			case 1: days = 31; // January
				break;
			case 2: // February
				// Calculate leap year. Note: may need to adjust for years 1-3.
				if(year % 4.0 = 0.0){
					days = 29; // Leap year.
				}else{
					days = 28; // Normal year.
				}
				break;
			case 3: days = 31; // March
				break;
			case 4: days = 30; // April
				break;
			case 5: days = 31; // May
				break;
			case 6: days = 30; // June
				break;
			case 7: days = 31; // July
				break;
			case 8: days = 31; // August
				break;
			case 9: days = 30; // September
				break;
			case 10: days = 31; // October
				break;
			case 11: days = 30; // November
				break;
			case 12: days = 31; // December
				break;
		}
			
		// Display number of days in month.
		cout << endl << days << " days" << endl;
	
		// Add pause & clear.
	
		return 0: // May need to remove in 'void' function.
	}