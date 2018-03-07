/***************************************************************************************
 Name:Enis Tahiraj
 Date:03/03/2018
 Title:Knapsack
 Description: Finds the maximum value with a given weight W=5
 ***************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
int max(int a, int b);
int knapSack(int W, int w[], int v[], int n );

int main(){

int w[] = {1, 2, 1, 2, 3};
int v[] = {5, 8, 3, 7, 10};
int W = 5;
int n = 5;
int maxVal = knapSack(W, w, v, n);
cout <<"\nMax Value is: " << maxVal <<endl; 

	return 0;
}


int max(int a, int b){
	return (a > b)? a : b;
}

int knapSack(int W, int w[], int v[], int n ){

	int B[n+1][W+1];

	for (int i=0; i<=n; i++){
		B[i][0] = 0;
	}
	for (int k=0; k<=W; k++){
		B[0][k] = 0;
	}
	for (int i=1; i<=n; i++){
		for (int k=1; k<=W; k++){
			if (w[i-1] <= k){
				B[i][k] = max(v[i-1]+B[i-1][k-w[i-1]], B[i-1][k]);
			}
			else {
				B[i][k] = B[i-1][k];
			}
		}
	}
	//reconstructing
	int i=n, k=W;
	vector <int> pickItems;
	while (i > 0 && k > 0){
		if (B[i][k] != B[i-1][k]){
			pickItems.push_back(i);
			i--;
			k = k-w[i];
		}
		else{
			i--;
		}
	}
		cout <<"\nThe picked items are: ";
		for (int p=pickItems.size()-1; p>=0; p--){
		cout << pickItems[p] <<", ";
	}
	return B[n][W];
}
