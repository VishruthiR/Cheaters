#include "HashMap.h"
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>
#include <climits>
using namespace std;

int HashMap::hashKey(string chunk){
    long long chunkVal = 0;
    long long chunkValtemp = 0;
    long long chunkVal2 = 0;
    for(int i = 0; i < chunk.length(); i++) {
        if (chunkVal + long(chunk[i] * pow(3, i)) > 0) {
            chunkVal += long(chunk[i] * pow(3, i)); // power function instead of 11^i... 11 gave me overflow so I am using 7
        } else {
            chunkVal %= LISTSIZE;
            return (int(chunkVal));
        }
    }
    chunkVal %= LISTSIZE;
    return (int(chunkVal));
}

void HashMap::insert(int key, int docIndex){
    HashNode *insertNode = new HashNode;
    insertNode->docIndex = docIndex;
    insertNode->next = list[key];
    list[key] = insertNode;
}

void HashMap::mappingResult(int result[][100]) {
    int i = 0;
    while(i < LISTSIZE){
        while(list[i] != NULL){
            if(list[i]->next == NULL){
                delete list[i];
                list[i] = NULL;
            }
            else{
                result[list[i]->docIndex][(list[i]->next)->docIndex] += 1;
                HashNode *temp = list[i]->next;
                delete list[i];
                list[i] = temp;
            }
        }
        i++;
    }
}

void HashMap::mapping(queue<string> qpt, int nElements, int docIndex) {
    vector<string> nWordSequence;
    for (int i = 0; i < nElements; i++) {
        nWordSequence.push_back(qpt.front());
        qpt.pop();
    }
    while(!qpt.empty()) {
        string chunk = ""; //had to change this to "" instead of NULL
        for (int i = 0; i < nElements; i++) { // changed this nElements instead of size of vector.. its always the same
            chunk += nWordSequence[i];
        }
        insert(hashKey(chunk),docIndex);
        nWordSequence.erase(nWordSequence.begin());
        nWordSequence.push_back(qpt.front());
        qpt.pop();
    }
}