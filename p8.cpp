//Program to find out maximum and minimum using divide and conquer rule.

#include<iostream>
#include <climits>
using namespace std;

// Structure to hold maximum and minimum elements
struct MinMax {
    int min;
    int max;
};

// Function to find maximum and minimum using divide and conquer
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, leftResult, rightResult;
    int mid;

    // If there is only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.min = arr[high];
            result.max = arr[low];
        } else {
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;
    }

    // If there are more than two elements, divide the array into two halves
    mid = (low + high) / 2;
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    // Compare maximums of two parts
    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}

/*
        The time complexity of the algorithm to find the minimum and maximum elements in an array using divide and conquer is O(n), 
        where n is the number of elements in the array.
*/