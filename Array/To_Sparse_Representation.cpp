//Given a matrix, convert it into a sparse representation using 3-tuple format: (row, col, value).
#include <iostream>
using namespace std;

class SPARSE_REPRESENTATION{
  private:
    int nonZero = 0;
    int (*newMatrix)[3];
  public:
    SPARSE_REPRESENTATION():newMatrix(nullptr){}
    ~SPARSE_REPRESENTATION(){delete[]newMatrix;}

    template<size_t row, size_t col>
    int findNonZero(int (&matrix)[row][col]){
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(matrix[i][j] != 0){
            nonZero++;
          }
        }
      }
      return nonZero;
    }

    //for displaying element
    void display(){
      for(int i = 0; i < nonZero; i++){
        for(int j = 0; j < 3; j++){
          cout << newMatrix[i][j] << "    ";
        }
        cout << endl;
      }
    }

    template<size_t R, size_t C>
    void sparseRepresent(int (&matrix)[R][C]){

      newMatrix = new int[findNonZero(matrix)][3];
      int k = 0;
      cout << "Row " << "col " << "value \n";
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(matrix[i][j] != 0){
            newMatrix[k][0] = i;
            newMatrix[k][1] = j;
            newMatrix[k][2] = matrix[i][j];
            k++;
          }
        }
      }
      display();
    }
};
int main(){
  int A[4][4] = {
    {1,2,3,0},
    {0,0,8,0},
    {9,0,7,6},
    {0,0,0,1}
  };
  SPARSE_REPRESENTATION R;
  R.sparseRepresent(A);
  return 0;
}