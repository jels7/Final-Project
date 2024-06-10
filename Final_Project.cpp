#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


class Graph {  // Graph class
private:
    int numVertices; // Number of vertices
    vector<vector<int>> adjacencyMatrix; // Adjacency matrix

public:
    Graph(int vertices) {  // Constructor
        numVertices = vertices;  // Set number of vertices
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
    } // End of constructor

    void addVertex() {  // Add vertex
        numVertices++; // Increment number of vertices
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));  // Resize adjacency matrix
        for (int i = 0; i < numVertices - 1; i++) {  // Loop through vertices
            adjacencyMatrix[i].resize(numVertices, 0); 
        }
    }

    void addEdge(int source, int destination) {  // Add edge
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {  // Check if source and destination are valid
            adjacencyMatrix[source][destination] = 1;
            adjacencyMatrix[destination][source] = 1;
        }
    }

    vector<int> shortestPath(int source, int destination) {  // Shortest path
        vector<int> distance(numVertices, INT_MAX);  // Distance vector
        vector<int> parent(numVertices, -1);
        vector<bool> visited(numVertices, false); 

        distance[source] = 0;  // Set distance of source to 0

        for (int i = 0; i < numVertices - 1; i++) {  // Loop through vertices
            int minDistance = INT_MAX;
            int minVertex = -1;

            for (int j = 0; j < numVertices; j++) {  // Loop through vertices
                if (!visited[j] && distance[j] < minDistance) {
                    minDistance = distance[j];  // Set min distance
                    minVertex = j;
                }
            }

            visited[minVertex] = true;  // Set visited to true

            for (int j = 0; j < numVertices; j++) {
                if (!visited[j] && adjacencyMatrix[minVertex][j] && distance[minVertex] != INT_MAX &&  // Check if not visited and adjacency matrix is not 0
                    distance[minVertex] + adjacencyMatrix[minVertex][j] < distance[j]) {
                    distance[j] = distance[minVertex] + adjacencyMatrix[minVertex][j];
                    parent[j] = minVertex;  // Set parent
                }
            }
        }

        vector<int> path;  // Path vector
        int currentVertex = destination;  // Set current vertex to destination

        while (currentVertex != -1) {  // Loop while current vertex is not -1
            path.insert(path.begin(), currentVertex);  // Insert current vertex to path
            currentVertex = parent[currentVertex];  // Set current vertex to parent
        }

        return path;  // Return path
    }

    vector<pair<int, int>> minSpanTree() {  // Minimum spanning tree
        vector<pair<int, int>> mst;  // Minimum spanning tree vector
        vector<int> key(numVertices, INT_MAX);  // Key vector
        vector<bool> mstSet(numVertices, false);  // Minimum spanning tree set

        key[0] = 0;  // Set key of 0 to 0

        for (int i = 0; i < numVertices - 1; i++) {  // Loop through vertices
            int minKey = INT_MAX;  // Set min key to INT_MAX
            int minIndex = -1;  // Set min index to -1

            for (int j = 0; j < numVertices; j++) {  // Loop through vertices
                if (!mstSet[j] && key[j] < minKey) {
                    minKey = key[j];
                    minIndex = j;
                }
            }

            mstSet[minIndex] = true;

            for (int j = 0; j < numVertices; j++) {  // Loop through vertices
                if (adjacencyMatrix[minIndex][j] && !mstSet[j] && adjacencyMatrix[minIndex][j] < key[j]) {
                    key[j] = adjacencyMatrix[minIndex][j];
                }
            }
        }

        for (int i = 1; i < numVertices; i++) {
            mst.push_back(make_pair(i, key[i]));
        }

        return mst;
    }
};

int main() {  // Main function
    Graph graph(5);  // Create graph with 5 vertices

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);

    vector<int> shortestPath = graph.shortestPath(0, 4);  // Shortest path from 0 to 4
    cout << "Shortest Path: ";
    for (int vertex : shortestPath) {
        cout << vertex << " ";
    }
    cout << endl;

    vector<pair<int, int>> minSpanTree = graph.minSpanTree();  // Minimum spanning tree
    cout << "Minimum Spanning Tree: ";
    for (auto edge : minSpanTree) {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;

    return 0;
}