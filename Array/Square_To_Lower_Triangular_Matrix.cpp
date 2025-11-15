//Write a Program to convert a square matrix into its lower triangular matrix from(zero out upper values).
#include <iostream>
using namespace std;

class TO_LOWER_TRIANGULAR{
    public:
    //checks whether it is square matrix or not?
    bool isSquare(int rows, int columns){
      return (rows == columns);
    }
    
    //square matrix to lower triangular matrix
    template<size_t R, size_t C>
    void toLowerTriangular(int (&matrix)[R][C]){
      cout << "Order: " << R << " x " << C << endl;
      if(!isSquare(R, C)){
        cout << "Not Square Matrix | Can't be Converted\n";
        return;
      }
      //for zero out the lower elements
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(i < j && matrix[i][j] != 0){
            matrix[i][j] = 0;
          }
        }
      }
    }

    //for displaying matrix elements
    template<size_t row, size_t col>
    void display(int (&ptr)[row][col]){
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          cout << ptr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(){
  int A[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  TO_LOWER_TRIANGULAR T;
  T.toLowerTriangular(A);
  T.display(A);
  return 0;
}