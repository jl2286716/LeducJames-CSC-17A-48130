/*
	Programmer: James Leduc
	Program Name: Gaddis_8thEd_Assignment01
	Date Created: 08/30/2014
	Date Modified: 08/31/2014
	Purpose: A menu driven program to run scripts from chapters 3-8 in
		"Starting Out With C++: From Control Structures Through Objects" by Tony Gaddis, 8th Edition:
		3.12 (pg144), 3.13 (pg144), 4.10 (pg221), 5.11 (pg295), 6.7 (pg368), 7.6 (pg449), 8.7 (pg493)
		Two problems from chapters 5 through 8 should include flowcharts.
*/

// Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
void showMenu();
void convertCelsius();
void convertCurrency();
void determineDays();
void pedictPopInc();
void createTempTable();
	float celsius(float);
void displayWeather();
void searchStrings();
	string binarySearch(const string, int, string);
	void sortArray(int [], int);

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
			case 706: displayWeather();
				break;
			case 807: searchStrings();
				break;
			default: cout << "Invalid! Please choose from the available choices!";
		}

	}while(choice != 0);
	
	cout << endl << "Good bye!";
	
	return 0;
}

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
		fahr = ((9.0 / 5.0) * celc) + 32.0;
		
		// Set precision and show decimal point.
		// Uses <iomanip>
		cout << setprecision(2) << fixed << showpoint;
		
		// Display results.
		cout << endl << celc << " degrees Celsius equals " 
			 << fahr << " degrees Fahrenheit." << endl;
		
		system("pause");
		system("cls");
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
		// Uses <iomanip>
		cout << setprecision(2) << fixed << showpoint;
		
		// Display results.
		cout << endl << "$" << dollars << " (USD) is equal to " << euroConvert
			<< " Euros (EUR) and " << yenConvert << " Japanese Yen (JPY)." << endl;
			
		system("pause");
		system("cls");
	}
	
// 4.10: Days in a Month
	// Write a program that asks the user to enter the month (letting the user enter an integer
	// in the range of 1 through 12) and the year. The program should then display the number of
	// days in that month.
	void determineDays(){
			
		// Create variables.
		int month, year, days;
		float leap;
		
		cout << "This program shows the number of days in a given month of a given year." << endl;
		
		// Get and validate month.
		do{
			// Get month from user.
			cout << "Enter a month (1-12): ";
			cin >> month;
			
			// Prompt user to enter valid data.
			if(month < 1 || month > 12){
				cout << "Please enter a valid month (1-12)!" << endl;
			}
			
		}while(month < 1 || month > 12);
		
		//Get and validate year.
		do{
			// Get year from user.
			cout << endl << "Enter a year: ";
			cin >> year;
			
			// Prompt user to enter valid data.
			if(year < 0 || year > 9999){
				cout << "Please enter a valid year (0-9999)!" << endl;
			}
			
		}while(year < 0 || year > 9999);
				
		// Determine days in month.
		switch(month){
			case 1: days = 31; 	// January
				break;
			case 2: 			// February
				// Calculate leap year. Note: may need to adjust for years 1-3.
				leap = year % 4;
				if(leap == 0){
					days = 29; 	// Leap year.
				}else{
					days = 28; 	// Normal year.
				}
				break;
			case 3: days = 31; 	// March
				break;
			case 4: days = 30; 	// April
				break;
			case 5: days = 31; 	// May
				break;
			case 6: days = 30; 	// June
				break;
			case 7: days = 31; 	// July
				break;
			case 8: days = 31; 	// August
				break;
			case 9: days = 30; 	// September
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
	
		system("pause");
		system("cls");
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
		int startingNum, 		// Starting number of organisms. 2 and above.
			population; 		// Predicted population increase.
		float dailyIncrease, 	// Average daily population increase. Positive numbers only.
			numOfDays; 			// Number of days they will multiply. 1 and above.
			
		cout << "This program calculates a projected population growth." << endl << endl;
		
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
			
		population = startingNum; // Initialize the population.
			
		// Calculate population increase.
		for(int i = 0; i < numOfDays; i++){
			population *= (dailyIncrease/100);
		}
		
		cout << endl << "If a population of " << startingNum << " organisms increases at a rate of "
			 << dailyIncrease << "% over " << numOfDays << " day(s),"
			 << endl << "the resulting population will be "
			 << population << " organisms." << endl << endl;
		
		system("pause");
		system("cls");
	}

// 6.7: Celsius Temperature Table
	// The formula for converting a temperature from Fahrenheit to Celsius is
		// C = (5 / 9) * (F - 32)
		// F = degrees Fahrenheit & C = degrees Celsius
	// Write a function named celsius that accepts a Fahrenheit temperature as an argument.
	// The function should return the temperature, converted to Celsius. Demonstrate the function
	// by calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
	// and their Celsius equivalents.
	void createTempTable(){
		// Create variables.
		float celsTemp, 	// Degrees Celsius.
			fahrTemp = 0; 	// Degrees Fahrenheit initialized to 0.
			
		cout << "This program displays Fahrenheit temperatures from" << endl
			 << "0 through 20 and their Celsius equivalents." << endl << endl;
		
		for(fahrTemp; fahrTemp <= 20; fahrTemp++){
		
			celsTemp = celsius(fahrTemp);
			
			// Set precision.
			// Uses <iomanip>
			cout << setprecision(2) << fixed << showpoint;
			
			// Display results.
			cout << fahrTemp << "F = " << celsTemp << "C" << endl;
		}
		
		system("pause");
		system("cls");
	}
	
	// Converts Fahrenheit to Celsius. Passes 'fahrTemp' as 'f' and returns 'c' for 'celcTemp'.
	float celsius(float f){
		float c; //Variable for degrees Celsius.
		
		c = (5.0 / 9.0) * (f - 32.0);
	
		return c;
	}
	
// 7.6: Rain or Shine
	// An amateur meteorologist wants to keep track of weather conditions during the past year's
	// three-month summer season and has designated each day as either rainy ('R'), cloudy ('C'),
	// or sunny ('S'). Write a program that stores this information in a 3 x 30 array of characters,
	// where the row indicates the month (0 = June, 1 = July, 2 = August) and the column indicates
	// the day of the month. Note that data are not being collected for the 31st of any month.
	// The program should begin by reading the weather data in from a file. Then it should create a
	// report that displays, for each month and for the whole three-month period, how many days were
	// rainy, how many were cloudy, and how many were sunny. It should also report which of the three
	// months had the largest number of rainy days. Data for the program can be found in the
	// RainOrShine.txt file.
	// Uses <fstream>
	void displayWeather(){
	
		const int ROWS = 3, COLS = 30; 	// Initialize array size.
		char arr[ROWS][COLS]; 			// Create and initialize array.
		ifstream inFile; 				// Input file stream object.
		int rInCount,					// Array row index counter.
			cInCount,					// Array column index counter.
			junR = 0,					// June rainy day counter/totals.
			julR = 0,					// July rainy day counter/totals.
			augR = 0,					// August rainy day counter/totals.
			junC = 0,					// June cloudy day counter/totals.
			julC = 0,					// July cloudy day counter/totals.
			augC = 0,					// August cloudy day counter/totals.
			junS = 0,					// June sunny day counter/totals.
			julS = 0,					// July sunny day counter/totals.
			augS = 0;					// August sunny day counter/totals.

	
		cout << "This program will now read in the weather conditions from a text file" << endl
			 << "for the Summer months in 30 day increments and display them on screen." << endl
			 << "It will also display the months with the most rainy, cloudy, and sunny days." << endl
			 << "0 = June, 1 = July, 2 = August" << endl
			 << "R = rainy, C = cloudy, S = sunny" << endl << endl;
			 
		// Open RainOrShine.txt file.
		inFile.open("RainOrShine.txt", ios::in);
		
		if(inFile.fail()){
			cout << "File opening failed!";
		}

		for(int i = 0; i < ROWS; i++)
		{
			for(int j = 0; j < COLS; j++)
			{
				inFile >> arr[i][j];
			}
		}
	 
		// Close RainOrShine.txt file.
		inFile.close();

		cout << endl;
		
		// Display array with row headers.
		for(int r = 0; r < ROWS; r++){
			cout << r;
			for(int c = 0; c < COLS; c++){
				cout << arr[r][c];
			}
			cout << endl;
		}
		
		// Search array for how many times 'R' appears on each row.
		for(rInCount = 0; rInCount < ROWS; rInCount++){
			for(cInCount = 0; cInCount < COLS; cInCount++){
				if(arr[rInCount][cInCount] == 'R'){
					if(rInCount == 0){
						junR++;
					}else if(rInCount == 1){
						julR++;
					}else if(rInCount == 2){
						augR++;
					}
				}
			}
		}
		
		// Search array for how many times 'C' appears on each row.
		for(rInCount = 0; rInCount < ROWS; rInCount++){
			for(cInCount = 0; cInCount < COLS; cInCount++){
				if(arr[rInCount][cInCount] == 'C'){
					if(rInCount == 0){
						junC++;
					}else if(rInCount == 1){
						julC++;
					}else if(rInCount == 2){
						augC++;
					}
				}
			}
		}

		// Search array for how many times 'S' appears on each row.
		for(rInCount = 0; rInCount < ROWS; rInCount++){
			for(cInCount = 0; cInCount < COLS; cInCount++){
				if(arr[rInCount][cInCount] == 'S'){
					if(rInCount == 0){
						junS++;
					}else if(rInCount == 1){
						julS++;
					}else if(rInCount == 2){
						augS++;
					}
				}
			}
		}

		// Compare and display which month had the most rainy days (the most 'R's).
		if(junR > julR && junR > augR){
			cout << endl << "June had the most rainy days this summer: " << junR << " rainy days." << endl;
		}else if(julR > augR){
			cout << endl << "July had the most rainy days this summer: " << julR << " rainy days." << endl;
		}else{
			cout << endl << "August had the most rainy days this summer: " << augR << " rainy days." << endl;
		}
			
		// Compare and display which month had the most cloudy days (the most 'C's).
		if(junC > julC && junC > augC){
			cout << endl << "June had the most cloudy days this summer: " << junC << " cloudy days." << endl;
		}else if(julC > augC){
			cout << endl << "July had the most cloudy days this summer: " << julC << " cloudy days." << endl;
		}else{
			cout << endl << "August had the most cloudy days this summer: " << augC << " cloudy days." << endl;
		}

		// Compare and display which month had the most sunny days (the most 'S's).
		if(junS > julS && junS > augS){
			cout << endl << "June had the most sunny days this summer: " << junS << " sunny days." << endl;
		}else if(julS > augS){
			cout << endl << "July had the most sunny days this summer: " << julS << " sunny days." << endl;
		}else{
			cout << endl << "August had the most sunny days this summer: " << augS << " sunny days." << endl;
		}

		system("pause");
		system("cls");
	}
	
// 8.7: Binary String Search
	// Modify the 'binarySearch' function presented in chapter 8 so it searches an array of strings
	// instead of an array on ints. Test the function with a driver program. Use Program 8-8 as a
	// skeleton to complete. (The array must be sorted before the binary search will work.)
	void searchStrings(){
		const int NUM_NAMES = 20;
		string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
									"Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
									"Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
									"Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee",
									"Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
									
		// Insert your code
		
		cout << endl << "I have no idea what I'm supposed to do with this..." << endl << endl;
		
		system("pause");
		system("cls");
	}

	// The Binary Search Function
	string binarySearch(const string array, int numElems, string value){
		int first = 0,				// First array element.
			last = numElems - 1,	// Last array element.
			middle,					// Midpoint of search.
			position = -1;			// Position of search value.
		bool found = false;			// Flag.

		while (!found && first <= last){
			middle = (first + last) / 2;		// Calculate midpoint.
			if (array[middle] == value){		// If value is found at mid.
				found = true;
				position = middle;
			}else if (array[middle] > value){	// If value is in lower half.
				last = middle - 1;
			}else{
				first = middle + 1;				// If value is in upper half.
			}
		}
		return position;
	}

	// The Bubble Sort Function
	void sortArray(int array[], int size){
		bool swap;
		int temp;

		do{
			swap = false;
			for (int count = 0; count < (size - 1); count++){
				if (array[count] > array[count + 1]){
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					swap = true;
				}
			}
		}while (swap);
	}