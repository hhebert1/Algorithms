//
//  graph.cpp
//  HW7
//
//  Created by Hannah on 4/10/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <set>
#include "graph.hpp"

using namespace std;

Vertex * graph:: addVertex(string name)
{
        Vertex * v = new Vertex(name);
        vertices[name]=v;
        return v;
}
    
Edge * graph:: addEdge(string Source, string Dest)
{
        
    if (vertices.find(Source) != vertices.end() && vertices.find(Dest) != vertices.end())
    {
        Vertex * SourceV = vertices.find(Source)->second;
        Vertex * DestV = vertices.find(Dest)->second;
        Edge * e = new Edge(SourceV,DestV);
        (*SourceV).addEdge(e);
        (*DestV).addEdge(e);
        edges.push_back(e);
        return e;
    }
    else
        return 0;
}
    
    
Vertex * graph::findVertex(string in_name)
{
    if (vertices.find(in_name) != vertices.end())
        return vertices.find(in_name)->second;
    else
        return 0;
}
    
set<Vertex *> graph:: vertNeighbors(Vertex * v)
{
    set<Vertex *> neighbors;
    vector<Edge *> edges = v->outEdges;
    for (vector<Edge *>::const_iterator it = edges.begin(); it != edges.end(); ++it) {
        if ((*it)->vertex1 != v)
        {
            neighbors.insert((*it)->vertex1);
        }
        if ((*it)->vertex2 !=v)
        {
            neighbors.insert((*it)->vertex2);
        }
    }
    neighbors.insert(v);
    return neighbors;
}


void graph::ThreeNeighbors(Vertex * v)
{
    set<Vertex *> neighbors=vertNeighbors(v);
    set<Vertex *> twoNeighbors;
    set<Vertex *> threeNeighbors;
    
    //add all 1st neighbors
    threeNeighbors.insert(neighbors.begin(), neighbors.end());
    
    for(set<Vertex *>:: iterator it = neighbors.begin(); it != neighbors.end(); ++it)//add all 1st neighbors to set
    {
        set<Vertex *> subNeighbors;
        subNeighbors=vertNeighbors(*it);
        twoNeighbors.insert(subNeighbors.begin(), subNeighbors.end());//add all 2neighbors
    }
    
    //add all 2nd neighbors
    threeNeighbors.insert(twoNeighbors.begin(), twoNeighbors.end());//add to threeneighbors set

    for (set<Vertex *>::iterator it = twoNeighbors.begin(); it != twoNeighbors.end(); ++it)//add all 2nd neighbors to set
    {
        set<Vertex *> subNeighbors;
        subNeighbors=vertNeighbors(*it);
        threeNeighbors.insert(subNeighbors.begin(), subNeighbors.end());//add all 3rd neighbors
    }
    
    //print all three neighbors
    for (set<Vertex * >::iterator it=threeNeighbors.begin(); it!=threeNeighbors.end(); ++it)
        cout << (*it)->name << endl;

}
    
    
    
    
    
    
    
    
    
    
    
    
    
