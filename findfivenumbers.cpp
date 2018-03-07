/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/28/2018
 Title:Find 5 biggest numbers smaller than X
 Description:The program gets user's input (int) for X and n (size of an array), then it takes
            a sorted array, doesnt accept unsorted array or duplicate numbers. Using Binary Search
            we find and print 5 (or less) biggest numbers that are smaller than X.
 ***************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
void storetoArr(int n, vector<int> & arr);
void findX(vector<int> & arr, int &n, int &x);
void printFiveLeft(vector<int>& arr, int index);

int main(){
    
    int x,n;
    
    cout <<"\nEnter a number X: ";
    cin >> x;
    
    cout <<"\nEnter the size of your array: ";
    cin >> n;
    
    vector<int> arr;
    
    storetoArr(n, arr);
    findX(arr, n, x);
    return 0;
}

void storetoArr(int n, vector<int> & arr ){
    int numbers;
    cout <<"\nEnter the numbers of your array (sorted): \n";
    
    for (int i=0; i<n; i++){
        cin >> numbers;
        if (!(cin)){      //check for int input, dont accept anything but numbers
            cout <<"\nInvalid Input\n";
            cin.clear();
            cin.ignore();
            i--;
        }
        if (i > 0 && numbers <= arr[i-1]){    //only accept sorted array with unique numbers
            cout <<"\nEnter unique numbers in increasing order "<<endl;
            i--;
        }
        else{
            arr.push_back(numbers);
        }
        
    }
    
}

void findX(vector<int> & arr, int &n, int &x){
    int l=0;
    int h=n-1;
    int mid;
    while (l <= h){
        mid = (l+h)/2;
        if (arr[n-1] < x){             //check if x exists in array
            printFiveLeft(arr, h);
            break;
        }
        if (arr[0] >= x){             //check if x exists in array
            cout <<"There are no numbers smaller than "<<x <<endl;
            break;
        }
        if (arr[mid] == x){          //check if our midle index equals x
            printFiveLeft(arr, mid-1);
            break;
        }
        else if (arr[mid] < x && arr[mid+1] > x){     //check if our middle is the biggest number smaller than X
            printFiveLeft(arr, mid);
            break;
        }
        else if (arr[mid] > x && arr[mid-1] < x){     //check if the number to the left of middle is the biggest
            printFiveLeft(arr, mid-1);                // number smaller than X
            break;
        }
        else if (arr[mid] < x){
            l = mid+1;
        }
        else if (arr[mid] > x){
            h = mid-1;
        }
    }
}

void printFiveLeft( vector<int>& arr, int index ){
    int q = index-4;      //hold the index value to print numbers from smallest to biggest
    while (q < 0){        //if there are less than 5 numbers smaller than x
        q++;             // increment the starting index to the first element in the array arr[o]
    }
    cout <<endl;
    for (int i=q; i<=index; i++){
        if (i == index)
            cout << arr[i];
        else
            cout << arr[i] <<", ";
    }
    cout <<endl;
}

