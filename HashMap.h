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

#define LISTSIZE 10000001

using namespace std;

class HashMap {
public:

    int hashKey(string word);
    void insert(int key, int docIndex);
    void mappingResult(int **result);
    void mapping(queue<string>* qpt, int nElements, int docIndex);

private:

    struct HashNode {
        int key;
        HashNode *next;
    };
    HashNode* list[LISTSIZE] = {nullptr};
};



#endif //CHEATERS_HASHMAP_H
