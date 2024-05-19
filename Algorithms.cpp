/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/

#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <climits>
#include <iostream>


using namespace std;
#define INF 2147483647

/**
 * Checks if the given graph is connected.
 * 
 * This function performs a breadth-first search (BFS) starting from vertex 0
 * to visit all reachable vertices in the graph. If all vertices are visited
 * after BFS traversal, the graph is considered connected.
 * 
 * @param g The graph to check for connectivity.
 * @return True if the graph is connected, otherwise false.
 * @throws std::invalid_argument If the graph is empty.
 *
 */

bool ariel::Algorithms::isConnected(const ariel::Graph &g)
{
    if (g.size() == 0)
    {
        
        throw invalid_argument("Error: Empty Graph");
    }

    vector<bool> visited(g.size(), false);
    queue<int> q;
    q.push(0);

    visited[0] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g.size(); i++)
        {
            if (!visited[i] && g._graph[v][i] != 0)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    // Check if all the vertices are visited
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
        {
            cout<<"Graph is not connected"<<endl;
            return false;
        }
    }
    cout<<"Graph is connected"<<endl;
    return true;
}

/**
 * Calculates the shortest path from a source vertex to a destination vertex in the given graph.
 * 
 * This function uses the Bellman-Ford algorithm to find the shortest path from the source vertex
 * to all other vertices in the graph. It then checks for the existence of negative cycles in the graph.
 * If a negative cycle is found, the function prints the cycle vertices. Otherwise, it prints the shortest
 * path from the source to the destination vertex.
 * 
 * @param graph The graph in which to find the shortest path.
 * @param source The source vertex.
 * @param destination The destination vertex.
 * @return True if the shortest path is found and printed, otherwise false.
 * @throws std::invalid_argument If the graph is empty or if the source or destination vertex is out of range.
 * 
 */

void ariel::Algorithms::printPath(const vector<int>& parent, int v) {
    if (v == -1) return;
    printPath(parent, parent[v]);
    if (parent[v] != -1) cout << "->";
    cout << v;
}

bool ariel::Algorithms::shortestPath(const ariel::Graph &graph, int source, int destination)
{
    if(graph.size() == 0){
        throw invalid_argument("Error: Empty Graph");
    }

    if((source < 0 || destination >= graph._graph[0].size())||(destination < 0 || source >= graph._graph[0].size())){
        throw invalid_argument("Error: Invalid vertices");
    }

    
    int V = graph.size();
    vector<int> distance(V,INF);
    vector<int> parent(V, -1);
    int negativeCycleStart = -1;

    distance[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph._graph[u][v] != 0 && distance[u] !=INF && distance[u] + graph._graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph._graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
   bool isInCycle[V];
  // Check for negative cycle
    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            if (graph._graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph._graph[u][v] < distance[v])
            {
                // Negative cycle found, backtrack to find cycle vertices
                while (!isInCycle[v])
                {
                    isInCycle[v] = true;
                    v = parent[v];
                    negativeCycleStart = v;
                }
                cout<<"Negative cycle found "<<endl;
                ariel::Algorithms::negativeCycle(negativeCycleStart,parent,isInCycle);
                return false;
            }
        }
    }

    // Print shortest path from source to destination
    if (distance[destination] !=INF) {
        cout << "Shortest path from " << source << " to " << destination << ": ";
        printPath(parent, destination);
        cout << endl;
    } else {
        cout << "No path from " << source << " to " << destination << " exists" << endl;
        return false;
    }
    

    return true;
}

/**
 * Checks if the given graph contains a negative cycle and prints the vertices
 * involved in the cycle if found.
 * 
 * @param g The graph to check for a negative cycle.
 * @return True if a negative cycle is found, otherwise false.
 * @throws std::invalid_argument If the graph is empty.
 * 
 */

bool ariel::Algorithms:: isContainsCycle(const ariel::Graph &g)
        {
            if(g.size() == 0){
                throw invalid_argument("Error: Empty Graph");
            }

            if(negCyclefloydWarshall(g)){
                cout<<"Negative cycle was detected, check the cycle with shortestPath "<<endl;
                return true;
            }

            size_t n = g.size();
            vector<int> parent(n, -1);      // Store parent of each node
            vector<bool> visited(n, false); // Mark nodes as visited
            vector<int> cycleNodes;         // Store cycle nodes

            for (int i = 0; i < n; ++i)
            {
                if (!visited[i])
                {
                    if (ariel::Algorithms::isContainsCycleUtil(g, i, visited, parent, cycleNodes))
                    {
                        // print the cycle
                        cout << "The cycle is: ";
                        for (size_t i = 0; i < cycleNodes.size(); ++i)
                        {
                            cout << cycleNodes[i];
                            if (i < cycleNodes.size() - 1)
                            {
                                cout << "->";
                            }
                        }
                        cout << endl;
                        return true; // Cycle detected
                    }
                }
            }
            cout<<"No cycles"<<endl;
            return false; 
        }


bool ariel::Algorithms:: isContainsCycleUtil(const ariel::Graph &g, int v, vector<bool> &visited, vector<int> &parent, vector<int> &cycleNodes)
{

	visited[v] = true; // Mark current node as visited

    // Visit all neighbors of current node
    for (int u = 0; u < g.size(); ++u)
    {
        if (g._graph[v][u] == 1)
        {
            if (!visited[u])
            {
                parent[u] = v;
                if (ariel::Algorithms::isContainsCycleUtil(g, u, visited, parent, cycleNodes))
                {
                    return true; // Cycle detected
                }
            }
            else if (u != parent[v])
            {
                // Cycle detected, backtrack to find cycle nodes
                int cur = v;
                while (cur != u)
                {
                    cycleNodes.push_back(cur);
                    cur = parent[cur];
                }
                cycleNodes.push_back(u);
                cycleNodes.push_back(v);

                // Rearrange cycleNodes to start from u and end at v
                vector<int> reversedCycleNodes(cycleNodes.size());
                for (size_t i = 0; i < cycleNodes.size(); ++i)
                {
                    reversedCycleNodes[i] = cycleNodes[cycleNodes.size() - 1 - i];
                }
                cycleNodes = reversedCycleNodes;

                return true;
            }
        }
    }
    return false; // No cycle found from this node

}
/**
 * Prints the negative cycle
*/
void ariel::Algorithms::negativeCycle(int negativeCycleStart,vector<int> parent,bool isInCycle[]){
        cout << "Negative cycle found, cycle vertices: ";
        int v = negativeCycleStart;
        do
        {       
            cout << v << "->";
            isInCycle[v] = false; // Mark as visited
            v = parent[v];
            
        } while (false != isInCycle[v]);
        cout<<negativeCycleStart<< endl;

}
/** 
 * Helper function for "isContainsCycle" for detecting a negative cycle
 * SOURCE: https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/
*/
bool ariel::Algorithms:: negCyclefloydWarshall(const ariel::Graph g)
{
    /* dist[][] will be the output matrix that will 
       finally have the shortest 
    distances between every pair of vertices */
    int dist[g.size()][g.size()], i, j, k;
  
    /* Initialize the solution matrix same as input
      graph matrix. Or we can say the initial values 
      of shortest distances are based on shortest 
      paths considering no intermediate vertex. */
    for (i = 0; i < g.size(); i++)
        for (j = 0; j < g.size(); j++)
            dist[i][j] = g._graph[i][j];
  
    /* Add all vertices one by one to the set of 
       intermediate vertices.
    ---> Before start of a iteration, we have shortest
         distances between all pairs of vertices such 
         that the shortest distances consider only the
         vertices in set {0, 1, 2, .. k-1} as intermediate 
         vertices.
    ----> After the end of a iteration, vertex no. k is 
          added to the set of intermediate vertices and 
          the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < g.size(); k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < g.size(); i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < g.size(); j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // If distance of any vertex from itself
    // becomes negative, then there is a negative
    // weight cycle.
    for (int i = 0; i < g.size(); i++)
        if (dist[i][i] < 0)
            return true;
    return false; 
}

/**
 * Checks if the given graph is bipartite and prints its bipartite sets.
 * 
 * This function performs a breadth-first search (BFS) traversal of the graph
 * to determine if it can be divided into two disjoint sets (by coloring) such that no two
 * vertices within the same set are adjacent. If such a partition exists,
 * the function prints the vertices in each set.
 * 
 * @param graph The graph to check for bipartiteness.
 * @return True if the graph is bipartite and its bipartite sets are printed, otherwise false.
 * @throws std::invalid_argument If the graph is empty.
 * 
 */

bool ariel::Algorithms::isBipartite(const ariel::Graph &graph)
{
    if(graph.size() == 0){
        throw invalid_argument("Error: Empty Graph");
    }
    int V = graph.size();
    vector<int> color(V, -1); // Initialize all vertices with no color
    vector<bool> visited(V, false); // Mark all vertices as not visited

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            color[i] = 0; // Assign the initial color to the first vertex

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                visited[u] = true;

                for (int v = 0; v < V; ++v) {
                    if (graph._graph[u][v]) {
                        if (color[v] == -1) {
                            // Assign the opposite color to the adjacent vertex
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            // If adjacent vertices have the same color, graph is not bipartite
                            cout<<"The graph is not bipartite"<<endl;
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Separate vertices into two sets based on their colors
    vector<int> setA, setB;
    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) {
            setA.push_back(i);
        } else {
            setB.push_back(i);
        }
    }

    cout<<"The graph is bipartite: ";

    // Print the bipartite sets
    cout << "A={";
    for (size_t i = 0; i < setA.size(); ++i) {
        cout << setA[i];
        if (i != setA.size() - 1) cout << ", ";
    }
    cout << "}, B={";
    for (size_t i = 0; i < setB.size(); ++i) {
        cout << setB[i];
        if (i != setB.size() - 1) cout << ", ";
    }
    cout << "}" << endl;

    return true;
}