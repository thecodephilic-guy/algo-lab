// Program to implement graph traversal using Depth First Search 

#include <iostream>
using namespace std;

// Function to perform Depth First Search (DFS) traversal on a graph represented by an adjacency matrix
void DFS(int graph[][5], int start, bool visited[], int V) {
    // Mark the current node as visited and print it
    visited[start] = true;
    cout << start << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int v = 0; v < V; ++v) {
        if (graph[start][v] && !visited[v]) {
            DFS(graph, v, visited, V);
        }
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    int V = 5; // Number of vertices in the graph
    bool visited[V] = {false}; // Array to keep track of visited vertices

    cout << "Depth First Traversal starting from vertex 0: ";
    DFS(graph, 0, visited, V);

    return 0;
}

/*
        Time Complexities:- Let T(n, e) and S(n, e) be the maximum time and maximum 
        - additional space taken by algorithm DFS for an n-vertex and e-edge graph, then S(n, e) 
        = Θ(n) and T(n, e) = Θ(n + e) if adjacency lists are used and T(n, e) =Θ(n²) if 
        adjacency matrices are used. 
*/