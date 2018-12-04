#ifndef CHEATERS_HASHMAP_H
#define CHEATERS_HASHMAP_H

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

class HashMap {
public:
    HashMap(int numSequences){
        head = NULL;
        listSize = numSequences;
        //EXPLAIN TO VISH
        nodeFinder = new HashNode[listSize];
    }
    int hash(string word);
    int hashChunk(queue<string> *qpt);
    void insert(int *keys, int *values, int key, int value);
    int search(int *keys, int *values, int key);
    int hashKey(vector <string> nWordSequence, int listSize);
    int getListSize()
    {
        return listSize;
    };

private:
    //EXPLAIN TO VISH
    int listSize;
    struct HashNode {
        int key;
        bool flag;
        HashNode *next;
    };
    HashNode *head;
    //EXPLAIN TO VISH
    HashNode *nodeFinder;
};



#endif //CHEATERS_HASHMAP_H
