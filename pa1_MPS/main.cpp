#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <list>

#include "./header/MPS.h" 
#include "./header/utils.h"
using namespace std;

int main(int argc, char **argv){
    
    if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        exit(1);
    }
    
    map<int ,int > endpoint;
    // ? Load input data
    int num_point = Read_file_to_map(endpoint, argv[1]);
    
    
    vector<vector<int> > MPS = vector_2D_create(num_point, num_point);
    vector<vector<int> > indicator = vector_2D_create(num_point-1 , num_point);
    Build_MPS(MPS, indicator, endpoint, num_point);
    cout << "MIPS(0," << num_point-1<< ") :" << MPS[0][num_point-1]<< endl ;
    
    list<int> candidate;
    Recover_chords( indicator, endpoint , candidate, 0, num_point-1, num_point);
    candidate.sort();
    candidate.reverse();

    int size = candidate.size();
    vector< vector<int> > chords = vector_2D_create(size, 2);
    for(int i=0; i<size; ++i){
        int k = candidate.back();
        candidate.pop_back();
        chords[i][0] =  k;
        chords[i][1] =  endpoint[k];
        // cout << chords[i][0] << "\t" << chords[i][1] <<endl;
    }
    
    Write_file(MPS[0][num_point-1] ,chords , argv[2]);

}

