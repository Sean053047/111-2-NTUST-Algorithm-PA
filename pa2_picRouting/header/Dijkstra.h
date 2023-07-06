
#include <vector>
#include <string>
#include <map>
#include "./customized.h"

using namespace std;
#ifndef DIJK
#define DIJK

vector< vector<Grid>> create_graph(int row, int col);
void show_path(vector< vector < Grid> > &Graph, int y , int x);
vector<vector<Grid>> Dijkstra(map<string ,int> &condition, map<int, vector<int> > &net);

#endif