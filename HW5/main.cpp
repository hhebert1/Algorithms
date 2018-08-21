//
//  main.cpp
//  HW5
//
//  Created by Hannah on 3/17/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

//use with dicitonary.txt

#include <iostream>

#include "HashTable.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    if (argc <= 1)
    {
        cout << "Please supply a file name for the dictionary as input" << endl;
        return 1;
    }
    
    HashTable* hashTable = new HashTable(argv[1]);
    
    cout << "Spell checking...\n";
    
    hashTable->SpellCheck("spelling");
    hashTable->SpellCheck("spel");
    hashTable->SpellCheck("goiing");
    hashTable->SpellCheck("abcdefghijklmnop");
    hashTable->SpellCheck("A");
    hashTable->SpellCheck("Diacipiperazine");
    hashTable->SpellCheck("diacipIperazine");
    
    return 0;
}
