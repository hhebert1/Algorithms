//
//  main.cpp
//  HW6_b
//
//  Created by Hannah on 3/27/16.
//  Copyright © 2016 Hannah. All rights reserved.
//

//for use with text file dictionary.txt

#include <iostream>
#include <fstream>
#include "Dictionary.hpp"

int main()
{
    Trie* trie = new Trie();
    
    ifstream infile;
    infile.open("Dictionary.txt");
    
    string temp;
    
    while (!infile.eof())
    {
        getline(infile, temp);
        trie->addWord(temp);
    }
    
    infile.close();
    
    ifstream ifs ("BigData.txt");
    string s;
    
    return 0;
    
}
