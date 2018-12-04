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
    while (inFile) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 0 ; i < s.size() ; i++){
            if(ispunct(s[i])){
                s.erase(i--, 1);
            }
        }
        qpt.push(s);
        inFile >> s;
    }
    //-----------------------------------------------------------------
    //NWordSequences
    long documentElements = qpt.size();
    long counter = 0;
    vector<string> nWordSequence;
    for(int i = 0 ; i < nElements; i++){
        nWordSequence.push_back(qpt.front());
        qpt.pop();
    }
    //At this point we have our initial vector of n Words
    while(counter < (documentElements - nElements) ){
        for( int i = 0; i < nWordSequence.size() ; i++ ) {
            cout << nWordSequence[i] << endl;
        }
        //EXPLAIN TO VISH
        HashMap testMap((documentElements - nElements));
        cout << testMap.hashKey(nWordSequence, testMap.getListSize()) << endl;
        nWordSequence.erase(nWordSequence.begin());
        nWordSequence.push_back(qpt.front());
        qpt.pop();
        counter ++;
        cout << endl;
    }
    //PrintTestQ
    //while(!qpt.empty()){
    //    cout << qpt.front() << endl;
    //    qpt.pop();
    //}
}

