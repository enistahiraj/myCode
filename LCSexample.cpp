/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/28/2018
 Title:Longest Common Secuence
 Description: The program finds the LCS of two given binary numbers.
 ***************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b);
int lcs(int x, int X[], int Y[], int y);
int main() {
    int x= 8;
    int y= 9;
        int X[] = {1,0,0,1,0,1,0,1};
        int Y[] = {0,1,0,1,1,0,1,1,0};
        int p = lcs(x, X, Y, y);
        cout <<"\nThe LCS of X and Y is: "<<p<<endl;

        return 0;
}
//function to return the max value of two given numbers
int max(int a, int b){
    return (a>b)? a : b;
}
//function to find the lcs
int lcs(int x, int X[], int Y[], int y){
    int i, j;
    int B[x+1][y+1];      //declaring the array
    for (i=0; i<=x; i++){    //set the base case for i
        B[i][0] = 0;
	}
    for (j=0; j<=y; j++){    //set the base case for j
        B[0][j] = 0;
	}
    for (i=1; i<=x; i++){
        for (j=1; j<=y; j++){
			if (X[i-1] == Y[j-1]){
		   	 B[i][j] = max(B[i-1][j-1]+1,B[i-1][j]);
			} 
			else{
		   	 B[i][j] = max(B[i][j-1],B[i-1][j]);
				}
		}

 	}

 	    //reconstructing  
	    i=x;
	    int k=y;  
	    vector <int> pickItems;  
	    while (i > 0 && k > 0){  
        	if (B[i][k] != B[i-1][k]){  
          	 pickItems.push_back(X[i]);  
          	 i--;  
          	 k--;  
      	 	}  
        	else{  
            i--;  
      		 }  
  		 }  
       cout <<"\nThe picked items are: ";  
       for (int p=pickItems.size()-1; p>=0; p--){  
       cout << pickItems[p] <<", ";  
		}

    return B[x][y];
}




