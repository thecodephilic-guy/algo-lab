//Program to find the given element using Binary Search:

#include<iostream>
using namespace std;

int binarySearch(int arr[], int x, int low, int high){

    if(high >= low){
        int mid = low + (high-low)/2;   //calculating the middle of array

        //base case
        if(arr[mid] == x){
            return mid;         //element found!
        }

        if(x < arr[mid]){
            return binarySearch(arr, x, low, mid-1);
        }

        if(x > arr[mid]){
            return binarySearch(arr, x, mid+1, high);
        }
    }
    return -1;

}
int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(int); //size of array

    //function call:
    int result = binarySearch(arr, x, 0, n-1);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index: " << result;
    return 0;
}

/*
    Time complexities: -For Searching the element the worst case time complexity is O(n) 
                        and average case is O(log n). 

*/