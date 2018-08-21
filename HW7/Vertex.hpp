//
//  Vertex.hpp
//  HW7
//
//  Created by Hannah on 4/13/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <vector>
#include <string>
#include <iostream>
#include "Edge.hpp"

using namespace std;

class Edge;

class Vertex
{
public:
    Vertex(string inName);
    string name;
    vector<Edge *> outEdges;
    
    void addEdge(Edge *);
};


#endif /* Vertex_hpp */
