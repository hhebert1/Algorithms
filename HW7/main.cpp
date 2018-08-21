

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include "graph.hpp"

using namespace std;

int main()
{
    char firstChar;
    int num_vertex;
    
    string input;
    
    string sourceNode;
    string destNode;
    
    firstChar= '9';
    num_vertex=firstChar-'0';
    graph citygraph;
    citygraph.addVertex("BOS");
    citygraph.addVertex("JFK");
    citygraph.addVertex("MIA");
    citygraph.addVertex("ORD");
    citygraph.addVertex("STL");
    citygraph.addVertex("DFW");
    citygraph.addVertex("DEN");
    citygraph.addVertex("SEA");
    citygraph.addVertex("LAX");
    
    citygraph.addEdge("BOS", "JFK");
    citygraph.addEdge("BOS", "ORD");
    citygraph.addEdge("JFK", "MIA");
    citygraph.addEdge("JFK", "STL");
    citygraph.addEdge("JFK", "SEA");
    
    citygraph.addEdge("MIA", "DFW");
    citygraph.addEdge("ORD", "STL");
    citygraph.addEdge("ORD", "DEN");
    citygraph.addEdge("ORD", "SEA");
    citygraph.addEdge("STL", "DFW");
    
    citygraph.addEdge("STL", "DEN");
    citygraph.addEdge("DFW", "LAX");
    citygraph.addEdge("DEN", "SEA");
    citygraph.addEdge("DEN", "LAX");
    citygraph.addEdge("SEA", "LAX");
    
    
    string inputNode= "BOS";
    Vertex* inVert = citygraph.findVertex(inputNode);
    
    citygraph.ThreeNeighbors(inVert);
    
    return 0;
}
