#include <vector> 
#include <map>
#include <string>
#include <fstream>
#include <iostream>

int Read_file_to_map(std::map<int, int>& endpoint, std::string file_path){
    std::fstream data_file;
    std::string buffer;
    int num_point;
    data_file.open(file_path, std::fstream::in);
    if(!data_file.is_open()){
        std::cout << "Error: the input file is not opened!!" << std::endl;
        exit(1);
    }
    else{
        // ? To initiate num_point & endpoint_map 
        getline(data_file , buffer);
        num_point = stoi(buffer);        
        while(getline(data_file, buffer)){
            if (buffer.length() == 1 ) {
                break;
            }
            int key = stoi(buffer.substr(0, buffer.find(" ")));
            int val = stoi(buffer.substr(buffer.find(" ")+1, buffer.length()));
            endpoint[key] = val;  
            endpoint[val] = key; 
        }
    }
    return num_point;
}

void Write_file(int num_chords, std::vector< std::vector<int> > & chords, std::string file_path){
    std::fstream result_file;
    result_file.open(file_path, std::fstream::out);
    if(!result_file.is_open()){
        std::cout << "Error: the output file is not opened!!" << std::endl;
        exit(1);
    }else{
        result_file << num_chords <<std::endl ;
        for (int i = 0 ;  i< chords.size() ; ++i){
            if (chords[i][0] >1000){
                result_file << chords[i][0] << "\t" << chords[i][1] << std::endl;
            }else{
                result_file << chords[i][0]  << "\t\t" << chords[i][1]<< std::endl;
            }
        }
        result_file.close();
    }
}

std::vector< std::vector<int>> vector_2D_create(int row, int col){
        std::vector< std::vector<int> > MIS;
        MIS.resize(row);
        for(int i = 0 ; i<row ; ++i){
            MIS[i].resize(col);
            for (int j = 0 ; j<col; ++j){
                MIS[i][j] = 0;
            }
        }
        // cout << MIS.size()  << MIS[MIS.size()-1].size()<< endl;
        
        return MIS;
}
void show_vector(std::vector < std::vector < int > > & vec){
    for (int i =0 ; i<vec.size() ; ++i){
        for(int j=0 ; j< vec[i].size() ; ++j){
            std::cout << vec[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}
