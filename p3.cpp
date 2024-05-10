// Program to Sort an array using Bubbl-Sort algorithm.

#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    bool swapped;   //flag for optimization 
    for(int i = 0; i<n-1; i++){
        swapped = false;

        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                //swap:
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        //after first pass if swapped remains false means array is already sorted then no need to check further:
        if(!swapped){
            break;
        }
    }
}

//driver code:
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //sorting the array:
    bubbleSort(arr, n);

    cout<<"Sorted Array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

/*
        Time complexities: -
            Best Case Complexity - It occurs when there is no sorting required, i.e. the array is already 
                sorted. The best-case time complexity of bubble sort is O(n). 

            Average Case Complexity - It occurs when the array elements are in jumbled order that is not 
                properly ascending and not properly descending. The average case time complexity of bubble 
                sort is O(n2). 
                
            Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse 
                order. That means suppose you have to sort the array elements in ascending order, but its 
                elements are in descending order. The worst-case time complexity of bubble sort is O(n2). 
*/