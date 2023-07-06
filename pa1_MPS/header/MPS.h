#include <vector>
#include <map>
#include <list>

#ifndef MPS_Key
#define MPS_Key

void Build_MPS(std::vector< std::vector<int>> &MPS, std::vector< std::vector<int>> &indicator, std::map<int, int> &endpoint, int num_point);
int Recover_chords( std::vector< std::vector<int>> &indicator, std::map<int, int> endpoint, std::list<int> &candidate, int i, int j, int num_point);

#endif