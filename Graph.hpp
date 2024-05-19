/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
using namespace std;
namespace ariel
{
    class Graph
    {
        public:
            vector<vector<int>> _graph;
            void loadGraph(vector<vector<int>> graph);

            void printGraph() const;

            int size() const;

            Graph operator+(const Graph& other) const;

            Graph& operator+=(const Graph& other);

            Graph& operator+();

            Graph& operator++();

            Graph& operator++(int);

            Graph operator-(const Graph& other) const;

            Graph& operator-=(const Graph& other);

            Graph& operator-();

            Graph& operator--();

            Graph& operator--(int);
                
            Graph operator*(int scalar) const;

            Graph& operator*=(int scalar);

            Graph operator*(const Graph& other) const;

            friend ostream& operator<<(std::ostream& os, const Graph& g);

            bool contains(const Graph& other) const;

            bool operator==(const Graph& other) const;
            bool operator!=(const Graph& other) const;
            bool operator<(const Graph& other) const;
            bool operator<=(const Graph& other) const;
            bool operator>(const Graph& other) const;
            bool operator>=(const Graph& other) const;

            private:
            void validateGraph() const ;
            
    }; // class Graph

}; // namespace ariel

#endif