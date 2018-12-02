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
    int hash(string word);
    int hashChunk(queue<string> *qpt);
    void insert(int *keys, int *values, int key, int value);
    int search(int *keys, int *values, int key);
private:
};



#endif //CHEATERS_HASHMAP_H
