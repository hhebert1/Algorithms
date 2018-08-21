//
//  Edge.hpp
//  HW7
//
//  Created by Hannah on 4/13/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include "Vertex.hpp"
#include <iostream>

class Vertex;

class Edge
{
public:
    Edge(Vertex*, Vertex*);
    Vertex * vertex1;
    Vertex * vertex2;
};

#endif /* Edge_hpp */
