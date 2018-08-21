//
//  LNode.hpp
//  HW4_q4
//
//  Created by Hannah on 3/2/16.
//  Copyright © 2016 Hannah. All rights reserved.
//
#ifndef LNode_hpp
#define LNode_hpp

#include <stdio.h>

class LNode {
public:
    int val;
    LNode* next;
    LNode(int x=0);
};

#endif /* LNode_hpp */

