//Program to implement graph traversal using Breadth First Search

#include<iostream>
#include <queue>
using namespace std;

// Function to perform Breadth First Search (BFS) traversal on a graph represented by an adjacency matrix
void BFS(int graph[][5], int start, int V) {
    bool visited[V] = {false}; // Array to keep track of visited vertices
    queue<int> q; // Queue for BFS traversal

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        cout << u << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex u
        // If an adjacent vertex has not been visited, mark it as visited and enqueue it
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
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
    int start = 0; // Starting vertex for BFS traversal

    cout << "Breadth First Traversal starting from vertex " << start << ": ";
    BFS(graph, start, V);

    return 0;
}

/*
    Time Complexities:- Let T(n,e) and S(n,e) be the maximum time and maximum 
    additional space taken by algorithm BFS on any graph G with n vertices and e edges. 
    T(n, e) = Θ(n + e) and S(n, e) = Θ(n) if G is represented by its adjacency lists. If G is 
    represented by its adjacency matrix, then T(n, e) =Θ(n²) and S(n ,e) = Θ(n). 
*/
