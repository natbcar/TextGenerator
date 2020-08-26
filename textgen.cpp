#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

set<string> readFileSet(string fileName){
    set<string> words;
    string ifileName = fileName + ".txt";
    string word;
    ifstream infile;
    infile.open(ifileName.c_str());
    while(!infile.eof()){
        getline(infile, word, ' ');
        for(int i = 0; i < word.length(); i++){
            if(!isalpha(word[i])){
                word.erase(i);
            }
        }
        words.insert(word);
    }
    infile.close();
    string ofileName = fileName + "_set.txt";
    ofstream outfile;
    outfile.open(ofileName.c_str());
    if(outfile){
        set<string>::iterator it;
        for(it = words.begin(); it != words.end(); it++){
            outfile << *it << endl;
        }
        outfile.close();
    }
    return words;
}
vector<string> readFileVector(string fileName){
    vector<string> words;
    string ifileName = fileName + ".txt";
    string word;
    ifstream infile;
    infile.open(ifileName.c_str());
    while(!infile.eof()){
        getline(infile, word, ' ');
        for(int i = 0; i < word.length(); i++){
            if(!isalpha(word[i])){
                word.erase(i);
            }
        }
        words.push_back(word);
    }
    infile.close();

    string ofileName = fileName + "_vector.txt";
    ofstream outfile;
    outfile.open(ofileName.c_str());
    if(outfile){
        for(int i = 0; i < words.size(); i++){
            outfile << words[i] << endl;
        }
        outfile.close();
    }
    return words;
}

int main(int argc, char* argv[]){
    string fileName = argv[1];
    set<string> txtSet = readFileSet(fileName);
    vector<string> txtVector = readFileVector(fileName);
    string output = "";
    srand(time(NULL));
    list<string> state;
    map<list<string>, vector<string> > txtMap;
    int M = 2;
    for(int i = 0; i < M; i++){
        state.push_back("");
    }
    for(int i = 0; i < txtVector.size(); i++){
        txtMap[state].push_back(txtVector[i]);
        state.push_back(txtVector[i]);
        state.pop_front();
    }
    state.clear();
    for(int i = 0; i < M; i++){
        state.push_back("");
    }
    for(int i = 0; i < 100; i ++){
        int ind = rand() % txtMap[state].size();
        cout << txtMap[state][ind] << " ";
        state.push_back(txtMap[state][ind]);
        state.pop_front();
    }
    cout << endl;

    return 0;
}
