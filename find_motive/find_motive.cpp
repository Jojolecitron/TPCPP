#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


int find_motive(std::string filename, std::string motive){
    std::ifstream file (filename); 
    std::string line;
    if(!file.is_open()){
        std::cout << "The file " << filename << " could not be opened." << std::endl;
        return 1;
    }
    int nb_it(0);
    std::string mot;
    file >> mot;
    while(!file.eof()){
        if(mot.find(motive) != std::string::npos){
            nb_it++;
        }
        file >> mot;
    }
    std::cout << "The file " << filename << " contains " << nb_it << " words containing the motive " << motive << std::endl;
    return 0;
}


int main(int argc, char* argv[]){
    if(argc == 3)
        return find_motive(argv[1], argv[2]);
    else
        std::cout << "nombre d'argument mauvais " << argc << '\n' ;
    return 0;
}
