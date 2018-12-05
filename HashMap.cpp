#include "HashMap.h"
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int HashMap::hashKey(string chunk){
    long chunkval = 0;
    for(int i = 0; i < chunk.length(); i++){
        chunkval += (int(chunk[i])) * (11^i);
    }
    return ((int)(chunkval % LISTSIZE));
}

void HashMap::insert(int key, int docIndex){
    HashNode *insertNode = new HashNode;
    insertNode->docIndex = docIndex;
    insertNode->next = list[key];
    list[key] = insertNode;
}

void HashMap::mappingResult(int **result) {
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
        string chunk = NULL;
        for (int i = 0; i < nWordSequence.size(); i++) {
            chunk += nWordSequence[i];
        }
        insert(hashKey(chunk),docIndex);
        nWordSequence.erase(nWordSequence.begin());
        nWordSequence.push_back(qpt.front());
        qpt.pop();
    }
}