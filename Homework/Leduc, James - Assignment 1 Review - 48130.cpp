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
void showMenu();
void convertCelsius();
void convertCurrency();
void determineDays();
void pedictPopInc();
void createTempTable();
float celsius(float);

#incluse <iostream>
using namespace std;

int main(){

	int choice;
	
	cout << "Homework Assignment 1: Review (from Gaddis, 8th Edition)" << endl << endl;

	do{
		// Display menu of choices.
		showMenu();
		
		cin >> choice;
		cout << endl << endl;

		switch(choice){
			case 312: convertCelsius();
				break;
			case 313: convertCurrency();
				break;
			case 410: determineDays();
				break;
			case 511: pedictPopInc();
				break;
			case 607: createTempTable();
				break;
			case 706: 
				break;
			case 807:
				break;
			//case 0: exit(0);
				//break;
			default: cout << "Invalid! Please choose from the available choices!";
		}

	}while(choice != 0);
	
	return 0;
)

// Function Definitions

// Display menu of choices.
	void showMenu(){	
		cout << "Please choose from the list below" << endl
			 << "by entering the number on the left." << endl
			 << "Enter 0 to end the program." << endl << endl
			 << "312: Celsius to Fahrenheit" << endl
			 << "313: Currency" << endl
			 << "410: Days in a Month" << endl
			 << "511: Population" << endl
			 << "607: Celsius Temperature Table" << endl
			 << "706: Rain or Shine" << endl
			 << "807: Binary String Search" << endl << endl
			 << "Your choice: ";
	}


// 3.12: Celsius to Fahrenheit
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

// 3.13: Currency
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
		cout << endl << "$" << dollars << " (USD) is equal to " << euroConvert
			<< " Euros (EUR) and " << yenConvert << " Japanese Yen (JPY)." << endl;
			
		// Add pause & clear.
		
		return 0; // May need to remove in 'void' function.
	}
	
// 4.10: Days in a Month
	// Write a program that asks the user to enter the month (letting the user enter an integer
	// in the range of 1 through 12) and the year. The program should then display the number of
	// days in that month.
	void determineDays(){
			
		// Create variables.
		int month, year, days;
		
		cout << "This program shows the number of days in a given month of a given year." << endl;
		
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
	
// 5.11: Population
	// Write a program that will predict the size of a population of organisms.
	// The program should ask the user for the starting number of organisms, their average daily
	// population increase (as a percentage), and the number of days they will multiply.
	// A loop should display the size of the population for each day.
	// Input Validation:
		// Do not accept a number less than 2 for the starting size of the population.
		// Do not accept a negative number for average daily population increase.
		// Do not accept a number less than 1 for the number of days they will multiply.
	void pedictPopInc(){
		
		// Create variables.
		int startingNum, // Starting number of organisms. 2 and above.
			population; // Predicted population increase.
		float dailyIncrease, // Average daily population increase. Positive numbers only.
			numOfDays; // Number of days they will multiply. 1 and above.
			
		cout << "This program calculates a projected population growth." << endl;
		
		// Get and validate the beginning population number.
		do{
			cout << "Enter the beginning population number (must be an integer above 1): ";
			cin >> startingNum;
			
			if(startingNum < 2){
				cout << "Invalid input! Please enter an integer above 1!";
			}
			
		}while(startingNum < 2);
		
		// Get and validate the average daily increase.
		do{
			cout << endl << "Enter the average daily increase (positive percentage only): ";
			cin >> dailyIncrease;
			
			if(dailyIncrease <= 0){ // Test for decimal results.
				cout << "Invalid input! Please enter a positive percentage only!";
			}
			
		}while(dailyIncrease <= 0);
		
		// Get and validate the number of days the population will multiply.
		do{
			cout << endl << "Enter the number of days the population will multiply"
			<< endl << "(at least 1 day must elapse): ";
			cin >> numOfDays;
			
			if(numOfDays < 1){
				cout << "Invalid input! At least 1 day MUST elapse!";
			}
			
		}while(numOfDays < 1);
			
		//dailyIncrease /= 100; // Convert percentage to decimal
		population = startingNum; // Initialize the population.
			
		// Calculate population increase.
		for(int i = 0; i < numOfDays; i++){
			population *= (dailyIncrease/100);
		}
		
		//dailyIncrease *= 100; // Convert decimal back to percentage.
		
		cout << endl << "If a population of " << startingNum << " organisms increases at a rate of %"
			 << dailyIncrease << " over " << numOfDays << " day(s), the resulting population will be "
			 << population << " organisms.";
		
		// Add pause & clear.
	}

//6.7: Celsius Temperature Table
	// The formula for converting a temperature from Fahrenheit to Celsius is
		// C = (5 / 9) * (F - 32)
		// F = degrees Fahrenheit & C = degrees Celsius
	// Write a function named celsius that accepts a Fahrenheit temperature as an argument.
	// The function should return the temperature, converted to Celsius. Demonstrate the function
	// by calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
	// and their Celsius equivalents.
	void createTempTable(){
		// Create variables.
		float celcTemp, // Degrees Celsius.
			fahrTemp = 0; // Degrees Fahrenheit initialized to 0.
			
		cout << "This program displays Fahrenheit temperatures from" << endl
			 << "0 through 20 and their Celsius equivalents." << endl << endl;
		
		for(fahrTemp; fahrTemp <= 20; fahrTemp++){
		
			celcTemp = celsius(fahrTemp);
			
			// Set precision.
			cout << setprecision(2) << fixed << showpoint;
			
			// Display results.
			cout << fahrTemp << "F = " << celcTemp << "C" << endl;
		}
	}
	
	// Converts Fahrenheit to Celsius. Passes 'fahrTemp' as 'f' and returns 'c' for 'celcTemp'.
	float celsius(float f){
		float c; //Variable for degrees Celsius.
		
		c = (5 / 9) * (f - 32);
	
		return c;
	}
	
	
	
	
	
	
	
	