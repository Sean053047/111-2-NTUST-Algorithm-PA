#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <list>


void Build_MPS(std::vector< std::vector< int> >& MPS, std::vector< std::vector< int>> & indicator, std::map<int ,int>& endpoint, int num_point){
    int k; // unique number the unique pair of j endpoint
    int comparison_val;
    for (int j =1; j<num_point; ++j){
        k = endpoint[j];
        for (int i =0 ; i< j ; ++i){
            if (i == k) {
                MPS[i][j] = MPS[i+1][j-1] + 1;
                indicator[i][j] =3;
            }else{
                if (k==0)
                {
                    comparison_val =1 +MPS[k+1][j-1];
                }else if ( k == num_point -1){
                    comparison_val =MPS[i][k-1] +1;
                }else{
                    comparison_val =MPS[i][k-1] +1 + MPS[k+1][j-1];
                }

                if ( i<=k && k <=j && (comparison_val) >(MPS[i][j-1])){
                    MPS[i][j] = comparison_val;
                    indicator[i][j] = 2;
                }else{
                    MPS[i][j] = MPS[i][j-1];
                    indicator[i][j] = 1;
                }
            }
        }
    }
    // cout <<"Build_MIS =>" <<  &MPS << " " << &indicator << " " << &endpoint<<endl;
}
void Recover_chords( std::vector< std::vector<int> >& indicator, std::map<int, int> endpoint ,std::list<int>& candidate, int i, int j, int num_point){
    int k;
    switch (indicator[i][j]){
        break;
        case 1:
            Recover_chords( indicator, endpoint, candidate , i, j-1, num_point);
        break;
        case 2:
            k = endpoint[j];
            candidate.push_back(k);
            if (k !=0){
                Recover_chords( indicator ,endpoint, candidate , i, k-1, num_point);
            }
            if (k !=num_point-1){
                Recover_chords( indicator ,endpoint, candidate , k+1, j-1, num_point);
            }
        
        break;
        
        case 3:
            k = endpoint[j];
            candidate.push_back(k);
            Recover_chords( indicator, endpoint , candidate , i+1 ,j-1, num_point );
        break;
    }
}
