#include <string>
#ifndef CUS_H
#define CUS_H
using namespace std;
struct Grid
{
    bool operator()(Grid* g1, Grid* g2) {
        return g1->weight < g2->weight;
    }
    int row;
    int col;
    int weight;
    Grid *pre;
};

struct Path_dist{
    int pid;
    double dist;
    string judge = "Smaller";
    bool operator () (Path_dist p1, Path_dist p2) {
        if (p1.judge == "Bigger"){
            return p1.dist > p2.dist;
        }
        else{
            return p1.dist < p2.dist;
        }
    }
};

#endif