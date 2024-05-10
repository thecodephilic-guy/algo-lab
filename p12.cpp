//Program to implement Kruskal's algorithm using greedy method:

#include<iostream>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to compare two edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Find operation of union-find
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union operation of union-find
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
int kruskalMST(Edge edges[], int V, int E) {
    Edge result[V - 1]; // This will store the resultant MST
    std::sort(edges, edges + E, compareEdges); // Sort all the edges based on their weights

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int i = 0; // An index variable to track the edges added to the result
    int e = 0; // An index variable to traverse the sorted edges
    int minCost = 0; // Variable to store the minimum cost

    // While MST is not yet formed and we haven't exhausted all edges
    while (i < V - 1 && e < E) {
        Edge next_edge = edges[e++]; // Pick the next edge with minimum weight

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not form a cycle, add it to the result and increment the index
        if (x != y) {
            result[i++] = next_edge;
            Union(subsets, x, y);
            minCost += next_edge.weight; // Add the weight of the current edge to the minimum cost
        }
    }

    // Print the MST
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (i = 0; i < V - 1; ++i) {
        std::cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << std::endl;
    }

    // Deallocate memory for subsets
    delete[] subsets;

    return minCost;
}

int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Find the minimum spanning tree using Kruskal's algorithm
    int minCost = kruskalMST(edges, V, E);
    std::cout << "Minimum cost: " << minCost << std::endl;

    return 0;
}

/*
        Time Complexities:- The computing time is O(|E| log |E|) where E is the edge set of 
        graph G. 
*/