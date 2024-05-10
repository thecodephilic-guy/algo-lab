// To search an element using linear search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index: " << result;
    return 0;
}

/*
    Time Complexity: 
        The best-case complexity is O(1) if the element is found in the first iteration of the loop.
         
        The worst-case time complexity is O(n), if the search element is found at the end of the array, provided 
            the size of the array is n. 
*/