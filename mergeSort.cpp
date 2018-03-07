/***************************************************************************************
 Name:Enis Tahiraj
 Date:03/02/2018
 Title: Merge Sort
 Description:Demonstration of merge sort
 ***************************************************************************************/
#include <iostream>
using namespace std;
void merge(int Array[], int low, int high, int mid);
void mergesort(int Array[], int low, int high);
int main(){
    
    int arraySize = 16;
    int Array[] = {100,50,60,40,70,30,80,20,90,55,85,75,65,45,25,35};
    
    int low = 0;
    int high = arraySize-1;
    mergesort(Array, low, high);
    
    for (int i=0; i<arraySize; i++){
        cout <<Array[i] <<" ";
    }
    
    return 0;
}

void mergesort(int Array[], int low, int high){
    
    if (low < high){
        int mid;
        mid = (low + high)/2;
        mergesort(Array, low, mid);
        mergesort(Array, mid+1, high);
        merge(Array, low, high, mid);
    }
    return;
}
void merge(int Array[], int low, int high, int mid){
    
    int i, j, k, c[16];
    
    i=low;
    k=low;
    j=mid+1;
    
    while (i<=mid && j<=high){
        if (Array[i] < Array[j]){
            c[k] = Array[i];
            i++;
        }
        else{
            c[k] = Array[j];
            j++;
        }
        k++;
    }
    while (i<=mid){
        c[k] = Array[i];
        i++;
        k++;
    }
    while (j<=high){
        c[k] = Array[j];
        j++;
        k++;
    }
    for (i=low; i<k; i++){
        Array[i] = c[i];
    }
    
}
