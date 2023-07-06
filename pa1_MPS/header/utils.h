
#include <vector>
#include <map>
#include <string>
#ifndef UTILS_Key
#define UTILS_Key

int Read_file_to_map(std::map<int, int> &endpoint, std::string file_path);
void Write_file(int num_chords, std::vector<std::vector<int>> &chords, std::string file_path);
std::vector<std::vector<int>> vector_2D_create(int row, int col);
void show_vector(std::vector<std::vector<int>> &vec);

#endif