#ifndef HashTable_hpp
#define HashTable_hpp

#include <string>
#include <set>
#include <vector>
using namespace std;

#include <iostream>

class HashTable
{
public:
    HashTable();
    HashTable(string input_file); //initialized set to contain input file words
    
    set<string> Dictionary_map; //library of words
    
    void SpellCheck(string);//calculates possible versions of input string and checks to see if those version are in the dictionary_map
    
    void print_suggestions(set<string> found_strings);//iterates through set of suggestions and prints them
    
};

#endif


