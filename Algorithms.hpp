/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/

#ifndef Algorithms_HPP
#define Algorithms_HPP

#include "Graph.hpp"
#include <vector>
#include <string>
using namespace std;
namespace ariel
{
    namespace Algorithms
    {
        bool isConnected(const Graph &g);
        bool shortestPath(const Graph &g, int src, int dest);
        void printPath(const std::vector<int>& parent, int v);
        bool isContainsCycle(const Graph &g);
        void negativeCycle(const int negativeCycleStart,vector<int> parent,bool isInCycle[]);
        bool negCyclefloydWarshall(const ariel::Graph g);
        bool isBipartite(const Graph &g);
        bool isContainsCycleUtil(const ariel::Graph& g, int v, vector<bool> &visited, vector<int> &parent,vector<int>&cycleNodes );
        
    }; // namespace Algorithms
} // namespace ariel

#endif