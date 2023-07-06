#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <map>



#include "../header/customized.h"

using namespace std;

void show_total_weight(vector<vector<Grid>> &Path){
    int weight=0;
    for ( int i =0 ; i<Path.size() ; ++i){
        int end = Path[i].size()-1;
        weight += Path[i][end].weight;
    }
    cout << "Total Weight: " << weight<<endl;   
}

vector<vector<int>> vector_2D_create(int row, int col)
{
    vector<vector<int>> vec;
    vec.resize(row);
    for (int i = 0; i < row; ++i){
        vec[i].resize(col);
        for (int j = 0; j < col; ++j){
            vec[i][j] = 0;
        }
    }
    return vec;
}


pair<map<string, int>, map<int, vector<int>>> read_file(string file_path)
{
    fstream input_file;
    string buffer;
    map<string, int> condition;
    map<int, vector<int>> net;
    input_file.open(file_path, fstream::in);
    if (!input_file.is_open())
    {
        cout << " Error: the input file is not opened!!" << endl;
        exit(1);
    }
    getline(input_file, buffer);
    int idx1 = buffer.rfind(' ');
    int idx2 = buffer.rfind(' ', idx1 - 1);
    condition["col"] = stoi(buffer.substr(idx2 + 1, idx1));
    condition["row"] = stoi(buffer.substr(idx1 + 1, buffer.length()));
    for (int i = 0; i < 4; ++i)
    {
        getline(input_file, buffer);
        int idx1 = buffer.find(" ");
        int idx2 = buffer.rfind(" ");
        condition[buffer.substr(0, idx1)] = stoi(buffer.substr(idx2 + 1, buffer.length()));
    }

    while (getline(input_file, buffer))
    {
        int idx1 = -1;
        int idx2;
        vector<int> endpoints;
        if (buffer.length() == 0)
        {
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            idx2 = buffer.find(" ", idx1 + 1);
            endpoints.push_back(stoi(buffer.substr(idx1 + 1, idx2)));
            idx1 = idx2;
            if (i == 3)
            {
                endpoints.push_back(stoi(buffer.substr(idx1, buffer.length())));
            }
        }
        int key = endpoints[0];
        endpoints.erase(endpoints.begin());
        net[key] = endpoints;
    }
    return make_pair(condition, net);
}

void write_file(vector<vector<Grid>> &Path, string file_path)
{
    fstream result_file;
    result_file.open(file_path, fstream::out);
    if (!result_file.is_open())
    {
        cout << "Error: The output file is not opened!" << endl;
        exit(0);
    }
    for (int i = 0; i < Path.size(); ++i)
    {       
        result_file << i << " " << Path[i].size() - 1 << endl;   
        for (int j = 0; j < Path[i].size() - 1; ++j){
            result_file << Path[i][j].col << " " << Path[i][j].row << " ";
            result_file << Path[i][j + 1].col << " " << Path[i][j + 1].row << endl;
        }
    }
}

