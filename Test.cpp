/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 * I added tests
 */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with disconnected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}}; // 2 is isolated
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
    {0, 0, 0, 0},  // 0 is isolated
    {0, 1, 0, 0},  // 1 connects to 2
    {0, 0, 1, 1},  // 2 connects to 3
    {0, 0, 1, 0}   // 3 connects to 2
  };
  g.loadGraph(graph2);

  CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);

    
    vector<vector<int>> graph1 = {
    {0, 1, 0, 1},  
    {1, 0, 1, 0},  
    {0, 1, 0, 1},  
    {1, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);
    
    
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 1) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 2) == true);
}

TEST_CASE("Test shortestPath with disconnected nodes")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},  // 0 connects to 1
        {1, 0, 0},  // 1 connects to 0
        {0, 0, 0}}; // 2 is isolated
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == false);

    
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},  // 0 connects to 1 2
        {1, 0, 1, 0, 0},  // 1 connects to 0 2 
        {1, 1, 0, 1, 0},  // 2 connects to 0 1 3
        {0, 0, 1, 0, 0},  // 3 connects to 2
        {0, 0, 0, 0, 0}}; // 4 is isolated
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == false);
}

TEST_CASE("Test shortestPath with invalid source or destination")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, -1, 0) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, -1) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 3) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 3, 0) == false);
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with acyclic graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with negative cycle in the graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {2, 0, 0, 0},
        {0, 0,-5, 0},
        {6, 0, 0, 4},
        {0,-3, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}



TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == true);

  
    vector<vector<int>> graph5 = {
    {0, 1, 0, 0},  
    {1, 0, 1, 0}, 
    {0, 1, 0, 1},  
    {0, 0, 1, 0}   
  };
  g.loadGraph(graph5);

  CHECK(ariel::Algorithms::isBipartite(g) == true);
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test empty graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {};
    g.loadGraph(graph);
    CHECK_THROWS(ariel::Algorithms::isConnected(g));
    CHECK_THROWS(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK_THROWS(ariel::Algorithms::isBipartite(g) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 1) == false);
}

//===========| test operators |===========//

TEST_CASE("Test operator+")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2);

    ariel::Graph ansGraph;
    vector<vector<int>> ans = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    ansGraph.loadGraph(ans);

    CHECK(g1 + g2 == ansGraph);
}

TEST_CASE("Test operator++")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2);

    ariel::Graph ansGraph;
    vector<vector<int>> ans = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    ansGraph.loadGraph(ans);

    CHECK(g1 + g2 == ansGraph);
}

TEST_CASE("Test operator++ (post-increment)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1++;

    vector<vector<int>> incrementedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    ariel::Graph ans;
    ans.loadGraph(incrementedGraph);

    CHECK(g2 == g1); 

    CHECK(g1 == ans);
}

TEST_CASE("Test operator++ (pre-increment)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    vector<vector<int>> incrementedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    ariel::Graph ans;
    ans.loadGraph(incrementedGraph);

    ariel::Graph& g2 = ++g1;

    CHECK(g1 == ans);

    CHECK(g2 == g1);

}

TEST_CASE("Test operator+= (add and assign)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2);

    vector<vector<int>> ans = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    ariel::Graph expected;
    expected.loadGraph(ans);

    g1 += g2;

    CHECK(g1 == expected);
}

TEST_CASE("Test unary operator+")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = +g1;

    CHECK(g1 == g2);
}


TEST_CASE("Test operator-")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2);

    ariel::Graph ansGraph;
    vector<vector<int>> ans = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    ansGraph.loadGraph(ans);

    CHECK(g1 - g2 == ansGraph);
}

TEST_CASE("Test operator-- (post-decrement)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1--; 

    vector<vector<int>> decrementedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    
    ariel::Graph ans;
    ans.loadGraph(decrementedGraph);

    CHECK(g2 == g1);  

    CHECK(g1 == ans);
}

TEST_CASE("Test operator-- (pre-decrement)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph1);

    vector<vector<int>> decrementedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    
    ariel::Graph ans;
    ans.loadGraph(decrementedGraph);

    ariel::Graph& g2 = --g1;

    CHECK(g1 == ans);

    CHECK(g2 == g1);
}

TEST_CASE("Test operator-= (subtract and assign)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g2.loadGraph(graph2);

    vector<vector<int>> ans = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph expected;
    expected.loadGraph(ans);

    g1 -= g2;

    CHECK(g1 == expected);
}

TEST_CASE("Test operator*(int scalar)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    int scalar = 3;
    ariel::Graph result = g1 * scalar;

    vector<vector<int>> ans = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    ariel::Graph expected;
    expected.loadGraph(ans);

    CHECK(result == expected);
}

TEST_CASE("Test operator*=(int scalar)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    int scalar = 3;
    g1 *= scalar;

    vector<vector<int>> ans = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    ariel::Graph expected;
    expected.loadGraph(ans);

    CHECK(g1 == expected);
}

TEST_CASE("Test operator*(const Graph& other)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};
    g2.loadGraph(graph2);

    ariel::Graph result = g1 * g2;

    vector<vector<int>> ans = {
        {30, 24, 18},
        {84, 69, 54},
        {138, 114, 90}};
    ariel::Graph expected;
    expected.loadGraph(ans);

    CHECK(result == expected);
}

TEST_CASE("Test contains(const Graph& other)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}};
    g2.loadGraph(graph2);

    CHECK(g1.contains(g2));
    
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {1, 0},
        {1, 1}};
    g3.loadGraph(graph3);

    CHECK(g1.contains(g3));
}

TEST_CASE("Test operator==")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 == g2);
}

TEST_CASE("Test operator!=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test operator<")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(graph3);

    CHECK(!(g1 < g3));
}

TEST_CASE("Test operator<=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 <= g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 <= g3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g4.loadGraph(graph4);

    CHECK(g1 <= g4);
}

TEST_CASE("Test operator>")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 > g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);

    CHECK(!(g1 > g3));
    CHECK(g3>g2);
}

TEST_CASE("Test operator>=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 >= g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);

    CHECK(!(g1 >= g3));
}







