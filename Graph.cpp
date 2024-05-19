/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/


#include "Graph.hpp"
#include <iostream>

using namespace std;

namespace ariel
{
        /**
     * @brief Loads a new graph into the object.
     * 
     * This function replaces the current graph with the specified one,
     * performs a validation check to ensure the graph is square,
     * and throws an exception if the graph is invalid.
     * 
     * @param graph The new graph to load.
     * 
     * @throws std::invalid_argument If the input graph is not square.
     */
    void Graph::loadGraph(vector<vector<int>> graph)
    {
            // Clear the graph before loading the new one.
            this->_graph.clear();

            // Copy the new graph.
            for (const auto& row : graph) {
                vector<int> rowCopy(row.begin(), row.end());
                this->_graph.push_back(rowCopy);
            }

            // Validate the graph.
            this->validateGraph();
    }

    /**
     * This function prints the number of vertices and edges in the graph.
     */
    void Graph::printGraph() const
    {
        int vertices = this->_graph.size();
        int edges = 0;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
    }

    /**
     * Returns the number of vertices.
    */

    int Graph:: size() const
    {
        return this -> _graph.size();
    }


    Graph Graph::operator+(const Graph& other) const
    {
        // Ensure the graphs are the same size
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be the same size to add.");
        }

        int n = this->size();
        Graph result;
        result._graph.resize(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result._graph[i][j] = this->_graph[i][j] + other._graph[i][j];
            }
        }

        return result;
    }

        Graph& Graph::operator+=(const Graph& other)
    {
        // Ensure the graphs are the same size
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be the same size to add.");
        }

        int n = this->size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                this->_graph[i][j] += other._graph[i][j];
            }
        }

        return *this;
    }

    Graph& Graph::operator+()
    {

        int n = this->size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                1* this->_graph[i][j];
            }
        }

        return *this;
    }

    Graph Graph::operator*(const Graph& other) const
    {
        // Ensure the graphs are the same size
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be the same size to add.");
        }

        int n = this->size();
        Graph result;
        result._graph.resize(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                for(int k = 0; k< n; k++){
                result._graph[i][j] += this->_graph[i][k] * other._graph[k][j];
                }
            }
        }

        return result;
    }

    Graph& Graph::operator-=(const Graph& other)
    {
        // Ensure the graphs are the same size
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be the same size to add.");
        }

        int n = this->size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                this->_graph[i][j] -= other._graph[i][j];
            }
        }

        return *this;
    }

    Graph Graph::operator-(const Graph& other) const
    {
        // Ensure the graphs are the same size
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be the same size to add.");
        }

        int n = this->size();
        Graph result;
        result._graph.resize(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result._graph[i][j] = this->_graph[i][j] - other._graph[i][j];
            }
        }

        return result;
    }

    Graph& Graph::operator-()
    {
        int n = this->size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
               this->_graph[i][j] = -1*this->_graph[i][j];
            }
        }

        return *this;
    }


    Graph& Graph::operator--()
    {
        int n = this->size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(this->_graph[i][j] !=0){
                    --this->_graph[i][j];
                }
            }
        }

        return *this;
    }

    Graph& Graph::operator--(int){
        Graph copy = *this;
                int n = this->size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(this->_graph[i][j] !=0){
                    this->_graph[i][j]--;
                }
            }
        }
        return *this;
    }


    Graph& Graph::operator++()
    {
        int n = this->size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(this->_graph[i][j] !=0){
                    ++this->_graph[i][j];
                }
            }
        }

        return *this;
    }

    Graph& Graph::operator++(int){
        Graph copy = *this;
                int n = this->size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(this->_graph[i][j] !=0){
                    this->_graph[i][j]++;
                }
            }
        }

        return *this;
    }


    Graph Graph:: operator*(int scalar) const
    {
        Graph result;
        int n = this->size();
        result._graph.resize(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result._graph[i][j] = this->_graph[i][j] * scalar;
            }
        }

        return result;

    }

    Graph& Graph::operator*=(int scalar)
    {
        int n = this->size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                this->_graph[i][j] *= scalar;
            }
        }

        return *this;
    }

    bool Graph::operator==(const Graph& other) const
    {
        if (this->size() != other.size())
        {
            return false;
        }

        int n = this->size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (this->_graph[i][j] != other._graph[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool Graph::operator!=(const Graph& other) const
    {
        return !(*this == other);
    }

    ostream& operator<<(ostream& os, const Graph& graph)
    {
        int n = graph.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                os << graph._graph[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    /**
     * @brief Checks if the current graph contains the specified subgraph.
     *
     * This method determines whether the `other` graph is a subgraph of the current graph.
     * A subgraph is defined as a smaller graph that can be found within a larger graph.
     *
     * The method works by iterating over all possible positions in the current graph where
     * the top-left corner of the subgraph could be placed, and checking if the subgraph
     * matches the corresponding portion of the current graph.
     *
     * @note If the `other` graph has a greater size than the current graph, it cannot be
     * a subgraph and the method immediately returns false.
     *
     * Example:
     * @code
     * Graph g1;
     * vector<vector<int>> graph1 = {
     *     {1, 2, 3},
     *     {4, 5, 6},
     *     {7, 8, 9}
     * };
     * g1.loadGraph(graph1);
     *
     * Graph g2;
     * vector<vector<int>> graph2 = {
     *     {5, 6},
     *     {8, 9}
     * };
     * g2.loadGraph(graph2);
     *
     * bool result = g1.contains(g2); // result will be true
     */

    bool Graph::contains(const Graph& other) const
    {
        int n = this->size();
        int m = other.size();

        if (m > n)
        {
            return false;
        }

        for (int i = 0; i <= n - m; ++i)
        {
            for (int j = 0; j <= n - m; ++j)
            {
                bool match = true;
                for (int k = 0; k < m && match; ++k)
                {
                    for (int l = 0; l < m && match; ++l)
                    {
                        if (this->_graph[i + k][j + l] != other._graph[k][l])
                        {
                            match = false;
                        }
                    }
                }
                if (match)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool Graph::operator<(const Graph& other) const{

        int n = this->size();

        if (this->size() > other.size() )
        {
            return false;
        }


        if(other.contains(*this) &&this->size() != other.size()){
            return true;
        }

        int _thisEdges = 0;
        int _otherEdges = 0;
        for(int i = 0; i< n; i++){
             for(int j = 0; j< n; j++){
                    if(this->_graph[i][j] != 0) _thisEdges++;
                    if(other._graph[i][j] != 0) _otherEdges++;
            }
        }
        return _thisEdges < _otherEdges;
    }

    bool Graph::operator<=(const Graph& other) const{

        if (this->size() > other.size())
        {
            return false;
        }
        return (*this < other) || (*this == other);;
    }

    bool Graph::operator>(const Graph& other) const{

        int n = other.size();

        if (this->size() < other.size())
        {
            return false;
        }
        if(this->contains(other) && this->size() != other.size()){
            return true;

        }
       
        int _thisEdges = 0;
        int _otherEdges = 0;
        for(int i = 0; i< n; i++){
             for(int j = 0; j< n; j++){
                    if(this->_graph[i][j] != 0) _thisEdges++;
                    if(other._graph[i][j] != 0) _otherEdges++;
            }
        }
        return _thisEdges > _otherEdges;
    }

    bool Graph::operator >=(const Graph& other) const{

        if (this->size() < other.size())
        {
            return false;
        }

        return (*this > other) || (*this == other);
    }


    /**
     * @brief Validates the integrity of the graph.
     * 
     * This function checks if the graph is square.
     * If the graph is not square, it throws an exception.
     * 
     * @throws std::invalid_argument If the graph is not square.
     */

    void Graph::validateGraph() const
    {
        int vertices = this->_graph.size();
        for (int i = 0; i < vertices; i++)
        {
            if (this->_graph[i].size() != vertices)
            {
                cout<<"Invalid graph: The graph is not a square matrix."<<endl;
                throw invalid_argument("Invalid graph.");
            }
        }
    }
}; 