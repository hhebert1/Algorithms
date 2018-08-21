
//
//  main.cpp
//  HW4_q4
//
//  Created by Hannah on 3/2/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

#include <iostream>
#include "LNode.hpp"
#include "LSorter.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LNode LNode1(5);
    LNode LNode2(1);
    LNode LNode3(7);
    LNode LNode4(13);
    LNode LNode5(2);
    LNode LNode6(9);
    
    LNode1.next = &LNode2;
    LNode2.next = &LNode3;
    LNode3.next = &LNode4;
    LNode4.next = &LNode5;
    LNode5.next = &LNode6;
    
    LSorter solution;
    LNode* head = solution.sortList(&LNode1);
    
    LNode* currnode = head;
    while (currnode != nullptr){
        cout << currnode->val << endl;
        currnode = currnode->next;
    }
    
    return 0;
}
