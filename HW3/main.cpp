#include <iostream>
#include <string>
#include "numCell.h"

using namespace std;

int main() {
    
    //declare variables for (i)
    numCell<int> num1(46);
    numCell<int> num2(2);
    numCell<int> num3(15);
    
    //declare sum for (i)
    numCell<int> int_sum;
    
    //compute and print sum for (i)
    int_sum = num1+num2+num3;
    cout<< "46+2+15=" << int_sum.read()<<endl;
    
    
    //declare variables for (ii)
    numCell<string> string1("abra");
    numCell<string> string2("cadabra");
    
    //declare sum for (ii)
    numCell<string> string_sum;
    
    //compute and print sum for (ii)
    string_sum = string1+string2;
    cout<< "'abra' + 'cadabra' = " << string_sum.read()<<endl;
    
    
    //write over previous variable and declare new ones for (iii)
    string1.write("temp");
    string2.write("lates");
    numCell<string> string3("are");
    numCell<string> string4("us");
    numCell<string> string5("eful");
    
    //write over string_sum and print for (iii)
    string_sum.write(string1.read()+string2.read()+string3.read()+string4.read()+string5.read());
    cout<< "'temp' + 'lates' + 'are' + 'us' + 'ful' = " << string_sum.read()<<endl;
    
    return 0;
}

