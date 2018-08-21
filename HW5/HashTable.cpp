//
//  HashTable.cpp
//  HW5
//
//  Created by Hannah on 3/17/16.
//  Copyright © 2016 Hannah. All rights reserved.
//
#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

HashTable::HashTable(string filename)
{
    ifstream infile(filename.c_str());
    if(!infile)
    {
        cout <<"Canot open file"<<endl;
        return;
    }
    
    string temp;
    while (!infile.eof())
    {
        getline(infile, temp);
        Dictionary_map.insert(temp);
    }
    
    infile.close();
}


void HashTable::SpellCheck(string word)
{
    string check_String1=word;//for lowercase checks
    string check_String2=word;//for uppercase checks
    
    set<string> found_strings;
    
    cout<< "--"<< word <<"--"<<endl;
    
    //check if word is spelled correctly
    if(Dictionary_map.find(check_String1) != Dictionary_map.end())
        found_strings.insert(check_String1);
    
    //if not find suggestions
    else
    {
        //lowercase check
        for(int i=97; i<123;i++)
        {
            for(int j=0; j< word.size();j++)
            {
                //replace_char
                check_String1[j]=i;
                check_String2[j]=i-32;//uppercase replace
                if(Dictionary_map.find(check_String1) != Dictionary_map.end())
                    found_strings.insert(check_String1);
                
                if(Dictionary_map.find(check_String2) != Dictionary_map.end())
                    found_strings.insert(check_String2);
            
                check_String1=word;
                check_String2=word;
            
                //insert_char
                check_String1.insert(j,1,i);
                check_String2.insert(j,1,i-32);//uppercase insert
                
                if(Dictionary_map.find(check_String1) != Dictionary_map.end())
                    found_strings.insert(check_String1);
                
                if(Dictionary_map.find(check_String2) != Dictionary_map.end())
                    found_strings.insert(check_String2);
            
                check_String1=word;
                check_String2=word;
                
            
                //delete_char
                check_String1.erase(check_String1.begin()+j);
                if(Dictionary_map.find(check_String1) != Dictionary_map.end())
                    found_strings.insert(check_String1);
            
                check_String1=word;
                check_String2=word;
                
                //swap 2 char
                swap(check_String1[j],check_String1[j+1]);
                if(Dictionary_map.find(check_String1) != Dictionary_map.end())
                    found_strings.insert(check_String1);
            
                check_String1=word;
                check_String2=word;
            }
        }
        
    }

    //print list
    if(found_strings.empty())
       cout<<"no matches found!"<<endl;
    else
        print_suggestions(found_strings);
    
    cout<<endl;
    
}

void HashTable::print_suggestions( set<string> found_strings)
{
        for (set<string>::iterator iter = found_strings.begin(); iter != found_strings.end(); iter++)
        cout << *iter << endl;
}

