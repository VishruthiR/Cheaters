#include<stdlib.h>
#include<iostream>
#include<stdbool.h>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<cstring>
#include"HashMap.h"

using namespace std;

struct displayNode{
    int matches;
    string doc1;
    string doc2;
};


int getdir(string dir, vector<string> &files);
void displayResults(int results[][100], vector<string> fileNames, int numDocs, int threshold);
bool operator < (const displayNode a, const displayNode b);


int main(int argc, char *argv[]){
    //-----------------------------------------------------------------
    //Get arguments (directory path, chunk size, threshold)
    HashMap hashObject;
    int nElements = 5;
    int threshold = 0;;
    int numDoc = 0;;
    string dir = "";
    
    dir = argv[1];
    char * randpoint = argv[2];
    nElements = atoi (randpoint);
    randpoint = argv[3];
    threshold = atoi (randpoint);
    
    
    vector<string> files = vector<string>();
    numDoc = getdir(dir,files);
    
    //Initializing array
    if(numDoc != 0){
        int result[100][100];
        for(int i = 0 ; i < numDoc ; i++){
            for(int j = 0 ; j <numDoc ; j++){
                result[i][j] = 0;
            }
        }
        for(int docIndex = 0; docIndex < files.size(); docIndex++) {
            queue<string> qpt;
            ifstream inFile;
            string fName = files[docIndex];
            fName = dir + "/" + fName;
            inFile.open(fName.c_str());
            string s;
            inFile >> s;
            //Sets up Queue
            while (inFile) {
                transform(s.begin(), s.end(), s.begin(), ::toupper);
                for (int i = 0; i < s.size(); i++) {
                    if (ispunct(s[i])) {
                        s.erase(i--, 1);
                        i++;
                    }
                    if ((int)s[i] > 90 || (int)s[i] < 65 ){
                        if((int)s[i] > 57 || (int)s[i] < 48 ) {
                            s.erase(i--, 1);
                            i++;
                        }
                    }
                }
                qpt.push(s);
                inFile >> s;
            }
            hashObject.mapping(qpt, nElements, docIndex);
        }
        hashObject.mappingResult(result);
        displayResults(result,files,numDoc,threshold);
    }
}








int getdir(string dir, vector<string> &files){
    int count = 0;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error opening directory : " << dir << endl;
        return 0;
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        if(string(dirp->d_name) == "." || string(dirp->d_name) == ".."){
            continue;
        }
        else {
            files.push_back(string(dirp->d_name));
            count++;
        }
    }
    closedir(dp);
    return count;
}






void displayResults(int results[][100], vector<string> fileNames, int numDocs, int threshold){
    vector<displayNode> toPrint;
    for(int i = 0; i < numDocs; i++){
        for(int j = 0; j < numDocs; j++){
            if((i < j) && (results[i][j] >= threshold)){
                displayNode newNode = {results[i][j], fileNames[i], fileNames[j]};
                toPrint.push_back(newNode);
            }
        }
    }
    sort(toPrint.begin(), toPrint.end());
    for(int k = 0; k < toPrint.size(); k++){
        cout<<toPrint[k].matches<<" : "<<toPrint[k].doc1<<" , "<<toPrint[k].doc2<<endl;
    }
}

bool operator < (const displayNode a, const displayNode b){
    return (a.matches > b.matches);
}
/*
 for (int k = 0 ; k < numDoc ; k++){
 for (int v = 0 ; v < numDoc ; v++){
 cout << result[k][v] << " ";
 }
 cout << endl;
 }
 */
