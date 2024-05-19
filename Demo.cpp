/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 * This is Demo class for Ex1
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    cout << "===================================================================" << endl;
    cout << "Graph1: represents a disconnected graph with 3 connected components" << endl;
    cout << "===================================================================" << endl;
    ariel::Graph g;
    // 4x4 matrix that represents a disconnected graph with 3 connected components.
    vector<vector<int>> graph1 = {
        {0, 0, 0, 0},  // 0 is isolated
        {0, 1, 0, 0},  // 1 connects to 1
        {0, 0, 1, 1},  // 2 connects to 3
        {0, 0, 1, 0}}; // 3 connects to 2
    g.loadGraph(graph1);

    g.printGraph();                    // Should print: "Graph with 4 vertices and 4 edges."
    Algorithms::isConnected(g);        // Should print: "Graph is not connected". returns false
    Algorithms::shortestPath(g, 0, 2); // Should print: "No path from 0 to 2 exists". returns false
    Algorithms::isContainsCycle(g);    // Should print: "1->1" ( 1 is pointing on it self). returns true
    Algorithms::isBipartite(g);        // Should print: "The graph is not bipartite". returns false

    cout << "===================================================================" << endl;
    cout << "Graph2: represents a non-connected graph with a cycle" << endl;
    cout << "===================================================================" << endl;
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},  // 0 connects to 1 2
        {1, 0, 1, 0, 0},  // 1 connects to 0 2
        {1, 1, 0, 1, 0},  // 2 connects to 0 1 3
        {0, 0, 1, 0, 0},  // 3 connects to 2
        {0, 0, 0, 0, 0}}; // 4 is isolated

    g.loadGraph(graph2);

    g.printGraph();                    // Should print: "Graph with 5 vertices and 8 edges."
    Algorithms::isConnected(g);        // Should print: "Graph is not connected" returns false.
    Algorithms::shortestPath(g, 0, 4); // Should print: "No path from 0 to 4 exists" returns false.
    Algorithms::isContainsCycle(g);    // Should print: "The cycle is: 2->0->1->2" returns true.
    Algorithms::isBipartite(g);        // Should print: ""The graph is not bipartite" returns false.

    cout << "===================================================================" << endl;
    cout << "Graph3: represents a bipartide connected graph with no cycles" << endl;
    cout << "===================================================================" << endl;
    // 4x4 matrix that reprsents a bipartide connected graph with no cycles.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},  // 0 connects to 1
        {1, 0, 1, 0},  // 1 connects to 0 2
        {0, 1, 0, 1},  // 2 connects to 1 3
        {0, 0, 1, 0}}; // 3 connects to 2

    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                    // Should print: "Graph with 4 vertices and 6 edges."
    Algorithms::isConnected(g);        // Should print: "Graph is connected" returns true.
    Algorithms::shortestPath(g, 0, 3); // Should print: "Shortest path from 0 to 3: 0->1->2->3" returns true.
    Algorithms::isContainsCycle(g);    // Should print: "No cycles" returns false.
    Algorithms::isBipartite(g);        // Should print: "The graph is bipartite: A={0, 2}, B={1, 3}. returns true"

    cout << "===================================================================" << endl;
    cout << "Graph4: invalid graph" << endl;
    cout << "===================================================================" << endl;
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        e.what(); // Should print: "Invalid graph: The graph is not a square matrix."
    }

    cout << "===================================================================" << endl;
    cout << "Graph5: represents a weighted connected directed graph with no cycles" << endl;
    cout << "===================================================================" << endl;

    // 5x5 matrix that represents a weighted connected directed graph with no cycles.
    vector<vector<int>> graph5 = {
        {0, 2, 0, 4, 0},  // 0 points on 1 3
        {0, 0, 1, 0, 3},  // 1 points on 2 4
        {0, 0, 0, 0, 5},  // 2 points on 4
        {0, 0, 0, 0, 1},  // 3 points on 4
        {0, 0, 0, 0, 0}}; // 1 2 3 points on 4

    g.loadGraph(graph5);

    g.printGraph();                    // Should print: "Graph with 5 vertices and 6 edges."
    Algorithms::isConnected(g);        // Should print: "Graph is connected" returns true.
    Algorithms::shortestPath(g, 0, 4); // Should print: "Shortest path from 0 to 4: 0->1->4" returns true.
    Algorithms::isContainsCycle(g);    // Should print: "No cycles" returns false.
    Algorithms::isBipartite(g);        // should print: "The graph is not bipartite" returns false.

    cout << "===================================================================" << endl;
    cout << "Graph6: represents a weighted connected directed graph with a negative cycle" << endl;
    cout << "===================================================================" << endl;

    // 5x5 matrix that represents a weighted connected directed graph with a negative cycle.
    vector<vector<int>> graph6 = {
        {0, 2, 0, 0, 4},   // 0 points on 1 3
        {0, 0, 0, 1, 0},   // 1 points on 3
        {3, 0, 0, 0, 0},   // 2 points on 0
        {0, 0, 0, 0, 0},   // 1 4 point on 3
        {0, 0, -8, 3, 0}}; // 4 points on 2 3

    g.loadGraph(graph6);

    g.printGraph();                    // Should print: "Graph with 5 vertices and 6 edges."
    Algorithms::isConnected(g);        // Should print: "Graph is connected" returns true.
    Algorithms::shortestPath(g, 2, 0); // Should print: "Negative cycle found, cycle vertices: 0->2->4->0" returns false.
    Algorithms::isContainsCycle(g);    // Should print: "Negative cycle was detected, check the cycle with shortestPath" returns true.
    Algorithms::isBipartite(g);        // The graph is not bipartite. returns false.

    cout << "===================================================================" << endl;
    cout << "Operators" << endl;
    cout << "===================================================================" << endl;

    Graph g1;
    vector<vector<int>> graph1_1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1_1);

    Graph g2;
    vector<vector<int>> graph2_2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2_2);

    cout << g1 + g2 << endl; // Matrix of 1
    cout << ++g1 << endl;    // Matrix of 0 and 2
    cout << g1-- << endl;    // the initial g1
    cout << g1 * g2 << endl; // shold print matrix {0 1 0},{2 0 2},{0 1 0}

    Graph g3;
    vector<vector<int>> graph3_3 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g3.loadGraph(graph3_3);

    cout << g3 - g2 << endl; // Matrix of 0

    g3 += g2;
    cout << g3 << endl; // g3 is consists of 2 and 0

    g3 -= g2;
    cout << g3 << endl; // g3 is consists of 1 and 0

    cout << g3 * 50 << endl; // Matrix of 50 and 0

    cout << "===================================================================" << endl;
    cout << "Comparison operators" << endl;
    cout << "===================================================================" << endl;

    Graph g4;
    vector<vector<int>> graph4_4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g4.loadGraph(graph4_4);

    Graph g5;
    vector<vector<int>> graph5_5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g5.loadGraph(graph5_5);

    bool res;
    res = g4 > g5;
    cout << res << endl; // Should print 1 (true)
    res = g4 >= g5;
    cout << res << endl; // Should print 1 (true)


    Graph g6;
    vector<vector<int>> graph6_6 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g6.loadGraph(graph6_6);

    res = g4 > g6;
    cout << res << endl; // Should print 0 (false)
    res = g6 > g5;
    cout << res <<endl;  // Should print 1 (true) (g6 has more edges)

    res = g3 == g2;
    cout << res << endl; // Should print 1 (true)

    return 0;
}
