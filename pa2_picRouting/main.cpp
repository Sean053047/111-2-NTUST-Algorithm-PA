#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <list>
#include <map>
    
#include "./header/utils.h"
#include "./header/Dijkstra.h"
#include "./header/customized.h"

using namespace std;
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        exit(1);
    }

    auto start = chrono::high_resolution_clock::now();
    map<string, int> condition;
    map<int, vector<int>> net;
    tie(condition, net) = read_file(argv[1]);
    vector<vector<Grid>> Path = Dijkstra(condition, net);
    
    show_total_weight(Path);
    
    write_file(Path, argv[2]);


    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Duration: "<<  duration.count() << " s\n";
}