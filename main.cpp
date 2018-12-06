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

int getdir(string dir, vector<string> &files);
void displayResults(int results[][100], vector<string> fileNames, int numDocs, int threshold);

int main(int argc, char *argv[]){
    //-----------------------------------------------------------------
    //Get arguments (directory path, chunk size, threshold)
    //REMEMBER TO CHANGE*************
    HashMap hashObject;
    int nElements = 6;
    queue<string> qpt;
    queue<string> empty;
    string dir = string("sm_doc_set");
    int numDoc = 0;

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
            qpt = decltype(qpt){};
        }
        hashObject.mappingResult(result);
        displayResults(result,files,numDoc,200);
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
    for(int i = 0; i < numDocs; i++){
        for(int j = 0; j < numDocs; j++){
            if((i < j) && (results[i][j] >= threshold)){
                cout<<fileNames[i]<<" , "<<fileNames[j]<<" : "<<results[i][j]<<endl;
            }
        }
    }
}

/*
for (int k = 0 ; k < numDoc ; k++){
for (int v = 0 ; v < numDoc ; v++){
cout << result[k][v] << " ";
}
cout << endl;
}
 */