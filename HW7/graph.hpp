//
//  graph.hpp
//  HW7
//
//  Created by Hannah on 4/10/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <set>
#include "Edge.hpp"
#include "Vertex.hpp"

using namespace std;


class graph
{
public:
    
    vector<Edge*> edges;
    map<string, Vertex*> vertices;
    
    Vertex *  addVertex(string name);
    Edge * addEdge(string Source, string Dest);
    Vertex * findVertex(string name);
    
    set<Vertex *> vertNeighbors(Vertex *);
    void ThreeNeighbors(Vertex *);

    
};


#endif /* graph_hpp */
