#include <vector>
#include <queue>
#include <map>
#include <string>
#include "./customized.h"

using namespace std;
#ifndef UTILS_H
#define UTILS_H


pair< map<string ,int>  , map<int, vector<int> > >  read_file(string file_path);

void show_total_weight(vector<vector<Grid>> &Path);


vector< vector<int>> vector_2D_create(int row, int col);

void write_file(vector<vector<Grid>> &Path, string file_path);

#endif