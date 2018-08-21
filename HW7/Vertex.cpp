//
//  Vertex.cpp
//  HW7
//
//  Created by Hannah on 4/13/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#include "Vertex.hpp"


void Vertex::addEdge(Edge * e)
{
    outEdges.push_back(e);
}

Vertex::Vertex(string input_name)
{
    name=input_name;
}