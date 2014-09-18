

#include <cstdlib>
#include <iostream>

using namespace std;

//prototypes
int *fillArray(int, int);
void printArray(int *, int, int);
int *sort(int *, int);

int main(){

	return 0;
}

int *sort(int *a, int n){
	int *b=new int[n];
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+
	}
}

void printArray (int *a, int n, int parLine){
	for(int 1=0;i<n;i++){
		cout<<a[i]<<" ";
		if(i%perLine==(perLine-1))cout<<endl;
	}
}

int *fillArray(int n, int mod){
	//allocate memory
	int *array= new int[n];
	
	//initialize with 
	for(int i=0;i<n;i++){
		array[i]=i%mod;
	}
	return array
}