#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;
//collaborator Allison Durkin
//My name is Hannah Hebert


string Analyze (string str, int size)
{
    vector<string> subStrings;
    
    if (str.size() < size)
    {
        return str;
    }
    
    // fill vector with substrings based on size input
    for (int i=0; i < str.size(); i++)
    {
        subStrings.push_back(str.substr(i,size));
    }
    
    map<string, int> countMap;
    //vector<int> countVec[subStrings.size()];
    string max_element = "";
    int max_count = 0;
    
    for (vector<string>::iterator it = subStrings.begin(); it != subStrings.end(); it++)
    {
        int count = countMap[*it]++;
        if(count > max_count)
        {
            max_count = count;
            max_element = *it;
        }
    }
    
    return max_element;
}

int main(int argc, char *argv[])
{
    int size=atoi(argv[2]);
    string str = argv[1];
    
    cout << Analyze(str,size)<< endl;
    
    return 0;
}

