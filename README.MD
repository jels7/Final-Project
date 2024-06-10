Implement a graph class:


                                    class Graph {  // Graph class
                        private:
                            int numVertices; // Number of vertices
                            vector<vector<int>> adjacencyMatrix; // Adjacency matrix


 Function to add a new vertex to the graph:


                                    void addVertex() {  // Add vertex
                                numVertices++; // Increment number of vertices
                                adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));  // Resize adjacency matrix
                                for (int i = 0; i < numVertices - 1; i++) {  // Loop through vertices
                                    adjacencyMatrix[i].resize(numVertices, 0); 
                                }


Function to add a new edge between two vertices of the graph:


                                    void addEdge(int source, int destination) {  // Add edge
                                if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {  // Check if source and destination are valid
                                    adjacencyMatrix[source][destination] = 1;
                                    adjacencyMatrix[destination][source] = 1;
                                }


 Function for a shortest path algorithm:


                                    vector<int> shortestPath(int source, int destination) {  // Shortest path
                                vector<int> distance(numVertices, INT_MAX);  // Distance vector
                                vector<int> parent(numVertices, -1);
                                vector<bool> visited(numVertices, false); 


Function for a minimum spanning tree algorithm:


                                    vector<pair<int, int>> minSpanTree() {  // Minimum spanning tree
                                vector<pair<int, int>> mst;  // Minimum spanning tree vector
                                vector<int> key(numVertices, INT_MAX);  // Key vector
                                vector<bool> mstSet(numVertices, false);  // Minimum spanning tree set

                                key[0] = 0;  // Set key of 0 to 0

       
