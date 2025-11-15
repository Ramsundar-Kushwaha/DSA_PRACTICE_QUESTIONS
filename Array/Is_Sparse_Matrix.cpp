//Write a Program to count the number of zero elements in a matrix. if zeros > 60% classify it as a sparse matrix
#include <iostream>
using namespace std;

class IS_SPARSE{
  public:
    template<size_t R, size_t C>
    bool isSparse(int (&matrix)[R][C]){
      int totalZero = 0;
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(matrix[i][j] == 0){
            totalZero++;
          }
        }
      }
      float percentageOfZeros = (totalZero * 100.0f) / (R * C);

      cout << "No. of Zeros: " << percentageOfZeros <<"%\n";

      if(percentageOfZeros > 60){
        cout << "Is Sparse Matrix\n";
        return true;
      }
      cout << "Is Not Sparse\n";
      return false;
    } 
};
int main(){
  int A[4][4] = {
    {1,0,0,0},
    {0,6,7,0},
    {9,0,0,1},
    {3,0,0,0}
  };
  IS_SPARSE S;
  S.isSparse(A);
  return 0;
}