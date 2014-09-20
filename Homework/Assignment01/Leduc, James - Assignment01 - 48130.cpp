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
int *mode(int *,int, int);

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
	int modes = *mode(*b,size,range);
	
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

int *mode(int *b,int n, int r){
	
	// Declare, allocate, and clean arrays.
	int arrSize = (n / r) + 2;
	int modalSrch[n][2];
	int modalFix[arrSize][2];
	int modal[arrSize];
	for(int j=0;j<arrSize;j++){
		modal[j]=NULL;
		modalFix[j][0]=NULL;
		modalFix[j][1]=NULL;
	}
	
	int modeComp = 0,		// Mode Compare variable
		modeChk = 1, 		// Mode Check variable
		modeCnt = 0,		// Mode Count variable
		modeFreq = 0,		// Incremented by modeChk
		modeVal = 0,		// Mode number value
		modeMax = 0;		//
	bool isMode = false;	// Mode Flag
		
	// Create the modalSrch array, which stores values and their frequencies.
	for(int i=1;i<=n;i++){
		
		modalSrch[i-1][0] = b[i-1];
		modalSrch[i-1][1] = modeChk;
		
		modeComp = b[i-1] - b[i];	// Compare elements in array.
		
		if(modeComp == 0){
			modeChk++;		// If the values are the same, increment the modeChk.
		}else{
			modeChk=1;		// If the values are different, modeChk resets.
		}
	}	
	
	// Count the modes, their frequencies, and place the values into modal array
	for(int m=1;m<=n;m++){
		if(modalSrch[m-1][1] > modalSrch[m][1] && modalSrch[m-1][1] > modeFreq){
			modeFreq = modalSrch[m-1][1];
			modeCnt = 1;
			modal[1] = modeCnt;
			modal[2] = modeFreq;
		}else if(modalSrch[m-1][1] > modalSrch[m][1] && modalSrch[m-1][1] == modeFreq){
			modeCnt++;
			modal[1] = modeCnt;
			modal[2] = modeFreq;
		}
	}
		
/*	for(int k=0;k<n;k++){
		if(modalSrch[k+1][1] - modalSrch[k][1] < 0){
			modeVal = modalSrch[k][0];
			modeFreq = modalSrch[k][1];
		}
	}
		
		if(modeChk >= 2){
			isMode=true;	// A mode must have at least 2 or more of the same value.
		}else{
			isMode=false;	// If not, they're not modes.
		}
		
		
		if(isMode == true){
			modeFreq = modeChk;
			if(modeFreq > modal[2]){
				modal[2] = modeFreq;
				modeCnt = 1;
			}
		}else if(isMode == false && modeFreq >= 2){
			modeVal = b[i-1];
			modeCnt++;
			
			int k = 3;
			modal[1] = modeCnt;
			modal[2] = modeFreq;
			modal[k] = modeVal;
			k++;
		}
	*/	
		
	
	
	//output {num of modes, mode frequency, modes values}
	return modal;
}
