#include<stdlib.h>
#include<iostream>
#include<stdbool.h>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include"HashMap.h"

using namespace std;

int main(){
    int nElements = 6;
    queue<string> qpt;
    ifstream inFile;
    inFile.open("test.txt");
    string s;
    inFile >> s;

    //-----------------------------------------------------------------
    //LowerCase Function
    //ErasePunc Function
    //Makes Queue for document
    while (inFile) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < s.size(); i++) {
            if (ispunct(s[i])) {
                s.erase(i--, 1);
                }
            }
        qpt.push(s);
        inFile >> s;
        }
    //-----------------------------------------------------------------

}