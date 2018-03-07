/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/27/2018
 Title:Binary Search
 Description:Search for number 100 using binary search
 ***************************************************************************************/
#include <iostream>
using namespace std;
int binarySearch(int Array[], int X, int arraySize);


int main(){
	
int arraySize = 16;
int Array[] = {20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95};
int X = 100;
int p = binarySearch(Array, X, arraySize);
	if (p != X){
		cout <<"\nX doesn't exist in the array\n";
	}
	else
		cout <<p;

	return 0;
}


int binarySearch(int Array[], int X, int arraySize){

	int l=0;
	int r = arraySize;
	int mid;

	while (l < r){
		mid = (l+r)/2;
		if (Array[mid] == X){
			return Array[mid];
		}
		else if (Array[mid] < X){
			l = mid+1;
		}
		else if (Array[mid] > X){
			r = mid-1;
		}
		
	}
return 0;
}
