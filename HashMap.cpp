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

int HashMap::hash(string word){
    int wordval = 0;
    for(int i = 0; i < word.length(); i++){
        wordval += word[i];
    }
    return wordval;
}
int HashMap::hashChunk(queue<string> *qpt) {

}

void HashMap::insert(int *keys, int *values, int key, int value){

}

int HashMap::search(int *keys, int *values, int key) {

}

