//Program to implement Quick-sort:

#include<iostream>
using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the pivot element (can be any element, here we choose the last element)
    int i = low - 1; // Index of the smaller element

    // Partitioning loop
    for (int j = low; j < high; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            ++i; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Swap arr[i+1] and arr[high] (or pivot)
    return i + 1; // Return the partitioning index
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/*
    Time complexities: -Quick sort has an average time of O(n log n) on n elements. Its worst case time 
                        is O(n²) 
*/
