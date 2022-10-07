#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int find_motive(string filename, string motive){
    ifstream file (filename); 
    string line;
    if(!file.is_open()){
        cout << "The file " << filename << " could not be opened." << endl;
        return 1;
    }
    int nb_it(0);
    int nb(0);
    int pos(0);
    string mot;
    file >> mot;
    while(!file.eof()){
        for(int i = 0; i<mot.length(); i++){
            if(mot[i] == motive[pos]){
                pos++;
            }
            else{
                pos = 0;
            }
            if(pos == motive.length()){
                nb_it++;
                pos = 0;
                break;
            }
        }
        nb++;
        file >> mot;
    }
    cout << "The file " << filename << " contains " << nb_it << " words containing the motive " << motive << endl;
    return 0;
}


int main(int argc, char* argv[]){
    if(argc == 3)
        return find_motive(argv[1], argv[2]);
    else
        cout << "nombre d'argument mauvais " << argc << '\n' ;
    return 0;
}
