/*
	Programmer: James Leduc
	Program Name: Mode Investigation
	Date Created: 09/14/2014
	Date Modified: 09/13=4/2014
	Purpose: A program to investigate modes.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
//#include <string>
using namespace std;

int main(){	// A mode is a value that occurs the most within a set.
	// Initialize array and create variables.
	const int SIZE = 20, ROWS = 2;
	int numArr[SIZE];
	int compArr[ROWS][SIZE];
	int num,		// Random number from 1 - 10.
		arrVal,		// Value stored in array.
		valComp,	// Comparison value.
		count = 0;	// Instance counter.

	// Fill the array with random number.
	for(int i = 0; i < SIZE; i++){
		num = rand() * 10 + 1;	// Generate random a number from 1 to 10.
		numArr[i] = num;		// Place that random number into the array.
	}
	
	// Compare values and their iterations and place them into compArr array.
	for(int j = 0; j < SIZE; j++){
		arrVal = numArr[j];				// Pull a value to compare.
		for(int k = 0; k < SIZE; k++){
			valComp = numArr[k];		// Pull another value to compare.
			if(arrVal == valComp){
				count++;				// If both values are the same, the counter increases.
			}
		}
		compArr[0][j] = arrVal;
		compArr[1][j] = count;
	}
	
	// Write code that compares iterations and outputs the most prominent value.

	return 0;
}
