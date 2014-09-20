/* 
 * Author: 	James Leduc
 * Created: Sep 18, 2014
 * Purpose: Modes
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int *fillArray(int,int);
void printArray(int *,int,int);
int *sort(int *,int);
float avg(int *,int);
float median(int *,int);
int *mode(int *,int);

//Execution begins here
int main(int argc, char** argv) {

    //Create the array
    int size;
	cin >> "Enter a size: " >> size;
	
	cout << endl;
	
	int range;
	cin >> "Enter a max value: " >> range;
	range++;
	
    int *a = fillArray(size,range);
	
    // Sort the array
    int *b = sort(a,size);
	
	// Calculate and show the average
	float c = avg(b,size);
	cout << endl << "The average is " << c << endl;

	// Calculate and show the median
	float d = median(b,size);
	cout << endl << "The median is " << d << endl;
	
    // Show the result
	int pLine = range*2;
    printArray(a,size,pLine);
    printArray(b,size,pLine);

	// Calculate the modes
	int modes = *mode(*b,size);
	
    // Deallocate memory and exit
    delete []a;
    delete []b;
	delete []modes;
    return 0;
}

// Function Definitions

int *sort(int *a,int n){

    //Allocate a sortable array
    int *b=new int[n];
	
    //Copy the array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
	
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    return b;
}

void printArray(int *a,int n,int perLine){
    cout << endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout << endl;
}

int *fillArray(int n,int mod){

    //Allocate memory
    int *array=new int[n];
	
    //Initialize with 
    for(int i=0;i<n;i++){
        array[i]=i%mod;
    }
    return array;
}

float avg(int *b,int n){
	float val=0;
	for(int i=0;i<n;i++){
		val+=b[i];
	}
	val/=n;
	return val;
}

float median(int *b,int n){
	float val=0;
	float mid=((static_cast<float>(n) + 1) / 2) - 1;
	int intMid=mid;
	if(mid==intMid){
		val=static_cast<float>(b[intMid]);
	}else{
		val=((static_cast<float>(b[intMid]))+(static_cast<float>(b[intMid+1])))/2;
	}
	return val;
}

int *mode(int *b,int n){
	int modal[];
	int modeComp = 0,		// Mode Compare variable
		modeChk = 0, 		// Mode Check variable
		modeCnt = 0,		// Mode Count variable
		modeFreq = 0,		// Incremented by modeChk
		modeVal = 0,		// Mode number value
		modeSize = 0;		//
	bool isMode = false;	// Mode Flag
	
	
	for(int i=1;i<n;i++){
	
		modeComp = b[i-1] - b[i];		// Compare elements in array.
		
		if(modeComp == 0){modeChk++;}	// If the values are the same, increment the modeChk.
		else{modeChk=0;}				// If the values are different, modeChk resets.
		
		if(modeChk >= 2){isMode=true;}	// A mode must have at least 2 or more of the same value.
		else{isMode=false;}				// If not, they're not modes.

		if(isMode == true){
			modeFreq = modeChk;
		}else if(isMode == false && modeNum >= 2){
			modeVal = b[i-1];
			modeCnt++;
		}
		
		modal[1] = modeCnt;
		modal[2] = modeFreq;
		modal[3] = modeVal;
		
		
	}
	
	//output {num of modes, mode frequency, modes values}

}
