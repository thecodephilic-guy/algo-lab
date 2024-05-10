// Program to implement all pairs shortest path:

#include <iostream>
using namespace std;

#define V 4 // Number of vertices in the graph
#define INF 99999 // Infinity, representing no connection between vertices

// Function to find the shortest paths between all pairs of vertices using Floyd Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V]; // Array to store the shortest distances between all pairs of vertices

    // Initialize distances to the given graph
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];

    // Update shortest distances by considering all vertices as intermediates
    for (int k = 0; k < V; ++k) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; ++i) {
            // Pick all vertices as destination for the above source
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances between all pairs of vertices
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}

// Complexity:- The time efficiency of Floyd’s algorithm is cubic i.e. Θ (n3)