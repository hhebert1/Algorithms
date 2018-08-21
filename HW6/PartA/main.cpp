#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>

//for use with 600MB file bigData.txt

using namespace std;
#define BUID 24

int findID(string,int); //returns the amount of BU ID's present in the current file.

int main() { //Test program
    fstream in ("BigData.txt");
    
    long long int hits=0;
    int check=0;
    
    string word;
    long int pos=0;
    
    while (in >> word) { //Read BigData in word for word.
        check=findID(word,BUID);
        hits+=check;
        if (pos%10000000==0)
            printf("At word %ld, total matches: %lld\n",pos,hits);
        if (check) { //Non-zero amount of BUIDs in the current string!
        }
        pos++;
    }
    printf("Finished at word %ld, total matches: %lld\n",pos,hits);
    return 0;
}

int findID(string s, int n) { //returns the amount of BU ID's present in the current file.
    int matches=0;
    int runsum=0;
    for (int i=0; (i+8)<s.length(); i++) { //Make sure it's longer!
        if (s[i]=='U') { //check if it starts with U
            for (int j=1; j<10; j++) {
                if ((j<9)&&(isdigit(s[i+j])) ) { //Makes sure the 8 characters following U are #s
                    continue;
                } else if ( (j==9) && (!isdigit(s[i+j])) ) { //Make sure no digits after 8 digits
                    runsum=0;
                    for (int k=1; k<9; k++) {
                        runsum+=s[i+k];
                    }
                    if (runsum-384 > n) //-384 to account for the ASCII numeral offsets.
                        matches++;
                    i+=j; //Push the loop forward.
                } else {
                    i+=j; //There was a non digit within the 8, or a digit on the 9th, go forward
                    break;
                }
            }
        } else
            continue; //Didn't start with U, continue on through the string.
    }
    return matches; //Done!
}

