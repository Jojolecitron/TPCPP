#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int find_motive(string filename, string motive){
    ifstream file (filename); 
    string line;
    if(!file.is_open()){
        cout << "The file " << filename << "could not be opened." << endl;
        return 1;
    }   
    int pos(0);
    int nb_it(0);
    while(getline(file, line)){
        for(int i = 0; i<line.length(); i++){
            if(pos == motive.length()){
                nb_it++;
                pos = -1;
            }
            else if(line[i] == ' '){
                pos = 0;
            }
            else if(line[i] == motive[pos] && pos != -1){
                pos++;
            }
            else{
                pos = 0;
            }
        }
    }
    cout << "The file " << filename << " contains " << nb_it << " words containing " << motive << endl;
    return 0;
}


int main(){
    string filename, motive;
    cin >> filename;
    cin >> motive;
    find_motive(filename, motive);
    return 0;
}