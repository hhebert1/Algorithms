#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

long BinarySum (string fileName)
{
    long result=0;
    
    //Open file
    ifstream input(fileName.c_str());
    
    if (input.fail())
    {
        cout<< "File does not exist"<<endl;
        cout<< "Exit program"<<endl;
        return 0;
    }
    
    string s_binNumber;
    long decNumber;
    
    //Read data
    while(!input.eof()) //Continue if not end of file
    {
        getline(input, s_binNumber, '\n');
        
        decNumber=0;
        
        long size= s_binNumber.size();
        
        for (int i=0; i < size; i++) // convert each string line into a decimal value
        {
            if (s_binNumber.c_str()[i] == '1')
            {
                decNumber = decNumber+ pow(2, size-i-1);
            }
        }
        
        result = result + decNumber;//add decimal values
        
    }
    
    input.close();
    
    return result;
}

int main(int argc, char*argv[])
{
    long result;
    if (argc != 2)
    {
        cout<< "Incorrect number of inputs."<<endl;
        return 0;
    }
    
    result=BinarySum(argv[1]);
    cout<<result<<endl;
    
    return 0;
    
}
