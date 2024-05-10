//Program to implement Knapsack problem:

#include<iostream>
using namespace std;

#include <iostream>
#include <algorithm>

// Function to solve the knapsack problem
double knapsack(int capacity, int weight[], int profit[], int n) {
    double ratio[n + 1][capacity + 1];

    // Build table ratio[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                ratio[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                ratio[i][w] = max(profit[i - 1] + ratio[i - 1][w - weight[i - 1]], ratio[i - 1][w]);
            } else {
                ratio[i][w] = ratio[i - 1][w];
            }
        }
    }

    return ratio[n][capacity];
}

int main() {
    int profit[] = {12, 10, 20, 15};
    int weight[] = {2, 3, 1, 4};
    int capacity = 15;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << "Maximum profit is: " << knapsack(capacity, weight, profit, n) << endl;

    return 0;
}
