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

#define LISTSIZE 1000001
#define HASHDIV 1000001

using namespace std;

class HashMap {
public:
    int hashKey(string chunk);
    void insert(int key, int docIndex);
    void mapping(queue<string> qpt, int nElements, int docIndex);
    void mappingResult(int results[][100]);

private:

    struct HashNode {
        int docIndex;
        HashNode *next;
    };
    HashNode* list[LISTSIZE];
};

#endif //CHEATERS_HASHMAP_H