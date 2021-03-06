/* 
 * Author: 		James Leduc
 * Created:		Sep 18, 2014
 * Modified:	Sep 25, 2014
 * Purpose:		Average, Median, Mode
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
void printMode(int *);

//Execution begins here
int main() {

    //Create the array
    int size;
	cout << "Enter a size: ";
	cin >> size;
	
	cout << endl;
	
	int range;
	cout << "Enter a max value: ";
	cin >> range;
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
	
    // Show test results
	//int pLine = range*2;
    //printArray(a,size,pLine);
    //printArray(b,size,pLine);


	cout << endl << "I can't get the modes to work!\n";

	// Calculate the modes
	int *modes = mode(b,size);
	
	// Show the modes
	printMode(modes);
	
    // Deallocate memory and exit
    delete []a;
    delete []b;
	//delete []modes;
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
	// Determine max frequency
	int count=0,
		freq=0;
	for(int i=1;i<n;i++){
		if(b[i]==b[i-1]){
			count++;
			if(freq<count){
				freq=count;
			}
		}else{
			count=0;
		}
	}
	cout << "The maximum frequency is = " << freq+1 << endl;
	system("pause");

	// Count modes
	int modeNum=0;
		count=0;
	for(int j=1;j<n;j++){
		if(b[j]==b[j-1]){
			count++;
			if(freq==count){
				modeNum++;
			}
		}else{
			count=0;
		}
	}
	cout << "There are " << modeNum << " modes." << endl;
	system("pause");

	// Declare and fill mode array - THIS IS WHERE IT BREAKS!!
	int *modal=new int[modeNum+2];
	modal[0]=modeNum;
	modal[1]=freq+1;
	modeNum=2;
	count=0;
	for(int k=1;k<n;k++){
		if(b[k]==b[k-1]){
			count++;
			if(freq==count){
				modal[modeNum++]=b[k];
			}
		}else{
			count=0;
		}
	}
	return modal;
}

void printMode(int *m){
	// Print the modal array
	if(m[0]==0){
		cout << "The mode set is {0}" << endl;
	}else{
		cout << "The mode set is {";
		for(int i=2;1<m[0]+2;i++){
			cout << "}" << endl;
		}
	}
}